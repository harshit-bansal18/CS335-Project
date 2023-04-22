#!/bin/bash

MILE1="./build/milestone4/"
BIN="java2x86"
TEST="milestone4/tests/"


make clean
make milestone4

for file in ${TEST}*.java
do 
    echo "Running on $file"
    ${MILE1}${BIN} --input $file --output build/milestone4/dump/$(basename $file .java).s
    gcc -c build/milestone4/dump/$(basename $file .java).s -o build/milestone4/dump/$(basename $file .java).o
    gcc build/milestone4/dump/$(basename $file .java).o -o build/milestone4/dump/$(basename $file .java)
done