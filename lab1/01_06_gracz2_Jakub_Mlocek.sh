FILE=komenda.txt
losFILE=los2.txt


if [[ -f "$FILE" ]] && [[ ! -f "$losFILE" ]]
then
	while read line;
	do
		line1=$line
	done < komenda.txt
	
	if (( line1 == "start" ))
	then
		touch los2.txt
		chmod +x los2.txt
		rand=$(($RANDOM%3+1))
	    	echo $rand > los2.txt
	else
		exit
	fi
fi

exit

