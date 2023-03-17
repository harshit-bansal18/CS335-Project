%{
    #include <stdio.h>
    #include <stdarg.h>
    #include <stdlib.h>
    #include <string.h>
    #include <iostream>
    #include <iomanip>
    #include <vector>
    #include <fstream>
    // #include <argparse/argparse.hpp>
    #include "symbol_table.hpp"
    
    #define YYDEBUG 1
    using namespace std;

    extern "C" int yylex();
    extern "C" FILE *yyin;
    extern "C" int yylineno;

    static int node_num=-1;

    ofstream dotfile;

    int yyerror(const char *);
    int pass_no = 0;

%}

%define parse.error verbose

%union {
    int num;
    double float_num;
    char* str;
    struct stackentry* stack_entry;
}

%token<str> INT LONG BYTE CHAR SHORT FLOAT DOUBLE BOOLEAN VAR IF ELSE FOR WHILE BREAK CONTINUE VOID NEW RETURN PUBLIC PRIVATE CLASS STATIC FINAL SWITCH YIELD CATCH FINALLY SYNCHRONIZED ASSERT PLUS MINUS DIV MODULO INCREMENT DECREMENT GEQ LEQ GT LT NEQ DEQ BITWISE_AND BITWISE_OR BITWISE_XOR BITWISE_COMPLEMENT LEFT_SHIFT RIGHT_SHIFT UNSIGNED_RIGHT_SHIFT AND OR NOT ASSIGNMENT COLON QM LPAREN RPAREN LCURLY RCURLY LSQUARE RSQUARE SEMICOLON COMMA DOT ARROW CHAR_LITERAL BOOLEAN_LITERAL NULL_LITERAL INTEGER_LITERAL FP_LITERAL STRING TEXT_BLOCK IDENTIFIER THIS INSTANCEOF SUPER THROW THROWS EOF_ IMPLEMENTS INTERFACE EXTENDS PACKAGE IMPORT ASTERIK DO TRY CASE DEFAULT

%left INCREMENT DECREMENT
%left NOT BITWISE_COMPLEMENT
%left ASTERIK DIV MODULO
%left PLUS MINUS
%left LEFT_SHIFT RIGHT_SHIFT UNSIGNED_RIGHT_SHIFT 
%left GEQ LEQ GT LT NEQ DEQ
%left BITWISE_AND
%left BITWISE_XOR
%left BITWISE_OR
%left AND
%left OR
%right ASSIGNMENT ASSIGN


%type<str> Empty
%type<stack_entry> A
%type<stack_entry> B
%type<stack_entry> start 
%start start
%%

start : Empty{} B {stackentry* temp = $3;}

B : A {$$ = $1;}
|   B A {$$ = $1;}


A : BOOLEAN { 
                    struct stackentry* entry = new_entry(); 
                    entry->type = __BOOLEAN;
                    $$ = entry;
                  }
;

Empty : {$$ = "";};

%%

void handle_signal(int s) {
    printf("Received signal %d\n", s);

    fflush(stdout);
    exit(1);
}



int main(int argc, char *argv[]) {

    argparse::ArgumentParser program("javap");

    struct args *_args = new struct args;


    program.add_argument("--input")
        .required()
        .help("java file to parse");

    program.add_argument("--output")
        .required()
        .help("output dot file");
  
    
    program.add_argument("--verbose")
        .help("increase output verbosity for parser")
        .default_value(false)
        .implicit_value(true);


    try {
        program.parse_args(argc, argv);
    }
    catch (const std::runtime_error &err) {
        std::cerr << err.what() << std::endl;
        std::cerr << program;
        std::exit(1);
    }


    _args->input = (char*)(program.get<std::string>("--input").c_str());

  

    _args->output = (char*)(program.get<std::string>("--output").c_str());

    if (program["--verbose"] == true) {
        _args->verbose = true;
    }


    yydebug = 0;
    
    if (_args->verbose)
        yydebug = 1;

    
    while(pass <= 2) {
        yyin = fopen(_args->input, "r");
    
    
    
        /* dotfile.open(_args->output);


        dotfile << "digraph AST {\n";
        dotfile << "node [fontname = courier, shape = box, colorscheme = paired6];\n";
        dotfile << "edge [color=blue];\n"; */

        do {
            yyparse();
        } while(!feof(yyin));

        /* dotfile << "}"; */

        /* dotfile.close(); */
    }
    return 0;
}

int yyerror(const char *s) {
    printf("syntax error: line %d: %s\n", yylineno, s);
    dotfile.close();
    exit(1);
}