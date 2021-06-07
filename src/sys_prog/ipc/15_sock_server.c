// #include <errno.h>
// #include <pthread.h>
// #include <stdio.h>
// #include <sys/socket.h>
// #include <sys/un.h>
// #include <unistd.h>

// void *worker_f(void *arg) {
//   printf("New client created\n");
//   int client_sock = (int)arg;
//   while (1) {
//     int buffer = 0;
//     ssize_t size = read(client_sock, &buffer, sizeof(buffer));
//     if (size == -1) {
//       printf("error = %s\n", strerror(errno));
//       continue;
//     }
//     if (size == 0) {
//       printf("Closed connection\n");
//       break;
//     }
//     printf("Received %d\n", buffer);
//     ++buffer;
//     if (write(client_sock, &buffer, sizeof(buffer)) == -1)
//       printf("error = %s\n", strerror(errno));
//     else
//       printf("Sent %d\n", buffer);
//   }
//   close(client_sock);
//   return NULL;
// }
// typedef unsigned int u32;
// typedef unsigned char u8;

// unsigned int swap_u32(unsigned int value) 
// {
//   unsigned int val = 0;
//   val |= ((value & 0x000000ff)) << 24 | ((value & 0x0000ff00) << 8) |
//          ((value & 0x00ff0000) >> 8) | ((value & 0xff000000) >> 24);
//   return val;
// }

// void u32_to_stream(u8 *stream,  u32 *value) 
// {
// 	u8 *ptr = (u8 *)value;
// 	stream[0] = *ptr++;
// 	stream[1] = *ptr++;
// 	stream[2] = *ptr++;
// 	stream[3] = *ptr++;
// }

// int main(int argc, const char **argv) 
// {
//   int sock = socket(AF_UNIX, SOCK_STREAM, 0);
//   if (sock == -1) {
//     printf("error = %s\n", strerror(errno));
//     return -1;
//   }
//   struct sockaddr_un addr;
//   addr.sun_family = AF_UNIX;
//   sprintf(addr.sun_path, "%s", "sock_server");
//   if (bind(sock, (struct sockaddr *)&addr, sizeof(addr)) != 0) {
//     printf("error = %s\n", strerror(errno));
//     return -1;
//   }
//   if (listen(sock, 128) == -1) {
//     printf("error = %s\n", strerror(errno));
//     return -1;
//   }
//   pthread_attr_t attr;
//   pthread_attr_init(&attr);
//   pthread_attr_setdetachstate(&attr, 1);
//   while (1) {
//     pthread_t worker_thread;
//     int client_sock = accept(sock, NULL, NULL);
//     if (client_sock == -1) {
//       printf("error = %s\n", strerror(errno));
//       continue;
//     }
//     int rc =
//         pthread_create(&worker_thread, &attr, worker_f, (void *)client_sock);
//     if (rc != 0) {
//       printf("error = %s\n", strerror(rc));
//       close(client_sock);
//     }
//   }
//   pthread_attr_destroy(&attr);
//   close(sock);
//   return 0;
// }