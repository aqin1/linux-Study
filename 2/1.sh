#!/bin/bash
echo $0
echo $1
echo $2
echo $3
echo $@
echo $#
echo $?
echo $$
sum=10
unset sum
echo -n "enter q to exit sh!:";read var
if [ "$var" = "quit" ]
then
	sum=`expr 12 + 8 / 2`
	echo "sum=$sum"
	echo "exit"
else
	echo -n "input number add with sum:";read var
	sum=`expr $sum + $var`
	echo "sum=$sum"
	echo "exit error!"
fi
