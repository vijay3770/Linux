Message Queues are used for inter process comunications between different processes.


In This example the following API are used:
1. int msgget(key_t key, int msgflag);
	Key	-> a unique key is needed to identify the message queue.
	magflags->IPC_CREAT, IPC_EXCL
	returns message ID, used my other API's to access the queue.

2. int msgsnd(int msgid, const void *msgp, size_t msgsz, int msgflg)
	msgid 	-> id returned my msgget
	msgp	-> Pionter to the msg. First word is used for type.
	msgsz	-> size of the msg.
	msgflg  -> flags.
3. int msgrcv(int msgid, constvoid *msgp, size_t msgsz, long msgtype, int msgflgs);
4. int msgctrl(int msgid, int cmd, strcut msgid_ds *buf);
	
In this example there are two processes(msgwrite, msgread)

msgwrite:
1. Will take the input from the user and write it on to the queue.
msgread:
1. Will read the msg on the queue and display the msg. when the end string is sent the process will terminate.
