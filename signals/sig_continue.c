#define _GNU_SOURCE
#include <signal.h>
#include "signal_functions.h"           /* Declaration of printSigset() */
#include "tlpi_hdr.h"

struct sigaction sa;
sigset_t sig_collect;
int sig = -1;

void sigcont_handler(void)
{
    printf("Running the SIGCONT handler.\n");
}

int main(int argc, char *argv[])
{
    sa.sa_handler = sigcont_handler;
    sigemptyset(&sig_collect);
    sigaddset(&sig_collect, SIGCONT);
    sigaction(SIGCONT, &sa, NULL);

    printf("%s PID is: %d\n", argv[0], getpid());
    sigprocmask(SIG_BLOCK, &sig_collect, NULL);  // 全局阻塞SIGCONT信号
    printf("Block SIGCONT signal.\n");

    int sleep_sec = atoi(argv[1]);
    sleep(sleep_sec);

    printf("Catch the SIGCONT signal.\n");
    sigprocmask(SIG_UNBLOCK, &sig_collect, NULL);  // 接触SIGCONT信号的阻塞
    printf("Unblock SIGCONT signal.\n");

    fflush(stdout);

    // 短暂延迟，确保 printf 输出完成
    usleep(1000);  // 延迟 1 毫秒

    return 0;
    
}