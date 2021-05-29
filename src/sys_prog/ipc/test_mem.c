// #include <stdlib.h>
// #include <unistd.h>
// #include <stdio.h>
// #include <string.h>
// #include <time.h>
// #include <sys/types.h>
// #include <sys/wait.h>
// #include <sys/time.h>
// #include <stdint.h>
// #include <sys/mman.h>
// #include <sched.h>

// #define MEM_SIZE 65536
// #define IS_READABLE 0 
// #define IS_WRITABLE 1
// #define MEM_META_SIZE 2

// struct worker {
// 	char *mem;
// 	int *array;
// 	int size;
// 	int id;
// };

// void
// write_to_shared_mem(char *mem, const char *src, int size)
// {
//   volatile char *is_readable = &mem[IS_READABLE];
//   volatile char *is_writable = &mem[IS_WRITABLE];
//   mem += MEM_META_SIZE;
//   int mem_size = MEM_SIZE - MEM_META_SIZE;
//   int saved_size = mem_size;
//   char *saved_mem = mem;
//   while (1) {
//     while (!*is_writable) { sched_yield(); } // wait until is_writable
//     int to_copy = mem_size > size ? size : mem_size;
//     memcpy(mem, src, to_copy);
//     size -= to_copy;
//     mem_size -= to_copy;
//     mem += to_copy;
//     src += to_copy;

//     *is_writable = 0;
//     *is_readable = 1;
//     if (size == 0) { break; }
//     mem = saved_mem;
//     mem_size = saved_size;
//   }
// }

// void
// read_from_shared_mem(char *mem, char* dst, int size)
// {
//   volatile char *is_readable = &mem[IS_READABLE];
//   volatile char *is_writable = &mem[IS_WRITABLE];
//   mem += MEM_META_SIZE;
//   int mem_size = MEM_SIZE - MEM_META_SIZE;
//   int saved_size = mem_size;
//   char *saved_mem = mem;
// 	while (1) {
// 		while (! *is_readable)
// 			sched_yield();
// 		int to_copy = mem_size > size ? size : mem_size;
// 		memcpy(dst, mem, to_copy);
// 		size -= to_copy;
// 		mem_size -= to_copy;
// 		mem += to_copy;
// 		dst += to_copy;

// 		*is_readable = 0;
// 		*is_writable = 1;
// 		if (size == 0)
// 			break;
// 		mem = saved_mem;
// 		mem_size = saved_size;
// 	}
// }

// void
// sorter(struct worker *worker, const char *filename)
// {
// 	FILE *file = fopen(filename, "r");
// 	int size = 0;
// 	int capacity = 1024;
// 	int *array = malloc(capacity * sizeof(int));
// 	while (fscanf(file, "%d", &array[size]) > 0) {
// 		++size;
// 		if (size == capacity) {
// 			capacity *= 2;
// 			array = realloc(array, capacity * sizeof(int));
// 		}
// 	}
// 	qsort(array, size, sizeof(int), cmp);
// 	fclose(file);
// 	printf("Worker %d sorted %d numbers\n", worker->id, size);
// 	write_to_shared_mem(worker->mem, (char *) &size, sizeof(size));
// 	write_to_shared_mem(worker->mem, (char *) array, sizeof(int) * size);
// 	free(array);
// }

// int main()
// {
//   char* memm = malloc(1024);
//   memset(memm, 66, 2);
//   memset(memm + 2, 65, 98);
//   memset(memm + 100, 70, 921);
//   memm[1023] = 0;
//   mem(memm, NULL);
//   free(memm);
//   memm = NULL;
//   return 0;
// }