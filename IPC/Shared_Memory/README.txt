Shared memory will let the two processes communicate with each other my mapping a shared memroy on to their address space

API's:

int shmget(key_t key, size_t size, int shmflags);
	key 	-> unique number used to identify the shared memory
	size	-> size of the shared memory. sould be multiples of page size.
	shmflags-> IPC_CREAT, IPC_EXCL
	
	Returns the shmid(used by other API's), -1 on failure.

void* shmat(int shmid, const void* shmaddr, int shmflg);
	shmid 	-> The id returned my shmget
	shmaddr	-> to specify the attaching address. if NULL syscall will choses sutable address to attach.
	shmflags-> shared memory flags.

	Returns the address of the shared memory, -1 on failure.

int shmdt(const void* shmaddr)
	shmaddr -> this is the address returned by shmat.

	Returns 0 if success else -1 on failure.

int shmctl(int shmid, int cmd, struct shmid_ds *buf);


Example:
1. Two unrelated processes will share a memory in which one process shm_write will write into shared memory and shm_read will read the data out of the shared memory.

