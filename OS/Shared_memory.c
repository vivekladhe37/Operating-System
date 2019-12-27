#include<stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>


int main()
{
  key_t key=ftok("/home/shwetagote/shweta",1);
  int id=shmget(key,1024,IPC_CREAT|0666);
  int * buf=shmat(id,NULL,0);
  printf("Enter the integer");
  scanf("%d",buf);
  printf("U entered :%d",*buf);
  shmdt(buf);
  return 0;

}
