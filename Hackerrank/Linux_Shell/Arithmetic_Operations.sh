#!/bin/bash

read x
printf "%.3f" $(echo $x | bc -l)
