// #include <apue.h>

// static sigset_t newmask;
// static sigset_t oldmask;

// int main()
// {
//   sigemptyset(&newmask);
//   sigemptyset(&oldmask);
//   sigaddset(&newmask, SIGQUIT);
//   sigprocmask(SIG_BLOCK, &newmask, &oldmask);

//   sleep(5);

//   sigprocmask(SIG_SETMASK, &oldmask, NULL);
//   return 0;
// }