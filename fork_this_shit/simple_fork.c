#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    pid_t pid;
    pid = fork();

    /* child gets a pid of zero */
    if (pid == 0) {
        printf("%d: we're in the child\n", getpid());
    } else {
        /* wait till the child exits */
        wait(NULL);
        printf("%d: we're in the parent\n", getpid());
    }

    return 0;
}
