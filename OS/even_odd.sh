echo "Enter number:"
read x
if [ $(($x % 2)) -eq 0 ];then
	echo "Even number"
else
	echo "Odd number"
fi
