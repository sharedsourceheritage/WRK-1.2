/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

#include "common.h"

//---------------------------------------------------------
// Global definitions needed by the lexer and parser
//---------------------------------------------------------

int _cdecl yywrap()
{
    return 1;
}

void _cdecl yyerror( const char* message )
{
    return;
}
