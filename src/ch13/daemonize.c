// #include <unistd.h>
// #include <fcntl.h>
// #include <errno.h>
// #include <syslog.h>
// #include <signal.h>

// const char* const LOCKFILE = "first_daemon";

// //This function takes a file descriptor for input and marks the file as locked for writing.
// //More information on how it works (would take too long to explain here) in chapter 14 - "Advanced I/O"
// //of the book "Advanced Programming in the Unix Environment"
// int lockfile(int fd) 
// {
//     struct flock fl;
 
//     fl.l_type = F_WRLCK;
//     fl.l_start = 0;
//     fl.l_whence = SEEK_SET;
//     fl.l_len = 0;
//     return(fcntl(fd, F_SETLK, &fl));
// }
 
// #define	FILE_MODE	(S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)

// int DaemonAlreadyRunning(void)
// {
//   int fd;
//   char buf[16];

//   fd = open(LOCKFILE, O_RDWR | O_CREAT, FILE_MODE);
//   if (fd < 0) 
//   {
//     syslog(LOG_ERR, "can′t open %s: %s", LOCKFILE, strerror(errno));
//     exit(1);
//   }
//   if (lockfile(fd) < 0) 
//   {
//     if (errno == EACCES || errno == EAGAIN) 
//     {
//       close(fd);
//       return(1);
//     }
//     syslog(LOG_ERR, "can′t lock %s: %s", LOCKFILE, strerror(errno));
//     exit(1);
//   }
//   ftruncate(fd, 0);
//   sprintf(buf, "%ld", (long)getpid());
//   write(fd, buf, strlen(buf)+1);
//   return(0);
// }

// void
// daemonize(const char* cmd)
// {
//   pid_t pid;
//   //First Fork. This allows the process to become a session leader and releases the attachment to the console.
//   //The attachment to the console si lost since the original process cease to exist.
//   if ((pid= fork()) < 0)
//     err_quit("%s: can′t fork", cmd);
//   else if (pid != 0) //From now on, the function is forked for parent and child. In case of the father, he needs to die
//     exit(0);
  
//   //Creates a new session and becomes the sessions leader. Remember, if we are here, it is for sure the child.
//   //the father has been killed after the fork with the exit call.
//   setsid(); // Become session leader. Don't have terminal.
  
//   struct sigaction sa;
//   //Ensure future opens won′t allocate controlling TTYs.
//   sa.sa_handler = SIG_IGN;
//   sigemptyset(&sa.sa_mask);
//   sa.sa_flags = 0;
//   if (sigaction(SIGHUP, &sa, NULL) < 0)
//     err_quit("%s: can′t ignore SIGHUP", cmd);

//   if ((pid= fork()) < 0)
//     err_quit("%s: can′t fork", cmd);
//   else if (pid != 0) /* parent */
//     exit(0);
// }
