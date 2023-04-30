%top{
#include "calculator.tab.h"
#include <iostream>
#include <string>
#define YY_DECL extern "C" int yylex()
using namespace std;
}

%option noyywrap
%option yylineno

%%

[ \t\n]            /* ignore whitespace */
[0-9]+             { yylval.str = strdup(yytext); return NUMBER; }
"+"                { return '+'; }
"-"                { return '-'; }
"*"                { return '*'; }
"/"                { return '/'; }
.                  {printf("Invalid character"); }

%%
