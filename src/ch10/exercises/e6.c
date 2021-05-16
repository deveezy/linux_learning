// #include <unistd.h>
// #include <signal.h>
// #include <stdio.h>
// #include <stdlib.h>

// #define NUM_ITERATIONS 100

// static volatile sig_atomic_t sigflag; /* set nonzero by sig handler */
// static sigset_t newmask, oldmask, zeromask;

// static void
// sig_usr(int signo)  /* one signal handler for SIGUSR1 and SIGUSR2 */
// {
// 	sigflag = 1;
// }

// static void
// TELL_WAIT(void)
// {
// 	if (signal(SIGUSR1, sig_usr) == SIG_ERR)
// 		perror("signal(SIGUSR1) error");

// 	if (signal(SIGUSR2, sig_usr) == SIG_ERR)
// 		perror("signal(SIGUSR2) error");

// 	sigemptyset(&zeromask);
// 	sigemptyset(&newmask);
// 	sigaddset(&newmask, SIGUSR1);
// 	sigaddset(&newmask, SIGUSR2);

// 	/* Block SIGUSR1 and SIGUSR2, and save current signal mask */
// 	if (sigprocmask(SIG_BLOCK, &newmask, &oldmask) < 0)
// 		perror("SIG_BLOCK error");
// }

// static void
// TELL_PARENT(void)
// {
// 	kill(getppid(), SIGUSR2); /* tell parent we’re done */
// }

// static void
// TELL_CHILD(pid_t pid)
// {
//     kill(pid, SIGUSR1); /* tell child we’re done */
// }

// static void
// WAIT_PARENT(void)
// {
// 	while (sigflag == 0)
// 		sigsuspend(&zeromask);  /* and wait for parent */
// 	sigflag = 0;
// 	/* Reset signal mask to original value */
// 	if (sigprocmask(SIG_SETMASK, &oldmask, NULL) < 0)
// 		perror("SIG_SETMASK error");
// }

// static void
// WAIT_CHILD(void)
// {
// 	while (sigflag == 0)
// 		sigsuspend(&zeromask);  /* and wait for child */
// 	sigflag = 0;
// 	/* Reset signal mask to original value */
// 	if (sigprocmask(SIG_SETMASK, &oldmask, NULL) < 0)
// 		perror("SIG_SETMASK error");
// }

// static int increment_value(FILE* const file)
// {
//   sleep(1);
//   int value = 0;
//   fseek(file, 0, SEEK_SET);
//   fread(&value, sizeof(value), 1, file);

//   ++value;
  
//   fseek(file, 0, SEEK_SET);
//   fwrite(&value, sizeof(value), 1, file);
//   fflush(file);
  
//   return value;
// }

// int main(int argc, char** argv)
// {
//   FILE* const file = fopen("temp", "w+");
//   if (!file) 
//   {
//     perror("fopen");
//     return 1;
//   }

//   TELL_WAIT(); // block usr1 and usr2 signals

//   int i;
//   pid_t pid = fork();

//   if (pid < 0) 
//   {
//     perror("fork");
//     return 1;
//   }

//   if (pid == 0) // child
//   {
//     for (i = 0; i < NUM_ITERATIONS; ++i)
//     {
//       printf(" child incrementing, value: %3d\n", increment_value(file));
//       TELL_PARENT();
//       WAIT_PARENT();
//     }
    
//   }
//   else  // parent
//   {
//     for (i = 0; i < NUM_ITERATIONS; ++i) 
//     {
//       WAIT_CHILD();
// 			printf("parent incrementing, value: %3d\n", increment_value(file));
//       TELL_CHILD(pid);
// 		}
//   }

//   return 0;
// }