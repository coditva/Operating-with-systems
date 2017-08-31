#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    pid_t pid;
    pid = fork();

    if (pid < 0) {
        /* there was an error */
        fprintf(stderr, "%d: Fork failed\n", getpid());
    } else if (pid == 0) {
        /* child gets a pid of zero */
        printf("Child:\n");
        execl("/bin/ls", "ls", NULL);
        printf("We'll never reach here\n");
    } else {
        /* inside parent */
        wait(NULL);
        printf("\nChild complete\n");
    }

    return 0;
}
