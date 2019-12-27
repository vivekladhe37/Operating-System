#include<stdio.h                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             
#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include<string.h>
void func1(int arg)
{
printf("We are handling signal :%d",arg);

}
int main()
{
  int i=0;
  struct sigaction sig_act;
  memset(&sig_act,0,sizeof(struct sigaction));
  sig_act.sa_handler=func1;
  sigaction(2,&sig_act,NULL);
  while(1)
  {
    sleep(1);
    printf("%d\n",i++);

  }


return 0;
}
