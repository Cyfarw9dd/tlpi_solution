#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>

#define SIZE 128

char temp_buffer[SIZE];
int flag;
int opt_fd = -1;

int main(int argc, char *argv[])
{
    setvbuf(stdout, temp_buffer, _IOFBF, SIZE);
    printf("If I had more time, ");
    write(STDOUT_FILENO, "I would have written you a shorter letter.\n", 43);
    return 0;
}