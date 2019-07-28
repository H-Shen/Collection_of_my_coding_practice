#!/bin/bash

while read string
    do
        echo "$string" | cut -c 13-
    done
