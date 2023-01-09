#!/bin/bash

hash=$1
wordlistFILE=$2

if [[ -f "$wordlistFILE" ]]
then
    while read line;
    do
        currHash="$(echo -n "$line" | md5sum)"
        currHash=${currHash: : 32}
        echo $hash -- $currHash -- $line
        if [[ $1 == $currHash ]];
        then
            echo "Found it! Password is: $line"
            exit
        fi
    done < $wordlistFILE
else
    echo "File not found!"
    exit
fi
