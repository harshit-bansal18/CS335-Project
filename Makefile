all: milestone1

G++ := g++ -O3 -Wno-write-strings
MILESTONE1 := milestone1/src
Parser_Src := parser/lalr1.y
Lexer_Src := scanner/lexer.l
Parser_Out := parser.tab.c
Parser_Header := parser.tab.h
Lexer_Out := lexer.yy.c
Binary := javap
INCLUDE1 := -I ./milestone1/include/

MILESTONE2 := milestone2/src
INCLUDE2 := -I ./milestone2.1/semantic/include/ -I ./milestone1/include/
Semantic := semantic
build/milestone1:
	mkdir -p build/milestone1
	bison -t --header=$@/${Parser_Header} -o $@/${Parser_Out} ${MILESTONE1}/${Parser_Src}
	flex -o $@/${Lexer_Out} ${MILESTONE1}/${Lexer_Src}
	${G++} ${INCLUDE1} -o $@/${Binary} $@/*.c

milestone1: build/milestone1

build/milestone2:
	mkdir -p build/milestone2
	bison -t --header=$@/${Parser_Header} -o $@/${Parser_Out} ${MILESTONE2}/${Parser_Src}
	flex -o $@/${Lexer_Out} ${MILESTONE2}/${Lexer_Src}
	${G++} ${INCLUDE2} -o $@/${Binary} $@/*.c ${MILESTONE1}/${Semantic}/*.cpp

milestone2: build/milestone2
clean:
	rm -rf build