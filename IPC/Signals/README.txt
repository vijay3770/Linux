Signals are used in asynchronous communications. They are called the software interrupts.

They work like a interrupts with in each process.

Signals can be handled in three different ways
    1. Execute default handler, will be in handled by kernel.
    2. Execute user defined handle.
    3. Mask the signal. this will ignore the signal handling.

The signal can be either blocked or ignored. On ignoring the signal will not save the pending state of the signal. block will save the pending sate of the signal and on unblock the signal is handled if pending and the control is handled to the process.


API's used:
1.sighandler_t signal(int signum, sighandler_t handler);
    signum:     Signal number
    handler:    SIG_IGN-> will ignore the provided signal
                SIG_DFL-> will use the default handler
                user defined handler
This API is used to manipulate the signal behavior.

2. int sigprocmask(int how, const sigset_t *restrict set, sigset_t *restrict oset);
    changes the current signal mask. Signals are blocked if they are members of the current signal mask set.
    how:   SIG_BLOCK    set will have the list of signals to be blocked
           SIG_UNBLOCK  set will have the list of signals to be unblocked
           SIG_SETMASK  current set will replace the previous blocked list, if not current signals will be                       appended to the existing list.
    if oset is not null on return it contain all the signals that are SIG_BLOCK

3. sigset_t set; can be operated through the following API's
        sigemptyset(&set); -> will reset the set to zeros.
        sigaddset(&set, signum) -> will add the signum to set.
        sigfillset(&set);   -> will fill set with all the signals.


Note: SIGKILL (9) and SIGSTOP (19) operation is always default handler execution. these signals can be blocked or ignored or change the default handler.
