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

void reverse_str(char* str)
{
    int len = strlen(str);
    char temp;
    
    for(int i = 0; i < len/2; i++)
    {
        printf("Readfor:%d, %c, %c\n",i, str[i], str[len -1 -i]);
        temp = str[len -1 -i];
        str[len - 1 -i] = str[i];
        str[i] = temp;
    }
}

int main()
{
    int shmid;
    shm_command* shmaddr;
    char* cmd[10];
    printf("Read: Get shared memory\n");
    shmid = shmget(SHM_KEY, sizeof(shm_command), 0644|IPC_CREAT);
    if(shmid < 0)
    {
        printf("Fail to get the shared memeory");
    }
    
    printf("Read: Attach shared memory to address space\n");
    shmaddr = (shm_command*)shmat(shmid, NULL, 0);
    
    printf("Read: wait for the command from write process\n");
    while(shmaddr->valid == 0);
    

    if(shmaddr->cmd == 1)
    {
        printf("CMD 1:%s\n", shmaddr->data);
    }
    else if(shmaddr->cmd == 2)
    {
        reverse_str(shmaddr->data);
        printf("CMD 2:%s\n",shmaddr->data);
    }
    else
    {
        printf("CMD %d not supported\n", shmaddr->cmd);
    }
    shmaddr->valid = 0;
    
    printf("Read: detach shared memory\n");
    shmdt(shmaddr);
    return 0;
}
