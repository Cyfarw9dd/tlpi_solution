#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>

int input_fd = -1;
int output_fd = -1;

int main(int argc, char *argv[])
{
    if (argc > 1)
    {
        input_fd = open(argv[1], O_WRONLY, 0644);
        write(input_fd, "Hello", 5);
        lseek(input_fd, 1000000, SEEK_CUR);  // 创建空洞
        write(input_fd, "World", 5);
        close(input_fd);

        output_fd = open(argv[2], O_WRONLY | O_CREAT, 0644);
    }

    return 0;
}