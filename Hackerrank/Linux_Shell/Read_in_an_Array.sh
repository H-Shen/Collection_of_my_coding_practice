#! /bin/bash

currentIndex=0

while read string
    do
        Unix[$currentIndex]="$string"
		currentIndex=$currentIndex+1
    done
    
echo ${Unix[@]}
