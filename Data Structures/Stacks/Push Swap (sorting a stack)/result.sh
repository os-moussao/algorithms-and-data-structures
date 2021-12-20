#!/bin/sh
while read p;
do
    #./push_swap $p | ./checker_Mac $p
    res=$(./push_swap $p | ./checker_Mac $p)
    if [[ $res == "OK" ]];
    then
        echo $p
    fi
done < permutations