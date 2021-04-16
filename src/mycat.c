// #include <unistd.h>
// #include <fcntl.h>
// #include <apue.h>

// #define BUFFER_SIZE 80
// char buffer[BUFFER_SIZE];

// int main(int argc, char** argv)
// {
//     int fd = STDIN_FILENO;

//     const char* start = argv[1];
//     if (argc > 1)
//     {
//         fd = open(argv[1], O_RDONLY);
//     }

//     if (fd == -1)
//         err_sys("Cannot open file");

//     ssize_t bytes_read;
//     while (bytes_read = read(fd, buffer, BUFFER_SIZE))
//     {
//         write(STDOUT_FILENO, buffer, bytes_read);
//     }
//     close(fd);
//     return 0;
// }