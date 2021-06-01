#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct A {
  short b;
  long a;
  char g;
  int f;
} A;

typedef struct B {
  int a;
  long b;
  int z;
} B;

typedef struct C {
  char c;
  char b;
  char z;
} C;

int main()
{
  sizeof(A);
  A b;
  int a = __alignof__(b);
  return 0;
}