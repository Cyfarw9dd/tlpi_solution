#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

off_t pos;
int opt_fd;
int line_num, cnt = 0;
char buf[1];

int main(int argc, char *argv[])
{
    if (argc > 2)
    {
        if (strcmp(argv[1], "-n") == 0)
        {
            line_num = atoi(argv[2]);  // 获取输入行号
            argc--;
            argc--;
            argv++;
            argv++;  
        }   

        opt_fd = open(argv[1], O_RDONLY, 0766);
        pos = lseek(opt_fd, 0, SEEK_END);
        char read_buffer[128];
        ssize_t bytes_read = 0;
        int i = 0;
        char **buffer = malloc(line_num * sizeof(char *));
        for (int j = 0; j < line_num; j++) {
            buffer[j] = malloc(128 * sizeof(char));
        }
        while (pos > 0 && cnt < line_num)
        {
            // 每次循环向前递减偏移量
            lseek(opt_fd, --pos, SEEK_SET);
            read(opt_fd, buf, sizeof(buf));
            i++;
            if (-1 == opt_fd)
            {
                perror("Occurr error when reading the file.\n");
                exit(1);
            }
            if ('\n' == buf[0])
            {
                cnt++;
                if ((bytes_read = read(opt_fd, buffer[cnt], i)) < 0) 
                    perror("Occur an error when reading the file.\n");
                i = 0;
            }
        }

        for (int j = line_num; j > 0; j--)
        {
            printf("%s", buffer[j]);
        }

        free(buffer);

    }


    return 0;
}