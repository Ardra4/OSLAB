#include <stdio.h>
#include <sys/shm.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
int main()
{
char str[100];
int shmid=shmget((key_t)2366,1024,0666|IPC_CREAT);
printf("Key of shared memory is %d\n", shmid);
void *shm=shmat(shmid,NULL,0);
printf("Process is attached at %p \n", shm);
printf("Enter data: ");
scanf("%s", str);
strcpy(shm,str);
printf("\nValue written by writer process: %s\n", (char*)shm);
}
