#/bin/bash
#找出名字为 a~z 的文件夹
for i in $(ls)
do
	#方法一
#	if [ -d $i ] 
#	then
#		if echo $i | grep -wq '[a-z]'
#		then
#			echo -n "     $i"
#		fi
#	fi
	#方法二
	if echo $i | grep -wq '[a-z]' && [ -d $i ]
	then
		echo -n "     $i"
	fi
done
