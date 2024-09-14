#define _GNU_SOURCE
#include <signal.h>
#include "signal_functions.h"           /* Declaration of printSigset() */
#include "tlpi_hdr.h"

#define BUFFER_SIZE 12
struct sigaction sa;

/**
 * @brief   abort()本身就是一个可重入并且线程安全的函数，所以在调用的时候同样也需要注意这一点
 *          无论阻塞或者忽略SIGABRT信号，abort()的调用均不受影响
 * 
 */
void my_abort_handler(void)
{
    fflush(stdin);
    fflush(stdout);

    _exit(0);
}

void my_abort(void)
{
    sa.sa_handler = my_abort_handler;
    sigemptyset(&sa.sa_mask);

    for (int i = 1; i < NSIG; i++)
    {
        if (SIGABRT == i)
            continue;
        sigaddset(&sa.sa_mask, i);
    }

    // 更改SIGABRT信号的信号处理器函数
    sigaction(SIGABRT, &sa, NULL);

    // 发送SIGABRT信号，并且生成核心转储文件
    raise(SIGABRT); 
}

int main(int argc, char *argv[])
{
    char buffer[BUFFER_SIZE];
    sigaction(SIGABRT, SIG_DFL, NULL);
    printf("the %s now is running...\n", argv[0]);
    printf("try 'abort' to raise up a SIGABRT signal.\n");

    while (fgets(buffer, sizeof(buffer), stdin))
    {
        if (strstr(buffer, "abort"))
            my_abort();
    }

    return 0;
}