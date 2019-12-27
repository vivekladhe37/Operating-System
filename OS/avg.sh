echo "Enter three numbers"
read x
read y
read z
echo "scale=2;($x + $y + $z)/3" | bc
#echo "Average of three numbers is:$avg"
