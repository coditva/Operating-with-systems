#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    pid_t pid;
    pid = fork();

    /* child gets a pid of zero */
    if (pid == 0) {
        printf("%d: we're in the child\n", getpid());
        exit(2);
    } else {
        pid = wait(NULL);
        printf("%d: we're in the parent\n", getpid());
        printf("%d: my child is: %d\n", getpid(), pid);
        printf("%d: my child is dead now and wait returns %d\n",
                getpid(), wait(NULL));
    }

    return 0;
}
