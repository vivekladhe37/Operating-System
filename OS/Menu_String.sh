i="y"



while [ $i = "y" ]
do
clear
echo "******MENU******"
echo "1.Lenghth of string"
echo "2.Copy String"
echo "3.Concatenate String"
echo "4.Comapre"
echo "5.Reverse"
echo "Enter Your Choice"
read ch
case $ch in
1) echo "Enter String:"
   read x
   t=`echo $x|wc -c`
   l=`expr $t - 1`
   echo "length of string:$l"
   ;;
2) echo "Enter String for Copy"
   read y
   s=$y
   echo "Copied String is:$s"
   ;;
3) echo "3.Concaten String"
   echo "Enter String to conactenate"
   read r
   s="shweta"
   p=$s$r
   echo "Concatened String is:$p"
   ;;
4) echo "Enter First String:"
   read x
   echo "Enter Second String:"
   read y
   if [ $x == $y ];then
	 echo "Strings are equal"
   else
	 echo "Not Equal"
   fi
   ;;

5) echo "Enter String To reverse"
   read x
   echo $x | rev 
   ;;
esac
echo "Do you want to continue?"
read i
if [ $i != "y" ];then
	exit
fi
done


