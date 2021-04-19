// #include <apue.h>
// #include <fcntl.h>

// #define BUF_SIZE 4096

// int main(int argc, const char** argv)
// {
//     int hole_fd = open("holes", O_RDWR | O_TRUNC | O_CREAT, FILE_MODE);
//     if (hole_fd == -1)
//         err_sys("Cannot open file");

//     // FIXME: check return value
//     ssize_t bytes_written = write(hole_fd, "hello", 5);
//     off_t cur_pos = lseek(hole_fd , 1000, SEEK_CUR);
//     bytes_written = write(hole_fd, "world", 5);

//     int copy_fd = open("holes_copy", O_RDWR | O_TRUNC | O_CREAT, FILE_MODE);
//     if (copy_fd == -1)
//         err_sys("Cannot open file");
    
//     lseek(hole_fd, 0, SEEK_SET);

//     char buf_in[BUF_SIZE] = { 0 };
//     ssize_t read_bytes = -1;
//     while (read_bytes != 0)
//     {
//         read_bytes = read(hole_fd, buf_in, BUF_SIZE);
//     }

//     off_t end_pos = lseek(hole_fd, 0, SEEK_END);
//     char buf_out[BUF_SIZE] = { 0 };
//     size_t out_index = 0;
//     for (size_t i = 0; i < end_pos; ++i)
//     {
//         if (buf_in[i] != 0)
//             buf_out[out_index++] = buf_in[i];
//     }

//     bytes_written = write(copy_fd, buf_out, strlen(buf_out));
//     printf("%s\n", buf_out);
//     close(hole_fd);
//     return 0;
// }