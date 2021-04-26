#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

int main(int argc, const char** argv)
{
  int id = fork();
  int n = 0;
  int status;
  if (id == 0)
  {
    n = 1;
  }
  else
  {
    n = 5;
  }
  if (id != 0) { wait(&status); }
  int i;
  for (i = n; i < n + 5; ++i)
  {
    printf("%d ", i);
    fflush(stdout);
  }
  if (id != 0) { printf("\n"); }
  return 0;
}