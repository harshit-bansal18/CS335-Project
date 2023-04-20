#!/bin/bash

if [[ $# -ne 1 ]];
then
    echo "format: ./run.sh <input_file>"
    exit 1
fi

./build/milestone4/java2x86 --input ./milestone4/tests/$1 --output function.s > tac.txt
# gcc -c -fPIE -m64 -fno-asynchronous-unwind-tables -fno-exceptions function.s -o function.o 
# gcc -o function function.o
gcc -fPIE function.s -o function -no-pie -Wl,-z,noexecstack
# ./function
