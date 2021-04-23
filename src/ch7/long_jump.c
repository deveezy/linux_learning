// #include <stdio.h>
// #include <setjmp.h>
// #include <stdlib.h>

// jmp_buf buf;

// double compute_avg(double* values, size_t length)
// {
//   if (length <= 0)
//   {
//     longjmp(buf, 1);
//   }
//   double sum = .0;
//   for (int i = 0; i < length; ++i)
//   {
//     sum += values[i];
//   }
//   return sum / (double)length;
// }

// int main(int argc, const char** argv)
// {
//   int arr_length = argc - 1;
//   double* darr = malloc(sizeof(double) * arr_length);
//   for (int i = 1; i < argc; ++i)
//   {
//     darr[i-1] = atof(argv[i]);
//   }
//   if (setjmp(buf) == 0)
//   {
//     double avg = compute_avg(darr, arr_length);
//     printf("%lf\n", avg);
//   }
//   else
//   {
//     printf("ERROR\n");
//   }
 
//   free(darr);

//   return 0;
// }