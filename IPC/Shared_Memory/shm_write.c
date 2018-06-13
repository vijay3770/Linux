#include <stdio.h>
#include <unistd.h>
#include <sys/shm.h>
#include <string.h>
#define SHM_KEY (123456)

typedef struct shm_command{
    int valid;
    int cmd;
    char data[512];
}shm_command;

int main()
{
    int shmid;
    shm_command* shmaddr;
    char* cmd[10];
    
    printf("Write: Get shared memory\n");
    shmid = shmget(SHM_KEY, sizeof(shm_command), 0644|IPC_CREAT);
    if(shmid < 0)
    {
        printf("Fail to get the shared memeory");
    }
    
    printf("Write: attach shared memory to address space\n");
    shmaddr = (shm_command*)shmat(shmid, NULL, 0);
    shmaddr->valid = 0;
    printf("please enter \n1 to display msg on read process, \n2 to display inverted msg on the read proces\n");
    scanf("%d",&shmaddr->cmd);
    while ((getchar()) != '\n');
    
    printf("enter the data:");
    fgets(shmaddr->data, 512, stdin);
    shmaddr->data[strlen(shmaddr->data) -1] = '\0';
    shmaddr->valid = 1;
    sleep(1);
    
    printf("Write: detach shared memory\n");
    shmdt(shmaddr);
    return 0;
}
