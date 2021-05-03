// #include <apue.h>
// #include <fcntl.h>

// #include <stdio.h>

// int main(int argc, const char** arv)
// {
//   char* command[] = { "grep", "-E", "c$", "-", 0 };
//   char* bin_file = command[0];

//   int redirect_fd = open("redirect_fd.txt", O_CREAT | O_TRUNC | O_WRONLY);
//   if (dup2(redirect_fd, STDOUT_FILENO) == -1)
//     err_sys("DUP2 error");
//   close(redirect_fd);

//   if (execvp(bin_file, command) == -1)
//   {
//     fprintf(stderr, "Error executing %s\n", bin_file);
//   }
//   printf("Done\n");
//   return 0;
// }