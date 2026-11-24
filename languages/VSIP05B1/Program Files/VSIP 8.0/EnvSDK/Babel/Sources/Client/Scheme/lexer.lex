%{
#include "service.h"
#include "parser.cpp.h"
%}

token               {identifier}|{boolean}|{number}|{character}|{string}|\(|\)|#\(|'|`|,|,@|\.
delimiter           {whitespace}|\(|\)|\"|;
whitespace          [\t \n\r\f\v]
comment             ;.*\n
atmosphere          {whitespace}|{comment}
intertokenspace     {atmosphere}*
identifier          {initial}{subsequent}*|{peculiaridentifier}
initial             {letter}|{specialinitial}
letter              [a-zA-Z]
specialinitial      !|\$|%|&|\*|\/|:|\<|=|\>|\?|^|_|~
subsequent          {initial}|{digit}|{specialsubsequent}
digit               [0-9]
specialsubsequent   \+|\-|\.|@
peculiaridentifier  \+|\-|\.\.\.
syntactickeyword    {expressionkeyword}|else|=\>|define|unquote|unquote\-splicing
expressionkeyword   quote|lambda|if|set\!|begin|cond|and|or|case|let|let\*|letrec|do|delay|quasiquote
boolean             #t|#f
character           #\.|#{charactername}
charactername       space|newline
string              \"{stringelement}*\"
stringelement       [^\"]|(\\\")
number              {num2}|{num8}|{num10}|{num16}

num2                {prefix2}{complex2}
complex2            {real2}|{real2}@{real2}|{real2}\+{ureal2}i|{real2}\-{ureal2}i|{real2}\+i|{real2}\-i|\+{ureal2}i|\-{ureal2}i|\+i|\-i
real2               {sign}{ureal2}
ureal2              {uinteger2}|{uinteger2}\/{uinteger2}
uinteger2           {digit2}+#*
prefix2             {radix2}{exactness}|{exactness}{radix2}

num8                {prefix8}{complex8}
complex8            {real8}|{real8}@{real8}|{real8}\+{ureal8}i|{real8}\-{ureal8}i|{real8}\+i|{real8}\-i|\+{ureal8}i|\-{ureal8}i|\+i|\-i
real8               {sign}{ureal8}
ureal8              {uinteger8}|{uinteger8}\/{uinteger8}
uinteger8           {digit8}+#*
prefix8             {radix8}{exactness}|{exactness}{radix8}

num10               {prefix10}{complex10}
complex10           {real10}|{real10}@{real10}|{real10}\+{ureal10}i|{real10}\-{ureal10}i|{real10}\+i|{real10}\-i|\+{ureal10}i|\-{ureal10}i|\+i|\-i
real10              {sign}{ureal10}
ureal10             {uinteger10}|{uinteger10}\/{uinteger10}|{decimal10}
decimal10           {uinteger10}{suffix}|\.{digit10}+#*{suffix}|{digit10}+\.{digit10}*#*{suffix}|{digit10}+#+\.#*{suffix}
uinteger10          {digit10}+#*
prefix10            {radix10}{exactness}|{exactness}{radix10}

num16               {prefix16}{complex16}
complex16           {real16}|{real16}@{real16}|{real16}\+{ureal16}i|{real16}\-{ureal16}i|{real16}\+i|{real16}\-i|\+{ureal16}i|\-{ureal16}i|\+i|\-i
real16              {sign}{ureal16}
ureal16             {uinteger16}|{uinteger16}\/{uinteger16}
uinteger16          {digit16}+#*
prefix16            {radix16}{exactness}|{exactness}{radix16}

suffix              ({exponentmarker}{sign}{digit10}+)?
exponentmarker      e|s|f|d|l
sign                [\+\-]?
exactness           (#i|#e)?
radix2              #b
radix8              #o
radix10             (#d)?
radix16             #x
digit2              [01]
digit8              [0-7]
digit10             [0-9]
digit16             {digit10}|a|b|c|d|e|f

%%

{identifier}              { return SCHEME_IDENTIFIER; }
{boolean}                 { return SCHEME_BOOL;    }
{number}                  { return SCHEME_NUM;    }
{character}               { return SCHEME_CHAR;    }
{string}                  { return SCHEME_STRING;    }
\(                        { return LPAREN;    }
\)                        { return RPAREN;    }
#\(                       { return POUNDPAREN; }
`                         { return BACKQUOTE;    }
'                         { return APOS;    }
,                         { return COMMA;    }
,@                        { return COMMAAT;    }
\.                        { return PERIOD;    }
{comment}                 { return LEX_COMMENT; }
{whitespace}              { return LEX_WHITE; }
.                         { char buf[80];
                                  sprintf( buf, "invalid character ('%c', 0x%x)", yytext[0], yytext[0] );
                                  g_service->lexicalError( SevError, buf );
                                  yymore();
                                }


%%

#include <stdservice.c>
