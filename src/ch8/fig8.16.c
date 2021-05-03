// #include "apue.h"
// #include <sys/wait.h>

// char* env_init[] = { "USER=unknown", "PATH=/tmp", NULL };

// void print_env()
// {
// 	int i;
// 	char** ptr;
// 	extern char** environ;

// 	for (ptr = environ; *ptr != 0; ++ptr)
// 	{
// 		printf("%s\n", *ptr);
// 	}
// }

// int main(void)
// {
// 	uid_t uid = getuid();
// 	gid_t eid = getegid();
// 	pid_t	pid;

// 	if ((pid = fork()) < 0) 
//   {
// 		err_sys("fork error");
// 	} 
//   else if (pid == 0) 
//   {			
//     /* specify pathname, specify environment */
//     if (execle("/usr/bin/echo", "/usr/bin/echo", "myarg1", "MY ARG2", (char *)0, env_init) < 0)
// 			err_sys("execle error");
// 	}

// 	if (waitpid(pid, NULL, 0) < 0)
// 		err_sys("wait error");

// 	if ((pid = fork()) < 0) 
//   {
// 		err_sys("fork error");
// 	} 
//   else if (pid == 0)  
//   {	
//     /* specify filename, inherit environment */
// 		if (execlp("ls", "ls", (char *)0) < 0)
// 			err_sys("execlp error");
// 	}

// 	exit(0);
// }