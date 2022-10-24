FILE=komenda.txt
losFILE=los1.txt


if [[ -f "$FILE" ]] && [[ ! -f "$losFILE" ]]
then
	while read line;
	do
		line1=$line
	done < komenda.txt
	
	if (( line1 == "start" ))
	then
		touch los1.txt
		chmod +x los1.txt
		rand=$(($RANDOM%3+1))
	    	echo $rand > los1.txt
	else
		exit
	fi
fi

exit
