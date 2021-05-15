// #include	<sys/wait.h>
// #include	<errno.h>
// #include	<signal.h>
// #include	<unistd.h>
// #include <stdio.h>

// int
// system(const char *cmd)	/* with appropriate signal handling */
// {
//     int stat;
//     pid_t pid;
//     struct sigaction ignore, savintr, savequit;
//     sigset_t saveblock;
//     if (cmd == NULL)
//       return 1;
//     ignore.sa_handler = SIG_IGN;
//     sigemptyset(&ignore.sa_mask);
//     ignore.sa_flags = 0;
//     sigemptyset(&savintr.sa_mask);
//     sigemptyset(&savequit.sa_mask);
//     sigaction(SIGINT, &ignore, &savintr);
//     sigaction(SIGQUIT, &ignore, &savequit);
//     sigaddset(&ignore.sa_mask, SIGCHLD);
//     sigprocmask(SIG_BLOCK, &ignore.sa_mask, &saveblock); // block CHILD signal
//     if ((pid = fork()) == 0) 
//     {
//       sigaction(SIGINT, &savintr, (struct sigaction *)0);
//       sigaction(SIGQUIT, &savequit, (struct sigaction *)0);
//       sigprocmask(SIG_SETMASK, &saveblock, (sigset_t *)0);
//       execl("/bin/sh", "sh", "-c", cmd, (char *)0);
//       _exit(127);
//     }
//     if (pid == -1) 
//     {
//       stat = -1; /* errno comes from fork() */
//     } 
//     else 
//     {
//       while (waitpid(pid, &stat, 0) == -1) 
//       {
//         if (errno != EINTR)
//         {
//           stat = -1;
//           break;
//         }
//       }
//     }
//     sigaction(SIGINT, &savintr, (struct sigaction *)0);
//     sigaction(SIGQUIT, &savequit, (struct sigaction *)0);
//     sigprocmask(SIG_SETMASK, &saveblock, (sigset_t *)0);
//     return stat;
// }

// int main(int argc, char** argv)
// {
//   system("find * /home/tlt/dev/kernel/linux");
//   return 0;
// }