#!/bin/bash

while read string
    do
        echo "$string" | cut -d ' ' -f 4
    done
