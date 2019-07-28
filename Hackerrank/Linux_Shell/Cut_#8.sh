#!/bin/bash

while read string
    do
        echo "$string" | cut -d ' ' -f-3
    done
