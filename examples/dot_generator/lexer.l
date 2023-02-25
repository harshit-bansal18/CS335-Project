%{
    #include "parser.tab.h"
    #define YY_DECL extern "C" int yylex()
%}

%option noyywrap
%option yylineno

%x END_INPUT


WHITESPACE  [ \t]+
DIGIT       [0-9]+
NUM         {DIGIT}|{DIGIT}\.{DIGIT}
WORD        [a-zA-Z]+
EOL         [\n]

%%


{WORD}        { yylval.str = strdup(yytext);
                
                 return LITERAL; }

{NUM}         { 
                yylval.str = strdup(yytext);
                
                return ID; }

"+"         { return '+';}

"-"         { return '-'; }

"="         { return '='; }

";"        { yylval.str = strdup(yytext); return ';'; }

{EOL}         { }

{WHITESPACE}  { }

<INITIAL><<EOF>> { BEGIN(END_INPUT); return EOF_; }
<END_INPUT><<EOF>> { return 0; }

.             { printf("invalid expression: %s\n", yytext); }

%%