#!/bin/bash

MILE1="./build/milestone2/"
BIN="javas"
TEST="milestone2/tests/"


make clean
make milestone2

for file in ${TEST}*.java
do 
    echo "Running on $file"
    ${MILE1}${BIN} --input $file
done

# for i in {1..10};
# do
#     echo "Running on test_$i.java"
#     ${MILE1}${BIN} --input ${TEST}"test_$i.java" --output build/milestone1/$i.gv
#     dot -Tpng build/milestone1/$i.gv > build/milestone1/$i.png
# done