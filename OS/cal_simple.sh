echo "Enter First number"
read x
echo "Enter Second number"
read y
#let "sum= x + y"
#let "prod= x * y"
#let "div= x / y" 
#let "sub= x - y"
#echo "Sum is $sum"
#echo "Product is $prod"
#echo "Divison is $div"
#echo "Substractin is $sub"
echo "Division is:"
echo "scale=2;$x / $y" | bc
echo "product is:"
echo "scale=2;$x * $y" | bc
