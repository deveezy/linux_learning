// #include <sched.h>
// #include <stdio.h>
// #include <stdbool.h>
// #include <pthread.h>

// struct complex_thing
// {
//   bool lock;
//   char string[128];
// };

// volatile struct complex_thing thing;

// volatile bool start = false;

// void*
// thread_f(void* arg) // arg = 0, 1, 2, 3, 4, 5
// {
//   int id = (int*)arg;
//   // printf("%d\n", thing.lock);
//   while (!start) {}; // break cycle when all the 6 threads was created
//   if (!thing.lock)
//   {
//     thing.lock = true;
//     for (int i = 0; i < sizeof(thing.string) - 1; ++i)
//       thing.string[i] = 'a' + id;
//   }
//   return NULL;
// }

// int
// main()
// {
//   pthread_t tid[6];

//   // Create 6 threads
//   for (int i = 0; i < 6; ++i)
//     pthread_create(&tid[i], NULL, thread_f, (void*)i);
  
//   // set start only when 6 threads was created
//   start = true;
//   // wait for 6 threads
//   for (int i = 0; i < 6; ++i)
//     pthread_join(tid[i], NULL);

//   printf("%s\n", thing.string);
//   return 0;
// }