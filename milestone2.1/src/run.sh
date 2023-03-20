bison -d -t parser/lalr1_fast.y
flex scanner/lexer.l
g++ -I semantic/include_fast -o semantic_analyser semantic/symbol_table_fast.cpp semantic/actions_fast.cpp lex.yy.c lalr1_fast.tab.c 
