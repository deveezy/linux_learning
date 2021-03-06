// #include <apue.h>
// #include <errno.h>

// int my_dup2(int fd,int fd2)
// {
// 	int tmpfd = -1, i, lastfd;
// 	int *fds;

// 	if(fd2 < 0
// #ifdef FOPEN_MAX
// 		|| fd2 > FOPEN_MAX
// #endif
// 	  )
// 		{
// 			errno = EBADF;
// 			printf("my_dum2, %d fd2 is not valid number.\n",__LINE__);
// 			return -1;
// 		}

// 	tmpfd = dup(fd2);
// 	if(-1 == tmpfd)
//   {
//     switch(errno)
//     {
//       case EBADF:
//         //fd2 is not opened.
//         break;
//       case EMFILE:
//         close(fd2);
//         return -1;
//         break;
//       default:
//         printf("my_dum2, %d] dum fd2 failed.\n",__LINE__);
//         return -1;
//     }
//   }
// 	else
//   {
//     close(tmpfd);
//     close(fd2);
//   }
	
// 	fds = (int*)malloc(fd2 * sizeof(int));
// 	for(i = 0; i < fd2; ++i)
//   {
//     fds[i] = -1;
//   }

// 	lastfd = -1;

// 	while(tmpfd = dup(fd))
//   {
//     if(-1 == tmpfd)
//     {
//       goto FAIL_EXIT;
//     }
//     else if(tmpfd == fd2)
//       break;
//     else
//     {
//       fds[tmpfd] = tmpfd;
//       lastfd = tmpfd;
//     }
//   }

//   for(i = 0; i < fd2; ++i)
//   {
//     if(-1 != fds[i])
//       close(fds[i]);
//   }
//   free(fds);
//   return fd2;

// FAIL_EXIT:
//   for(i = 0; i < fd2; ++i)
//   {
//     if(-1 != fds[i])
//       close(fds[i]);
//   }
//   free(fds);
//   return -1;
// }

// int test_my_dup2(int argc,char ** argv)
// {
// 	int fd;
// 	if(argc < 3)
//   {
//     printf("usage: excise oldfd newfd\n");
//     return 0;
//   }
// 	fd = my_dup2(atoi(argv[1]),atoi(argv[2]));
// 	if(-1 == fd)
//   {
//     printf("dup2 fd failed\n");
//     return -1;
//   }
// 	printf("return fd by my_dup2 is %d\n",fd);

// 	return 0;
// }

// int main(int argc,char **argv)
// {
// 	test_my_dup2(argc,argv);
// 	return 0;
// }
