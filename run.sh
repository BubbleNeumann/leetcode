#!/bin/bash

echo "compiling $1"
g++ $1 -o out
echo "running $1"
./out

