# Read from the file words.txt and output the word frequency list to stdout.
declare -A freq

while read -r -a line; 
do
    for word in "${line[@]}";
    do
	    if [ ${freq[$word]+_} ]; then ((freq[$word]++)); else freq[$word]=1; fi
    done;
done < words.txt

for word in "${!freq[@]}"
do 
	echo $word ${freq[$word]}
done |
sort -r -n -k 2