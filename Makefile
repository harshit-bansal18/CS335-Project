all: milestone1

G++ := g++ -O3 -Wno-write-strings
MILESTONE1 := milestone1/src
Parser_Src := parser/lalr1.y
Lexer_Src := scanner/lexer.l
Parser_Out := parser.tab.c
Parser_Header := parser.tab.h
Lexer_Out := lexer.yy.c
Binary := execute
GRAPH := parser.gv
build/milestone1:
	mkdir -p build/milestone1
	bison -t --header=$@/${Parser_Header} -o $@/${Parser_Out} ${MILESTONE1}/${Parser_Src}
	flex -o $@/${Lexer_Out} ${MILESTONE1}/${Lexer_Src}
	${G++} -o $@/${Binary} $@/*.c

milestone1: build/milestone1
	

clean:
	rm -rf build