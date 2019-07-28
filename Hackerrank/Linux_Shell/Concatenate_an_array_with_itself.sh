#!/bin/bash

i=0

while read item || [ -n "$item" ]
    do
        Unix[$i]="$item"
        i=$i+1
    done

UnixShell=("${Unix[@]}" "${Unix[@]}" "${Unix[@]}")
echo "${UnixShell[@]}"
