
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

// FgPrjExt.cpp
// This file holds the source code for the extensions for the
// figure project

#include "stdafx.h"
#include "PrjInc.h"
#include <strsafe.h>


FILE* OpenStream(LPCWSTR wszFileName, LPCWSTR wszMode)
{
    // we do not suport Win9X
    return _wfopen(wszFileName, wszMode);
}


//This class manages building

HRESULT CFigBuildManager::Build(
    /* [in] */ IVsOutputWindowPane *pIVsOutputWindowPane, 
    /* [in] */ CMyProjectHierarchy *pMyProjectHierarchy, 
    /* [in] */ CString strOutDir)
{
    ExpectedPtrRet(pIVsOutputWindowPane);
    ExpectedPtrRet(pMyProjectHierarchy);
    HRESULT                hr = S_OK;
    USES_CONVERSION;

    CFileVwProjNode* pProjectNode = pMyProjectHierarchy->GetProjectNode();
    ExpectedExprRet(pProjectNode != NULL);

    CHierNode*            pHierNode = pProjectNode->GetHead(/*BOOL fDisplayOnly = TRUE*/ FALSE);
    CString                strOutputDirectory;
    BOOL                fCompilationFailed = FALSE;

    CBuildProjNode* pBuildNode = pMyProjectHierarchy->GetBuildProjNode();
    if ( !pBuildNode )
        return E_FAIL;

    hr = GetAbsoluteOutputDirectory(pMyProjectHierarchy, strOutDir, strOutputDirectory);
    IfFailRet(hr);

    //Build steps are:

    // Load the fig compiler server

    hr = LoadFigCompilerServer( pIVsOutputWindowPane );
    IfFailRet(hr);

    //Iterate through the nodes.  Select all the fig
    //files.  Send each fig file to the compiler.  If it 
    //compiles successfully, send each file name, along
    //with the x and y offsets and color, to the compiler 
    //server

    //Look through all the fig files.  If a fig file
    //does not fail compilation, then note that

    FigVector successful;


    pIVsOutputWindowPane->OutputString( L"Compiling fig files...\n" );
    while (SUCCEEDED( hr ) && pHierNode != NULL)
    {
        if (pHierNode->IsKindOf(Type_CFigFileNode)) 
        {    
            CFigFileNode *pFigFileNode = static_cast<CFigFileNode*>(pHierNode);

            CString strFileName = pFigFileNode->GetFullPath();
            ASSERT(strFileName.Find(_T(".fig")) > 1);
            if (!pFigFileNode->m_ExcludeFromBuild)
            {
                pIVsOutputWindowPane->OutputString( L"Compiling " );
                pIVsOutputWindowPane->OutputString( strFileName );
                pIVsOutputWindowPane->OutputString( L"... " );
                pIVsOutputWindowPane->OutputString( L"\n" );
                CComBSTR bstrError;  //This will be the error string
                ASSERT(m_pNewFigComp);
                hr = pFigFileNode->Compile( strOutputDirectory, m_pNewFigComp, &bstrError );
                if (bstrError!=NULL)
                {
                    pIVsOutputWindowPane->OutputString( L"Compilation failed because\n" );
                    pIVsOutputWindowPane->OutputString( bstrError );
                    pIVsOutputWindowPane->OutputString( L"\n" );
                    fCompilationFailed = TRUE;
                }
                else if (FAILED(hr))
                {
                    pIVsOutputWindowPane->OutputString( L"Compilation failed.\n" );
                    fCompilationFailed = TRUE;
                }
                else
                {
                    CProcessedFigFile    SuccessfulFig;
                    SuccessfulFig.m_FileName = pFigFileNode->GetFileName();
                    successful.push_back( SuccessfulFig );
                    CString strCsName;
                    CString strSourcePath;
                    hr = GetOutputOfFigFile(
                        pFigFileNode->GetFileName(), 
                        strOutputDirectory,
                        strCsName,
                        strSourcePath);
                    IfFailRet(hr);
                    hr = pBuildNode->AddItem((LPCTSTR) strSourcePath, (LPCTSTR)strCsName);
                    IfFailRet(hr);
                }
            }
        }
        pHierNode = pHierNode->GetNext(/*BOOL fDisplayOnly = TRUE*/ FALSE);
    }    

    //Now all the fig files that compiled are in the successful
    //vector and copied to the Build Project directory

    //Collect all the cs files, except for ones that
    //are excluded from build.  Open up each, look 
    //for the magic block, and insert all the calls it
    //knows about.  Copy the cs file to the output 
    //directory
    
    //That's it    


    pHierNode = pProjectNode->GetHead(/*BOOL fDisplayOnly = TRUE*/ FALSE);
    pIVsOutputWindowPane->OutputString( L"Updating cs files ... \n" );
    while (SUCCEEDED( hr ) && pHierNode != NULL)
    {
        if (pHierNode->IsKindOf(Type_CLangFileNode)) 
        {    
            CLangFileNode *pLangFileNode = static_cast<CLangFileNode*>(pHierNode);
            CString strFileName = pLangFileNode->GetFullPath();
            ASSERT(strFileName.Find(_T(".cs")) > 1);

            if (!pLangFileNode->m_ExcludeFromBuild)
            {
                CString        outputFile = strOutputDirectory;
                outputFile += pLangFileNode->GetFileName();
                pIVsOutputWindowPane->OutputString(strFileName);
                pIVsOutputWindowPane->OutputString( L"...\n" );

                FILE* ostream;
                if ((ostream = OpenStream(strFileName, L"r" )) == NULL )
                {
                    pIVsOutputWindowPane->OutputString( L"Could not open a specified cs file\n" );
                    fCompilationFailed = TRUE;
                }
                else
                {
                    hr = InsertLangCalls( pIVsOutputWindowPane, ostream, outputFile, successful );
                    fclose( ostream );
                    IfFailRet(hr);
                }

                hr = pBuildNode->AddItem((LPCTSTR) outputFile, (LPCTSTR) pLangFileNode->GetFileName());
                IfFailRet(hr);
            }
        }

        pHierNode = pHierNode->GetNext(/*BOOL fDisplayOnly = TRUE*/ FALSE);
    }

    pBuildNode->Refresh();

    if (fCompilationFailed)
        hr = S_FALSE;
    else
        hr = S_OK;

    return hr;
};


