
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

#include "stdafx.h"
#include "PrimitiveToken.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Arrow.h"
#include "ClassDriver.h"

#define MB_CUR_MAX_DEF 10

Driver::Driver()
{
    m_Parse = NULL;
    OleInitialize( NULL );
};
Driver::~Driver()
{
    if (m_Parse)
    {
        m_Parse->Release();
        m_Parse = NULL;
    }
    OleUninitialize();
};
      
void Driver::BuildClasses()
{
    //Iterate through all the valid tokens and 
    //try to build valid cs objects in order.
    //Values will be popped off as they are used
    
    while (!primitiveTokens.empty())
    {
        PrimitiveTokenVector::iterator iterator = primitiveTokens.begin(); 
        if (iterator->AreYouAnArrow())
            NewArrow( primitiveTokens );
        else if (iterator->AreYouACircle())
            NewCircle( primitiveTokens );
        else if (iterator->AreYouARectangle())
            NewRectangle( primitiveTokens );
        else
            primitiveTokens.erase(iterator);
    }
}

void Driver::EmitClasses( char* xOffset, char* yOffset, char* penColor, BSTR* bs_ErrorString )
{
    string  basicInfo = "namespace DefaultNamespace\n{\nusing System;\nusing System.Drawing;\nusing System.Collections;\nusing System.ComponentModel;\nusing System.Windows.Forms;\n\n";
    basicInfo.append( "public class " );
    basicInfo.append( currentClass );
    basicInfo.append( " : FigureDrawingObject {\n" );
    basicInfo.append( "public void Draw(PaintEventArgs e){\n" );
    string  finishesFile = "\n}\n}\n}"; //For method and class completion

    outputDirectory.append("\\");
    currentFile=outputDirectory.append( currentFile );

    if (!IsFileValid(currentFile, false))
    {
        wstring sError = L"Invalid output .cs file\n";
        *bs_ErrorString = SysAllocString( sError.c_str() );
        return;
    }

    FILE* output = fopen(currentFile.c_str(), "w" );
    if (NULL == output)
    {
        wstring sError = L"Could not open the output .cs file\n";
        *bs_ErrorString = SysAllocString( sError.c_str() );
        return;
    }
    
    fputs( basicInfo.c_str(), output );

    CCircleVector::iterator citerator;
    while (!parsedCircles.empty())
    {
        citerator = parsedCircles.begin();
        citerator->GenerateStream( output, xOffset, yOffset, penColor );
        parsedCircles.erase( citerator );
    }

    CRectangleVector::iterator riterator;
    while (!parsedRectangles.empty())
    {
        riterator = parsedRectangles.begin();
        riterator->GenerateStream( output, xOffset, yOffset, penColor );
        parsedRectangles.erase( riterator );
    }

    CArrowVector::iterator aiterator;
    while (!parsedArrows.empty())
    {
        aiterator = parsedArrows.begin();
        aiterator->GenerateStream( output, xOffset, yOffset, penColor );
        parsedArrows.erase( aiterator );
    }
    fputs( finishesFile.c_str(), output );
    fclose( output );
}

bool Driver::LoadParser()
{
    HRESULT hr = NOERROR; 
    hr = CoCreateInstance( CLSID_FigParse, NULL,
                              CLSCTX_INPROC_SERVER, IID_IFigParse,
                              (LPVOID*)&m_Parse);
    if (FAILED(hr))
    {
        std::cout<<"Parser Didn't load\n";
        return false;
    }
    return true;
};

void Driver::NewArrow( PrimitiveTokenVector &primitiveTokens )
{
    PrimitiveTokenVector::iterator
                iterator = primitiveTokens.begin();
    CArrow  ja;
    _ASSERTE( eType == iterator->type );
    while (!primitiveTokens.empty())
    {
        primitiveTokens.erase( primitiveTokens.begin() ); // no matter what, get rid of it; first one is type, following are parameters
        iterator = primitiveTokens.begin();
        if (eParameter == iterator->type)
        {
            if (UNASSIGNED == ja.fromX)
                ja.fromX = iterator->IntegerValue();
            else if (UNASSIGNED == ja.fromY)
                ja.fromY=iterator->IntegerValue();
            else if (UNASSIGNED == ja.toX)
                ja.toX = iterator->IntegerValue();
            else if (UNASSIGNED == ja.toY)
            {
                ja.toY = iterator->IntegerValue();
                parsedArrows.push_back( ja );
                primitiveTokens.erase( iterator ); // get rid of it
                break;
            }
        }
        else break; // some syntax error
    }
}

