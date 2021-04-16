#include <apue.h>
#include <fcntl.h>

int main()
{
    int fd;
    if ((fd = open("tempfile", O_RDWR)) < 0)
        err_sys("open error");
    
    int res_link = link("foo", "foo_link");
    return 0;
}