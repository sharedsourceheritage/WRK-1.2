
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

#include "stdafx.h"
#include "Arrow.h"

void CArrow::GenerateStream(FILE* output,char* xOffset,char* yOffset, char* penColor){

	// _itoa result could be up to 21 bytes for 64-bit signed int
	char fromXString[22];
	_itoa( fromX, fromXString, 10 );

	char fromYString[22];
	_itoa( fromY, fromYString, 10 );

	char toXString[22];
	_itoa( toX, toXString, 10 );

	char toYString[22];
	_itoa( toY, toYString, 10 );

	string command = "this.DrawLineAndArrow(e, ";
	command.append(xOffset);
	command.append(", ");
	command.append(yOffset);
	command.append(", ");
	command.append(penColor);
	command.append(", ");
	command.append(fromXString);
	command.append(", ");
	command.append(fromYString);
	command.append(", ");
	command.append(toXString);
	command.append(", ");
	command.append(toYString);
	command.append(");\n");
	command.append("// ");
	command.append(comment);
	command.append("\n");
	fputs(command.c_str(),output);
};