/* sig_sender.c

   Usage: sig_sender PID num-sigs sig [sig2]

   Send signals to sig_receiver.c.

   Sends 'num-sigs' signals of type 'sig' to the process with the specified PID.
   If a fourth command-line argument is supplied, send one instance of that
   signal, after sending the previous signals.
*/
#define _GNU_SOURCE
#include <signal.h>
#include "signal_functions.h"           /* Declaration of printSigset() */
#include "tlpi_hdr.h"

int
main(int argc, char *argv[])
{
    int numSigs, sig, j;
    pid_t pid;

    pid = getLong(argv[1], 0, "PID");

    // 对这里的代码进行更改
    for (int i = 1; i < NSIG; i++)
    {
        if (9 == i || 32 == i || 33 == i)
            continue;
        kill(atoi(argv[1]), i);
    }

    printf("%s: exiting\n", argv[0]);
    exit(EXIT_SUCCESS);
}