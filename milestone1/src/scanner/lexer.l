
%top{
    #include <string>
    #include <fstream>
    #include <iomanip>
    #include <unordered_map>
    #include <queue>

    #include "parser.tab.h"
    #define YY_DECL extern "C" int yylex()

    using namespace std;

    void check_for_null(const char* ptr){
        if(ptr == NULL) {
            printf("[TITLE_HEADING]Error in allocating memory by strdup\n");
            exit(-1);
        }
    }
}
%option noyywrap
%option yylineno
%x REALLYEND

ESCAPAE_SEQ             \\[stbnfr{LINE_TERMINATOR}\'\\\"]   

CRLF                \r\n
LINE_TERMINATOR     {CRLF}|[\r\n]

WHITESPACE          [ \t\f]+

JAVA_LETTER              [a-zA-Z$_]

DIGIT               [0-9]

DIGITS              {DIGIT}|{DIGIT}([0-9_]+)?{DIGIT}

UNDERSCORE         [_]
SUFFIX             [lL]? 

ID                  {JAVA_LETTER}({JAVA_LETTER}|{DIGIT})*

/* TYPE_ID             ^/(?!"yield"|"var"|"permits"|"record"|"sealed")({ID}) */

BOOLEAN_LITERAL     true|false

CHAR_LITERAL        \'([^\\\'\n\r]|\\.)\'

NULL_LITERAL        null

DECIMAL_NUMERAL             0|[1-9]{DIGITS}?|[1-9][_]+{DIGITS}
DECIMAL_INTEGER_LITERAL     {DECIMAL_NUMERAL}{SUFFIX}

HEX_DIGIT                   [0-9a-fA-F]
HEX_DIGIT_AND_UNDERSCORE    [0-9a-fA-F_]+
HEX_DIGITS                  {HEX_DIGIT}|{HEX_DIGIT}{HEX_DIGIT_AND_UNDERSCORE}?{HEX_DIGIT}
HEX_NUMERAL                 0[xX]{HEX_DIGITS}
HEX_INTEGER_LITERAL         {HEX_NUMERAL}{SUFFIX}

OCTAL_DIGIT                 [0-7]
OCTAL_DIGIT_AND_UNDERSCORE  [0-7_]+
OCTAL_DIGITS                {OCTAL_DIGIT}|{OCTAL_DIGIT}{OCTAL_DIGIT_AND_UNDERSCORE}?{OCTAL_DIGIT}
OCTAL_NUMERAL               0{OCTAL_DIGITS}|0{UNDERSCORE}+{OCTAL_DIGITS}
OCTAL_INTEGER_LITERAL       {OCTAL_NUMERAL}{SUFFIX}

BINARY_DIGIT                [0-1]
BINARY_DIGIT_AND_UNDERSCORE [0-1_]+
BINARY_DIGITS               {BINARY_DIGIT}|{BINARY_DIGIT}{BINARY_DIGIT_AND_UNDERSCORE}?{BINARY_DIGIT}
BINARY_NUMERAL              0[bB]{BINARY_DIGITS}
BINARY_INTEGER_LITERAL      {BINARY_NUMERAL}{SUFFIX}


INTEGER_LITERAL         {DECIMAL_INTEGER_LITERAL}|{HEX_INTEGER_LITERAL}{OCTAL_INTEGER_LITERAL}|{BINARY_INTEGER_LITERAL}

EXPONENT_PART           [eE][+-]?{DIGITS}
FLOAT_TYPE_SUFFIX       [fFdD]

DECIMAL_FP_LITERAL      {DIGITS}\.{DIGITS}?{EXPONENT_PART}?{FLOAT_TYPE_SUFFIX}?|\.{DIGITS}{EXPONENT_PART}?{FLOAT_TYPE_SUFFIX}?|{DIGITS}{EXPONENT_PART}{FLOAT_TYPE_SUFFIX}?|{DIGITS}{EXPONENT_PART}?{FLOAT_TYPE_SUFFIX}

HEX_SIGNIFICAND         {HEX_NUMERAL}[\.]?|0[xX]{HEX_DIGITS}?[\.]{HEX_DIGITS}
BINARY_EXPONENT         [pP][-+]?{DIGITS}
HEXADECIMAL_FP_LITERAL  {HEX_SIGNIFICAND}{BINARY_EXPONENT}{FLOAT_TYPE_SUFFIX}?

FP_LITERAL              {DECIMAL_FP_LITERAL}|{HEXADECIMAL_FP_LITERAL}

STRING                  \"([^\"\\\n\r]|\\.)*\"

TEXT_BLOCK_CHAR         [^\\\"]|\"[^\\\"]|\"\"[^\\\"]|{ESCAPAE_SEQ}|{LINE_TERMINATOR}
TEXT_BLOCK              \"\"\"{WHITESPACE}?{LINE_TERMINATOR}{TEXT_BLOCK_CHAR}*\"\"\"

TRADITIONAL_COMMENT \/\*([^\*]|[\r\n]|(\*+([^\*\/]|[\r\n])))*[\*]+\/
EOL_COMMENT         \/\/[^\n\r]*([\n\r]|\r\n)
COMMENT             {TRADITIONAL_COMMENT}|{EOL_COMMENT}

%%

"permits"|"record"|"sealed"|"yield"        {}

"int"                                     {return INT;}
"long"                                    {return LONG;}
"byte"                                    {return BYTE;}
"char"                                    {return CHAR;}
"short"                                   {return SHORT;}

"float"                                   {return FLOAT;}
"double"                                  {return DOUBLE;}
"boolean"                                 {return BOOLEAN;}

"new"                                     {return NEW;}
"if"                                      {return IF;}
"else"                                    {return ELSE;}
"for"                                     {return FOR;}
"while"                                   {return WHILE;}
"break"                                   {return BREAK;}
"continue"                                {return CONTINUE;}

"void"                                    {return VOID;}
"return"                                  {return RETURN;}
"public"                                  {return PUBLIC;}
"private"                                 {return PRIVATE;}
"class"                                   {return CLASS;}
"static"                                  {return STATIC;}

"final"                                   {return FINAL;}
"var"                                     {return VAR;}
"assert"                                  {return ASSERT;}
"throw"                                   {return THROW;}

"::"								  {return DOUBLE_COLON;}
"<>"                                  {return DIAMOND;}

"+"                                   {return PLUS;}
"-"                                   {return MINUS;}
"*"                                   {return ASTERIK;}
"/"                                   {return DIV;}
"%"                                   {return MODULO;}
"++"                                  {return INCREMENT;}
"--"                                  {return DECREMENT;}

">="								  {return GEQ;}
"<="								  {return LEQ;}
">"									  {return GT;}
"<"									  {return LT;}
"!="								  {return NEQ;}
"=="								  {return DEQ;}

"&"                                   {return BITWISE_AND;}
"|"                                   {return BITWISE_OR;}
"^"                                   {return BITWISE_XOR;}
"~"                                   {return BITWISE_COMPLEMENT;}
"<<"                                  {return LEFT_SHIFT;}
">>"                                  {return RIGHT_SHIFT;}
">>>"                                 {return UNSIGNED_RIGHT_SHIFT;}  

"&&"								  {return AND;}
"||"								  {return OR;}
"!"                                   {return NOT;}

"="|"+="|"-="|"*="|"/="|"&="|"%="|">>="|"<<="|">>>="|"|="|"^="         {
                                                                            yylval.str = yytext;
                                                                            check_for_null(yylval.str);
                                                                            return ASSIGNMENT;
                                                                        }

":"									  {return COLON;}
"?"									  {return QM;}

"("									  {return LPAREN;}
")"									  {return RPAREN;}
"{"									  {return LCURLY;}
"}"									  {return RCURLY;}
"["									  {return LSQUARE;}
"]"									  {return RSQUARE;}
";"									  {return SEMICOLON;}
","									  {return COMMA;}
"."                                   {return DOT;}

"this"                                {return THIS;}
"instanceof"                          {return INSTANCEOF;}
"super"                               {return SUPER;}
"implements"                          {return IMPLEMENTS; }
"interface"                           { return INTERFACE; }
"extends"                             { return EXTENDS; }
"package"                             { return PACKAGE; }
"import"                              { return IMPORT; }

{CHAR_LITERAL}                          {   
                                            yylval.str = strdup(yytext); 
                                            check_for_null(yylval.str);
                                            return CHAR_LITERAL;
                                        }

{BOOLEAN_LITERAL}                       {   
                                            yylval.str = strdup(yytext); 
                                            check_for_null(yylval.str);
                                            return BOOLEAN_LITERAL;
                                        }

{NULL_LITERAL}                          {   
                                            yylval.str = strdup(yytext); 
                                            check_for_null(yylval.str);
                                            return NULL_LITERAL;
                                        }

{INTEGER_LITERAL}                       {   
                                            //yylval.num = stoi(yytext); 
                                            //check_for_null(yylval.num); 
                                            return INTEGER_LITERAL;
                                        }

{FP_LITERAL}                            {   
                                            //yylval.float_num = stof(yytext); 
                                            //check_for_null(yylval.float_num); 
                                            return FP_LITERAL;
                                        }

{STRING}                                {  
                                            yylval.str = strdup(yytext); 
                                            check_for_null(yylval.str);
                                            return STRING;
                                        }

{TEXT_BLOCK}                            {   
                                            yylval.str = strdup(yytext); 
                                            check_for_null(yylval.str);
                                            return TEXT_BLOCK;
                                        }

{ID}                                    {   
                                            yylval.str = strdup(yytext); 
                                            check_for_null(yylval.str);
                                            return IDENTIFIER;
                                        }

{LINE_TERMINATOR}                      {}
{WHITESPACE}                           {}
{COMMENT}                              {}

<INITIAL><<EOF>>        { BEGIN(REALLYEND); return EOF_; } 

<REALLYEND><<EOF>>      { return 0; }

.                                       { printf("Illegal character on line %d: %s\n",yylineno, yytext);}

%%