STDMETHODIMP CFigBuildManager::GetAbsoluteOutputDirectory(
    /* [in] */      CMyProjectHierarchy* pMyProjectHierarchy, 
    /* [in]      */ const CString& strOutputDirectory,       
    /* [in, out] */       CString& strAbsoluteOutputDirectory)
{
    ExpectedPtrRet(pMyProjectHierarchy);
    if ( strOutputDirectory.IsEmpty() )
    {
        strAbsoluteOutputDirectory = pMyProjectHierarchy->GetProjectLocation();
        if (strAbsoluteOutputDirectory.Right(1) != _T("\\"))
            strAbsoluteOutputDirectory += _T("\\");
        strAbsoluteOutputDirectory += g_szBuildProjName;
    }
    else if (LUtilIsAbsolutePath(strOutputDirectory))
    {
        strAbsoluteOutputDirectory = strOutputDirectory;    // absolute path given
    }
    else
    {    // relative path given; prepend with project directory.
        if (!LUtilConcatPaths(pMyProjectHierarchy->GetProjectLocation(), strOutputDirectory, strAbsoluteOutputDirectory))
            return E_FAIL;
    }

    if (strAbsoluteOutputDirectory.Right(1) != _T("\\"))
        strAbsoluteOutputDirectory += _T("\\");

    if (!LUtilDirExists(strAbsoluteOutputDirectory))
        if (!LUtilCreateDirectory(strAbsoluteOutputDirectory))
            return GetLastError();

    return S_OK;
}


STDMETHODIMP CFigBuildManager::Clean(
    /* [in] */ IVsOutputWindowPane* pIVsOutputWindowPane, 
    /* [in] */ CMyProjectHierarchy* pMyProjectHierarchy, 
    /* [in] */ CString strOutDir) 
{
    ExpectedPtrRet(pIVsOutputWindowPane);
    ExpectedPtrRet(pMyProjectHierarchy);

    HRESULT    hr = S_OK;
    USES_CONVERSION;

    CBuildProjNode* pBuildNode = pMyProjectHierarchy->GetBuildProjNode();
    ExpectedExprRet(pBuildNode != NULL);

    CComPtr<IVsHierarchy>  srpIVsHierarchyNested = pBuildNode->GetNested();
    ExpectedExprRet(srpIVsHierarchyNested != NULL);

    CComPtr<IVsProject2> srpIVsProject2;
    hr = srpIVsHierarchyNested->QueryInterface(
        IID_IVsProject2, 
        (void **)&srpIVsProject2);
    IfFailRet(hr);

    CString strOutputDirectory;
    hr = GetAbsoluteOutputDirectory(pMyProjectHierarchy, strOutDir, strOutputDirectory);
    IfFailRet(hr);

    CFileVwProjNode* pProjectNode = pMyProjectHierarchy->GetProjectNode();
    ExpectedExprRet(pProjectNode != NULL);

    hr = pIVsOutputWindowPane->OutputString( L"Cleaning...\n" );
    IfFailRet(hr);

    //Iterate through the nodes.  Select all the fig and cs 
    //files. Check for the corresponfing cs file and remove it.

    CHierNode* pHierNode = pProjectNode->GetHead(/*BOOL fDisplayOnly = TRUE*/ FALSE);
    while ( (pHierNode != NULL) && SUCCEEDED(hr))
    {
        CString strCsFullName;
        BOOL    fClean = FALSE;

        if (pHierNode->IsKindOf(Type_CFigFileNode)) 
        {    
            CFigFileNode *pFigFileNode = static_cast<CFigFileNode*>(pHierNode);
            if (!pFigFileNode->m_ExcludeFromBuild)
            {
                CString strCsName;
                hr = GetOutputOfFigFile(
                    pFigFileNode->GetFileName(), 
                    strOutputDirectory,
                    strCsName,
                    strCsFullName);
                IfFailRet(hr);
                fClean = TRUE;
            }
        } 
        else if (pHierNode->IsKindOf(Type_CLangFileNode))
        {
            CLangFileNode *pLangFileNode = static_cast<CLangFileNode*>(pHierNode);
            if (!pLangFileNode->m_ExcludeFromBuild)
            {
                strCsFullName = strOutputDirectory + pLangFileNode->GetFileName();
                fClean = TRUE;
            }
        }

        if (fClean)
        {
            ExpectedExprRet(!strCsFullName.IsEmpty());

            pIVsOutputWindowPane->OutputString( L"Cleaning " );
            pIVsOutputWindowPane->OutputString( strCsFullName );
            pIVsOutputWindowPane->OutputString( L"... \n" );

            VSDOCUMENTPRIORITY docPriority;
            BOOL     fInProject = FALSE;
            VSITEMID itemid;
            hr = srpIVsProject2->IsDocumentInProject(
                T2COLE(strCsFullName),
                &fInProject,
                &docPriority,
                &itemid);
            IfFailRet(hr);

            if (fInProject)
            {
                BOOL fRemoved   = FALSE;
                hr = srpIVsProject2->RemoveItem(NULL, itemid, &fRemoved);
                if (FAILED(hr))
                {
                    pIVsOutputWindowPane->OutputString(T2COLE(strCsFullName));
                    pIVsOutputWindowPane->OutputString( L" can not be removed from its project!\n" );
                    continue;
                }
            }
            else
            {
                if (!::DeleteFile(strCsFullName))
                {
                    hr = HRESULT_FROM_WIN32(GetLastError());
                    pIVsOutputWindowPane->OutputString(strCsFullName);
                    pIVsOutputWindowPane->OutputString( L" can not be deleted!\n" );
                    continue;
               }
            }             
        }

        pHierNode = pHierNode->GetNext(/*BOOL fDisplayOnly = TRUE*/ FALSE);
    }

    pBuildNode->Refresh();
   
    return hr;
}


