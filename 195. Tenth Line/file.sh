#! /bin/bash
filename="file.txt"
counter=0
echo "" >> file.txt
while read line; do
counter=$((counter+1))
if [ $counter -eq 10 ]; then
    echo "$line"; 
fi
done < file.txt