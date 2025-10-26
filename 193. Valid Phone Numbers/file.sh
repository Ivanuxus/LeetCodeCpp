#! /bin/bash
filename="file.txt"
echo "" >> file.txt
while read line; do
if [[ "$line" =~ ^[0-9]{3}-[0-9]{3}-[0-9]{4}$ ]] || [[ "$line" =~ ^\([0-9]{3}\){1}[[:space:]][0-9]{3}[-]{1}[0-9]{4}$ ]]; then
    echo "$line"; 
    fi
done < file.txt