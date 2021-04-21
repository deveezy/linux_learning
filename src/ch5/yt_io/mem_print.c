// #include <stdio.h>
// #include <stdlib.h>

// typedef struct 
// {
//     int test;
//     char k;
//     short sh;
//     int* p;
//     char str[10];
// } Thing;

// int main()
// {
//     int i = 10;
//     Thing t = { 12, 'k', 256, &i,"testing" };
//     printf("%zu\n", sizeof(t));

//     unsigned char data;
    
//     for (size_t i = 0; i < sizeof(t); ++i)
//     {
//         if (i % 4 == 0)
//             printf("\n");

//         data = *((unsigned char*)&t + i);
//         printf("%02x ", data);
//     }
//     printf("\n");
//     return 0;
// }