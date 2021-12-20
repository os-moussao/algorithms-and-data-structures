#!/bin/sh
while read p;
do
    res=$(./push_swap $p | ./checker_Mac $p)
    n=$(./push_swap $p | wc -l)
    echo "res = $res    count = $n"
    # if [[ $n -gt 12 ]];
    # then
    #     echo "perm = $p            count = $n"
    #     #./push_swap $p | ./checker_Mac $p
    # fi
    # res=$(./push_swap $p | ./checker_Mac $p)
    # if [[ $res == "KO" ]];
    # then
    #     echo $p
    # fi
done < permutations