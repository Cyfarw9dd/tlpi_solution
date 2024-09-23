#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

#define INPUT_P "input.txt"
#define OUTPUT_P "output.txt"
#define READ_SIZE 128

char temp_buffer[READ_SIZE + 1];

int main(int argc, char *argv[])
{
    if (1 == argc && NULL == argv[1])
    {
        printf("Try to use '--help' for further information.\n");
        return 1;
    }    
    if (argc > 1 && strcmp(argv[1], "--help") == 0)
    {
        printf("my_tee [-ai][--help][--version][file name...].\n");
        return 0;
    }    

    int append_flag = 0;
    int fd_output = -1;
    int fd_input = STDIN_FILENO;
    size_t bytes_read;
    if (argc > 1 && strcmp(argv[1], "-a") == 0)
    {
        append_flag = 1;
        // 将-a视作从未出现过
        argc--;
        argv++;
    }

    // 如果指定了输出文件，那么则打开文件
    if (argc > 1)
    {
        // 打开输出文件，并且检查是否为追加模式
        fd_output = open(argv[1], O_WRONLY | O_CREAT | (append_flag ? O_APPEND : O_TRUNC), 0644);
        if (-1 == fd_output)
        {
            perror("Occur error when opening the file.\n");
            return 1;
        }
    }

    // 从标准输入中读取
    while ((bytes_read = read(fd_input, temp_buffer, READ_SIZE)) > 0)
    {
        temp_buffer[bytes_read] = '\0';
        write(STDOUT_FILENO, temp_buffer, bytes_read);
        if (fd_output != -1)
        {
            write(fd_output, temp_buffer, bytes_read);
        }
    }

    if (-1 == bytes_read)
    {
        perror("Error reading input.\n");
    }

    if (fd_output != -1)
    {
        close(fd_output);
    }

    return 0;
}