STDMETHODIMP CFigBuildManager::IsBuildUpToDate(
    /* [in] */  CMyProjectHierarchy* pMyProjectHierarchy, 
    /* [in] */  CString strOutDir,
    /* [out] */ BOOL *pfUpToDate) 
{
    ExpectedPtrRet(pMyProjectHierarchy);
    ExpectedPtrRet(pfUpToDate);
    *pfUpToDate = FALSE;

    HRESULT    hr        = S_OK;
    BOOL    fUpToDate = TRUE;

    CString strOutputDirectory;
    hr = GetAbsoluteOutputDirectory(pMyProjectHierarchy, strOutDir, strOutputDirectory);
    IfFailRet(hr);

    CFileVwProjNode* pProjectNode = pMyProjectHierarchy->GetProjectNode();
    ExpectedExprRet(pProjectNode != NULL);

    //Iterate through the nodes.  Select all the fig and cs 
    //files. Check for the corresponfing cs file and compare the time
    CHierNode* pHierNode = pProjectNode->GetHead(/*BOOL fDisplayOnly = TRUE*/ FALSE);
    while ( (pHierNode != NULL) && SUCCEEDED(hr))
    {
        CString strSourceFile;
        CString strDestFile;
        BOOL    fCompare = FALSE;

        if (pHierNode->IsKindOf(Type_CFigFileNode)) 
        {    
            CFigFileNode *pFigFileNode = static_cast<CFigFileNode*>(pHierNode);
            if (!pFigFileNode->m_ExcludeFromBuild)
            {
                if (pFigFileNode->IsPropertyChanged())
                {
                    fUpToDate = FALSE;
                }
                else
                {
                    strSourceFile = pFigFileNode->GetFullPath();
                    CString strShortName;
                    hr = GetOutputOfFigFile(
                        pFigFileNode->GetFileName(), 
                        strOutputDirectory,
                        strShortName,
                        strDestFile);
                    IfFailRet(hr);
                    fCompare = TRUE;
                }
            }
        } 
        else if (pHierNode->IsKindOf(Type_CLangFileNode))
        {
            CLangFileNode *pLangFileNode = static_cast<CLangFileNode*>(pHierNode);
            if (!pLangFileNode->m_ExcludeFromBuild)
            {
                strSourceFile = pLangFileNode->GetFullPath();
                strDestFile = strOutputDirectory + pLangFileNode->GetFileName();
                fCompare = TRUE;
            }
        }

        if (fCompare)
        {
            ExpectedExprRet(!strSourceFile.IsEmpty());
            ExpectedExprRet(!strDestFile.IsEmpty());
            
            BOOL fSourceIsNewer = TRUE;
            FILETIME ftSource;
            FILETIME ftDest;
            if ( LUtilGetFileTime(strSourceFile, &ftSource) &&
                 LUtilGetFileTime(strDestFile, &ftDest)) 
            {
                fSourceIsNewer = (CompareFileTime(&ftSource, &ftDest) > 0);
            }
            if (fSourceIsNewer)
                fUpToDate = FALSE;
        }

        pHierNode = pHierNode->GetNext(/*BOOL fDisplayOnly = TRUE*/ FALSE);
    }    

    *pfUpToDate = fUpToDate;
    return hr;
}


