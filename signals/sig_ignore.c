#define _GNU_SOURCE
#include <signal.h>
#include <stdlib.h>
#include "signal_functions.h"           /* Declaration of printSigset() */
#include "tlpi_hdr.h"

#define BUFFER_SIZE 12

int main(int argc, char *argv[])
{
    // 检查输入参数个数
    if (argc != 2) 
    {
        fprintf(stderr, "Usage: %s <mode>\n", argv[0]);
        return 1;
    }

    int mode = atoi(argv[1]);
    int terminate_status = 1;
    char buffer[BUFFER_SIZE];     

    // 根据输入参数决定进程是否忽视SIGINT信号
    if (argc > 1)  
    {
        switch (mode)
        {
            case 1:
                printf("The process will terminate by SIGINT.\n");
                break;
            case 2:
                printf("The process will not terminate by SIGINT.\n");
                signal(SIGINT, SIG_IGN);
                break;
            default:
                fprintf(stderr, "Invalid mode. Use 1 or 2.\n");
                return 1;
        }
    }

    do
    {
        if (NULL == fgets(buffer, sizeof(buffer), stdin))  // 从标注输入中读取字符串 
            break;
        if (NULL != strstr(buffer, "kill"))  // 查找字符串     
            terminate_status = 0;
    } while (terminate_status); 

    abort();  // 终止程序
    return 0;

}
