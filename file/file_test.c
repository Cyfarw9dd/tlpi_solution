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
        opt_fd = open(argv[1], O_WRONLY, 0766);
        if (-1 == opt_fd)
        {
            perror("Occurr an error when opening the file.\n");
            exit(1);
        }
        off_t offset = lseek(opt_fd, 1000, SEEK_SET);
        printf("Using the old file descriptor, the offset is %ld.\n", offset);
        int new_fd = dup(opt_fd);
        off_t new_offset = lseek(new_fd, 0, SEEK_CUR);
        printf("Acquiring the offset through the new file descriptor, the value is %ld.\n", new_offset);
        new_offset = lseek(new_fd, 2000, SEEK_SET);
        printf("Changing the offset through the new file descriptor, the value is %ld.\n", new_offset);
        offset = lseek(opt_fd, 0, SEEK_CUR);
        printf("Acquiring the offset through the old file descriptor, the value is %ld.\n", offset);
    }

    return 0;
}