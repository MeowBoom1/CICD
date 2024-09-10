#!/bin/bash

cd cat/
bash test_cat.sh &> res_cat.txt
RES_C=$(grep -c "FAILED" res_cat.txt)
if [ "$RES_C" -ne 0 ]; then
    exit 1
fi
rm -rf res_cat.txt
cd ../grep
bash test_grep/test_func_grep.sh &> res_grep.txt
RES_G=$(grep -c "FAILED" res_grep.txt)
if [ "$RES_G" -ne 0 ]; then
    exit 1
fi
rm -rf res_grep.txt