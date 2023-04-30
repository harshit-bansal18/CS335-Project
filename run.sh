#!/bin/bash

MILE1="./build/milestone4/"
BIN="java2x86"
TEST="milestone4/tests/"
TEST_DUMP="build/milestone4/dump/tests/"
BONUS_TEST="milestone4/bonus_tests/"
BONUS_TEST_DUMP="build/milestone4/dump/bonus_tests/"


make clean
make milestone4


# For running all test cases in milestone4/tests

for file in ${TEST}*.java
do 
    echo ""
    echo "Running on $file"
    echo ""
    ${MILE1}${BIN} --input $file --output ${TEST_DUMP}$(basename $file .java).s
    gcc -c ${TEST_DUMP}$(basename $file .java).s -o ${TEST_DUMP}$(basename $file .java).o
    gcc ${TEST_DUMP}$(basename $file .java).o -o ${TEST_DUMP}$(basename $file .java)
    ${TEST_DUMP}$(basename $file .java) > ${TEST_DUMP}$(basename $file .java).out
done

# For running all test cases in milestone4/bonus_tests

for file in ${BONUS_TEST}*.java
do 
    echo "Running on $file"
    ${MILE1}${BIN} --input $file --output build/milestone4/dump/bonus_tests/$(basename $file .java).s
    gcc -c build/milestone4/dump/bonus_tests/$(basename $file .java).s -o build/milestone4/dump/bonus_tests/$(basename $file .java).o
    gcc build/milestone4/dump/bonus_tests/$(basename $file .java).o -o build/milestone4/dump/bonus_tests/$(basename $file .java)
    ./build/milestone4/dump/bonus_tests/$(basename $file .java) > build/milestone4/dump/bonus_tests/$(basename $file .java).out
done

