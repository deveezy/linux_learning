#include <stdio.h>
#include <stdint.h>

void mem_dump_hex(void* ptr, size_t bytes)
{
    if (!ptr)
        return;


    for (int64_t byte = 0; byte < bytes; ++byte)
    {
        printf("%p: %X\n", &(ptr[byte]), *((char*)ptr + byte));
    }
}

void mem_dump_bin(void* ptr, size_t bytes)
{
    if (!ptr)
        return;

    char* ch_ptr = ptr;
    for (int64_t bit = 0; bit <= bytes * 8 - 1; ++bit)
    {
        char c = (*ch_ptr >> bit) & 1;
        if (bit % 8 == 0)
        {
            printf("\n%p: ", (ch_ptr + (bit / 8)) );
        }
        printf("%d", c);
    }
    printf("\n");
}

void bin_rep(int digit)
{
    long long i, j;
    for (i = 0; i < sizeof(digit); ++i)
    {
        char byte = *(((char*)&digit) + i);
        for (j = 8; j >= 0; --j)
        {
            char bit = (byte >> j) & 1;
            printf("%d", bit);
        }
        printf(" ");
    }
}

int main()
{
    int a = 13;

    mem_dump_hex(&a, sizeof(a));
    mem_dump_bin(&a, sizeof(a));
    // bin_rep(65533);
    return 0;
}