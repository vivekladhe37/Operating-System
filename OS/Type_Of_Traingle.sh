if [ $# -lt 3 ];then
   echo "Please Enter Three sides"
elif [[ $1 -eq $2 && $2 -eq $3 && $3 -eq $1 ]];then
   echo "Equilateral Traingle"
elif [[ $1 -eq $2 || $2 -eq $3 || $3 -eq $4 ]];then
   echo "Iscoscleles Traingle"
else
   echo "Scalen Traingle"
fi

