#!/bin/sh
while read p;
do
    #./push_swap $p | ./checker_Mac $p
    res=$(./push_swap $p | ./checker_Mac $p)
    # echo $res
    if [[ $res == "KO" ]];
    then
        echo $p
    fi
done < permutations