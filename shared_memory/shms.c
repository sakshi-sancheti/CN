#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/shm.h>
#include <sys/ipc.h>

int main()
{
void * shared ;
char buff[100];
int id = shmget((key_t)12,1024,0666|IPC_CREAT);
shared = shmat(id,NULL,0);
printf("process attached at %p with key %d\n",shared,id);
 
 
 strcpy(shared,"hey there");
 


}
