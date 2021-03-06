// #include <signal.h>
// #include <stdio.h>
// #include <unistd.h>
// #include <stdlib.h>
// #include <sched.h>
// #include <string.h>

// static int finished = 0;
// static int id = 0;

// static int
// is_usr1_blocked(void)
// {
// 	sigset_t old;
// 	sigprocmask(0, NULL, &old);
// 	return sigismember(&old, SIGUSR1);
// }

// static void
// on_new_signal(int signum)
// {
// 	int my_id = ++id;
// 	printf("Begin processing %d, usr1 block = %d\n", my_id,
// 	       is_usr1_blocked());

// 	if (my_id == 1)
// 		raise(signum);

// 	printf("End processing %d\n", my_id);
// 	++finished;
// }

// static void on_new_signal_action(int signo, siginfo_t* info, void* ctx)
// {
// 	int my_id = ++id;
// 	printf("Begin processing %d, usr1 block = %d\n", my_id, 
//     is_usr1_blocked());

// 	if (my_id == 1)
// 		raise(signo);

// 	printf("End processing %d\n", my_id);
// 	++finished;

// 	printf("Segfault: signum = %d, si_signo = %d, si_addr = %p, si_code = %d\n",
//     signo, info->si_signo, info->si_addr);
// }

// int
// main(int argc, char **argv)
// {
// 	struct sigaction act;
// 	// act.sa_handler = on_new_signal;
//   act.sa_sigaction = on_new_signal_action;
// 	sigemptyset(&act.sa_mask);
//   sigaddset(&act.sa_mask, SIGINT);
// 	act.sa_flags = SA_SIGINFO;
// 	for (int i = 1; i < argc; ++i) 
//   {
// 		if (strcmp(argv[1], "nodefer") == 0)
// 			act.sa_flags |= SA_NODEFER;
// 	}
// 	sigaction(SIGUSR1, &act, NULL);
// 	printf("Before raises, usr1 block = %d\n", is_usr1_blocked());
// 	raise(SIGUSR1);
// 	while (finished != 2)
// 		sched_yield();
// 	printf("After raises, usr1 block = %d\n", is_usr1_blocked());
// 	return 0;
// }