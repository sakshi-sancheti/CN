#include <signal.h>
#include <unistd.h>
#include <stdio.h>
int x=1;

void hdn()
{

printf("p2 received the signal\n");
x=0;
}
int main()
{

signal(SIGUSR1,hdn);
printf("my pgid is : %d\n",getpgid(getpid()));
while(x);

}
