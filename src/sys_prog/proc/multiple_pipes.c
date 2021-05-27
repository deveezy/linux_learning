// #include <unistd.h>
// #include <sys/wait.h>
// #include <stdio.h>

// int main(int argc, char** argv)
// {
//   int fd[3][2];
//   for (int i = 0; i < 3; ++i)
//     pipe( fd[i] );

//   pid_t pid1 = fork();
//   if (pid1 == 0) { // child 1

//     pid_t pid2 = fork();
//     if (pid2 == 0) { // child 2
//       close ( fd[0][0] );
//       close ( fd[0][1] );
//       close ( fd[1][1] );
//       close ( fd[2][0] );
//       int x;
//       read ( fd[1][0], &x, sizeof( int ) );
//       close( fd[1][0] );
//       x += 5;
//       write( fd[2][1], &x, sizeof( int ) );
//       close( fd[2][1] );
//       return 0;
//     } else { // child 1
//       close( fd[0][1] );
//       close( fd[1][0] );
//       close( fd[2][0] );
//       close( fd[2][1] );
//       int x;
//       read( fd[0][0], &x, sizeof( int ) ); 
//       close( fd[0][0] );
//       x += 5;
//       write( fd[1][1], &x, sizeof ( int ) );
//       close( fd[1][1] ) ;
//       waitpid(pid2, NULL, 0);
//       return 0;
//     }
//   } else { // parent
//     close( fd[0][0] );
//     close( fd[1][0] );
//     close( fd[1][1] );
//     close( fd[2][1] );
//     int x = 10;
//     write( fd[0][1], &x, sizeof( int ) );
//     close( fd[0][1] );
//     read ( fd[2][0], &x, sizeof( int ) );
//     close( fd[2][0]);
//     waitpid(pid1, NULL, 0);
//     printf("%d\n", x);
//   }
//   return 0;
// }