#!/bin/bash

while read string
    do
        echo "$string" | cut -c 3
    done
