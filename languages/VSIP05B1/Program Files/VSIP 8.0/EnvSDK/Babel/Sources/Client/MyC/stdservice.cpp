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