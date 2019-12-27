#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<stdlib.h>
int count=10;
pthread_mutex_t lock;
int * sum;

void * func1(void * arg)
{
  pthread_mutex_lock(&lock);
  printf("In Func1 Incrementing value:\n");
  count++;
  printf("Incremented Value %d:\n",count);
  printf("Accesing the sum:");
  *sum=20;
  pthread_mutex_unlock(&lock);
  return NULL;
}
void * func2(void * arg)
{
  pthread_mutex_lock(&lock);
  printf("In Func2 decrementing value:\n");
  sleep(5);
 // int * sum=malloc(sizeof(int));
  sum=(int *)arg;
  count--;
  printf("decremented Value %d:\n",count);
  printf("After Pthread Exit");
  pthread_mutex_unlock(&lock);
  printf("After Pthread Ulock\n");
  sleep(1);
  pthread_exit(sum);
}
int main()
{
  pthread_t id[2];
  pthread_mutex_init(&lock,NULL);
  int *sum=malloc(sizeof(int));
  int r2=10;
  pthread_create(&id[0],NULL,func1,NULL);
  pthread_create(&id[1],NULL,func2,&r2);
  pthread_join(id[0],NULL); 
  pthread_join(id[1],(void **)&sum); 
  printf("Return value is:%d",*sum);
  pthread_mutex_destroy(&lock);
  return 0;
}
