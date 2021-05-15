// #include <apue.h>
// #include <time.h>

// static void
// sig_alrm(int signo)
// {
//   printf("alrm\n");
// 	/* nothing to do, just returning wakes up sigsuspend() */
// }

// unsigned int
// sleep2(unsigned int seconds)
// {
// 	struct sigaction	newact, oldact;
// 	sigset_t			newmask, oldmask, suspmask;
// 	unsigned int		unslept;

// 	/* set our handler, save previous information */
// 	newact.sa_handler = sig_alrm;
// 	sigemptyset(&newact.sa_mask);
// 	newact.sa_flags = 0;
// 	sigaction(SIGALRM, &newact, &oldact);

// 	/* block SIGALRM and save current signal mask */
// 	sigemptyset(&newmask);
// 	sigaddset(&newmask, SIGALRM);
// 	sigprocmask(SIG_BLOCK, &newmask, &oldmask);

// 	alarm(seconds);
// 	suspmask = oldmask;

// 	/* make sure SIGALRM isn't blocked */
// 	sigdelset(&suspmask, SIGALRM);

// 	/* wait for any signal to be caught */
// 	sigsuspend(&suspmask);

// 	/* some signal has been caught, SIGALRM is now blocked */

// 	unslept = alarm(0);

// 	/* reset previous action */
// 	sigaction(SIGALRM, &oldact, NULL);

// 	/* reset signal mask, which unblocks SIGALRM */
// 	sigprocmask(SIG_SETMASK, &oldmask, NULL);
// 	return(unslept);
// }

// int main()
// {
//   struct timespec requested;
//   struct timespec remaining;

//   requested.tv_sec = 5;
//   // requested.tv_nsec = 0;
//   int ret = nanosleep(&requested, &remaining);
//   printf("%d\n", ret);
//   return 0;
// }