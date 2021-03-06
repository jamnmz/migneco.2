#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <errno.h>
#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int main (const int argc, char** argv)
{
        int shmid;

        //takes in arg and makes sure that the arg is even
        int twoK = atoi(argv[1]);
        if ((twoK % 2) != 0)
        {
                printf("Worker: Error: given int is not an even number");
                exit(EXIT_FAILURE);
        }

        //matching the shared mem ID to be the same as in the master class
        shmid = shmget(0x080698, sizeof(int), 0666 | IPC_CREAT);
        int *shm = (int*)shmat(shmid, NULL, 0);

        //checks if shared memory is set to 0
        if (*shm == 0)
        {
                printf("Worker: shared memory is set to 0");
        }
        else
        {
                //worker class has an error and exits if shared memory is not 0
                printf("Worker: ERROR: shared memory not set to 0");
                exit(EXIT_FAILURE);
        }

        //unfinished so left at 0 so program can compile
        *shm = 0;

        //waits for shared memory to reach 0
        while(*shm != 0)
        {
                sleep(1);                                                                                                                                            }
        printf("Worker: Shared memory reset to 0");

        return(EXIT_FAILURE);
}
