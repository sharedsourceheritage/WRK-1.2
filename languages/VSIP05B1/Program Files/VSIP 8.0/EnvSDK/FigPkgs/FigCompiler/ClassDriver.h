
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/
#pragma once

class Driver{
	string currentFile;
	string currentClass;
	string outputDirectory;
	string startDirectory;
	PrimitiveTokenVector primitiveTokens;
	CCircleVector parsedCircles;
	CRectangleVector parsedRectangles;
	CArrowVector parsedArrows;
public:
	Driver();
	~Driver(); 
	IFigParse* m_Parse;
	void BuildClasses();
	void EmitClasses(char* xOffset,char* yOffset,char* penColor,BSTR* bs_ErrorString);
	bool IsTheFileUpToDate(char* currentDirectory, char* outputDirectory, char* pchar,BSTR* bs_ErrorString);
	HRESULT StorePrimitiveTokens(string s, BSTR* pbstrError);
	void SaveFileAndClass(char* pfile);
	bool LoadParser();
	void NewArrow(PrimitiveTokenVector &primitiveTokens);
	void NewRectangle(PrimitiveTokenVector &primitiveTokens);
	void NewCircle(PrimitiveTokenVector &primitiveTokens);
	HRESULT ParseThisFile(FILE* input, BSTR* pbstrError);
	void SaveOutputDirectory(char directory[100]);
	void SaveCurrentDirectory(char directory[100]);
private:
	bool IsFileValid(string filePath, bool fileExist);

};
 