#include <signal.h>
#include <unistd.h>
#include <stdio.h>
void hdn()
{
printf("signal sent to grp\n");
}
int main()
{

int pid = getpid();

setpgid(pid,pid);
printf("process grp : %d\n",getpgid(getpid()));
printf("pid %d\n",pid);
int c =fork();
if(c==0)
{
execl("p1","p1",NULL);
}
c=fork();
if(c==0)
{
execl("p2","p2",NULL);
}
signal(SIGUSR1,hdn);
sleep(5);
killpg(pid,SIGUSR1);

}
