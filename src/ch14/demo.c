// #include <apue.h>
// #include <fcntl.h>

// int main()
// {
//   int fd = open("temp", O_RDWR | O_CREAT, FILE_MODE);
//   if (fd < 0) return 1;
//   struct flock fl;
//   fl.l_len = 0;
//   fl.l_start = 0;
//   fl.l_whence = SEEK_SET;
//   fl.l_type = F_WRLCK;
//   fl.l_pid = 0;

//   int res = writew_lock(fd, 0, SEEK_END, 0);
//   write(fd, "h", 1);
//   un_lock(fd, 0, SEEK_END, 0);
//   write(fd, "c", 1);
//   return 0;
// }