void Driver::NewCircle( PrimitiveTokenVector &primitiveTokens )
{
    PrimitiveTokenVector::iterator
                iterator = primitiveTokens.begin();
    CCircle jc;
    _ASSERTE( eType == iterator->type );
    while (!primitiveTokens.empty())
    {
        primitiveTokens.erase( primitiveTokens.begin() ); // no matter what, get rid of it; first one is type, following are parameters
        iterator = primitiveTokens.begin();
        if (eParameter == iterator->type)
        {
            if (UNASSIGNED == jc.upperLeftX)
                jc.upperLeftX = iterator->IntegerValue();
            else if (UNASSIGNED == jc.upperLeftY)
                jc.upperLeftY = iterator->IntegerValue();
            else if (UNASSIGNED == jc.diameter)
            {
                jc.diameter = iterator->IntegerValue();
                parsedCircles.push_back( jc );
                primitiveTokens.erase( iterator ); // get rid of it
                break;
            }
        }
        else break; // some syntax error
    }
}

void Driver::NewRectangle( PrimitiveTokenVector &primitiveTokens )
{
    PrimitiveTokenVector::iterator
                iterator = primitiveTokens.begin();
    CRectangle  jr;
    _ASSERTE( eType == iterator->type );
    while (!primitiveTokens.empty())
    {
        primitiveTokens.erase( primitiveTokens.begin() ); // no matter what, get rid of it; first one is type, following are parameters
        iterator = primitiveTokens.begin();
        if (eParameter == iterator->type)
        {
            if (UNASSIGNED == jr.upperLeftX)
                jr.upperLeftX = iterator->IntegerValue();
            else if (UNASSIGNED == jr.upperLeftY)
                jr.upperLeftY = iterator->IntegerValue();
            else if (UNASSIGNED == jr.width)
                jr.width = iterator->IntegerValue();
            else if (UNASSIGNED == jr.height)
            {
                jr.height = iterator->IntegerValue();
                parsedRectangles.push_back( jr );
                primitiveTokens.erase( iterator ); // get rid of it
                break;
            }
        }
        else break; // some syntax error
    }
}

HRESULT Driver::ParseThisFile( FILE* input , BSTR* pbstrError)
{
    HRESULT hr = S_OK;
    string  s;
    int     charValue;
    char    next;   
    while (!feof( input )) 
    {
        charValue = fgetc( input );
        if (charValue > 0)
        {
            next = (char) charValue;
            if (next == '\n')
            {
                s.append( "'" ); //The parser requires a comment
                hr = StorePrimitiveTokens( s, pbstrError );
                if ( FAILED(hr) )
                    return hr;
                s = "";
            }
            s.append( 1, next );
        }
    }
    s.append( "'" ); //The parser requires a comment
    hr = StorePrimitiveTokens( s, pbstrError );
    return hr;
}

bool Driver::IsTheFileUpToDate( char* currentDirectory, char* outputDirectory, char* pfile, BSTR *bs_ErrorString )
{
    //If the .cs file exists AND the .fig file is newer
    //than it, then signal that a rebuild is needed
    
    //Need to get rid of the last .fig, keeping 
    //in mind that first ones are OK

    struct _finddata_t i_file; 
    struct _finddata_t o_file;
    
    string baseName;
    baseName.append(currentDirectory);
    if (baseName.find( ".fig", 0 ) < 1)
    {
        wstring sError = L"When checking date dependencies, could not find the specified file.\n";
        *bs_ErrorString = SysAllocString( sError.c_str() );
        return false; //Not really the correct error
    };

    string outputFile;
    outputFile.append( outputDirectory );
    outputFile.append( "\\" );
    outputFile.append( pfile );
    outputFile.resize( outputFile.size() - 3 );
    outputFile.append( "cs" );

    if (!IsFileValid(outputFile, true))
    {
        wstring sError = L"Invalid output .cs file\n";
        *bs_ErrorString = SysAllocString( sError.c_str() );
        return false;
    }

    if ((_findfirst( currentDirectory, &i_file )) == -1L)
    {
        wstring sError = L"When checking date dependencies, could not find the specified file.\n";
        *bs_ErrorString = SysAllocString( sError.c_str() );
        return false;
    };

    if ((_findfirst( outputFile.c_str(), &o_file )) == -1L)
    {
        std::cout << "No corresponding cs file exists; building\n";
        return false;
    };

    //i_file.time_write is greater -> the .fig file is newer
    if (i_file.time_write > o_file.time_write)
    {
        std::cout << "The .fig file is newer than the corresponding .cs file.  Rebuilding\n";
        return false; 
    }

    //Though no error has ocurred, so this should still be referenced in cs files
    std::cout << "The .fig file is older than the corresponding .cs file.  Skipping rebuild\n";
    return true;
}

