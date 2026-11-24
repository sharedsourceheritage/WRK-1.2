
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/
#pragma once

class CCircle{
public:
	CCircle(){
	upperLeftX = UNASSIGNED;
	upperLeftY = UNASSIGNED;
	diameter = UNASSIGNED;
	};
	~CCircle(){};
	string comment;
	int upperLeftX;
	int upperLeftY;
	int diameter;
	void GenerateStream(FILE* output,char* xOffset,char* yOffset, char* penColor);
	
	//These two are strictly so the compiler will work
	//with tokens.  They are never called
	bool operator<(const CCircle& x) const {return true;};
	bool operator==(const CCircle& x) const {return true;};
};
	typedef vector<CCircle> CCircleVector;

