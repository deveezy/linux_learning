// #include <stdio.h>

// typedef struct Point
// {
//     int x;
//     int y;
//     int val;
// } Point;

// int main(int argc, const char** argv)
// {
//     FILE* file = fopen("input.txt", "r");
//     if (!file) return 1;

//     char buffer[256];
//     fgets(buffer, 256, file);

//     while (!feof(file))
//     {
//         Point p;
//         sscanf(buffer, "%d %d %d", &p.x, &p.y, &p.val);
//         printf("%d %d %d\n", p.x, p.y, p.val);
//         fgets(buffer, 256, file);
//     }
//     fclose(file);
//     return 0;
// }