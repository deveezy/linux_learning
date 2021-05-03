// #include <apue.h>
// #include <sys/wait.h>

// static void f1(void);
// static void f2(void);

// int main(int argc, const char** argv)
// {
//   f1();
//   f2();
//   _exit(0);
//   return 0;
// }

// static void f1(void)
// {
//   pid_t pid;
//   if ( (pid = fork()) < 0 )
//     err_sys("fork error");

//   int status;
//   wait(&status);
//   // child and parent both return
// }

// static void f2(void)
// {
//   char buf[1000];
//   int i;

//   for (i = 0; i < 1000; ++i)
//     buf[i] = 0;
// }