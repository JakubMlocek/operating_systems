#! /bin/bash

liczbaGier=$1
los1=0
los2=0
punktyGracza1=0
punktyGracza2=0
FILE1=los1.txt
FILE2=los2.txt

for (( i=0; i<$liczbaGier; i++ ))
do
	touch komenda.txt
	chmod +x komenda.txt

	echo "start" > komenda.txt
	
	bash gracz1.sh
	bash gracz2.sh

	until [[ -f "$FILE1" ]] && [[ -f "$FILE2" ]]
	do
		sleep 1
	done

	sleep 0.1
	rm komenda.txt

	while read line;
	do
		los1=$line
	done < los1.txt

	while read line;
	do
		los2=$line
	done < los2.txt
		
	#1=papier 2=nozyce 3=kamien
	if (( los1 == los2 ))
	then
		echo "Remis"
		punktyGracza1=$((punktyGracza1+1))
		punktyGracza2=$((punktyGracza2+1))
	elif (((( los1 == 3 )) && (( los2 == 1 )))) || (((( los1 == 1 )) && (( los2 == 2 )))) || (((( los1 == 2 )) && (( los2 == 3 ))))
	then
		echo "Wygrywa gracz 2"
		punktyGracza2=$((punktyGracza2+1))
	else
		echo "Wygrywa gracz 1"
		punktyGracza1=$((punktyGracza1+1))
	fi
	
	rm los1.txt
	rm los2.txt
	
done

echo "Liczba pkt gracza 1: $punktyGracza1"
echo "Liczba pkt gracza 2: $punktyGracza2"

touch komenda.txt
chmod +x komenda.txt

echo "stop" > komenda.txt

sleep 1

rm komenda.txt






