// #include <apue.h>
// #include <stdlib.h>
// #include <errno.h>
// #include <err.h>

// int my_dup2(int fd,int fd2)
// {

// 	if(fd2 < 0
// #ifdef FOPEN_MAX
// 		|| fd2 > FOPEN_MAX
// #endif
//     )
// 	{
// 		errno = EBADF;
// 		printf("my_dum2, %d fd2 is not valid number.\n",__LINE__);
// 		return -1;
// 	}

// 	int tmpfd = dup(fd2);

// 	if (tmpfd == -1)
// 	{
// 		switch(errno)
// 		{
// 			case EBADF:
// 				//fd2 is not opened.
// 				break;
// 			case EMFILE:
// 				if(close(fd2) == -1)
// 				{
// 					printf("my_dum2, %d] close fd2 failed.\n",__LINE__);
// 					return -1;
// 				}
// 				break;
// 			default:
// 				printf("my_dum2, %d] dum fd2 failed.\n",__LINE__);
// 				return -1;
// 		}
// 	}
// 	else
// 	{
// 		if(close(tmpfd) == -1)
// 		{
// 			printf("my_dum2, %d] close tmpfd failed.\n",__LINE__);
// 			return -1;
// 		}
// 		if(close(fd2) == -1)
// 		{
// 			printf("my_dum2, %d] close fd2 failed.\n",__LINE__);
// 			return -1;
// 		}
// 	}
	
// 	int* fds = (int *)malloc(fd2 * sizeof(int));
// 	if(!fds)
// 	{
// 		printf("my_dum2, %d] close fd2 failed.\n",__LINE__);
// 		errno = ENOMEM;
// 		return -1;
// 	}

// 	for (int i = 0; i < fd2; ++i)
// 	{
// 		fds[i] = -1;
// 	}

// 	int lastfd = -1;

// 	while(tmpfd = dup(fd))
// 	{
// 		if(tmpfd == -1)
// 		{
// 			printf("my_dup2, %d] dup fd failed, fd=%d, lastfd=%d, err=%d.\n",__LINE__,fd, lastfd);
// 			goto FAIL_EXIT;
// 		}
// 		else if(tmpfd == fd2)
// 			break;
// 		else
// 		{
// 			fds[tmpfd] = tmpfd;
// 			lastfd = tmpfd;
// 		}
// 	}
// 	for(int i= 0;i < fd2;++i)
// 	{
// 		if( fds[i] != -1)
// 			close(fds[i]);
// 	}
// 	free(fds);
// 	return fd2;

// 	FAIL_EXIT:
// 	for(int i = 0; i < fd2; ++i)
// 	{
// 		if(fds[i] != -1)
// 			close(fds[i]);
// 	}
// 	free(fds);
// 	return -1;
// }

// int test_my_dup2(int argc, char ** argv)
// {
// 	int fd;
// 	if(argc < 3)
// 	{
// 		printf("usage: excise oldfd newfd\n");
// 		return 0;
// 	}
// 	fd = my_dup2(atoi(argv[1]),atoi(argv[2]));
// 	if(fd == -1)
// 	{
// 		printf("dup2 fd failed\n");
// 		return -1;
// 	}

// 	printf("return fd by my_dup2 is %d\n",fd);

// 	return 0;
// }

// int main(int argc,char **argv)
// {
// 	test_my_dup2(argc, argv);
// 	return 0;
// }