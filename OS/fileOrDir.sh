for i in /home/dac/Desktop/*
do
   if [ -f $i ]
   then
	   echo "$i is a file"
   elif [ -d $i ]
   then
	   echo "$i is a dir"
   else
	   echo "Neither file or director"
   fi
done
