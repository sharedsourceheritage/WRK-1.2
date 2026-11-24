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
const char*    g_languageName              = "Scheme";
const char*    g_languageFileExtensions[]  = { ".scm", NULL };
const CLSID    g_languageCLSID             = { 0x7d2c6602, 0x28df, 0x4245, { 0x8f, 0xa9, 0x1c, 0xf3, 0x1e, 0xe6, 0xf3, 0x1e } }; //{7D2C6602-28DF-4245-8FA9-1CF31EE6F31E}

const LanguageProperty g_languageProperties[] =
{
  { "RequestStockColors", 1     },
  { "ShowCompletion",     1     },

  { "CodeSense",          1     },
  { "CodeSenseDelay",     1500  },
  { "MaxErrorMessages",   5     },
  { "QuickInfo",          0     },
  { "MatchBraces",        1     },
  { "SortMemberList",     1     },
  { "ShowMatchingBrace",  1     },
  { "MatchBracesAtCaret", 1     },
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
  static CommentFormat commentFormat =  { ";", NULL, NULL, true  };
  return &commentFormat;
}

/*---------------------------------------------------------
  Tokens
---------------------------------------------------------*/
override const TokenInfo* Service::getTokenInfo() const
{
  static TokenInfo tokenInfoTable[] =
  {

{ SCHEME_IDENTIFIER,  ClassKeyword,  "identifier '%s'", CharKeyword },
{ SCHEME_BOOL,        ClassText,     "boolean '%s'", CharLiteral },
{ SCHEME_NUM,         ClassNumber,      "number ('%s')", CharLiteral },
{ SCHEME_CHAR,        ClassString,      "char ('%s')", CharString },
{ SCHEME_STRING,      ClassString,      "string ('%s')", CharString },
{ LPAREN,             ClassText,        "'('"   , CharDelimiter, TriggerMatchBraces },
{ RPAREN,             ClassText,        "')'"   , CharDelimiter, TriggerMatchBraces },
{ POUNDPAREN,         ClassText,        "'#('"   , CharDelimiter, TriggerMatchBraces},
{ BACKQUOTE,          ClassText,        "'`'"   , CharDelimiter},
{ APOS,               ClassText,        "'''"   , CharDelimiter},
{ COMMA,              ClassText,        "','"   , CharDelimiter},
{ COMMAAT,            ClassText,        "',@'"   , CharDelimiter},
{ PERIOD,             ClassText,        "'.'"   , CharDelimiter},
{ LEX_WHITE,          ClassText,        "white space",   CharWhiteSpace},
{ LEX_COMMENT,        ClassComment,     "comment",       CharComment},

    //always end with the 'TokenEnd' token.
    { TokenEnd,     ClassText,      "<unknown>"          }
  };

  return tokenInfoTable;
};
