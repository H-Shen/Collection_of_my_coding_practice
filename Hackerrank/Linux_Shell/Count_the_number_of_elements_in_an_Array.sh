#!/bin/bash

TotalElement=0

while read item
    do
        Arr[$TotalElement]="$item"
        TotalElement=$TotalElement+1
    done
    
echo "${#Arr[@]}"
