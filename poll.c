#include <stdio.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include <poll.h>
#include <string.h>


int main()
{
int cnt=0;


struct pollfd mypoll;
memset(&mypoll,0,sizeof(mypoll));
mypoll.fd = 0 ;
mypoll.events = POLLIN;


printf("type your name : ");
while(1)

{

if(poll(&mypoll,1,100)==1)
{
char name [20];
read(0,name,20);
printf("\nhi %s\n", name);
break;
}
else
{
cnt++;
}

}

printf("it took you %d ms to type your name.\n",cnt);

}
