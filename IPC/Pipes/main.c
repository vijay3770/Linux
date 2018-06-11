#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    int pipefd[2];
    int status;
    int pid;
    char eixt_command[] = "exit\n";
    status = pipe(pipefd);
    
    if(status < 0)
    {
        printf("Fail to create the pipe\n");
        return -1;
    }
    
    pid = fork();
    
    if(pid < 0)
    {
        printf("Fail to create the child process!!\n");
        return -1;
    }
    else if(pid == 0)
    {
        printf("Child Process\n");
        /*This is child process*/
        char stdo[80];
        
        /*Child process do not need wirte pipe, so lets close it*/
        close(pipefd[1]);
        
        while(1)
        {
            /*Get the data from the pipe*/
            read(pipefd[0], stdo, 80);
            
            printf("child: %s", stdo);
            if(strcmp(stdo, eixt_command) == 0)
            {
                printf("Child: Bye Bye \n");
                break;
            }
        }
    }
    else
    {
        printf("Parent rocess \n");
        sleep(1);
        /*This is parent process*/
        char stdi[80];
        
        /*Parent do not need read pipe, so lets close it*/
        close(pipefd[0]);
        
        while(1)
        {
            /*Get the data from the keyboard*/
            fgets(stdi, 80, stdin);
            printf("Parent: %s", stdi);
            /*send the recied data to the child process*/
            write(pipefd[1], stdi, strlen(stdi)+1);
            
            if(strcmp(stdi, eixt_command) == 0)
            {
                printf("Paren waiting for child to exit\n");
                wait(NULL);
                printf("Parent: Bye Bye \n");
                break;
            }
        }
        
    }
    
    return 0;
}
