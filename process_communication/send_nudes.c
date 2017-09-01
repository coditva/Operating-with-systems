#include <sys/types.h>
#include <sys/wait.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <assert.h>

/* the location of nudes */
#define FILENAME "./nudes.txt"

int main(int argc, char *argv[])
{
    void *mmaped_memory;
    int file;
    struct stat st;
    size_t file_size;
    struct nudes_t {
        int no_of_nudes;
        char gender;
    } nudes, *msg;
    pid_t pid;

    /* populate nudes */
    nudes.no_of_nudes = 3;
    nudes.gender = 'M';

    /* open the file */
    file = open(FILENAME, O_RDWR | O_CREAT);
    assert(file != 0);

    /* get shared memory and write initial values to it*/
    write(file, &nudes, sizeof(nudes));
    msg = mmap(NULL,
            sizeof(nudes),
            PROT_READ | PROT_WRITE,
            MAP_PRIVATE,
            file, 0);
    assert(msg != MAP_FAILED);

    /* fork from here so that the mmaped memory will be common to both */
    pid = fork();

    /* child gets a pid of zero */
    if (pid == 0) {

        printf("%d: In child process\n", getpid());

        /* change message in file */
        nudes.no_of_nudes = 10;
        nudes.gender = 'G';
        lseek(file, 0, SEEK_SET);
        write(file, &nudes, sizeof(nudes));

        /* sync changes to shared memory */
        printf("%d: Changing shared memory contents\n", getpid());
        msync(msg, sizeof(nudes), MS_SYNC);
        /* NOTE: child process sharing nudes does not imply child pornography
         * in any way whatsoever */

    } else {

        printf("%d: In parent process\n", getpid());

        /* print value in shared memory before sharing */
        printf("%d: No of nudes: %d\tGender: %c\n",
                getpid(),
                msg->no_of_nudes,
                msg->gender);

        /* wait till the child exits */
        wait(NULL);
        printf("%d: Child process ended\n", getpid());

        /* write message in shared memory to stdout */
        printf("%d: No of nudes: %d\tGender: %c\n",
                getpid(),
                msg->no_of_nudes,
                msg->gender);
    }

    munmap(msg, sizeof(nudes));

    return 0;
}
