all: milestone4

G++ := g++ -O3 -Wno-write-strings
MILESTONE1 := milestone1/src
Parser_Src := parser/lalr1_modular.y
Lexer_Src := scanner/lexer.l
Parser_Out := parser.tab.c
Parser_Header := parser.tab.h
Lexer_Out := lexer.yy.c
Binary1 := javap
INCLUDE1 := -I ./milestone1/include/

MILESTONE2 := milestone2/src
Semantic := semantic
INCLUDE2 := -I ./milestone2/src/semantic/include/ -I ./milestone2/include/
Binary2 := javas

MILESTONE3 := milestone3/src
INCLUDE3 := -I ./milestone3/src/semantic/include/ -I ./milestone3/include/
Runtime := runtime
Binary3 := javair

MILESTONE4 := milestone4/src
INCLUDE4 := -I ./milestone4/src/semantic/include/ -I ./milestone4/include/ -I ./milestone4/src/runtime/include
Binary4 := java2x86

# build/milestone1:
# 	mkdir -p build/milestone1
# 	bison -t --header=$@/${Parser_Header} -o $@/${Parser_Out} ${MILESTONE1}/${Parser_Src}
# 	flex -o $@/${Lexer_Out} ${MILESTONE1}/${Lexer_Src}
# 	${G++} ${INCLUDE1} -o $@/${Binary} $@/*.c

# milestone1: build/milestone1

build/milestone2:
	mkdir -p build/milestone2
	mkdir -p build/milestone2/dump
	bison -t --header=$@/${Parser_Header} -o $@/${Parser_Out} ${MILESTONE2}/${Parser_Src}
	flex -o $@/${Lexer_Out} ${MILESTONE2}/${Lexer_Src}
	${G++} ${INCLUDE2} -o $@/${Binary2} $@/*.c ${MILESTONE2}/${Semantic}/*.cpp

milestone2: build/milestone2

build/milestone3:
	mkdir -p build/milestone3
	mkdir -p build/milestone3/dump
	bison -t --header=$@/${Parser_Header} -o $@/${Parser_Out} ${MILESTONE3}/${Parser_Src}
	flex -o $@/${Lexer_Out} ${MILESTONE3}/${Lexer_Src}
	${G++} ${INCLUDE3} -o $@/${Binary3} $@/*.c ${MILESTONE3}/${Semantic}/*.cpp


milestone3: build/milestone3


build/milestone4:
	mkdir -p build/milestone4/dump/tests/
	mkdir -p build/milestone4/dump/bonus_tests/
	bison -t --header=$@/${Parser_Header} -o $@/${Parser_Out} ${MILESTONE4}/${Parser_Src}
	flex -o $@/${Lexer_Out} ${MILESTONE4}/${Lexer_Src}
	${G++} ${INCLUDE4} -o $@/${Binary4} $@/*.c ${MILESTONE4}/${Semantic}/*.cpp ${MILESTONE4}/${Runtime}/*.cpp

milestone4: build/milestone4

clean:
	rm -rf build

clean_dump:
	rm -rf build/*/dump/*