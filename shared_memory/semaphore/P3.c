#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdlib.h>
#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>

sem_t s23,s34;

int main()
{

key_t key = ftok(".",67);
key_t key2 = ftok(".",68);

int id1 = shmget(key,sizeof(int),0666|IPC_CREAT);
int id2 = shmget (key2,sizeof(int),0666|IPC_CREAT);
sem_t  * p = (sem_t *) shmat(id1,NULL,0);
*p = s23;
sem_t *p2 = (sem_t *) shmat(id2,NULL,0);
*p2 = s34;

sem_init(p,1, 0);
sem_init(p2,1,0);


printf("I am P3. I am waiting for Semaphore S23\n");
sem_wait(p);
printf("I got semaphore S23 signalling from P2\n");
printf("enter any character to sem_signal s34\n");
char ch;
scanf("%c",&ch);
printf("I am signalling semaphore signal of S34\n");
sem_post(p2);
}

