ls -alR /usr | awk -F" " '{print $1}' | cut -c  1- | grep "^[b,c,d,p,f,l,s,-]" | sort | uniq -c

