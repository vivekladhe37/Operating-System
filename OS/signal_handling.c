#include<stdio.h>
#include<signal.h>
#include<unistd.h>
void handler(int arg)
{

printf("We are handling signal no:%d",arg);

}
int main()
{
   int i=0;
   printf("My Process Id%d\n",getpid());
   signal(2,handler);
   while(1)
   {
     printf("%d\n",i++);
     sleep(1);
   }
   return 0;
}
