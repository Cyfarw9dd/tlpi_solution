/* copy.c

   Copy the file named argv[1] to a new file named in argv[2].
*/
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/socket.h>
#include "tlpi_hdr.h"

#ifndef BUF_SIZE        /* Allow "cc -D" to override definition */
#define BUF_SIZE 128
#endif

/**
 * @brief   根据13-1中的习题，在默认缓冲区大小1024下，直接运行小文件，短文本的程序并且使用time命令计时，基本可以发现内核态的sys计时是为0的
 *          但是在当将缓冲区下调，减少至128的时候，当while循环至少执行两次，即read和write等IO系统调用至少执行两次的时候，内核态sys的计时此
 *          时便并不为零。由此可见，基础IO虽然没有缓冲，但其实是在用户态的时候是没有缓冲的，其在内核态的时候运行着一个缓冲区，在当调用此时较
 *          多的时候，内核也会增加cpu调度的时间
 *          如果需要数据写入可靠，可以加上O_SYNC标志，该标志会确保数据完整写入到磁盘内。但也因如此，这会增加用户态的运行用时。
 *          
 * 
 * @param argc 
 * @param argv 
 * @return int 
 */
int
main(int argc, char *argv[])
{
    int inputFd, outputFd, openFlags;
    mode_t filePerms;
    ssize_t numRead;
    char buf[BUF_SIZE];

    if (argc != 3 || strcmp(argv[1], "--help") == 0)
        usageErr("%s old-file new-file\n", argv[0]);

    /* Open input and output files */

    inputFd = open(argv[1], O_RDONLY);
    if (inputFd == -1)
        errExit("opening file %s", argv[1]);

    // 所谓截断标志，是为了在打开文件的时候清空文件
    openFlags = O_CREAT | O_WRONLY | O_TRUNC | O_SYNC;
    filePerms = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP |
                S_IROTH | S_IWOTH;      /* rw-rw-rw- */
    outputFd = open(argv[2], openFlags, filePerms);
    if (outputFd == -1)
        errExit("opening file %s", argv[2]);

    /* Transfer data until we encounter end of input or an error */

    while ((numRead = read(inputFd, buf, BUF_SIZE)) > 0)
        if (write(outputFd, buf, numRead) != numRead)
            fatal("write() returned error or partial write occurred");
    if (numRead == -1)
        errExit("read");

    if (close(inputFd) == -1)
        errExit("close input");
    if (close(outputFd) == -1)
        errExit("close output");

    exit(EXIT_SUCCESS);
}