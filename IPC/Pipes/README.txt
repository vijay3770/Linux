
Pipes are used to establish communication channel between to related processes.

The following system calls are used in this example

1.int pipe(int pipedes[2]);
  pipe is a system call used to create pipes which are noting but a special files.
  The system call would return with the 2 file descriptors as mentioned below.
  pipedes[0] —> will hold read pipe.
  pipedes[1] —> will hold write pipe.
2.read, write APIs can be used to read and write on to the pipes.
3. Pipes are one way communication only.
4. If the processes tries to read before something is written on the pipe, the 	  process will be in blocked state until data is available.


In this example, 

1. The parent process will get the input from the keyboard(STDIN) and 
2. Will send the received string to the child process through the pipe.
3. Child process will read the string and display it on the the screen(STDOUT).
4. When the user sends exit string parent process if sent it to child process and 	  wait for it to exit and parent will also exit.

I have two pipes used to communicate between two related processes(Parent/child).

