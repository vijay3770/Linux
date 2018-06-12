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
    
    fd = open("./fifo_twoway", O_RDWR);
    
    while(1)
    {
        fgets(input, sizeof(input), stdin);
        input[strlen(input) - 1] = '\0';
        
        if(strcmp(input, exit) == 0)
        {
            write(fd, input, strlen(input));
            close(fd);
            printf("Client: Bye Bye\n");
            break;
        }
        else
        {
            write(fd, input, strlen(input));
            
            printf("Client: rcvd-> %s\n", input);
            //sleep(1);
            
            count = read(fd, input, sizeof(input));
            input[count] = '\0';
            printf("Client: response-> %s\n", input);
        }
    }
    return 1;
}
