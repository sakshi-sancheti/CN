#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/msg.h>
#include <sys/ipc.h>


struct node 
{
long int type;
char msg[50]
};
int main()
{

int id;
struct node q1;
id = msgget((key_t)1234,0666 | IPC_CREAT);
char buff[20];
while(1)
{printf("enter some text:\n");
fget(buff,20,stdin);
q1.type=1;
strcpy(q1.msg, buffer);
msgsnd(id, (void *)&q1 ,50,0);
if(strcmp(buff,"end",3)==0) break;
}
return 0;

}


