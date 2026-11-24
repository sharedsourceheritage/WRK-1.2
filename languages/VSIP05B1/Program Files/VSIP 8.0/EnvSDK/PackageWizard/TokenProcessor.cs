//------------------------------------------------------------------------------
// <copyright from='2003' to='2004' company='Microsoft Corporation'>           
//  Copyright (c) Microsoft Corporation, All rights reserved.             
//  This code sample is provided "AS IS" without warranty of any kind, 
//  it is not recommended for use in a production environment.
// </copyright>                                                                
//------------------------------------------------------------------------------

using System;
using System.Collections;
using System.Globalization;

namespace PackageWizard
{
    public enum TokenReplaceType
    {
        ReplaceString,
        ReplaceNumber,
        ReplaceCode
    }

    /// <summary>
    /// Contain a number of functions that handle token replacement
    /// </summary>
    public class TokenProcessor
    {
        #region fields
            // Information used by the token replacement functions
            private string projectName;
            private string projectClass;
            private string currentTemplatePath;
            private string newProjectPath;
            private Guid packageGuid;
            private Guid menuGroupGuid;
            private Guid cmdSetGuid;

            // Internal fields
            private EnvDTE.DTE DTE;
            private bool isReady;
            private ArrayList listToReplace;
            private ArrayList listToDelete;

        #endregion

        #region Initialization
        public TokenProcessor()
        {
            projectName = null;
            projectClass = null;
            currentTemplatePath = null;
            newProjectPath = null;
            packageGuid = Guid.NewGuid();
            menuGroupGuid = Guid.NewGuid();
            cmdSetGuid = Guid.NewGuid();

            DTE = null;
            isReady = false;

            listToReplace = new ArrayList();
            listToDelete = new ArrayList();
        }


        public void AddReplace(string token, string replacement, TokenReplaceType ReplaceType)
        {
            listToReplace.Add(new ReplacePair(token, replacement, ReplaceType));
        }

        public void AddDelete(string tokenStart, string tokenEnd)
        {
            listToDelete.Add(new DeletePair(tokenStart, tokenEnd));
        }
        #endregion

        /// <summary>
        /// Look if every required field is set
        /// This is called by all accessor method and the result is cached
        /// so that we don't have to do the check every time a token processing
        /// function is called
        /// </summary>
        private void CheckIfReady()
        {
            isReady = projectName != null;
            isReady &= currentTemplatePath != null;
            isReady &= newProjectPath != null;
            isReady &= DTE != null;
            isReady &= packageGuid != Guid.Empty;
            isReady &= menuGroupGuid != Guid.Empty;
            isReady &= cmdSetGuid != Guid.Empty;
        }


        // NOTE: This function will accept a subset of the characters that can create an
        // identifier name: there are other unicode char that can be inside the name, but
        // this function will not allow. By now it can work this way, but when and if the
        // VSIP package will handle also languages different from english, this function
        // must be changed.
        private bool IsValidIdentifierChar(char c)
        {
            if ( (c>='a') && (c<='z') )
            {
                return true;
            }
            if ( (c>='A') && (c<='Z') )
            {
                return true;
            }
            if (c == '_')
            {
                return true;
            }
            if ( (c>='0') && (c<='9') )
            {
                return true;
            }

            return false;
        }

        private bool IsValidIdentifierStartChar(char c)
        {
            if ( !IsValidIdentifierChar(c) )
            {
                return false;
            }
            if ( (c>='0') && (c<='9') )
            {
                return false;
            }

            return true;
        }