void Driver::SaveFileAndClass( char* pfile )
{
    //Derive class names (the first part of the file)
    //and output file names (the first part + .cs)
    //For example fig1.fig yields class fig1 and output
    //file fig1.cs
        
    int     ch = '.';
    DWORD_PTR       result;
    char*   pdest;
    pdest = strchr( pfile, ch ); //pdest is a pointer to the first '.'  
    result = pdest - pfile; //the number of characters to copy
    
    currentFile.append( pfile, result );
    currentFile.append( ".cs" );
    currentClass.append( pfile, result );

    std::cout << "The file created is " << currentFile.c_str() << "\n";
    std::cout << "The class created is " << currentClass.c_str() << "\n";
}

void Driver::SaveCurrentDirectory( char directory[100] )
{
    startDirectory.append(directory);
}

void Driver::SaveOutputDirectory( char directory[100] )
{
    outputDirectory.append(directory);
}

HRESULT Driver::StorePrimitiveTokens( string s , BSTR* pbstrError)
{
    if (pbstrError != NULL)
        *pbstrError = NULL;

    int lengthA = (int)s.length();
    if ((lengthA == 0) || (s.c_str() == NULL))
        return S_FALSE;

    int lengthW = lengthA + 1;
    WCHAR* pwszLine = new WCHAR[lengthW];
    if (!pwszLine)
        return E_OUTOFMEMORY;

    HRESULT     hr = S_OK;
    long        ncMarks = MAXTOKENS;
    LPFIGMARK   pMks = NULL;

    int cchConverted =::MultiByteToWideChar(_AtlGetConversionACP(), 0, s.c_str(), lengthA, pwszLine, lengthW);
    if (cchConverted == 0)
    {
        hr = HRESULT_FROM_WIN32(::GetLastError());
        goto Error;
    }
    if (cchConverted >= lengthW)
    {
        hr = E_UNEXPECTED;
        goto Error;
    }
    pwszLine[cchConverted] = L'\0';

    pMks = new FIGMARK[ ncMarks ];  // allocate an array of tokens
    if (pMks == NULL)
    {
        hr = E_OUTOFMEMORY;
        goto Error;
    }
    memset( pMks, 0, ncMarks * sizeof( FIGMARK ) );  // blank out the memory

    //*pbstrError = NULL;
    hr = m_Parse->Line( pwszLine, &ncMarks, &pMks, pbstrError );
    if (FAILED(hr) || (::SysStringLen(*pbstrError) != NULL) )//Something went wrong
    { 
        hr = E_FAIL;
        goto Error;
    }
   
    // get results of parse no matter what
    for (long i = 0 ; i < ncMarks; i++)
    {
        FIGMARK token = pMks[i];
        if (0 != token.eTokenType)
        {
            char szBuf[MB_CUR_MAX_DEF];
            PrimitiveToken  pt;
            size_t start = token.nStart;
            size_t end = token.nEnd;
            pt.type = token.eTokenType;
            while (start <= end)
            {
                int nChars = wctomb(szBuf, pwszLine[start] );  // convert back to MBCS
                pt.value.append(szBuf, nChars );
                start++;
            };
            primitiveTokens.push_back( pt );
        };
    };  

Error:
    
    delete [] pMks;     // free array of tokens
    delete [] pwszLine;   // free line buffer

    return hr;
}

// That the file name is valid
bool Driver::IsFileValid(string filePath, bool dontCreate)
{
	bool result = false;
    HANDLE hFile = CreateFile(CA2W(filePath.c_str()),
                              0,
                              0,
                              NULL,
							  dontCreate ? OPEN_EXISTING : OPEN_ALWAYS,
							  SECURITY_SQOS_PRESENT | SECURITY_IDENTIFICATION,
							  NULL);

	// Now make sure the file is an actual file and not a pipe, device,...
	if ((hFile != INVALID_HANDLE_VALUE && GetFileType(hFile) == FILE_TYPE_DISK)
		 || (hFile == INVALID_HANDLE_VALUE && dontCreate))
    {
        result = true;
    }

	if (hFile)
		CloseHandle(hFile);

  return result;

}

