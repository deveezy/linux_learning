// #include <stdio.h>
// #include <string.h>

// typedef struct 
// {
//     int x;
//     int y;
// } Point;

// int main(int argc, const char** argv)
// {
//     Point p1 = { .x = 12, .y = -9 };

//     FILE* out = fopen("point.dat", "w");
//     if (!out) return 1;

//     char buffer_out[256];

//     snprintf(buffer_out, 256, "%d, %d\n", p1.x, p1.y);
//     fwrite(buffer_out, sizeof(char), strlen(buffer_out), out);
//     fclose(out);

//     FILE* in = fopen("point.dat", "r");
//     if (!in) return 1;
//     char buffer_in[256];
//     Point p_in;
//     fscanf(in, "%d, %d\n", &p_in.x, &p_in.y);
//     fclose(in);
//     printf("%d %d\n", p_in.x, p_in.y);
//     return 0;
// }