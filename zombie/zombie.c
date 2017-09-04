#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    pid_t pid, me;
    pid = fork();

    if (pid == 0) {
        me = getpid();
        printf("%d: I love eating brains\n", me);
        printf("%d: I am a zombie!\n", me);
    } else {
        me = getpid();

        printf("%d: Killing my child\n", me);
        printf("%d: Damn! He's a zombie now!\n", me);

        /* sleep so that my child becomes a zombie */
        sleep(20);
        wait(NULL);

        printf("%d: Not anymore\n", me);
    }

    return 0;
}