STDMETHODIMP CFigBuildManager::GetOutputOfFigFile(
    /* [in]      */ const CString& strFigFileShortName,       
    /* [in]      */ const CString& strOutputDirectory,       
    /* [in, out] */       CString& strOutputFileShortName,
    /* [in, out] */       CString& strOutputFileFullName)
{
    ExpectedExprRet(!strOutputDirectory.IsEmpty());
    ExpectedExprRet(!strFigFileShortName.IsEmpty());
    ExpectedExprRet(strFigFileShortName.Right(4).CompareNoCase(_T(".fig")) == 0);

    int cch = strFigFileShortName.GetLength();
    strOutputFileShortName = strFigFileShortName.Left(cch-3);
    strOutputFileShortName += _T("cs");
    strOutputFileFullName = strOutputDirectory + strOutputFileShortName;

    return S_OK;
}


HRESULT CFigBuildManager::InsertLangCalls(IVsOutputWindowPane *pIVsOutputPane,FILE* istream,CString outputFile,FigVector successful)
{
    ExpectedPtrRet(pIVsOutputPane);
    ExpectedPtrRet(istream);
    CLangLines    lines;
    CLangLine    line;
    int            charVal;

    while (!feof( istream ))
    {
        charVal = fgetc( istream );
        char    changed = (char) charVal;
        if (charVal == '\n')
        {
            line.m_Line += changed;
            lines.push_back( line );
            line = CLangLine();
        }
        else
            line.m_Line += changed;
    }

    // reject the very last token as end-of-file
    line.m_Line = line.m_Line.Left( line.m_Line.GetLength() - 1 );
    lines.push_back( line );

    // Now insert calls where ever you find the magic block
    // Even if the cs file doesn't have a magic block it should
    // still be copied
    FILE*    ostream; 
    if ((ostream = OpenStream( outputFile, L"w" )) == NULL )    // open the output file
        pIVsOutputPane->OutputString( L"Could not open a specified cs file\n" );
    else 
    {
        CLangLines::iterator    iterator;
        FigVector::iterator    figIterator;
        for (iterator = lines.begin(); iterator != lines.end(); iterator++) 
        {
            if (iterator->IsMagic())
            {
                for (figIterator = successful.begin(); figIterator != successful.end();figIterator++) 
                    figIterator->CreateFigCall( ostream );
            }
            else 
                iterator->PutLine(ostream);
        }    //Done iterating over  lines
        fclose(ostream);
    }
    return S_OK;    
};

HRESULT CFigBuildManager::LoadFigCompilerServer(IVsOutputWindowPane *pIVsOutputWindowPane)
{
    HRESULT hr = NOERROR;

    if (m_pNewFigComp != NULL)
        return S_OK;

    ExpectedPtrRet(pIVsOutputWindowPane);
    hr = _VxModule.VsCreateInstance(
        /* REFCLSID rclsid              */ CLSID_FigCompiler, 
        /* REFIID riid                  */ IID_IFigCompiler, 
        /* void **ppvObj              */ (LPVOID*)&m_pNewFigComp,
        /* IUnknown* pUnkOuter = NULL */ NULL, 
        /* DWORD dwFlags = CLSCTX_ALL */ CLSCTX_INPROC_SERVER);
    if( FAILED(hr))
        {
            pIVsOutputWindowPane->OutputString(L"The compiler server did not load\n");
            return hr; 
        };
    if( SUCCEEDED(hr))
        {
            pIVsOutputWindowPane->OutputString(L"The compiler server loaded\n");
        };
    return S_OK;
};

bool CLangLine::IsMagic()
{
    CString search = "//This line will be replaced by calls to cs classes. Do not edit this line";
    int start;
    start = m_Line.Find(search);
    if (start > 0) return true;
    else return false;
};

void CLangLine::PutLine(FILE* ostream)
{
    _fputts(m_Line,ostream);    
};

void CProcessedFigFile::CreateFigCall(FILE *stream){
    //Two lines.  For example 
    //Figure1 _Figure1 = new Figure1();
    //_Figure1.Draw(e);

    //At this point the file still has the .fig in it
    //This still might not be a valid .fig file 
    //int position = m_FileName.Find(".fig");
    CString className = m_FileName.Left(m_FileName.GetLength()-4);

    TCHAR* tab = _T("     ");
    TCHAR* newLine = _T("\n");
    TCHAR* space = _T(" ");
    TCHAR* easyOut = _T("_");
    TCHAR* equals = _T(" = new ");
    TCHAR* paren = _T("();\n");
    TCHAR* dotDraw = _T(".Draw(e);\n");
    _fputts(tab,stream);
    _fputts(className,stream);
    _fputts(space,stream);
    _fputts(easyOut,stream);
    _fputts(className,stream);
    _fputts(equals,stream);
    _fputts(className,stream);
    _fputts(paren,stream);
    _fputts(tab,stream);
    _fputts(easyOut,stream);
    _fputts(className,stream);
    _fputts(dotDraw,stream);
};

