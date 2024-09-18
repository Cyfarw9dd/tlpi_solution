#define _GNU_SOURCE
#include <signal.h>
#include "signal_functions.h"           /* Declaration of printSigset() */
#include "tlpi_hdr.h"

struct sigaction sa;
sigset_t signal_collect;

void sig_handler(int signum)
{
    printf("My signal num is: %d\n", signum);
}

int main(int argc, char *argv[])
{
    sigemptyset(&signal_collect);   
    sa.sa_handler = sig_handler;
    if (argc < 2)
    {
        printf("Arguement required, try '--help' for more information.\n");
        exit(EXIT_FAILURE);
    }    
    if (strcmp(argv[1], "--help") == 0)
    {
        printf("%s Usage: proc-name sleep-seconds.\n", argv[0]);
    }

    printf("%s PID is %d.\n", argv[0], getpid());

    for (int i = 1; i < NSIG; i++)
    {
        sigaction(i, &sa, NULL);
        sigaddset(&signal_collect, i);
    }

    sigprocmask(SIG_BLOCK, &signal_collect, NULL);
    printf("The proc will sleep for %d seconds.\n", atoi(argv[1]));

    sleep(atoi(argv[1]));
    sigprocmask(SIG_UNBLOCK, &signal_collect, NULL);


    exit(EXIT_SUCCESS);
}