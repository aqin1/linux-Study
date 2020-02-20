#!/bin/bash
echo -n "Please input a number:";read var1
echo "You first number is $var1"
echo -n "Please input a number again:";read var2
echo "You second number is $var2"
sum=`expr $var1 + $var2`
echo "The sum of tow number equal $sum"
if [ $sum -eq 10 ]
then
	echo 0
elif [ $sum -ne 10 ]
then
	echo -1
fi
