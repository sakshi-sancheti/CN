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

int main()
{
mkfifo("myfifo",0666);
int i;
printf("my pid is %d\n",getpid());
int fd=open("myfifo",O_RDONLY);
printf("reading fifo\n");
read(fd,&i,sizeof(int));
printf("pid of p1 :%d\n",i);

close(fd);

fd = open("myfifo",O_WRONLY);
printf("writing to fifo\n");
i = getpid();
write(fd,&i,sizeof(int));
close(fd);





}