HRESULT CFigFileNode::CreateInstance
(
LPCTSTR pszFullPath,
CFigFileNode **ppFileNode 
)
{
    ExpectedPtrRet(pszFullPath);
    ExpectedPtrRet(ppFileNode);

    CComObject<CFigFileNode> *pFileNode = NULL;  // created with 0 ref count
    HRESULT hr = CComObject<CFigFileNode>::CreateInstance(&pFileNode);
    if (SUCCEEDED(hr))
    {
        pFileNode->AddRef();
        hr = pFileNode->Initialize(pszFullPath);
        if (FAILED(hr))
        {
            pFileNode->Release();
            pFileNode = NULL;
        }
    }
    *ppFileNode = pFileNode;

    return hr;
}

CFigFileNode::CFigFileNode()
{
    m_ExcludeFromBuild = false;
    m_FigLineColor = Black;
    m_XOffset = "0";
    m_YOffset = "0";
    // this property is toggled whenever a property changes; signals a recompile is required.
    m_fPropertyChanged = false;

}

CFigFileNode::~CFigFileNode()
{
}  



//---------------------------------------------------------------------------
// Write information for node to project file.
//---------------------------------------------------------------------------
HRESULT CFigFileNode::Save
(
IVsPropertyStreamOut *pIVsPropertyStreamOut
) 
{
    USES_CONVERSION;
    ExpectedPtrRet(pIVsPropertyStreamOut);
    HRESULT hr = S_OK;

    WCHAR wszPenColor[2];
    switch (m_FigLineColor)
    {
    case Red:       hr = StringCchCopyW( wszPenColor, countof(wszPenColor), L"0" ); break;
    case White:     hr = StringCchCopyW( wszPenColor, countof(wszPenColor), L"1" ); break;
    case Blue:      hr = StringCchCopyW( wszPenColor, countof(wszPenColor), L"2" ); break;
    case Black:     hr = StringCchCopyW( wszPenColor, countof(wszPenColor), L"3" ); break;
    case Yellow:    hr = StringCchCopyW( wszPenColor, countof(wszPenColor), L"4" ); break;
    }
    IfFailRet(hr);

    hr = pIVsPropertyStreamOut->WriteSzAsBSTR(
                                        STR_PENCOLOR,
                                        wszPenColor,
                                        NULL /*szLineComment*/);
    IfFailRet(hr);
    hr = pIVsPropertyStreamOut->WriteSzAsBSTR(
                                        STR_XOFFSET,
                                        T2COLE(m_XOffset),
                                        NULL /*szLineComment*/);
    IfFailRet(hr);
    hr = pIVsPropertyStreamOut->WriteSzAsBSTR(
                                        STR_YOFFSET,
                                        T2COLE(m_YOffset),
                                        NULL /*szLineComment*/);
    IfFailRet(hr);
    hr = pIVsPropertyStreamOut->WriteSzAsBSTR(
                                        STR_EXCLUDEFROMBUILD,
                                        (m_ExcludeFromBuild ? L"T" : L"F"),
                                        NULL /*szLineComment*/);
    IfFailRet(hr);
    hr = pIVsPropertyStreamOut->WriteSzAsBSTR(
                                        STR_PROPERTYCHANGED,
                                        (m_fPropertyChanged ? L"T" : L"F"),
                                        NULL /*szLineComment*/);
    IfFailRet(hr);
    return hr;
}


//---------------------------------------------------------------------------
// Read information for node to project file.
//---------------------------------------------------------------------------
HRESULT CFigFileNode::Load
(
IVsPropertyStreamIn *pIVsPropertyStreamIn
) 
{
    ExpectedPtrRet(pIVsPropertyStreamIn);
    HRESULT hr = S_OK;

    for (;;)
    {
        CComPtr<IVsPropertyStreamIn> srpIVsPropertyStreamIn;
        VSPROPERTYSTREAMPROPERTYTYPE vspspt;

        WCHAR rgwchPropName[_MAX_PATH];

        CComVariant varValue;

        hr = pIVsPropertyStreamIn->Read(NUMBER_OF(rgwchPropName), rgwchPropName, NULL, &vspspt, &varValue, NULL);
        ASSERT(SUCCEEDED(hr));
        if (FAILED(hr))
            return hr;

        if (rgwchPropName[0] == L'\0')
            break;

        if (vspspt != VSPSPT_SIMPLE || varValue.vt != VT_BSTR)
        {
            ASSERT(vspspt == VSPSPT_SIMPLE && varValue.vt == VT_BSTR);
            return E_UNEXPECTED;
        }

        if (_wcsicmp(rgwchPropName, STR_PENCOLOR) == 0)
        {
             m_FigLineColor = Black;    // default to black
            if (_wcsicmp(varValue.bstrVal, L"0") == 0) m_FigLineColor = Red;
            if (_wcsicmp(varValue.bstrVal, L"1") == 0) m_FigLineColor = White;
            if (_wcsicmp(varValue.bstrVal, L"2") == 0) m_FigLineColor = Blue;
            if (_wcsicmp(varValue.bstrVal, L"3") == 0) m_FigLineColor = Black;
            if (_wcsicmp(varValue.bstrVal, L"4") == 0) m_FigLineColor = Yellow;
        }
        else if (_wcsicmp(rgwchPropName, STR_XOFFSET) == 0)
            m_XOffset = varValue.bstrVal;
        else if (_wcsicmp(rgwchPropName, STR_YOFFSET) == 0)
            m_YOffset = varValue.bstrVal;
        else if (_wcsicmp(rgwchPropName, STR_EXCLUDEFROMBUILD) == 0 && varValue.vt == VT_BSTR)
            m_ExcludeFromBuild = (_wcsicmp(varValue.bstrVal, L"T") == 0) ? true : false;
        else if (_wcsicmp(rgwchPropName, STR_PROPERTYCHANGED) == 0 && varValue.vt == VT_BSTR)
            m_fPropertyChanged = (_wcsicmp(varValue.bstrVal, L"T") == 0) ? true : false;
        else
        {
            // NOTE: we'll just ignore properties without recognized names
        }
    }
    return hr;
}


