#include<stdio.h>
#include <fcntl.h>              
#include <unistd.h>
#include<string.h>

int main()
{
  pid_t id;
  int fd[2];
  int ret=mkfifo("mypipe",O_CREAT | 0666);
  if(ret < 0)
  {
   printf("Pipe failed\n May be Pipe already Exits");
   return -1;
  }
  id=fork();
  if(id > 0)
  {
   char str1[20];
   int fd=open("mypipe",O_WRONLY);
   printf("Enter your name");
   scanf("%s",str1);
   write(fd,str1,strlen(str1)+1);
   close(fd);
  }
  else
  {
    
    char str1[10];
    int fd=open("mypipe",O_RDONLY);
    read(fd,str1,sizeof(str1));
    printf("Pipe had:%s",str1);
    close(fd);
  }
  return 0;
}
