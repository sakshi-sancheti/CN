#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>


int main()
{
int c = fork();

if(c==0)
{
printf("before dup2\n");
int file = open("sample.txt", O_WRONLY);
int temp =dup(STDOUT_FILENO);
dup2(file,STDOUT_FILENO);
write(temp,"hey there",sizeof("hey there"));

execlp("ping","ping","-c","1","google.com",NULL);


}
else
{
printf("parent process\n");

}

}




