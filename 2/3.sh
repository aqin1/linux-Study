#/bin/bash
#猜数字

#产生一个随机数
num=`date +%s`
#计数
count=83

#只是用于测试
#let "aa=1&&0"
#echo $aa

echo "               It's a guessing game!"
echo "                     Begin Game!"
#echo -n "Please input you number:";read var
read -p "Please input you number:" var
# 输入出错处理
# echo $var | grep -q '[^0-9]'  用于判断输入是否是数字其实是判断输入的字符串是否全部属于{0-9]内
while echo $var | grep -q '[^0-9]'
do
	read -p "Please input a number,not string:" var
done

#判断是否猜中数字
while true
do
	if [ $num -eq $var ]
	then
		echo "     You guessed the number,Good!"
		echo "             Game ends!"
		break
	elif [ $num -ne $var ]
	then
		if [ $var -gt $num ]
		then
			echo "You number greater than!"
		elif [ $var -lt $num ]
		then
			echo "You number less than!"
		fi
		echo -n "Please input you number:";read var
	fi
	count=`expr $count + 1`
done

echo "You guessed $count times"
#评定成绩
#    [90-100]*) 90~100，注意要有 * 
case $count in
	[90-100]*)
		echo "You scores 1"
		;;
	[80-89]*)
		echo "You scores 2"
		;;
	[70-79]*)
		echo "You scores 3"
		;;
	[60-69]*)
		echo "You scores 4"
		;;
	[50-59]*)
		echo "You scores 5"
		;;
	[40-49]*)
		echo "You scores 6"
		;;
	[30-39]*)
		echo "You scores 7"
		;;
	[20-29]*)
		echo "You scores 8"
		;;
	[10-19]*)
		echo "You scores 9"
		;;
	[0-9]*)
		echo "You scores 10"
		;;
esac

# 另一种判断方法
# -a 	逻辑与
# -o	逻辑或
# !	逻辑非
if [ $count -gt 90 -a $count -lt 100 ]
then
	echo "You scores 1"
elif [ "$conut" -gt 80 -a "$counta" -lt 89 ]	# 有无""均可
then
	echo "YOu scores 2"
fi
	


