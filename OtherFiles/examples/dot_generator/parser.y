%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <iostream>
    #include "ast.h"

    #define YYDEBUG 1
    using namespace std;

    extern "C" int yylex();
    extern "C" FILE *yyin;
    extern "C" int yylineno;

    int yyerror(const char *);


%}



%define parse.error verbose

%union {
    int num;
    char* str;
    struct exp* exp_val;
}

%token<str> LITERAL
%token<str> ID
%token EOF_
%type<exp_val>Op
%type <exp_val>Assign
%type <exp_val> Assigns
%type <exp_val> Id
%type <exp_val> Literal

%%
input: Assigns EOF_    { generate_script($1); }
;

Assigns:
    Assigns Assign ';' { $$ = make_exp_end($1, $2); }   
|   Assign ';'          { $$ =  make_exp_end($1, NULL); }
;

Assign:
    Literal '=' Op { $$ = make_exp_assign($1, $3); }
;


Op:
    Op '+' Op       { $$ = make_exp_add($1, $3); }
|   Op '-' Op       { $$ = make_exp_sub($1, $3); }
|   Id              { $$ = $1; }
;

Id:
    ID  {$$ = make_exp_int($1);}

Literal:
    LITERAL {$$ = make_exp_identifier($1);}

%%

int main(int argc, char* argv[]) {
    if (argc != 3) {
        cout << "format: ./build/run <file name> <debug>" << endl;
        exit (1);
    }
    yyin = fopen(argv[1], "r");

    yydebug = atoi(argv[2]);


    do {
        yyparse();
    } while(!feof(yyin));

    /* Print Stats*/
    /* print_stats(); */
    // make ast and then write to file
    return 0;
}

int yyerror(const char *s) {
    printf("syntax error: line %d: %s\n", yylineno, s);
    exit(1);
}