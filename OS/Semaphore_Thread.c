#include<stdio.h>
#include<pthread.h>
#include <semaphore.h>
#include<unistd.h>
sem_t mutex;
int count=10;
void* func1(void * arg)
{
  sem_wait(&mutex);
  printf("I am in func1 Incrementing the value\n");
  count++;
  printf("Incremented value%d\n",count);
  sem_post(&mutex);
  return NULL;
}	
void* func2(void * arg)
{
  sem_wait(&mutex);
  printf("I am in func2 decrementing the value\n");
  sleep(1);
  count--;
  printf("decremented value%d\n",count);
  sem_post(&mutex);
  return NULL;
}
int main()
{
  pthread_t tid[2];
  sem_init(&mutex,0,1);
  pthread_create(&tid[0],NULL,func1,NULL);
  pthread_create(&tid[1],NULL,func2,NULL);
  pthread_join(tid[0],NULL);
  pthread_join(tid[1],NULL);
  sem_destroy(&mutex);
  return 0;
}
