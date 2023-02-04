#include<stdlib.h>
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<string.h>
#include<signal.h>
#include<sys/ipc.h>
#include<sys/shm.h>
int pid;
int main()
{
printf("my pid is %d\n",getpid());
mkfifo("myfifo",0666);

int i = getpid();
int fd = open("myfifo",O_WRONLY);
printf("writing to fifo\n");
write(fd,&i,sizeof(int));
close(fd);


fd=open("myfifo",O_RDONLY);
printf("reading fifo\n");
read(fd, &i,sizeof(int));
printf("pid of p2 :%d\n",i);

close(fd);



}
