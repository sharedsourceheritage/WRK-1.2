
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

#include "stdafx.h"
#include "Circle.h"

void CCircle::GenerateStream(FILE* output,char* xOffset,char* yOffset, char* penColor) {

	// _itoa result could be up to 21 bytes for 64-bit signed int
	char upperLeftXString[22];
	_itoa( upperLeftX, upperLeftXString, 10 );
	char upperLeftYString[22];
	_itoa( upperLeftY, upperLeftYString, 10 );
	char diameterString[22];
	_itoa( diameter, diameterString, 10 );

	string command = "this.DrawCircle(e, ";
	command.append(xOffset);
	command.append(", ");
	command.append(yOffset);
	command.append(", ");
	command.append(penColor);
	command.append(", ");
	command.append(upperLeftXString);
	command.append(", ");
	command.append(upperLeftYString);
	command.append(", ");
	command.append(diameterString);
	command.append(");\n");
	command.append("// ");
	command.append(comment);
	command.append("\n");
	fputs(command.c_str(),output);
};