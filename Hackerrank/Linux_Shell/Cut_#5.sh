#!/bin/bash

while read string
    do
        echo "$string" | cut -f-3
    done
