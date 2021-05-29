// #include <stdio.h>
// #include <stdlib.h>
// #include <sys/time.h>
// #include <stdint.h>
// #include <memory.h>
// #include <unistd.h>
// #include <sys/wait.h>

// struct worker {
//   int fd[2];
//   int *array;
//   int size;
//   int id;
// };

// int
// cmp(const void* a, const void* b)
// {
//   return *(int*)a - *(int*)b;
// }

// void
// sorter(struct worker *const worker, const char *const filename)
// {
//   close(worker->fd[0]);
//   FILE *const file = fopen(filename, "r");
//   int size = 0;
//   int capacity = 1024;
//   int *array = malloc(capacity * sizeof(int));
//   while (fscanf(file, "%d", &array[size]) > 0) {
//     ++size;
//     if (size == capacity) {
//       capacity *= 2;
//       array = realloc(array, capacity * sizeof(int));
//     }
//   }
//   fclose(file);
//   qsort(array, size, sizeof(int), cmp);
//   printf("Worker %d sorted %d numbers\n", worker->id, size);
//   write(worker->fd[1], &size, sizeof(size));
//   write(worker->fd[1], array, sizeof(int) * size);
//   close(worker->fd[1]);
//   free(array);
// }

// void
// read_from_pipe(int fd, char *in, int size)
// {
//   int total = 0;
//   int rc = read(fd, in, size);
//   while (rc > 0 && size > 0) {
//     size -= rc;
//     in += rc;
//     total += rc;
//     rc = read(fd, in, size);
//   }
// }

// int
// main(int argc, const char** argv)
// {
//   struct timeval start;
//   gettimeofday(&start, NULL);
//   int nfiles = argc - 1;
//   struct worker *workers = malloc(sizeof(struct worker) * nfiles);
//   struct worker *w = workers;
//   for (int i = 0; i < nfiles; ++i, ++w) {
//     pipe(w->fd);
//     w->id = i;
//     if (fork() == 0) {
//       sorter(w, argv[i+1]);
//       free(workers);
//       return 0;
//     }
//     close(w->fd[1]);
//   }
//   int total_size = 0;
//   w = workers; 
//   for (int i = 0; i < nfiles; ++i, ++w) {
//     read_from_pipe(w->fd[0], (char*)&w->size, sizeof(w->size));
//     w->array = malloc(w->size * sizeof(int));
//     read_from_pipe(w->fd[0], (char*)w->array, w->size * sizeof(int));
//     printf("Got %d numbers from worker %d\n", w->size, w->id);
//     close(w->fd[0]);
//     wait(NULL);
//     total_size += w->size;
//   }
//   int *total_array = malloc(total_size * sizeof(int));
// 	int *pos = total_array;
// 	w = workers;
// 	for (int i = 0; i < nfiles; ++i, ++w) {
// 		memcpy(pos, w->array, w->size * sizeof(int));
// 		pos += w->size;
// 	}
	
//   struct timeval tmp;
//   gettimeofday(&tmp, NULL);
//   uint64_t microsecs = tmp.tv_sec * 1000000 + tmp.tv_usec - start.tv_sec * 1000000 + start.tv_usec;
//   printf("presort time = %1f\n", (microsecs + .0) / 1000000);

//   w = workers;
//   for (int i = 0; i < nfiles; ++i, ++w) {
//     free(w->array);
// 	}
//   free(total_array);
//   free(workers);
//   return 0;
// }