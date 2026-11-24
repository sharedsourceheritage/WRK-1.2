/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

#include "service.h"
#include "parser.cpp.h"

/*---------------------------------------------------------
  Globals
---------------------------------------------------------*/
const char*    g_languageName              = "Pascal";
const char*    g_languageFileExtensions[]  = { ".pas", ".pasmod", NULL };
const CLSID    g_languageCLSID             = { 0x40e4a46, 0x2b58, 0x4add, { 0xb7, 0x2b, 0x47, 0x3d, 0xf6, 0x42, 0x1d, 0xb9 } };

const LanguageProperty g_languageProperties[] =
{
  { "RequestStockColors", 1     },
  { "ShowCompletion",     1     },

  { "CodeSense",          1     },
  { "CodeSenseDelay",     1500  },
  { "MaxErrorMessages",   5     },
  { "QuickInfo",          1     },
  { "MatchBraces",        1     },
  { "SortMemberList",     1     },
  { "ShowMatchingBrace",  1     },

  { NULL, 0 }
};

/*---------------------------------------------------------
  Create Service
---------------------------------------------------------*/
HRESULT CreateBabelService( out IBabelService** babelService )
{
  TRACE("CreateBabelService");
  OUTARG(babelService);

  *babelService = new Service();
  if (*babelService == NULL) return E_OUTOFMEMORY;

  return S_OK;
}


/*---------------------------------------------------------
  Comments
---------------------------------------------------------*/
override const CommentFormat* Service::getCommentFormat() const
{
	static CommentFormat commentFormat =  { "//", "{", "}", true  };
  return &commentFormat;
}

/*---------------------------------------------------------
  Tokens
---------------------------------------------------------*/
override const TokenInfo* Service::getTokenInfo() const
{
  static TokenInfo tokenInfoTable[] =
  {

	  
	{ KWAND,			ClassKeyword,		"and",					CharKeyword },
	{ KWARRAY,			ClassKeyword,		"array",				CharKeyword },
	{ ASSIGNMENT,		ClassText,			":=",					CharDelimiter },
	{ KWCASE,			ClassKeyword,		"case",					CharKeyword },
	{ CHARACTER_STRING,	ClassString,		"string %s",			CharLiteral },
	{ COLON,			ClassText,			"':'",					CharDelimiter },
	{ COMMA,			ClassText,			"','",					CharDelimiter },
	{ KWCONST,			ClassKeyword,		"const",				CharKeyword },
	{ DIGSEQ,			ClassNumber,		"number %s",			CharLiteral },
	{ KWDIV,			ClassKeyword,		"div",					CharKeyword },
	{ KWDO,				ClassKeyword,		"do",					CharKeyword },
	{ DOT,				ClassText,			"'.'",					CharDelimiter,      TriggerMemberSelect },
	{ DOTDOT,			ClassText,			"'..'",					CharDelimiter },
	{ KWDOWNTO,			ClassKeyword,		"downto",				CharKeyword },
	{ KWELSE,			ClassKeyword,		"else",					CharKeyword },
	{ KWEND,			ClassKeyword,		"end",					CharKeyword,		TriggerMatchBraces },
	{ EQUAL,			ClassText,			"'='",					CharDelimiter },
	{ KWEXTERNAL,		ClassKeyword,		"external",				CharKeyword },
	{ KWFOR,			ClassKeyword,		"for",					CharKeyword },
	{ KWFORWARD,		ClassKeyword,		"forward",				CharKeyword },
	{ KWFUNCTION,		ClassKeyword,		"function",				CharKeyword },
	{ GE,				ClassText,			"'>='",					CharDelimiter },
	{ KWGOTO,			ClassKeyword,		"goto",					CharKeyword },
	{ GT,				ClassText,			"'>'",					CharDelimiter },
	{ IDENTIFIER,		ClassIdentifier,	"identifier '%s'",		CharIdentifier },
	{ KWIF,				ClassKeyword,		"if",					CharKeyword },
	{ KWIN,				ClassKeyword,		"in",					CharKeyword },
	{ KWLABEL,			ClassKeyword,		"label",				CharKeyword },
	{ LBRAC,			ClassText,			"'['",					CharDelimiter },
	{ LE,				ClassText,			"'<='",					CharDelimiter },
	{ LPAREN,			ClassText,			"'('",					CharDelimiter,		TriggerMatchBraces },
	{ LT,				ClassText,			"'<'",					CharDelimiter },
	{ MINUS,			ClassText,			"'-'",					CharDelimiter },
	{ KWMOD,			ClassKeyword,		"mod",					CharKeyword },
	{ KWNIL,			ClassKeyword,		"nil",					CharKeyword },
	{ KWNOT,			ClassKeyword,		"not",					CharKeyword },
	{ NOTEQUAL,			ClassText,			"'<>'",					CharDelimiter },
	{ KWOF,				ClassKeyword,		"of",					CharKeyword },
	{ KWOR,				ClassKeyword,		"or",					CharKeyword },
	{ KWOTHERWISE,		ClassKeyword,		"otherwise",			CharKeyword },
	{ KWPACKED,			ClassKeyword,		"packed",				CharKeyword },
	{ KWBEGIN,			ClassKeyword,		"begin",				CharKeyword,		TriggerMatchBraces },
	{ KWFILE,			ClassKeyword,		"file",					CharKeyword },
	{ PLUS,				ClassText,			"'+'",					CharDelimiter },
	{ KWPROCEDURE,		ClassKeyword,		"procedure",			CharKeyword },
	{ KWPROGRAM,		ClassKeyword,		"program",				CharKeyword },
	{ RBRAC,			ClassText,			"']'",					CharDelimiter },
	{ REALNUMBER,		ClassNumber,		"realnumber ('%s')",    CharLiteral },
	{ KWRECORD,			ClassKeyword,		"record",				CharKeyword },
	{ KWREPEAT,			ClassKeyword,		"repeat",				CharKeyword },
	{ RPAREN,			ClassText,			"')'",					CharDelimiter,		TriggerMatchBraces },
	{ SEMICOLON,		ClassText,			"';'",					CharDelimiter },
	{ KWSET,			ClassKeyword,		"set",					CharKeyword },
	{ SLASH,			ClassText,			"'/'",					CharDelimiter },
	{ STAR,				ClassText,			"'*'",					CharDelimiter },
	{ STARSTAR,			ClassText,			"'**'",					CharDelimiter },
	{ KWTHEN,			ClassKeyword,		"then",					CharKeyword },
	{ KWTO,				ClassKeyword,		"to",					CharKeyword },
	{ KWTYPE,			ClassKeyword,		"type",					CharKeyword },
	{ KWUNTIL,			ClassKeyword,		"until",				CharKeyword },
	{ UPARROW,			ClassText,			"'^'",					CharDelimiter },
	{ KWVAR,			ClassKeyword,		"var",					CharKeyword },
	{ KWWHILE,			ClassKeyword,		"while",				CharKeyword },
	{ KWWITH,			ClassKeyword,		"with",					CharKeyword },
	{ KWMODULE,			ClassKeyword,		"module",				CharKeyword },
	{ KWIMPORT,			ClassKeyword,		"import",				CharKeyword },

    
			  
    
	{ LEX_WHITE,		ClassText,			"white space",			CharWhiteSpace },
    { LEX_LINE_COMMENT, ClassComment,		"comment",				CharLineComment },
	{ LEX_COMMENT,		ClassComment,		"comment",				CharComment },

    //always end with the 'TokenEnd' token.
    { TokenEnd,     ClassText,      "<unknown>"          }
  };

  return tokenInfoTable;
};
