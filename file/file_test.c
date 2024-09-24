#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>

#define SIZE 128

char temp_buffer[] = "hello world\n";
int flag;
int opt_fd = -1;

int main(int argc, char *argv[])
{
    if (argc > 1)
    {
        opt_fd = open(argv[1], O_WRONLY, 0777);
        flag |= O_CREAT;
        fcntl(opt_fd, F_SETFL, flag);
        printf("Current status: If the file is not existed, it will create the file.\n");

        write(opt_fd, temp_buffer, sizeof(temp_buffer));
    }

    return 0;
}