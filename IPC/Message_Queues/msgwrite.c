#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/msg.h>
#include <sys/ipc.h>
#include <stdlib.h>

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
    system("touch msg.txt");
    
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
    
    msg.msg_type = 1; // type 0 will return back with error :invalid argument
    while(fgets(msg.msg, sizeof(msg.msg), stdin) != NULL)
    {
        len = strlen(msg.msg);
        if(msg.msg[len - 1] == '\n')
        {
            msg.msg[len -1 ] = '\0';
        }
        if(msgsnd(msg_id, &msg, len+1, 0) == -1)
        {
            perror("msgsnd failed !!\n");
        }
        
        if(strcmp(msg.msg, "end") == 0)
        {
            break;
        }
    }
    return 0;
}
