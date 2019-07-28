#!/bin/bash

currentIndex=0

while read item
    do
        Arr[$currentIndex]="$item"
        currentIndex=$currentIndex+1
    done
    
echo "${Arr[3]}"
