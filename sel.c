#include <stdio.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
fd_set readfd , writefd;
int fd[2];
struct timeval tv;

pipe(fd);

int pid = fork();

if(pid > 0 )
{

while(1)
{


FD_ZERO(&readfd);
FD_SET(STDIN_FILENO,&readfd);
FD_SET(fd[0],&readfd);
tv.tv_sec =8;
tv.tv_usec =0;


int a = select(FD_SETSIZE,&readfd,NULL,NULL,&tv);


if(!a) {printf("timeout\n");return 0;}

if(FD_ISSET(STDIN_FILENO,&readfd))
{

char msg[20];
read(STDIN_FILENO,msg,sizeof(msg));

printf("data from stdin : %s\n",msg);

}

if(FD_ISSET(fd[0],&readfd))
{

char msg[20];
read(fd[0],msg,sizeof(msg));

printf("data from pipe : %s\n",msg);

}
}


}

else
{
sleep(2);
close(fd[0]);
write(fd[1],"hey parent",sizeof("hey parent"));

sleep(1);

write(fd[1],"hey2.0 parent",sizeof("hey parent"));
close(fd[1]);
}

return 0;

}
