#!/bin/bash

echo "Input a number as n"

read n

echo "Output numbers from 1 to $n, excluding those that contain 3 or are multiples of 3"

for i in $(seq 1 $n)
do  
    tmp=$(echo "$i" | grep 3)
    if echo "$i" | grep -q 3 #if其实判断命令退出码，如果0则true否则false
    then
        continue
    fi

    if [ $(expr $i % 3) -eq 0 ]
    then
        continue
    fi
    echo -n "$i "
done

echo
