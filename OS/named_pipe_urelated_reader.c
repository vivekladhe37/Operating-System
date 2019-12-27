#include<stdio.h>
#include <fcntl.h>              /* Obtain O_* constant definitions */
#include <unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<sys/stat.h>
int main()
{

 char str1[10];
 int *no_pt,*phone_pt;
 int no,phone;
 no_pt=&no;
 phone_pt=&phone;
 int fd=open("mypipe",O_RDONLY);
 read(fd,str1,sizeof(str1));
 read(fd,&no,sizeof(no));
 read(fd,&phone,sizeof(phone));
 printf("Pipe had:%s\n",str1);
 printf("Pipe had:%d\n",*no_pt);
 printf("Pipe had:%d\n",*phone_pt);
 close(fd);
 return 0;
}
