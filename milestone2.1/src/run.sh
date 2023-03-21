bison -d -t parser/lalr1_fast.y --report all
flex scanner/lexer.l
g++ -I semantic/include_fast -I ../../milestone1/include/ -o semantic_analyser semantic/symbol_table_fast.cpp semantic/actions_fast.cpp lex.yy.c lalr1_fast.tab.c 
