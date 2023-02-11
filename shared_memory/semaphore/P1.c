#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdlib.h>
#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>


sem_t s41,s12;

int main()
{

key_t key = ftok(".",65);
key_t key2 = ftok(".",66);

int id1 = shmget(key,sizeof(int),0666|IPC_CREAT);
int id2 = shmget (key2,sizeof(int),0666|IPC_CREAT);


sem_t  * p = shmat(id1,NULL,0);
*p = s12;
sem_t * p2 = shmat(id2,NULL,0);
*p2 = s41;

sem_init(p,1, 0);
sem_init(p2,1,0);


printf("i am p1\nenter any character to sem_signal s12\n");
char ch;
scanf("%c",&ch);
printf("I am signalling semaphore signal of S12\n");
sem_post(p);
printf("I am waiting for semaphore S41\n");
sem_wait(p2);
printf("I got semaphore signalling from P4\n");

}