HRESULT CFigFileNode::Compile(CString strOutputDirectory, IFigCompiler* pNewFigComp, BSTR* pbstrError)
{    
    HRESULT hr = S_OK;

    ExpectedPtrRet(pbstrError);
    *pbstrError = NULL;
    if (! pNewFigComp)
        return E_POINTER;
  
    CComBSTR cbstrXOffset(m_XOffset); 
    if (!cbstrXOffset) return E_OUTOFMEMORY;
    CComBSTR cbstrYOffset(m_YOffset);
    if (!cbstrYOffset) return E_OUTOFMEMORY;
    CComBSTR cbstrPen("3"); // default to Black
    if (m_FigLineColor == Red) cbstrPen = "0";
    else if (m_FigLineColor == White) cbstrPen = "1";
    else if (m_FigLineColor == Blue) cbstrPen = "2";
    else if (m_FigLineColor == Yellow) cbstrPen = "4";
    if (!cbstrPen) return E_OUTOFMEMORY;
    CComBSTR cbstrFileName(GetFileName());
    if (!cbstrFileName) return E_OUTOFMEMORY;
    CComBSTR cbstrFullPath(GetFullPath());
    if (!cbstrFullPath) return E_OUTOFMEMORY;
    CComBSTR cbstrOutputDirectory(strOutputDirectory);
    if (!cbstrOutputDirectory) return E_OUTOFMEMORY;

    hr = pNewFigComp->Compile(cbstrXOffset, cbstrYOffset, cbstrPen, cbstrFileName, cbstrFullPath, cbstrOutputDirectory, m_fPropertyChanged, pbstrError);
    _IfFailRet(hr);

    // Reset the property changed to false
    if (!*pbstrError)
        m_fPropertyChanged = false;
    return hr;
};


//---------------------------------------------------------------------------
// Called by CVsHeirarchy on VSHPROPID_UserContext.
// Add our attributes and target links to filter our topics
// in the Dynamic Help window.
//---------------------------------------------------------------------------
HRESULT CFigFileNode::GetUserContext(IVsUserContext **ppUserCtx)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, 
        _T(": CFigFileNode::GetUserContext /VSHPROPID_UserContext/ this = 0x%x\n"), this);

    ExpectedPtrRet(ppUserCtx);
    *ppUserCtx = NULL;

    HRESULT hr = E_FAIL;
    if (m_srpUserCtx == NULL) 
    {
        hr = CreateUserContext(&m_srpUserCtx);
        IfFailRet(hr);
        ExpectedExprRet(m_srpUserCtx != NULL);

        hr = m_srpUserCtx->AddAttribute(VSUC_Usage_Filter, L"Item", L"vs.envsdk.figprj.figfilenode");  
        IfFailRet(hr);
    }

    *ppUserCtx = m_srpUserCtx;
    (*ppUserCtx)->AddRef();

    return S_OK;            
}


STDMETHODIMP CFigFileNode::put_PenColor( FigLineColor PenColor )
{
    if (PenColor > Yellow)
        return E_INVALIDARG;

    // If we can't edit the project file or it's checked in and we
    // don't want to check it out then we do not update the property.
    if ( !static_cast<CMyProjectHierarchy*>(GetCVsHierarchy())->QueryEditProjectFile() )
    {
        return OLE_E_PROMPTSAVECANCELLED;
    }
    m_FigLineColor = PenColor;
    HRESULT hr = OnPropertyChanged(DISPID_FigPrjSourceFile_PenColor);
    ASSERT(SUCCEEDED(hr));
    return S_OK;
}

STDMETHODIMP CFigFileNode::get_PenColor( FigLineColor *pType )
{
    ExpectedPtrRet(pType);
    *pType = m_FigLineColor;
    return S_OK;
}

STDMETHODIMP CFigFileNode::get_XOffset(BSTR* pXOffset)
{
    ExpectedPtrRet(pXOffset);
    *pXOffset = m_XOffset.AllocSysString();
    return (*pXOffset != NULL) ? NOERROR : E_OUTOFMEMORY;
}

