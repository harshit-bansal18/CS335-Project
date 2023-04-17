#!/bin/bash

MILE1="./build/milestone3/"
BIN="javair"
TEST="milestone3/tests/"


make clean
make milestone3

# for file in ${TEST}*.java
# do 
#     echo "Running on $file"
#     ${MILE1}${BIN} --input $file
# done

# ${MILE1}${BIN} --input ${TEST}"test_15.java"

./build/milestone3/javair --input ./milestone3/tests/test_0.java