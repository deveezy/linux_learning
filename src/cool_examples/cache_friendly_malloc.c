#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct complex_struct
{
  int id;
  char buf[10];
  char* long_buf;
};

void print_addr(struct complex_struct* complex)
{
  printf("int: %p, ", &complex->id);
  // printf("double: %p, ", &complex->a);
  // printf("long: %p, ", &complex->d);
  printf("char[]: %p, ", &complex->buf);
  printf("char*: %p \n", &complex->long_buf);
}

void print_addr2(char* mem, size_t size)
{
  for (size_t i = 0; i < size; ++i)
  {
    printf("%p: %c,\t", mem + i, *(mem + i));
  }
  printf("\n");
}

struct complex_struct* 
complex_struct_bad_new(int long_buf_len)
{
  struct complex_struct* ret = (struct complex_struct*)malloc(sizeof(*ret));
  ret->long_buf = (char*)malloc(long_buf_len);
  return ret;
}

struct complex_struct*
complex_struct_good_new(int long_buf_len)
{
  struct complex_struct* ret;
  int size = sizeof(*ret) + long_buf_len;
  ret = (struct complex_struct*)malloc(size);
  ret->long_buf = (char*)ret + sizeof(*ret);
  return ret;
}

int main(int argc, char** argv)
{
  struct complex_struct* bad  = complex_struct_bad_new(10);
  strcpy(bad->long_buf,"long");
  print_addr(bad);
  print_addr2(bad->long_buf, 4);

  printf("\n\n\n");

  struct complex_struct* good = complex_struct_good_new(10);
  strcpy(good->long_buf, "char");
  print_addr(good);
  print_addr2(good->long_buf, 4);
  free(bad);
  free(good);
  int a;
  __builtin_prefetch(&a);
  return 0;
}