STDMETHODIMP CFigFileNode::put_XOffset(BSTR XOffset)
{
    // If we can't edit the project file or it's checked in and we
    // don't want to check it out then we do not update the property.
    if ( !static_cast<CMyProjectHierarchy*>(GetCVsHierarchy())->QueryEditProjectFile() )
    {
        return OLE_E_PROMPTSAVECANCELLED;
    }

    m_XOffset = XOffset;
    HRESULT hr = OnPropertyChanged(DISPID_FigPrjSourceFile_XOffset);
    ASSERT(SUCCEEDED(hr));
    return NOERROR;
}
STDMETHODIMP CFigFileNode::get_YOffset(BSTR* pYOffset)
{
    ExpectedPtrRet(pYOffset);
    *pYOffset = m_YOffset.AllocSysString();
    return (*pYOffset != NULL) ? NOERROR : E_OUTOFMEMORY;
}

STDMETHODIMP CFigFileNode::put_YOffset(BSTR YOffset)
{
    // If we can't edit the project file or it's checked in and we
    // don't want to check it out then we do not update the property.
    if ( !static_cast<CMyProjectHierarchy*>(GetCVsHierarchy())->QueryEditProjectFile() )
    {
        return OLE_E_PROMPTSAVECANCELLED;
    }

    m_YOffset = YOffset;
    HRESULT hr = OnPropertyChanged(DISPID_FigPrjSourceFile_YOffset);
    ASSERT(SUCCEEDED(hr));
    return NOERROR;
}


STDMETHODIMP CFigFileNode::get_ExcludeFromBuild(VARIANT_BOOL *pVal)
{
    return CFileVwFileNode::get_ExcludeFromBuild(pVal);
}

STDMETHODIMP CFigFileNode::put_ExcludeFromBuild(VARIANT_BOOL Val)
{
    return CFileVwFileNode::put_ExcludeFromBuild(Val);
}

STDMETHODIMP CFigFileNode::get_ReadOnly(VARIANT_BOOL *pVal)
{
    return CFileVwFileNode::get_ReadOnly(pVal);
}

STDMETHODIMP CFigFileNode::put_ReadOnly(VARIANT_BOOL Val)
{
    return CFileVwFileNode::put_ReadOnly(Val);
}

STDMETHODIMP CFigFileNode::get_FileType(BSTR *pVal)
{
    return CFileVwFileNode::get_FileType(pVal);
}

STDMETHODIMP CFigFileNode::get_Size(double *pVal)
{
    return CFileVwFileNode::get_Size(pVal);
}

STDMETHODIMP CFigFileNode::get_ModifiedDate(VARIANT *pVal)
{
    return CFileVwFileNode::get_ModifiedDate(pVal);
}

STDMETHODIMP CFigFileNode::get_FilePath(BSTR *pVal)
{
    return CFileVwFileNode::get_FilePath(pVal);
}

STDMETHODIMP CFigFileNode::get_FileName(BSTR *pVal)
{
    return CFileVwFileNode::get_FileName(pVal);
}

STDMETHODIMP CFigFileNode::put_FileName(BSTR NewName)
{
    return CFileVwFileNode::put_FileName(NewName);
}


// interface ICategorizeProperties implementation

STDMETHODIMP CFigFileNode::MapPropertyToCategory(DISPID dispid, PROPCAT* ppropcat)
{
    ExpectedPtrRet(ppropcat);
    if (dispid >= DISPID_FigPrjSourceFile_ExcludeFromBuild)
        *ppropcat = PROPCAT_Behavior;
    else
        *ppropcat = PROPCAT_Misc;
    return S_OK;
}


STDMETHODIMP CFigFileNode::GetCategoryName(PROPCAT propcat, LCID lcid, BSTR* pbstrName)
{
    // we only use standard category names; thus we don't have to implement this method.
    ExpectedPtrRet(pbstrName);
    *pbstrName = NULL;
    return E_NOTIMPL;
}


STDMETHODIMP CFigFileNode::OnPropertyChanged(
    /* [in] */ DISPID dispid        /* = DISPID_UNKNOWN */, 
    /* [in] */ BOOL   fDirtyProject /* = TRUE           */)
{
    // Set property has changed to force a recompile of this file on next build
    m_fPropertyChanged = true;

    return CFileVwFileNode::OnPropertyChanged(dispid, fDirtyProject);
}



CLangFileNode::CLangFileNode()
{
    m_ExcludeFromBuild = false;
}

CLangFileNode::~CLangFileNode()
{
}

HRESULT CLangFileNode::CreateInstance
(
LPCTSTR pszFullPath,
CLangFileNode **ppFileNode 
)
{
    ExpectedPtrRet(pszFullPath);
    ExpectedPtrRet(ppFileNode);
    CComObject<CLangFileNode> *pFileNode = NULL;  // created with 0 ref count
    HRESULT hr = CComObject<CLangFileNode>::CreateInstance(&pFileNode);
    if (SUCCEEDED(hr))
    {
        pFileNode->AddRef();
        hr = pFileNode->Initialize(pszFullPath);
        if (FAILED(hr))
        {
            pFileNode->Release();
            pFileNode = NULL;
        }
    }
    *ppFileNode = pFileNode;

    return hr;
}

