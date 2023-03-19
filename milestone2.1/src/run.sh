bison -d -t parser/lalr1.y
flex scanner/lexer.l
g++ -I semantic/include -o semantic_analyser semantic/symbol_table.cpp semantic/actions.cpp lex.yy.c lalr1.tab.c 
