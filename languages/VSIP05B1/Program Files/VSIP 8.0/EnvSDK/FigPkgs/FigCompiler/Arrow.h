
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/
#pragma once

class CArrow{
public:
	int fromX;
	int fromY;
	int toX;
	int toY;
	CArrow(){
	fromX=UNASSIGNED;
	fromY=UNASSIGNED;
	toX=UNASSIGNED;
	toY=UNASSIGNED;};
	~CArrow(){};
	string comment;
	void GenerateStream(FILE* output,char* xOffset,char* yOffset, char* penColor);

	//These two are strictly so the compiler will work
	//with tokens.  They are never called
	bool operator<(const CArrow& x) const {return true;};
	bool operator==(const CArrow& x) const {return true;};
};
typedef vector<CArrow> CArrowVector;
