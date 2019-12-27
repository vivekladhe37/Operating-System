#include<stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
struct message
{
  long id;
  char str[30];
}m;
int main()
{
 key_t key=ftok("/home/shwetagote/shweta",123);
 
 int mqid=msgget(key,IPC_CREAT | 0666);
// msg->id=1;
 msgrcv(mqid,&m,sizeof( m),1,0);
 printf("Message Recived:%s\n",m.str);
 msgctl(mqid,IPC_RMID,NULL);
 return 0;
}
