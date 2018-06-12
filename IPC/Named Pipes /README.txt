Named Pipes also known as FIFO's are used for communication between two unrelated processes.

1. These pipes will exist even after the process created them is closed.
2. These pipes can be referenced similar to the regular files.
3. These FIFO special files are created using 
	int mkfifo(const char *pathname, mode_t mode);
	pathname -> path were the special file will be created
	mode -> permissions
5. Since FIFO are like regular files all operations that can be performed on files can be performed on FIFO's like open, read, write, close.
6. Once the fifo is created any processes can use it for reading or writing.
7. Two way communications can be done on the same FIFO file.


Note: The processes communicating on FIFO's should have them opened on both sides otherwise the read & writes will not work.



In this example two unrelated processes server and client will communicate with each other using FIFO's

Server:
1. Create the FIFO file and open it.
2. read for the commands from the client process.
3. process the command and write the response back to the client by writing into the same fifo.
4. When the exit command is received, FIFO is closed, removed and process is terminated.

Client:
1. Open the FIFO file.
2. Take the input from the user.
3. write the input in to the FIFO for the server to read.
4. read the response from the FIFO sent by the server.
5. If the user enters exit. FIFO is closed and process will terminate.

commands:
when ever anything other than exit is sent the server will send back the size of the string.