        #region Accessors
        public string ProjectName
        {
            set
            {
                // Before setting the project class name, we have to check if it is a correct
                // identifier for C# or C++.
                projectName = value;
                if ( projectName.Length == 0 )
                {
                    throw new Exception("The project name can't be empty");
                }
                projectClass = "";
                if ( projectName.Length > 0 )
                {
                    for (int i=0; i<projectName.Length; i++)
                    {
                        if ( IsValidIdentifierChar(projectName[i]) )
                        {
                            projectClass += projectName[i];
                        }
                        else
                        {
                            projectClass += '_';
                        }
                    }
                    if ( !IsValidIdentifierStartChar(projectClass[0]) )
                    {
                        projectClass = "_" + projectClass;
                    }
                }
                CheckIfReady();
            }
        }
        public string CurrentTemplatePath
        {
            set
            {
                currentTemplatePath = value;
                CheckIfReady();
            }
        }
        public string NewProjectPath
        {
            set
            {
                newProjectPath = value;
                CheckIfReady();
            }
        }
        public EnvDTE.DTE TheDTE
        {
            set
            {
                DTE = value;
                CheckIfReady();
            }
        }
        #endregion


        #region TokenProcessing
        /// <summary>
        /// Call function with same name to remove token and save the result
        /// in newProjectPath directory.
        /// </summary>
        /// <param name="file">Filename (name+extension) = source = destination</param>
        public void UntokenMiscFile(string file)
        {
            // Source and destination have same name
            UntokenMiscFile(file, file);
        }

        /// <summary>
        /// For all known token, replace token with correct value
        /// The resulting file is saved in the newProjectPath
        /// </summary>
        /// <param name="source">Filename (name+extension) of the source file</param>
        /// <param name="destination">Filename (name+extension) of the destination file</param>
        public void UntokenMiscFile(string source, string destination)
        {
            if (!isReady)
                throw new ArgumentNullException("TokenProcessor not initialized properly");

            string fileExt = System.IO.Path.GetExtension(destination);
            StringProcessor.LanguageType langType = StringProcessor.GetLanguageFromExtension( fileExt );

            EnvDTE.Window CurrentFile = DTE.OpenFile(
                EnvDTE.Constants.vsViewKindTextView, 
                System.IO.Path.Combine(currentTemplatePath, source)
            );
            ReplaceAllTokens(CurrentFile, langType);
            CurrentFile.Document.Save(newProjectPath + "\\" + destination);
            CurrentFile.Close(EnvDTE.vsSaveChanges.vsSaveChangesYes);
        }

        /// <summary>
        /// Replace all tokens in a project item (the project file itself or an object inside the project)
        /// </summary>
        /// <param name="projectItem">The item to untokenize</param>
        public void UntokenProjectFile(EnvDTE.ProjectItem projectItem)
        {
            if (!isReady)
                throw new ArgumentNullException("TokenProcessor not initialized properly");

            // Find the kind of item we are processing.
            string itemName = projectItem.Name;
            StringProcessor.LanguageType langType = StringProcessor.GetLanguageFromExtension( System.IO.Path.GetExtension(itemName) );

            EnvDTE.Window CurrentFile = projectItem.Open(EnvDTE.Constants.vsViewKindTextView);
            ReplaceAllTokens(CurrentFile, langType);
            CurrentFile.Close(EnvDTE.vsSaveChanges.vsSaveChangesYes);
        }
        /// <summary>
        /// Replace all tokens in a file that has already been open in the shell
        /// </summary>
        /// <param name="FileToProcess">An open file in the shell</param>
        /// <param name="LangType">The language expected for the file</param>
        private void ReplaceAllTokens(EnvDTE.Window FileToProcess, StringProcessor.LanguageType LangType)
        {
            if (!isReady)
                throw new ArgumentNullException("TokenProcessor not initialized properly");

            EnvDTE.TextDocument document = FileToProcess.Document.Object("TextDocument") as EnvDTE.TextDocument;

            // Optional Items (remove)
            // Do this first as this will remove token that would otherwise be replaced
            foreach(DeletePair pair in listToDelete)
                DeleteBetweenTokens(document, pair.TokenStart, pair.TokenEnd);

            // Required Items
            ReplaceToken(document, "%ProjectName%", projectName);
            ReplaceToken(document, "%ProjectClass%", projectClass);
            ReplaceToken(document, "%PackageGuid%", packageGuid.ToString("D"));
            ReplaceToken(document, "%PackageGuid1%", GuidToForm1(packageGuid));
            ReplaceToken(document, "%PackageGuid2%", GuidToForm2(packageGuid));
            ReplaceToken(document, "%MenuGroupGuid%", menuGroupGuid.ToString("D"));
            ReplaceToken(document, "%MenuGroupGuid1%", GuidToForm1(menuGroupGuid));
            ReplaceToken(document, "%MenuGroupGuid2%", GuidToForm2(menuGroupGuid));
            ReplaceToken(document, "%CmdSetGuid%", cmdSetGuid.ToString("D"));
            ReplaceToken(document, "%CmdSetGuid1%", GuidToForm1(cmdSetGuid));
            ReplaceToken(document, "%CmdSetGuid2%", GuidToForm2(cmdSetGuid));

            // Optional Items (replace)
            foreach(ReplacePair pair in listToReplace)
                ReplaceToken(document, pair.Token, pair.Replacement(LangType));
        }

