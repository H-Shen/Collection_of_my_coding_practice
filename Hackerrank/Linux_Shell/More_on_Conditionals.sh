#!/bin/bash

read x
read y
read z

if [ "$x" == "$y" ] && [ "$y" == "$z" ];then
	echo "EQUILATERAL"
elif [ "$x" == "$y" ] && [ "$y" != "$z" ];then
	echo "ISOSCELES"
elif [ "$x" != "$y" ] && [ "$y" == "$z" ];then
	echo "ISOSCELES"
elif [ "$x" == "$z" ] && [ "$z" != "$y" ];then
	echo "ISOSCELES"
else
	echo "SCALENE"
fi
