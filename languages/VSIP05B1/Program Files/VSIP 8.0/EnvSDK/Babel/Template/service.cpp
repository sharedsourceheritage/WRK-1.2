
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
const char*    g_languageName              = "MyLanguage";
const char*    g_languageFileExtensions[]  = { ".mylanguage", NULL };
const CLSID    g_languageCLSID             = ; //TODO: put your unique CLSID here

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
  { "ShowMatchingBrace",  0     },
  { "MatchBracesAtCaret", 0     },

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
  Tokens
---------------------------------------------------------*/
override const TokenInfo* Service::getTokenInfo() const
{
  static TokenInfo tokenInfoTable[] =
  {
    //TODO: add your own token information here
    { IDENTIFIER,  ClassIdentifier,  "identifier '%s'", CharIdentifier },
    { NUMBER,      ClassNumber,      "number ('%s')", CharLiteral      },
    { ';',         ClassText,        "';'",           CharDelimiter    },     
  
    { LEX_WHITE,   ClassText,        "white space",   CharWhiteSpace   },
    { LEX_LINE_COMMENT, ClassComment,"comment",       CharLineComment  },
    { LEX_COMMENT, ClassComment,     "comment",       CharComment      },

    //always end with the 'TokenEnd' token.
    { TokenEnd,     ClassText,      "<unknown>" }
  };

  return tokenInfoTable;
};