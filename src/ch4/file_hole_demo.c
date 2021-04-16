// #include <apue.h>
// #include <fcntl.h>

// int main()
// {
//     int fd = open("hole", O_CREAT | O_RDWR);
//     if (fd == -1)
//         err_sys("Cannot open file");
    
//     ssize_t bytes_written = write(fd, "hello", 5);
//     lseek(fd, 1000, SEEK_END);
//     bytes_written = write(fd, "suka", 4);
//     close(fd);
//     // write holes to file
//     return 0;
// }