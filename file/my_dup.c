#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int fd;
char temp_buffer[] = "Hello World\n";

int my_dup(int oldfd)
{
    return fcntl(oldfd, F_DUPFD);
}

int main(int argc, char *argv[])
{
    // 打开文件
    if (argc > 1)
    {
        fd = open(argv[1], O_WRONLY | O_CREAT, 0777);
        if (-1 == fd)
        {
            perror("Occur an error when opening the file.\n");
            exit(1);
        }
        int new_fd = my_dup(fd);
        write(new_fd, temp_buffer, sizeof(temp_buffer)); 
    }

    return 0;
}