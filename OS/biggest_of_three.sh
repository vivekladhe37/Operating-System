echo "Enter first number"
read x
echo "Enter second number"
read y
echo "Enter third number"
read z
if [ $x -gt $y ];then
   if [ $x -gt $z ];then
	echo "First Number is biggest"
   else
	 echo "Third Number is biggest"
   fi
else
  if [ $y -gt $z ];then
     echo "Second Number is biggest"
  else
     echo "Third number is biggest"
  fi
fi
  
