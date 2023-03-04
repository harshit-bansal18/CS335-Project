
%top{
    #include <string>
    #include <iostream>
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


SIGN                    [-+]?
SIGNED_INTEGER          {SIGN}{DIGITS}

EXPONENT_PART           [eE]{SIGNED_INTEGER}
FLOAT_TYPE_SUFFIX       [fFdD]

DECIMAL_FP_LITERAL      {DIGITS}\.{DIGITS}?{EXPONENT_PART}?{FLOAT_TYPE_SUFFIX}?|\.{DIGITS}{EXPONENT_PART}?{FLOAT_TYPE_SUFFIX}?|{DIGITS}{EXPONENT_PART}{FLOAT_TYPE_SUFFIX}?|{DIGITS}{EXPONENT_PART}?{FLOAT_TYPE_SUFFIX}

HEX_SIGNIFICAND         {HEX_NUMERAL}[\.]?|0[xX]{HEX_DIGITS}?[\.]{HEX_DIGITS}
BINARY_EXPONENT         [pP]{SIGNED_INTEGER}
HEXADECIMAL_FP_LITERAL  {HEX_SIGNIFICAND}{BINARY_EXPONENT}{FLOAT_TYPE_SUFFIX}?

FP_LITERAL              {DECIMAL_FP_LITERAL}|{HEXADECIMAL_FP_LITERAL}

STRING                  \"([^\"\\\n\r]|\\.)*\"

TEXT_BLOCK_CHAR         [^\\\"]|\"[^\\\"]|\"\"[^\\\"]|{ESCAPAE_SEQ}|{LINE_TERMINATOR}
TEXT_BLOCK              \"\"\"{WHITESPACE}?{LINE_TERMINATOR}{TEXT_BLOCK_CHAR}*\"\"\"

TRADITIONAL_COMMENT \/\*([^\*]|[\r\n]|(\*+([^\*\/]|[\r\n])))*[\*]+\/
EOL_COMMENT         \/\/[^\n\r]*
/* COMMENT             {TRADITIONAL_COMMENT}|{EOL_COMMENT} */


%%

"do"                                     {   
                                            yylval.str = strdup(yytext); 
                                            check_for_null(yylval.str);
                                            return DO;
                                          }
"case"                                    {   
                                            yylval.str = strdup(yytext); 
                                            check_for_null(yylval.str);
                                            return CASE;
                                          }
"default"                                    {   
                                            yylval.str = strdup(yytext); 
                                            check_for_null(yylval.str);
                                            return DEFAULT;
                                          }
"switch"                                  {   
                                            yylval.str = strdup(yytext); 
                                            check_for_null(yylval.str);
                                            return SWITCH;
                                          }

"int"                                     {   
                                            yylval.str = strdup(yytext); 
                                            check_for_null(yylval.str);
                                            return INT;
                                          }
"long"                                    {   
                                            yylval.str = strdup(yytext); 
                                            check_for_null(yylval.str);
                                            return LONG;
                                          }
"byte"                                    {   
                                            yylval.str = strdup(yytext); 
                                            check_for_null(yylval.str);
                                            return BYTE;
                                          }
"char"                                    {   
                                            yylval.str = strdup(yytext); 
                                            check_for_null(yylval.str);
                                            return CHAR;
                                          }
"short"                                   {   
                                            yylval.str = strdup(yytext); 
                                            check_for_null(yylval.str);
                                            return SHORT;
                                          }

"float"                                   {   
                                            yylval.str = strdup(yytext); 
                                            check_for_null(yylval.str);
                                            return FLOAT;
                                          }
"double"                                  {   
                                            yylval.str = strdup(yytext); 
                                            check_for_null(yylval.str);
                                            return DOUBLE;
                                          }
"boolean"                                 {   
                                            yylval.str = strdup(yytext); 
                                            check_for_null(yylval.str);
                                            return BOOLEAN;
                                          }

"new"                                     {   
                                            yylval.str = strdup(yytext); 
                                            check_for_null(yylval.str);
                                            return NEW;
                                          }
"if"                                      {   
                                            yylval.str = strdup(yytext); 
                                            check_for_null(yylval.str);
                                            return IF;
                                          }
"else"                                    {   
                                            yylval.str = strdup(yytext); 
                                            check_for_null(yylval.str);
                                            return ELSE;
                                          }
"for"                                     {   
                                            yylval.str = strdup(yytext); 
                                            check_for_null(yylval.str);
                                            return FOR;
                                          }
"while"                                   {   
                                            yylval.str = strdup(yytext); 
                                            check_for_null(yylval.str);
                                            return WHILE;
                                          }
"break"                                   {   
                                            yylval.str = strdup(yytext); 
                                            check_for_null(yylval.str);
                                            return BREAK;
                                          }
"continue"                                {   
                                            yylval.str = strdup(yytext); 
                                            check_for_null(yylval.str);
                                            return CONTINUE;
                                          }
"yield"                                   {   
                                            yylval.str = strdup(yytext); 
                                            check_for_null(yylval.str);
                                            return YIELD;
                                          }

"try"                                     {   
                                            yylval.str = strdup(yytext); 
                                            check_for_null(yylval.str);
                                            return TRY;
                                          }
"catch"                                   {   
                                            yylval.str = strdup(yytext); 
                                            check_for_null(yylval.str);
                                            return CATCH;
                                          }
"finally"                                {   
                                            yylval.str = strdup(yytext); 
                                            check_for_null(yylval.str);
                                            return FINALLY;
                                          }

"void"                                    {   
                                            yylval.str = strdup(yytext); 
                                            check_for_null(yylval.str);
                                            return VOID;
                                          }
"return"                                  {   
                                            yylval.str = strdup(yytext); 
                                            check_for_null(yylval.str);
                                            return RETURN;
                                          }
"public"                                  {   
                                            yylval.str = strdup(yytext); 
                                            check_for_null(yylval.str);
                                            return PUBLIC;
                                          }
"private"                                 {   
                                            yylval.str = strdup(yytext); 
                                            check_for_null(yylval.str);
                                            return PRIVATE;
                                          }
"class"                                   {   
                                            yylval.str = strdup(yytext); 
                                            check_for_null(yylval.str);
                                            return CLASS;
                                          }
"static"                                  {   
                                            yylval.str = strdup(yytext); 
                                            check_for_null(yylval.str);
                                            return STATIC;
                                          }

"final"                                   {   
                                            yylval.str = strdup(yytext); 
                                            check_for_null(yylval.str);
                                            return FINAL;
                                          }
"var"                                     {   
                                            yylval.str = strdup(yytext); 
                                            check_for_null(yylval.str);
                                            return VAR;
                                          }
"assert"                                  {   
                                            yylval.str = strdup(yytext); 
                                            check_for_null(yylval.str);
                                            return ASSERT;
                                          }
"throw"                                   {   
                                            yylval.str = strdup(yytext); 
                                            check_for_null(yylval.str);
                                            return THROW;
                                          }
"throws"                                   {   
                                            yylval.str = strdup(yytext); 
                                            check_for_null(yylval.str);
                                            return THROWS;
                                          }

"synchronized"                            {   
                                            yylval.str = strdup(yytext); 
                                            check_for_null(yylval.str);
                                            return SYNCHRONIZED;
                                          }

"+"                                   {   
                                            yylval.str = strdup(yytext); 
                                            check_for_null(yylval.str);
                                            return PLUS;
                                      }
"-"                                   {   
                                            yylval.str = strdup(yytext); 
                                            check_for_null(yylval.str);
                                            return MINUS;
                                      }
"*"                                   {   
                                            yylval.str = strdup(yytext); 
                                            check_for_null(yylval.str);
                                            return ASTERIK;
                                      }
"/"                                   {   
                                            yylval.str = strdup(yytext); 
                                            check_for_null(yylval.str);
                                            return DIV;
                                      }
"%"                                   {   
                                            yylval.str = strdup(yytext); 
                                            check_for_null(yylval.str);
                                            return MODULO;
                                      }
"++"                                  {   
                                            yylval.str = strdup(yytext); 
                                            check_for_null(yylval.str);
                                            return INCREMENT;
                                      }
"--"                                  {   
                                            yylval.str = strdup(yytext); 
                                            check_for_null(yylval.str);
                                            return DECREMENT;
                                      }
"->"                                  {   
                                            yylval.str = strdup(yytext); 
                                            check_for_null(yylval.str);
                                            return ARROW;
                                      }

">="						{   
                                            yylval.str = strdup(yytext); 
                                            check_for_null(yylval.str);
                                            return GEQ;
                                      }
"<="								  {   
                                            yylval.str = strdup(yytext); 
                                            check_for_null(yylval.str);
                                            return LEQ;
                                      }
">"									  {   
                                            yylval.str = strdup(yytext); 
                                            check_for_null(yylval.str);
                                            return GT;
                                      }
"<"									  {   
                                            yylval.str = strdup(yytext); 
                                            check_for_null(yylval.str);
                                            return LT;
                                      }
"!="								  {   
                                            yylval.str = strdup(yytext); 
                                            check_for_null(yylval.str);
                                            return NEQ;
                                      }
"=="								  {   
                                            yylval.str = strdup(yytext); 
                                            check_for_null(yylval.str);
                                            return DEQ;
                                      }

"&"                                   {   
                                            yylval.str = strdup(yytext); 
                                            check_for_null(yylval.str);
                                            return BITWISE_AND;
                                      }
"|"                                   {   
                                            yylval.str = strdup(yytext); 
                                            check_for_null(yylval.str);
                                            return BITWISE_OR;
                                      }
"^"                                   {   
                                            yylval.str = strdup(yytext); 
                                            check_for_null(yylval.str);
                                            return BITWISE_XOR;
                                      }
"~"                                   {   
                                            yylval.str = strdup(yytext); 
                                            check_for_null(yylval.str);
                                            return BITWISE_COMPLEMENT;
                                      }
"<<"                                  {   
                                            yylval.str = strdup(yytext); 
                                            check_for_null(yylval.str);
                                            return LEFT_SHIFT;
                                      }
">>"                                  {   
                                            yylval.str = strdup(yytext); 
                                            check_for_null(yylval.str);
                                            return RIGHT_SHIFT;
                                      }
">>>"                                 {   
                                            yylval.str = strdup(yytext); 
                                            check_for_null(yylval.str);
                                            return UNSIGNED_RIGHT_SHIFT;} 
                                         

"&&"								  {   
                                            yylval.str = strdup(yytext); 
                                            check_for_null(yylval.str);
                                            return AND;
                                      }
"||"								  {   
                                            yylval.str = strdup(yytext); 
                                            check_for_null(yylval.str);
                                            return OR;
                                      }
"!"                                   {   
                                            yylval.str = strdup(yytext); 
                                            check_for_null(yylval.str);
                                            return NOT;
                                      }

"="|"+="|"-="|"*="|"/="|"&="|"%="|">>="|"<<="|">>>="|"|="|"^="         {
                                                                            yylval.str = yytext;
                                                                            check_for_null(yylval.str);
                                                                            return ASSIGNMENT;
                                                                        }

":"									  {   
                                            yylval.str = strdup(yytext); 
                                            check_for_null(yylval.str);
                                            return COLON;
 
                                      }
"?"									  {   
                                            yylval.str = strdup(yytext); 
                                            check_for_null(yylval.str);
                                            return QM;
                                      }

"("									  {   
                                            yylval.str = strdup(yytext); 
                                            check_for_null(yylval.str);
                                            return LPAREN;
                                      }

")"									  {   
                                            yylval.str = strdup(yytext); 
                                            check_for_null(yylval.str);
                                            return RPAREN;
                                      }

"{"						{   
                                            yylval.str = strdup(yytext); 
                                            check_for_null(yylval.str);
                                            return LCURLY;
                                      }

"}"						      {   
                                            yylval.str = strdup(yytext); 
                                            check_for_null(yylval.str);
                                            return RCURLY;
                                      }

"["									  {   
                                            yylval.str = strdup(yytext); 
                                            check_for_null(yylval.str);
                                            return LSQUARE;
                                      }

"]"									  {   
                                            yylval.str = strdup(yytext); 
                                            check_for_null(yylval.str);
                                            return RSQUARE;
                                      }

";"									  {   
                                            yylval.str = strdup(yytext); 
                                            check_for_null(yylval.str);
                                            return SEMICOLON;
                                      }

","									  {   
                                            yylval.str = strdup(yytext); 
                                            check_for_null(yylval.str);
                                            return COMMA;
                                      }

"."                                   {   
                                            yylval.str = strdup(yytext); 
                                            check_for_null(yylval.str);
                                            return DOT;
                                      }

"this"                                {   
                                            yylval.str = strdup(yytext); 
                                            check_for_null(yylval.str);
                                            return THIS;
                                      }
"instanceof"                          {   
                                            yylval.str = strdup(yytext); 
                                            check_for_null(yylval.str);
                                            return INSTANCEOF;
                                      }
"super"                               {   
                                            yylval.str = strdup(yytext); 
                                            check_for_null(yylval.str);
                                            return SUPER;
                                      }
"implements"                          {   
                                            yylval.str = strdup(yytext); 
                                            check_for_null(yylval.str);
                                            return IMPLEMENTS; 
                                      }
"interface"                           {   
                                            yylval.str = strdup(yytext); 
                                            check_for_null(yylval.str);
                                            return INTERFACE; 
                                      }
"extends"                             {   
                                            yylval.str = strdup(yytext); 
                                            check_for_null(yylval.str);
                                            return EXTENDS; 
                                      }
"package"                             {   
                                            yylval.str = strdup(yytext); 
                                            check_for_null(yylval.str);
                                            return PACKAGE; 
                                      }
"import"                              {   
                                            yylval.str = strdup(yytext); 
                                            check_for_null(yylval.str);
                                            return IMPORT; 
                                      }

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
                                            yylval.str = strdup(yytext); 
                                            check_for_null(yylval.str); 
                                            return INTEGER_LITERAL;
                                        }

{FP_LITERAL}                            {   
                                            yylval.str = strdup(yytext); 
                                            check_for_null(yylval.str);
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

{EOL_COMMENT}                          {
                                            int c = yyinput();
                                            if(c == EOF){
                                                unput(c);
                                            }
                                       }

{TRADITIONAL_COMMENT}                  {/*ignore it*/}

<INITIAL><<EOF>>        { BEGIN(REALLYEND); return EOF_; } 

<REALLYEND><<EOF>>      { return 0; }

.                                       { printf("Illegal character on line %d: %s\n",yylineno, yytext);}

%%

