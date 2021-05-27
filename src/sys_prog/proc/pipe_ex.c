// #include <stdio.h>
// #include <unistd.h>

// int main()
// {
//   int parent[2];   
//   int child[2]; 
//   pipe(parent);
//   pipe(child);
//   pid_t pid = fork();
//   char buf[16] = {0};
//   if (pid == 0) // child
//   {
//       close(child[1]);
//       close(parent[0]);
//       int res = read(child[0], buf, 16);
//       write(parent[1], "from child", sizeof("from child"));
//       close(child[0]);
//       close(parent[1]); 
//       printf("%s: %d\n", buf, res);
//   }
//   else // parent
//   {
//     close(child[0]);
//     close(parent[1]);
//     write(child[1], "from parent", sizeof("from parent"));
//     int res = read(parent[0], buf, 16);
//     close(child[1]);
//     close(parent[0]);
//     printf("%s: %d\n", buf, res);
//   }
//   return 0;
// }