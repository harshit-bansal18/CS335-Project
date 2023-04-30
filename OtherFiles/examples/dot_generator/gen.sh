#!/bin/bash

make clean
make
./build/run test.txt $1
dot -Tpng ast.gv > file1.png