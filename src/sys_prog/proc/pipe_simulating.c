// #include <stdlib.h>
// #include <stdio.h>
// #include <sys/wait.h>
// #include <unistd.h>
// #include <time.h>

// int main(int argc, char** argv)
// {
//   int fd[2];
//   pipe(fd);
//   pid_t pid1 = fork();
//   if (pid1 == fork())
//   {
//     close(fd[0]);
//     // Child process 1(ping)
//     if (fd[1] != STDOUT_FILENO)
//     {
//       dup2(fd[1], STDOUT_FILENO);
//       close(fd[1]);
//     }
//     execlp("ping", "ping", "-c", "5", "google.com", NULL);
//   }

//   pid_t pid2 = fork();
//   if (pid2 == 0) 
//   {
//     close(fd[1]);
//     if (fd[0] != STDIN_FILENO)
//     {
//       dup2(fd[0], STDIN_FILENO);
//       close(fd[0]);
//     }
//     // Child process 2(ping)
//     execlp("grep", "grep", "rtt", NULL);
//   }
//   close(fd[0]);
//   close(fd[1]);
//   waitpid(pid1, NULL, 0);
//   waitpid(pid2, NULL, 0);
//   return 0;
// }