        /// <summary>
        /// Replace all instances of the token with the replacement string
        /// in the document (open in VS)
        /// </summary>
        /// <param name="document">VS document</param>
        /// <param name="token">Token to be replaced</param>
        /// <param name="replaceWith">Text to replace the token with</param>
        private void ReplaceToken(EnvDTE.TextDocument document, string token, string replaceWith)
        {
            if (!isReady)
                throw new ArgumentNullException("TokenProcessor not initialized properly");

            EnvDTE.TextRanges textRanges = null;
            int findOptions = (int)EnvDTE.vsFindOptions.vsFindOptionsFromStart+
                (int)EnvDTE.vsFindOptions.vsFindOptionsMatchCase+
                (int)EnvDTE.vsFindOptions.vsFindOptionsMatchWholeWord;

            //Replace all the text that matches token with thr replaceWith text:
            document.ReplacePattern(token, replaceWith, findOptions, ref textRanges);
        }

        /// <summary>
        /// Deletes the text between two tokens, and deletes the tokens it's self
        /// </summary>
        /// <param name="projectItem">The project item to make the replacements within.</param>
        /// <param name="token1">The first token to search for.</param>
        /// <param name="token2">The second token to search for.</param>
        private void DeleteBetweenTokens(EnvDTE.TextDocument textDocument, string token1, string token2)
        {
            EnvDTE.EditPoint unusedEditPoint = null;
            EnvDTE.TextRanges textRanges = null;
            EnvDTE.EditPoint tokenEndPoint;
            EnvDTE.EditPoint tokenStartPoint;
            int findOptions;
            findOptions = (int)EnvDTE.vsFindOptions.vsFindOptionsMatchCase + (int)EnvDTE.vsFindOptions.vsFindOptionsMatchWholeWord;

            //Create edit points for searching:
            tokenEndPoint = textDocument.StartPoint.CreateEditPoint();
            tokenStartPoint = textDocument.StartPoint.CreateEditPoint();

            //Loop while all start / end tokens can be found:
            while (tokenStartPoint.FindPattern(token1, findOptions, ref unusedEditPoint, ref textRanges))
            {
                if (tokenEndPoint.FindPattern(token2, findOptions, ref tokenEndPoint, ref textRanges))
                {
                    //Move the selection to bracket the start / end tokens:
                    textDocument.Selection.MoveToPoint(tokenStartPoint, false);
                    textDocument.Selection.MoveToPoint(tokenEndPoint, true);

                    //Delete the selection:
                    textDocument.Selection.Delete(1);
                }
                else
                {
                    break;
                }
            }
        }

