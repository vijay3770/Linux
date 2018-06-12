#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

int main()
{
    int status;
    int fd;
    char exit[10] = "exit";
    char input[80];
    int count;
    
    status = mkfifo("./fifo_twoway", 0640);
    
    fd = open("./fifo_twoway", O_RDWR);
    
    while(1)
    {
        count = read(fd, input, sizeof(input));
        
        input[count] = '\0';
        
        printf("Server: rcvd(%d)-> %s\n",count, input);
        
        if(strcmp(input, exit) == 0)
        {
            close(fd);
            unlink("./fifo_twoway");
            printf("Server: Bye Bye\n");
            break;
        }
        else
        {
            sprintf(input, "%d", count);
            input[strlen(input)] = '\0';
            write(fd, input, strlen(input)+1);
            sleep(1);
        }
    }
    return 1;
}
