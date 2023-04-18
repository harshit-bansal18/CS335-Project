#!/bin/bash

if [[ $# -ne 1 ]];
then
    echo "format: ./run.sh <input_file>"
    exit 1
fi

./build/milestone4/java2x86 --input ./milestone4/tests/$1 --output asm.s > long.txt
# gcc -c -fPIE -m64 -fno-asynchronous-unwind-tables -fno-exceptions asm.s -o asm.o 
# gcc -o asm asm.o
gcc -fPIE asm.s -o asm -no-pie -Wl,-z,noexecstack
