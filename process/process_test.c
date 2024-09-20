#define _GNU_SOURCE
#include <signal.h>
#include <sys/signal.h>
#include <time.h>
#include <sys/time.h>
#include "tlpi_hdr.h"

static int local = 1;
int status;

struct timespec request_t;
struct timespec remain_t;
struct timeval start;
struct timeval curr;
struct sigaction sa;

void signal_handler(int signum)
{
    printf("The children process return.\n");
}

int main(int argc, char *argv[])
{
    sa.sa_handler = signal_handler;
    sigaction(SIGCHLD, &sa, NULL);   

    request_t.tv_sec = 1;
    request_t.tv_nsec = 0;
    gettimeofday(&start, NULL);
    pid_t ret = fork();

    switch (ret)
    {
        case -1:
            perror("fork error.\n");
            exit(EXIT_FAILURE);
        case 0:
            for (int i = 0; i < 3; i++)
            {
                printf("Running: children process, loop time: %d.\n", i);
                nanosleep(&request_t, &remain_t);
            }
            break;
        default:
            wait(&status);
            if (WIFEXITED(status))
            {
                gettimeofday(&curr, NULL);
                printf("Running: parents process, time pass: %d seconds.\n", curr.tv_sec - start.tv_sec);
            }
            break;
    }

    return 0;
}