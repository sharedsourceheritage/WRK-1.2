
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
const wchar_t* g_languageName              = L"MyC";
const wchar_t* g_languageFileExtensions[]  = { L".myc", NULL };
const CLSID    g_languageCLSID             = {0x54D21404,0x5E7F,0x11D3,{0xB4,0x07,0x00,0x60,0x08,0xD1,0xBF,0x8C}};

const LanguageProperty g_languageProperties[] =
{
  { L"RequestStockColors", 1     },
  { L"ShowCompletion",     1     },

  { L"CodeSense",          1     },
  { L"CodeSenseDelay",     1500  },
  { L"MaxErrorMessages",   5     },
  { L"QuickInfo",          1     },
  { L"MatchBraces",        1     },
  { L"SortMemberList",     1     },
  { L"ShowMatchingBrace",  1     },
  { L"MatchBracesAtCaret", 1     },

  { NULL, 0 }
};

/*---------------------------------------------------------
  Create Service
---------------------------------------------------------*/
HRESULT CreateBabelService( out IBabelService** babelService )
{
  TRACE(L"CreateBabelService");
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
  static CommentFormat commentFormat =  { NULL, "/*", "*/", false  };
  return &commentFormat;
}

/*---------------------------------------------------------
  Tokens
---------------------------------------------------------*/
override const TokenInfo* Service::getTokenInfo() const
{
  static TokenInfo tokenInfoTable[] =
  {
    { IDENTIFIER, ClassIdentifier,  "identifier '%s'",  CharIdentifier    },
    { NUMBER,     ClassNumber,      "number ('%s')",    CharLiteral      },
    { ';',        ClassText,        "';'"     , CharDelimiter },     
    { ',',        ClassText,        "','"     , CharDelimiter, TriggerParamNext       },     
    { KWIF,       ClassKeyword,   "if"        , CharKeyword },
    { KWELSE,     ClassKeyword,   "else"      , CharKeyword, TriggerMatchBraces },
    { KWWHILE,    ClassKeyword,   "while"     , CharKeyword }, 
    { KWFOR,      ClassKeyword,   "for"       , CharKeyword }, 
    { KWCONTINUE, ClassKeyword,   "continue"  , CharKeyword },
    { KWBREAK,    ClassKeyword,   "break"     , CharKeyword },
    { KWRETURN,   ClassKeyword,   "return"    , CharKeyword },
    { KWEXTERN,   ClassKeyword,   "extern"    , CharKeyword },
    { KWSTATIC,   ClassKeyword,   "static"    , CharKeyword },
    { KWAUTO,     ClassKeyword,   "auto"      , CharKeyword },
    { KWINT,      ClassKeyword,   "int"       , CharKeyword },
    { KWVOID,     ClassKeyword,   "void"      , CharKeyword },

    { '(',        ClassText,  "'('"   , CharDelimiter, TriggerParamStart | TriggerMatchBraces }, 
    { ')',        ClassText,  "')'"   , CharDelimiter, TriggerParamEnd | TriggerMatchBraces },
    { '{',        ClassText,   "'{'"  , CharDelimiter, TriggerMatchBraces },
    { '}',        ClassText,   "'}'"  , CharDelimiter, TriggerMatchBraces },
    { '.',        ClassText,  "'.'"   , CharDelimiter, TriggerMemberSelect },
    { '=',        ClassText,  "'='"   , CharDelimiter},
    { '+',        ClassText,  "'+'"   , CharDelimiter},
    { '-',        ClassText,  "'-'"   , CharDelimiter},
    { '*',        ClassText,  "'*'"   , CharDelimiter},
    { '/',        ClassText,  "'/'"   , CharDelimiter},
    { '!',        ClassText,  "'!'"   , CharDelimiter},
    { '&',        ClassText,  "'&'"   , CharDelimiter},
    { '|',        ClassText,  "'|'"   , CharDelimiter},
    { '^',        ClassText,  "'^'"   , CharDelimiter},
    { EQ,         ClassText,  "'=='"  , CharDelimiter}, 
    { NEQ,        ClassText,  "'!='"  , CharDelimiter},
    { GT,         ClassText,  "'>'"   , CharDelimiter},
    { GTE,        ClassText,  "'>='"  , CharDelimiter},
    { LT,         ClassText,  "'<'"   , CharDelimiter},
    { LTE,        ClassText,  "'<='"  , CharDelimiter},
    { AMPAMP,     ClassText,  "'&&'"  , CharDelimiter},
    { BARBAR,     ClassText,  "'||'"  , CharDelimiter}, 
    
    { LEX_WHITE,    ClassText,      "white space",   CharWhiteSpace },
    { LEX_COMMENT,  ClassComment,   "comment",       CharComment },

    //always end with the 'TokenEnd' token.
    { TokenEnd,     ClassText,      "<unknown>"          }
  };

  return tokenInfoTable;
};