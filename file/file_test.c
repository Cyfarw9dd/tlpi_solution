#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

#define SIZE 128

char temp_buffer[SIZE + 1] = "hello world.\n";
int append_flag = 0;
int opt_fd = -1;

int main(int argc, char *argv[])
{
    if (argc > 1 && (strcmp(argv[1], "-a") == 0))
    {
        append_flag = 1;
        argc--;
        argv++;

        opt_fd = open(argv[1], O_WRONLY | O_APPEND, 0644);
        if (-1 == opt_fd)
        {
            perror("Occur error when opening the file.\n");
            exit(1);
        }
        off_t curr = lseek(opt_fd, 0, SEEK_SET);
        if (curr != 0)
        {
            perror("Set the offset failed.\n");
            exit(1);
        }
        write(opt_fd, "hello world", sizeof("hello world"));
    }

    return 0;
}