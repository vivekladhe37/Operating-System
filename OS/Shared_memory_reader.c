#include<stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main()
{
 key_t key=ftok("/home/shwetagote/shweta",1);
 int id=shmget(key,1024,0666);
 int * buf=shmat(id,NULL,0);
 printf("Shared Memory has %d: ",*buf);
 shmdt(buf);
 shmctl(id,IPC_RMID,NULL);
 return 0;
}
