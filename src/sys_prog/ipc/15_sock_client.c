// #include <sys/socket.h>
// #include <sys/un.h>
// #include <unistd.h>
// #include <errno.h>
// #include <stdio.h>

// int
// main()
// {
//   int sock = socket(AF_UNIX, SOCK_STREAM, 0);
//   if (sock == -1) {
// 		printf("error = %s\n", strerror(errno));
// 		return -1;
// 	}

//   struct sockaddr_un addr;
//   addr.sun_family = AF_UNIX;
//   sprintf(addr.sun_path, "%s", "sock_server");
//   if (connect(sock, (struct sockaddr *) &addr, sizeof(addr)) != 0) {
// 		printf("error = %s\n", strerror(errno));
// 		return -1;
// 	}
//   int number;
// 	while (scanf("%d", &number) > 0) {
// 		if (write(sock, &number, sizeof(number)) == -1) {
// 			printf("error = %s\n", strerror(errno));
// 			continue;
// 		}
// 		printf("Sent %d\n", number);
// 		number = 0;
// 		int rc = read(sock, &number, sizeof(number));
// 		if (rc == 0) {
// 			printf("Closed connection\n");
// 			break;
// 		}
// 		if (rc == -1)
// 			printf("error = %s\n", strerror(errno));
// 		else
// 			printf("Received %d\n", number);
// 	}
// 	close(sock);
//   return 0;
// }