//Added for cs file

STDMETHODIMP CLangFileNode::get_StartupItem(VARIANT_BOOL *pVal)
{
    ExpectedPtrRet(pVal);
    CFileVwProjNode* pNode = GetProjectNode();
    if (!pNode)
        return E_OUTOFMEMORY;
    if (this == pNode->GetStartupItem()) 
        *pVal = VARIANT_TRUE;
    else
        *pVal = VARIANT_FALSE;
    return S_OK;
}

STDMETHODIMP CLangFileNode::put_StartupItem(VARIANT_BOOL Val)
{
    // If we can't edit the project file or it's checked in and we
    // don't want to check it out then we do not update the property.
    if ( !static_cast<CMyProjectHierarchy*>(GetCVsHierarchy())->QueryEditProjectFile() )
    {
        return OLE_E_PROMPTSAVECANCELLED;
    }

    CFileVwProjNode* pNode = GetProjectNode();
    if (!pNode)
        return E_OUTOFMEMORY;
    BOOL fChange = FALSE;
    if (Val == VARIANT_TRUE && this != pNode->GetStartupItem()) 
    {
        pNode->SetStartupItem(this);
        fChange = TRUE; 
    }
    else if (Val == VARIANT_FALSE && this == pNode->GetStartupItem())
    {
        pNode->SetStartupItem(NULL);
        fChange = TRUE; 
    }
    if (fChange)
    {
        HRESULT hr = OnPropertyChanged(DISPID_FigPrjSourceFile_StartupItem);
        ASSERT(SUCCEEDED(hr));
    }
    return S_OK;
}

STDMETHODIMP CLangFileNode::get_ExcludeFromBuild(VARIANT_BOOL *pVal)
{
    return CFileVwFileNode::get_ExcludeFromBuild(pVal);
}

STDMETHODIMP CLangFileNode::put_ExcludeFromBuild(VARIANT_BOOL Val)
{
    return CFileVwFileNode::put_ExcludeFromBuild(Val);
}

STDMETHODIMP CLangFileNode::get_ReadOnly(VARIANT_BOOL *pVal)
{
    return CFileVwFileNode::get_ReadOnly(pVal);
}

STDMETHODIMP CLangFileNode::put_ReadOnly(VARIANT_BOOL Val)
{
    return CFileVwFileNode::put_ReadOnly(Val);
}

STDMETHODIMP CLangFileNode::get_FileType(BSTR *pVal)
{
    return CFileVwFileNode::get_FileType(pVal);
}

STDMETHODIMP CLangFileNode::get_Size(double *pVal)
{
    return CFileVwFileNode::get_Size(pVal);
}

STDMETHODIMP CLangFileNode::get_ModifiedDate(VARIANT *pVal)
{
    return CFileVwFileNode::get_ModifiedDate(pVal);
}

STDMETHODIMP CLangFileNode::get_FilePath(BSTR *pVal)
{
    return CFileVwFileNode::get_FilePath(pVal);
}

STDMETHODIMP CLangFileNode::get_FileName(BSTR *pVal)
{
    return CFileVwFileNode::get_FileName(pVal);
}

STDMETHODIMP CLangFileNode::put_FileName(BSTR NewName)
{
    return CFileVwFileNode::put_FileName(NewName);
}


// interface ICategorizeProperties implementation

STDMETHODIMP CLangFileNode::MapPropertyToCategory(DISPID dispid, PROPCAT* ppropcat)
{
    ExpectedPtrRet(ppropcat);
    if (dispid >= DISPID_FigPrjSourceFile_ExcludeFromBuild)
        *ppropcat = PROPCAT_Behavior;
    else
        *ppropcat = PROPCAT_Misc;
    return S_OK;
}

STDMETHODIMP CLangFileNode::GetCategoryName(PROPCAT propcat, LCID lcid, BSTR* pbstrName)
{
    // we only use standard category names; thus we don't have to implement this method.
    ExpectedPtrRet(pbstrName);
    *pbstrName = NULL;
    return E_NOTIMPL;
}


//---------------------------------------------------------------------------
// Called by CVsHeirarchy on VSHPROPID_UserContext.
// Add our attributes and target links to filter our topics
// in the Dynamic Help window.
//---------------------------------------------------------------------------
HRESULT CLangFileNode::GetUserContext(IVsUserContext **ppUserCtx)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, 
        _T(": CLangFileNode::GetUserContext /VSHPROPID_UserContext/ this = 0x%x\n"), this);

    ExpectedPtrRet(ppUserCtx);
    *ppUserCtx = NULL;

    HRESULT hr = E_FAIL;
    if (m_srpUserCtx == NULL) 
    {
        hr = CreateUserContext(&m_srpUserCtx);
        IfFailRet(hr);
        ExpectedExprRet(m_srpUserCtx != NULL);

        hr = m_srpUserCtx->AddAttribute(VSUC_Usage_Filter, L"Item", L"vs.envsdk.figprj.csfilenode");  
        IfFailRet(hr);
    }

    *ppUserCtx = m_srpUserCtx;
    (*ppUserCtx)->AddRef();

    return S_OK;            
}
