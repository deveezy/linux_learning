// #include "apue.h"
// #include <sys/wait.h>

// int		globvar = 6; /* external variable in initialized data */
// char	buf[] = "a write to stdout\n";

// void pr_exit(int status)
// {
// 	if (WIFEXITED(status))
//   {
// 		printf("normal termination, exit status = %d\n", WEXITSTATUS(status));
//   }
// 	else if (WIFSIGNALED(status))
//   {
// 		printf("abnormal termination, signal number = %d%s\n", WTERMSIG(status),
// #ifdef	WCOREDUMP
// 				WCOREDUMP(status) ? " (core file generated)" : "");
// #else
// 				"");
// #endif

//   }
// 	else if (WIFSTOPPED(status))
//   {
// 		printf("child stopped, signal number = %d\n", WSTOPSIG(status));
//   }
// }

// int main(void)
// {
// 	int		var;		/* automatic variable on the stack */
// 	pid_t	pid;

// 	var = 88;
// 	if (write(STDOUT_FILENO, buf, sizeof(buf)-1) != sizeof(buf)-1)
// 		err_sys("write error");

// 	printf("before fork\n");	/* we don't flush stdout */

// 	if ((pid = fork()) < 0) 
//   {
// 		err_sys("fork error");
// 	} 
//   else if (pid == 0) /* child */
//   {		
// 		globvar++;				/* modify variables */
// 		var++;
// 	} 
//   else 
//   {
//     sleep(10);
//     printf("parent");
// 	}

// 	printf("pid = %ld, glob = %d, var = %d\n", (long)getpid(), globvar, var);

// 	exit(0);
// }