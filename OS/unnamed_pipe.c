#include<stdio.h>
#include <fcntl.h>              
#include <unistd.h>
#include<string.h>
int main()
{
  pid_t id;
  int fd[2];
  int ret=pipe(fd);
  if(ret < 0)
  {
   printf("Pipe failed");
  }
  id=fork();
  if(id==0)
  {
   char str1[20];
   close(fd[0]);
   printf("Enter your name");
   scanf("%s",str1);
   write(fd[1],str1,strlen(str1)+1);
   close(fd[1]);
  }
  else
  {
    close(fd[1]);
    char str1[10];
    read(fd[0],str1,sizeof(str1));
    printf("Pipe had:%s",str1);
    close(fd[0]);
  }
  return 0;
}
