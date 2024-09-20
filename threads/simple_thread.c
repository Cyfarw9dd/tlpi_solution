#include <pthread.h>
#include "tlpi_hdr.h"

pthread_t thread_id;

static void *func_entry(void *arg)
{
    char *s = (char *)arg;
    printf("Calling from the thread: %s.\n", s);
    return (void *)s;
}

int main(int argc, char *argv[])
{
    int s = pthread_create(&thread_id, NULL, func_entry, "hello world");
    void *res;
    if (s != 0)
        perror("Thread create error occur.\n");

    printf("Calling from the main.\n");
    s = pthread_join(thread_id, &res);

    printf("The return data of the thread entry is: %s.\n", (char *)res);

    pthread_exit(NULL);

    printf("After the main() calling the pthread_exit(NULL).\n");
}