%{
#include "service.h"
#include "parser.cpp.h"
%}

%s init
%s comment

White0          [ \t\r\f\v]
White           {White0}|\n

CommentStart    \/\*
CommentEnd      \*\/
LineComment     \/\/
Hint            {White0}*[^ \t\r\f\v\n]+


%%

<init>[a-zA-Z_][a-zA-Z0-9_]*    { return IDENTIFIER; }
<init>[0-9]+                    { return NUMBER; }
<init>;                         { return ';';    }

<init>{CommentStart}            { g_service->enterComment( comment );
                                  yymore();
                                } 
<init>{LineComment}{Hint}.*\n   { g_service->lexicalError( SevHint, yytext+2 ); 
                                  return LEX_LINE_COMMENT; 
                                }
<init>{LineComment}.*\n         { return LEX_LINE_COMMENT; }
<init>{White0}+                 { return LEX_WHITE; }
<init>\n                        { return LEX_WHITE; }
<init>.                         { char buf[80];
                                  sprintf( buf, "invalid character ('%c', 0x%x)", yytext[0], yytext[0] );
                                  g_service->lexicalError( SevError, buf );
                                  yymore();
                                }


<comment>{CommentStart}         { g_service->enterComment();
                                  yymore();
                                }
<comment>{CommentEnd}           { g_service->leaveComment();
                                  return LEX_COMMENT;
                                }
<comment>.                      { yymore(); }
<comment>\n                     { return LEX_COMMENT; }

.|\n                            { g_service->setLexState(init); yyless(0); }


%%

#include <stdservice.c>