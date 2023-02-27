#!/bin/bash

MILE1="./build/milestone1/"
BIN="execute"
TEST="milestone1/tests/$1.java"


make clean
make milestone1
${MILE1}${BIN} < ${TEST} > out.gv