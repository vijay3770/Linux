#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void sigal_handle(int signum)
{
    printf("Inside the signal handle of %d", signum);
}

int main()
{
    printf("Open new terminal and issue the following command\n");
    printf("kill -SIGINT %d\n", getpid());
    
    signal(SIGINT, sigal_handle);
    while(1)
    {
        
    }
    return 0;
}
