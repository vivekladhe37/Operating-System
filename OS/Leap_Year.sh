echo "Enter the year"
read x
if [ $(($x % 4)) -eq 0 ];then
  if [ $(($x % 100)) -eq 0 ];then
	  if [ $(($x % 400)) -eq 0 ];then
		  echo "Leap Year"
	  else
		  echo "Not Leap Year"
	  fi
  else
	  echo "Leap Year"
  fi
else
	echo "Not Leap Year"
fi
