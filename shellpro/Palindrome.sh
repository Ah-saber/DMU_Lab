#!/bin/bash

echo "Input a number as n"

read n

echo "Ouput 1-$n palindrome"

for i in $(seq 1 $n)
do
    tmp=$(echo $i | rev)
    if [ $i -eq $tmp ]
    then
        echo -n "$i "
    fi
done

echo 