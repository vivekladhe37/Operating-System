#include<stdio.h>
#include <fcntl.h>              /* Obtain O_* constant definitions */
#include <unistd.h>
#include <string.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/wait.h>
int main()
{
 int ret=mkfifo("mypipe",O_CREAT | 0666);
 if(ret < 0)
 {
  printf("Pipe failed\n");
  return -1;
 }
 char buf[10];
 int *PRN_pt,*phone_no_pt;
 int PRN,phone_no;
 printf("Enter Your name:\n");
 scanf("%s",buf);

 printf("Enter Your PRN NO:\n");
 scanf("%d",&PRN);
 PRN_pt=&PRN;
 printf("Enter Your name:\n");
 scanf("%d",&phone_no);
 phone_no_pt=&phone_no;
 int fd=open("mypipe",O_WRONLY);
 write(fd,buf,strlen(buf)+1);
 write(fd,PRN_pt,sizeof(PRN));
 write(fd,phone_no_pt,sizeof(phone_no));
 close(fd);
 return 0;
}
