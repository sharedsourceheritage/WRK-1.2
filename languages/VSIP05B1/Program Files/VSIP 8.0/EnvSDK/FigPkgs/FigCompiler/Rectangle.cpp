
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

#include "stdafx.h"
#include "Rectangle.h"

void CRectangle::GenerateStream(FILE* output,char* xOffset,char* yOffset, char* penColor){

	// _itoa result could be up to 21 bytes for 64-bit signed int
	char upperLeftXString[22];
	_itoa( upperLeftX, upperLeftXString, 10 );
	char upperLeftYString[22];
	_itoa( upperLeftY, upperLeftYString, 10 );
	char widthString[22];
	_itoa( width, widthString, 10 );
	char heightString[22];
	_itoa( height, heightString, 10 );

	string command = "this.DrawRectangle(e, ";
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
	command.append(widthString);
	command.append(", ");
	command.append(heightString);
	command.append(");\n");
	command.append("// ");
	command.append(comment);
	command.append("\n");
	fputs(command.c_str(),output);
};