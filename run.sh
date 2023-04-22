#!/bin/bash

if [[ $# -ne 1 ]];
then
    echo "format: ./run.sh <input_file>"
    exit 1
fi

make clean
make

TEST="./milestone4/tests/"
for f in $
# ./asm
