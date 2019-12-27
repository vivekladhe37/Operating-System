echo "first number"
read x

echo "second number"
read y

sum=`expr $x + $y`
echo "sum is:$sum"
let sum=x+y;
echo "sum is:$sum"

prod=`expr $x \* $y`
echo "prod is: $prod"

echo "div is"

echo "scale=2;$x / $y" | bc
