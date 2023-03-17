bison -t parser/lalr1.y
clear
flex scanner/lexer.l
clear
g++ -I semantic/include -o semantic_analyser semantic/symbol_table.cpp lex.yy.c lalr1.tab.c 
