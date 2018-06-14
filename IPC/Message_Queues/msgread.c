#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/msg.h>
#include <sys/ipc.h>


typedef struct msgqueue_str
{
    long msg_type;/* message type, must be > 0 */
    char msg[250];
}msgqueue;

int main()
{
    msgqueue msg;
    int key;
    int status;
    int msg_id;
    int len;
    
    key = ftok("msg.txt", 'A');
    if(key < 0)
    {
        perror("Fial to get key!!\n");
        return -1;
    }
    
    msg_id = msgget( key, 0644| IPC_CREAT );
    if(msg_id < 0)
    {
        perror("Fail to get the msgqueue!!\n");
        return -1;
    }
    
    while(1)
    {
        if(msgrcv(msg_id, &msg, sizeof(msg.msg), 0, 0) == -1)
        {
            perror("rcv: msgrcv failed!!\n");
            return -1;
        }
        
        printf("rcved: \" %s \" \n", msg.msg);
        
        if(strcmp(msg.msg, "end") == 0)
        {
            break;
        }
    }
    return 0;
}
