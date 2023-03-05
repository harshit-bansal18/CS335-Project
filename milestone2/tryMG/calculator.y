%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


extern "C" int yylex();
extern "C" FILE *yyin;
extern "C" int yylineno;

int label_count = 0;

void emit(char* op, char* arg1, char* arg2, char* result) {
    printf("%s %s %s %s\n", op, arg1, arg2, result);
}

char* new_label() {
    char* label = (char*) malloc(10*sizeof(char));
    sprintf(label, "L%d", label_count++);
    return label;
}

int yyerror(const char* msg) {
    printf("Error: %s\n", msg);
    return 0;
}

%}

%union{
    char* str;
    int num;
}

%token<str> NUMBER
%type<str> expression
%left '+' '-'
%left '*' '/'

%%

expression:
    NUMBER                { $$ = $1; }
  | expression '+' expression  { $$ = new_label(); emit("ADD", $1, $3, $$); }
  | expression '-' expression  { $$ = new_label(); emit("SUB", $1, $3, $$); }
  | expression '*' expression  { $$ = new_label(); emit("MUL", $1, $3, $$); }
  | expression '/' expression  { $$ = new_label(); emit("DIV", $1, $3, $$); }
  ;

%%

int main() {
    printf("top %s\n", __func__);
    yyparse();
    return 0;
}


