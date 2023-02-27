%{
#include <stdio.h>
#include <stdlib.h>
extern int n=0;


%}

%token NUMBER
%token PLUS MINUS MULTIPLY DIVIDE
%token EOL

%start calc

%%

calc:
    expression EOL
    ;


expression:
    NUMBER { printf("node%d[label=\"%d\"];\n", ++n, $1); $$ = n; }
    | expression PLUS term {
        printf("node%d[label=\"+\"];\n", ++n);
        printf("node%d -> node%d;\n", n, $1);
        printf("node%d -> node%d;\n", n, $3);
        $$ = n;
    }
    | expression MINUS expression {
        printf("node%d[label=\"-\"];\n", ++n);
        printf("node%d -> node%d;\n", n, $1);
        printf("node%d -> node%d;\n", n, $3);
        $$ = n;
    }
    | expression MULTIPLY expression {
        printf("node%d[label=\"*\"];\n", ++n);
        printf("node%d -> node%d;\n", n, $1);
        printf("node%d -> node%d;\n", n, $3);
        $$ = n;
    }
    | expression DIVIDE expression {
        printf("node%d[label=\"/\"];\n", ++n);
        printf("node%d -> node%d;\n", n, $1);
        printf("node%d -> node%d;\n", n, $3);
        $$ = n;
    }
    ;

%%

int main(void)
{
    n = 0;
    printf("digraph AST {\n");
    printf("node [shape=circle,fontname=\"Courier-Bold\",fontsize=16];\n");
    printf("edge [color=blue];\n");
    yyparse();
    printf("}");
    return 0;
}

int yyerror(const char* msg)
{
    printf("Error: %s\n", msg);
    return 0;
}
