#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(int argc,char *argv[])
{
int fd[3][2],status;

for(int i=0;i<3;i++)
{
pipe(fd[i]);
}

int c=fork(); //p1
if(c==0)
{
close(fd[0][0]);
dup2(fd[0][1],STDOUT_FILENO);
execlp(argv[1],argv[1],NULL);

 
}

c=fork(); //p2
if(c==0)
{
dup2(fd[0][0],STDIN_FILENO);
dup2(fd[1][1],STDOUT_FILENO);
execlp(argv[2],argv[2],NULL);


}

c=fork(); //p3
if(c==0)
{
dup2(fd[1][0],STDIN_FILENO);
dup2(fd[2][1],STDOUT_FILENO);
execlp(argv[3],argv[3],NULL);
}

c=fork(); //p4
if(c==0)
{
close(fd[2][1]);
dup2(fd[2][0],STDIN_FILENO);
execlp(argv[4],argv[4],NULL);


}
for(int i=0;i<3;i++)
{close(fd[i][0]);
close(fd[i][1]);
}


waitpid(-1,&status,0);
waitpid(-1,&status,0);
waitpid(-1,&status,0);
waitpid(-1,&status,0);

}
