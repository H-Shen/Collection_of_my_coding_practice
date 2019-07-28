#!/bin/bash

read string
if [ "$string" == "Y" ];then
	echo "YES"
elif [ "$string" == "y" ];then
	echo "YES"
elif [ "$string" == "N" ];then
	echo "NO"
elif [ "$string" == "n" ];then
	echo "NO"
fi
