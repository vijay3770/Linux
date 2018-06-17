#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void signal_handle(int signum)
{
    printf("Inside the signal handle of %d\n", signum);
}


int main()
{
	void (*sigHandlerReturn)(int);
    printf("Open new terminal and issue the following command\n");
    printf("kill -SIGINT %d or hit ctl+c on the process running terminal\n", getpid());

	sigHandlerReturn = signal(SIGINT, signal_handle);

	if(sigHandlerReturn < 0)
	{
		perror("signal Error");
		return -1;
	}

    while(1)
    {
        
    }
    return 0;
}