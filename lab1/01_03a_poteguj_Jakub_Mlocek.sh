#!/bin/bash

result=$1

if [[ $2 ==  0 ]];
then 
	echo "0"
	exit 1;
fi

for ((i=1; i<$2; i++));
do
	result=$(($result*$1))
done
echo $result
