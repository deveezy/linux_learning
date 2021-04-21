// #include <stdio.h>

// typedef struct
// {
//     int x;
//     int y;
// } Point;


// int main(int argc, const char** argv)
// {
//     FILE* out = fopen("point.bin", "wb");
//     if (!out) return 1;
//     Point p1 = {.x = 13, .y = -9 };
//     size_t bytes_written = fwrite(&p1, sizeof(p1), 1, out);
//     if (bytes_written < 1) return 1;
//     fclose(out);

//     FILE* in = fopen("point.bin", "rb");
//     if (!in) return 1;
//     Point p2;
//     size_t bytes_read = fread(&p2, sizeof(p2), 1, in);
//     if (bytes_read < 1) return 1;
//     fclose(in);
//     printf("%d %d\n", p2.x, p2.y);
//     return 0;
// }