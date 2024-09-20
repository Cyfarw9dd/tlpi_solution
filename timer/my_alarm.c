#define _GNU_SOURCE
#include <signal.h>
#include <time.h>
#include <sys/time.h>
#include <sys/signal.h>
#include <stdlib.h>

#include "curr_time.h"                  /* Declares currTime() */
#include "itimerspec_from_str.h"        /* Declares itimerspecFromStr() */
#include "tlpi_hdr.h"


struct sigaction sa;
struct itimerval nv;

struct timeval start;
struct timeval curr;

unsigned int my_alarm(unsigned int seconds)
{
    if (0 == seconds)
        memset(&nv, 0, sizeof(nv));

    nv.it_interval.tv_sec = 0;
    nv.it_interval.tv_usec = 0;
    nv.it_value.tv_sec = seconds;
    nv.it_value.tv_usec = 0;

    unsigned int ret = setitimer(ITIMER_REAL, &nv, NULL);
}

void sigalarm_handler(void)
{
    gettimeofday(&curr, NULL);
    printf("Timer times up, signal handler triggered, time is %d.\n", curr.tv_sec - start.tv_sec);
    exit(EXIT_SUCCESS);
}

int main(int argc, char *argv[])
{
    int alarm_sec = 0;
    sa.sa_handler = sigalarm_handler;
    sigaction(SIGALRM, &sa, NULL);
    gettimeofday(&start, NULL);
    gettimeofday(&curr, NULL);

    printf("Before 'my_alarm' start, time is %d.\n", curr.tv_sec - start.tv_sec);

    my_alarm(atoi(argv[1]));


    for (;;);
}