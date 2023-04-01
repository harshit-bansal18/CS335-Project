#!/bin/bash

MILE1="./build/milestone1/"
BIN="javap"
TEST="milestone1/tests/"


make clean
make milestone1

for file in ${TEST}*.java
do 
    echo "Running on $file"
    ${MILE1}${BIN} --input $file --output build/milestone1/$(basename $file .java).gv
    dot -Tpng build/milestone1/$(basename $file .java).gv > build/milestone1/$(basename $file .java).png
done

# for i in {1..10};
# do
#     echo "Running on test_$i.java"
#     ${MILE1}${BIN} --input ${TEST}"test_$i.java" --output build/milestone1/$i.gv
#     dot -Tpng build/milestone1/$i.gv > build/milestone1/$i.png
# done