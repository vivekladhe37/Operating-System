#include<stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include<stdlib.h>

int main()
{
  pid_t id[5];
  int i;
  for(i=0;i<3;i++)
  {
     id[i]=fork();
     if(id[i] == 0)
     {
       //sleep(20);
       printf("I am Child %d\n",i+1);
       printf("My PID = %d\n",getpid());
       printf("My Parents's PID %d\n",getppid());
       printf("My Fork returned value%d\n",id[i]);
       break;
     }
     else
     {
      // sleep(5);
       printf("I am Parent %d\n",i+1);
       printf("My Fork Returned value %d\n",id[i]);
     }
  
  }
  for(i=0;i< 3;i++)
  {
     if(id[i]==0)
     {
         printf("My Fork returned value%d\n",id[i]);
	 break;

     }
     else
     {
       printf("My Fork returned value%d\n",id[i]);
       int status=0;
       wait(&status);
       if(WIFEXITED(status))
       {
         printf("Child Exited Normally\n");
       }
       else
       {
         printf("Child Has been killed %d\n",WEXITSTATUS(status));
       }
       if(WIFSIGNALED(status))
       {
        printf("Child has killed due to signal %d\n",WTERMSIG(status));

       }
    }
  }
}
