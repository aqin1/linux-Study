#/bin/bash
#This file is a examples
#1.shell 判断一个字符串是否由字母数字组成

read -p "input:" var
if echo "$var" | grep -q '^[a-zA-Z0-9]\+$'
then
	echo "ok"
else
	echo "invaliad"
fi

#2.shell判断变量是字符还是数字
#2_1
read -p "please input a num: "  num
if echo $num | grep -q '[^0-9]'
then
        echo "this is not a num,please input num"
        exit 1
fi

#2_2
read -p "please input a num: "  num
echo $num | grep -q '[^0-9]'
n1=$?
if [ $n1 -eq 0 ]
then
        echo "this is not a num,please input num"
        exit 1
fi

#2_3
read -p "please input a num: "  num
n1=`echo $num|sed 's/[0-9]//g'`
if [ ! -z $n1 ]
then
        echo "this is not a num,please input num"
        exit 1
fi
