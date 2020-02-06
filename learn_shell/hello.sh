#! /bin/bash

# chmod +x ./hello.sh
# ./hello.sh

for skill in Ada Coffe Action Java;
do
    echo "I am good at ${skill}Script"
done

# get the length of an array
# length=${#array_name[@]}
# length=${#array_name[*]}
# get the length of an element from an array
# lengthn=${#array_name[n]}

a=10
b=20
val=`expr $a + $b`
echo "a + b : $val"
val=`expr $a \* $b`
echo "a * b : $val"
if [ $a != $b ]
then
   echo "a is not equal to b"
fi
if [ $a -lt 100 -a $b -gt 15 ]
then
   echo "$a is less than 100 and $b is greater than 15 : return true"
else
   echo "$a is less than 100 and $b is greater than 15 : return false"
fi
if [ $a -lt 100 -o $b -gt 100 ]
then
   echo "$a is less than 100 or $b is greater than 100 : return true"
else
   echo "$a is less than 100 or $b is greater than 100 : return false"
fi

# read name 
# echo "$name. It is a test"

echo -e "OK! \n" # -e Escape character

echo `date` # `[command]`

printf "%-10s %-8s %-4s\n" 姓名 性别 体重kg
printf "%-10s %-8s %-4.2f\n" 郭靖 男 66.1234

int=1
while(( $int<=5 ))
do
    echo $int
    let "int++"
done

a=0
# until [ $a -gt 9 ]
until [ ! $a -le 9 ]
do
   echo $a
   a=`expr $a + 1`
done

site="runoob"
case "$site" in
   "runoob") echo "菜鸟教程"
   ;;
   "google") echo "Google 搜索"
   ;;
   "taobao") echo "淘宝网"
   ;;
esac

# command > /dev/null # screen output

# use . to refer to test.sh
. ./test.sh
# or use source
# source ./test.sh
echo $test