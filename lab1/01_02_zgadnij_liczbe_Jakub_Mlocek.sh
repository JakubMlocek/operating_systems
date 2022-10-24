#!/bin/bash

if [[ $1 -gt $2 ]];
then
	exit 0;
fi

pula=$(($2-$1))
result=$(($RANDOM%$pula+$1))

for ((i=0; i<5;i++))
do
	echo "Zgadnij jaka to liczba miedzy $1 a $2?"
	read input
	if [[ $input == $result ]];
	then
		echo "Brawo! Szukana liczba to $result";
	else
		echo "Szukaj dalej az znajdziesz $result";
	fi
done