        /// <summary>
        /// Produce a string with the following format:
        /// 0x01020304, 0x0506, 0x0708, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F, 0x10
        /// </summary>
        /// <param name="guid"></param>
        /// <returns></returns>
        public string GuidToForm1(Guid guid)
        {
            byte [] GuidBytes = guid.ToByteArray();
            string ResultingStr="";

            // First 4 bytes
            int i = 0;
            int Number = 0;
            for(i=0;i<4; ++i)
            {
                int CurrentByte = GuidBytes[i];
                Number += CurrentByte<<(8*i);
            }
            UInt32 FourBytes = (UInt32)Number;
            ResultingStr = string.Format(CultureInfo.InvariantCulture, "0x{0}", FourBytes.ToString("X"));

            // 2 chunks of 2 bytes
            for(int j=0; j<2; ++j)
            {
                Number = 0;
                for(int k=0;k<2; ++k)
                {
                    int CurrentByte = GuidBytes[i++];
                    Number += CurrentByte<<(8*k);
                }
                UInt16 TwoBytes = (UInt16)Number;
                ResultingStr += string.Format(CultureInfo.InvariantCulture, ", 0x{0}", TwoBytes.ToString("X"));
            }

            // 8 chunks of 1 bytes
            for(int j=0; j<8; ++j)
            {
                ResultingStr += string.Format(CultureInfo.InvariantCulture, ", 0x{0}", GuidBytes[i++].ToString("X"));
            }

            return ResultingStr;
        }

        /// <summary>
        /// Produce a string with the following format:
        /// 0x01020304, 0x0506, 0x0708, { 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F, 0x10 }
        /// </summary>
        /// <param name="guid"></param>
        /// <returns></returns>
        private string GuidToForm2(Guid guid)
        {
            byte [] GuidBytes = guid.ToByteArray();
            string ResultingStr="";

            // First 4 bytes
            int i = 0;
            int Number = 0;
            for(i=0;i<4; ++i)
            {
                int CurrentByte = GuidBytes[i];
                Number += CurrentByte<<(8*i);
            }
            UInt32 FourBytes = (UInt32)Number;
            ResultingStr = string.Format(CultureInfo.InvariantCulture, "0x{0}", FourBytes.ToString("X"));

            // 2 chunks of 2 bytes
            for(int j=0; j<2; ++j)
            {
                Number = 0;
                for(int k=0;k<2; ++k)
                {
                    int CurrentByte = GuidBytes[i++];
                    Number += CurrentByte<<(8*k);
                }
                UInt16 TwoBytes = (UInt16)Number;
                ResultingStr += string.Format(CultureInfo.InvariantCulture, ", 0x{0}", TwoBytes.ToString("X"));
            }

            // 8 chunks of 1 bytes
            ResultingStr += string.Format(CultureInfo.InvariantCulture, ", {{ 0x{0}", GuidBytes[i++].ToString("X"));
            for(int j=1; j<8; ++j)
            {
                ResultingStr += string.Format(CultureInfo.InvariantCulture, ", 0x{0}", GuidBytes[i++].ToString("X"));
            }
            ResultingStr += " }";

            return ResultingStr;
        }
        #endregion
    }


    // Storage classes for tokens
    class ReplacePair
    {
        private string token;
        private string replacement;
        private TokenReplaceType replaceType;

        public ReplacePair(string stringToReplace, string stringToReplaceWith, TokenReplaceType ReplaceType)
        {
            token = stringToReplace;
            replacement = stringToReplaceWith;
            replaceType = ReplaceType;
        }
        
        /// <summary>
        /// Token that needs to be replaced
        /// </summary>
        public string Token
        {
            get {return token;}
        }
        /// <summary>
        /// String to replace the token with
        /// </summary>
        public string Replacement(StringProcessor.LanguageType LangType)
        {
            string rep = replacement;

            if ( replaceType != TokenReplaceType.ReplaceString )
            {
                return rep;
            }

            return StringProcessor.EscapeString(rep, LangType);
        }
    }
    class DeletePair
    {
        private string tokenStart;
        private string tokenEnd;

        public DeletePair(string blockStart, string blockEnd)
        {
            tokenStart = blockStart;
            tokenEnd = blockEnd;
        }
        
        /// <summary>
        /// Token marking the begining of the block to delete
        /// </summary>
        public string TokenStart
        {
            get {return tokenStart;}
        }
        /// <summary>
        /// Token marking the end of the block to delete
        /// </summary>
        public string TokenEnd
        {
            get {return tokenEnd;}
        }
    }
}
