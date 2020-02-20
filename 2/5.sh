#/bin/bash
mkdir $1
cd $1
# {a..z},{0..9}是省略写法，{0..9..2} 步长是 2
for i in {a..z}
do
	mkdir $i
done
for i in {a..z}
do
	cd $i
	for j in {0..9}
	do
		touch $j
	done
	cd ..
done

# seq 命令
for i in `seq 0 3 30`
do
	echo $i
done

echo $(ls)  #结果同下
echo `ls`   #结果同上
