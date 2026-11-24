%{
#include "service.h"
%}
%expect 4

%token SCHEME_KEYWORD SCHEME_IDENTIFIER SCHEME_BOOL SCHEME_NUM 
%token SCHEME_CHAR SCHEME_STRING LPAREN RPAREN POUNDPAREN
%token BACKQUOTE APOS COMMA COMMAAT PERIOD 
%token LEX_WHITE LEX_COMMENT

%%

Program
    : Datums
    | error         { g_service->syntaxError("program"); }
    ;

Datums
    : Datum Datums
    | /* empty */
    ;

Datum
    : SimpleDatum
    | CompoundDatum
    ;

SimpleDatum
    : SCHEME_BOOL
    | SCHEME_NUM
    | SCHEME_CHAR
    | SCHEME_STRING
    | SCHEME_IDENTIFIER
    ;

CompoundDatum
    : List
    | Vector
    ;

List
    : LPAREN Datums RPAREN	{ g_service->matchPair($1, $3); }
    | LPAREN Datums error	{ g_service->expectError("list", ")"); }
    | LPAREN Datum Datums PERIOD Datum RPAREN	{ g_service->matchPair($1, $6); }
    | LPAREN Datum Datums PERIOD Datum error	{ g_service->expectError("list", ")"); }
    | Abbreviation
    ;

Abbreviation
    : AbbreviationPrefix Datum
    ;

AbbreviationPrefix
    : BACKQUOTE
    | APOS
    | COMMA
    ;

Vector
    : POUNDPAREN Datums RPAREN	{ g_service->matchPair($1, $3); }    
    | POUNDPAREN Datums error	{ g_service->expectError("vector", ")"); }
    ;

%%

