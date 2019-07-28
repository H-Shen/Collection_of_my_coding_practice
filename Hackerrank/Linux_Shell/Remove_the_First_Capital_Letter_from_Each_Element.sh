#!/bin/bash

TotalElement=0
change=.

while read item
    do
		item0=${change}${item:1}
        Arr[$TotalElement]="$item0"
        TotalElement=$TotalElement+1
    done
    
echo "${Arr[@]}"
