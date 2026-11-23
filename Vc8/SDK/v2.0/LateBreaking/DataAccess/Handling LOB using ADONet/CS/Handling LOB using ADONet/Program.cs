/*=====================================================================

  File:     Program.cs for Handling LOB using ADO.Net Example
  Summary:  The purpose of this sample is to show:
				1) how to read binary data from a file and store the 
                   contents into a database
				2) how to retrieve binary data stored in the database 
                   and write the contents to a file
  Date:	    April 14, 2003

---------------------------------------------------------------------
  This file is part of the Microsoft SQL Server Code Samples.
  Copyright (C) Microsoft Corporation.  All rights reserved.

  This source code is intended only as a supplement to Microsoft
  Development Tools and/or on-line documentation.  See these other
  materials for detailed information regarding Microsoft code samples.

  THIS CODE AND INFORMATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY
  KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
  IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
  PARTICULAR PURPOSE.
======================================================================== */

#region Using directives

using System;
using System.Collections.Generic;
using System.Text;
using System.IO;

#endregion

namespace Microsoft.Samples.SqlServer
{
    /// <summary>
    /// Entry point for the sample.
    /// </summary>
    class Program
    {
        /// <summary>
        /// Command line sample showing how to read/write large binary objects stored in the database.
        /// <param name="args[]">Input parameters.</param>		
        ///		/in:	Name of the file to read and store contents in the database. 
        ///		/out:	Name of the file to store the contents read from the database.
        ///		/dsrc:	Name of the database server.
        /// </summary>		
        static void Main(string[] args)
        {
            // Set default values for input parameters.
            Int32 DocumentID = 1;

            // Get the path location of the test file to be saved in the database.
            string datafilesDirectory
                = Directory.GetCurrentDirectory().ToUpper(
                System.Globalization.CultureInfo.InvariantCulture);

            try
            {
                Int32 stringLength = datafilesDirectory.IndexOf(@"CS\HANDLING LOB USING ADONET\BIN\DEBUG") - 1;
                if (stringLength < 0)
                    throw new DirectoryNotFoundException("Folder not found:  " + datafilesDirectory);

                datafilesDirectory = datafilesDirectory.Substring(0, stringLength) + @"\DataFiles\";

                // Use the user's application data folder to save the contents of varbinary(max) column.
                string userDirectory = System.Environment.GetEnvironmentVariable("APPDATA") + @"\";

                string inFileName = "testdoc.doc";
                string outFileName = "docout.doc";

                string dataSource = ".";

                // Split the parameters passed into individual arrays so that they can processed correctly.
                for (int i = 0; i < args.Length; i++)
                {
                    string arg = args[i];

                    // Name of the file to read and store contents in the database. 
                    if (arg.StartsWith("/in:"))
                        inFileName = arg.Substring(4);
                    // Name of the file to store the contents read from the database.
                    else if (arg.StartsWith("/out:"))
                        outFileName = arg.Substring(5);
                    // Name of the database server.
                    else if (arg.StartsWith("/dsrc:"))
                        dataSource = arg.Substring(6);
                }

                try
                {
                    // Make sure the folders / files exist.
                    DirectoryInfo directoryInfo = new DirectoryInfo(datafilesDirectory);
                    if (!directoryInfo.Exists)
                        throw new DirectoryNotFoundException("Folder not found:  " + datafilesDirectory);

                    directoryInfo = new DirectoryInfo(userDirectory);
                    if (!directoryInfo.Exists)
                        throw new DirectoryNotFoundException("Folder not found:  " + userDirectory);

                    FileInfo fileInfo = new FileInfo(datafilesDirectory + inFileName);
                    if (!fileInfo.Exists)
                        throw new FileNotFoundException("File not found.", inFileName);

                    LargeObjectBinary largeObjectBinary = new LargeObjectBinary(dataSource);
                    // Reads large binary objects from the database into a file.
                    largeObjectBinary.GetDocumentFromDb(DocumentID, userDirectory, outFileName);
                    // Save the contents of a file in the database.
                    largeObjectBinary.InsertDocument(datafilesDirectory, inFileName, fileInfo.Extension);
                }
                finally
                {
                }
            }
            catch (SystemException se)
            {
                Console.Error.WriteLine("A system exception occurred: {0}", se.ToString());
                Environment.Exit(1);
            }
            finally
            {
            }

            Environment.Exit(0);
        }
    }
}