#include<stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/types.h>
#include <sys/ipc.h>
struct message
{
  long id;
  char str[30];

};
int main()
{
 key_t key=ftok("/home/shwetagote/shweta",123);
 struct message msg;
 int mqid=msgget(key,IPC_CREAT | 0666);

 printf("Enter the message that you wants to send \n");
 scanf("%s",msg.str);
 msg.id=1;
 msgsnd(mqid,&msg,sizeof(msg),0);
 return 0;
}
