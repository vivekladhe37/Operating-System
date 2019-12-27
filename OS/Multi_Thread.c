#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<stdlib.h>
int count=10;
void * func1(void * arg)
{
  printf("In Func1 Incrementing value:\n");
 // sleep(1);
  count++;
  printf("Incremented Value %d:\n",count);
  return NULL;
}
void * func2(void * arg)
{
  printf("In Func2 decrementing value:\n");
  int * sum=malloc(sizeof(int));
  sum=(int *)arg;
  //sleep(1);
  count--;
  printf("decremented Value %d:\n",count);
  pthread_exit(sum);
}
int main()
{
  pthread_t id[2];
  int *sum=malloc(sizeof(int));
  int r2=10;
  pthread_create(&id[0],NULL,func1,NULL);
  pthread_create(&id[1],NULL,func2,&r2);
  pthread_join(id[0],NULL); 
  pthread_join(id[1],(void **)&sum); 
  printf("Return value is:%d",*sum);
  return 0;
}
