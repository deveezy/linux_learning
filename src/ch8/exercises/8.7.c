// #include <unistd.h>
// #include <stdio.h>
// #include <dirent.h>
// #include <fcntl.h>
// #include <apue.h>

// int main(int argc, const char** argv)
// {
//   DIR* dir = opendir("/");
//   if (fcntl(*((int*)dir), F_GETFD) & FD_CLOEXEC)
//     printf("DIR HAS CLO_EXEC_FLAG\n");
//   closedir(dir);


//   int fd = open("/", O_RDONLY);
//   if (fcntl(fd, F_GETFD) & FD_CLOEXEC)
//     printf("FD HAS CLO_EXEC_FLAG\n");
//   close(fd);
//   return 0;
// }