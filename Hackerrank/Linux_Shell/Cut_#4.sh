#!/bin/bash

while read string
    do
        echo "$string" | cut -c 1-4
    done
