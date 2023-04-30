
all: build/parser build/lexer build/run

build:
	mkdir $@

build/parser: build
	bison -t --header=build/parser.tab.h -o build/parser.tab.c parser.y 

build/lexer: build/parser
	flex -o build/lexer.yy.c lexer.l
 
build/run: build/parser build/lexer
	g++ -I./ -o $@ build/lexer.yy.c build/parser.tab.c ast.cpp

clean:
	rm -rf build