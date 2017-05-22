#include <stdio.h>
#include <error.h>
#include <semaphore.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#define SEMNAME "/semptest"
int main(int argc, char *argv[]) {
    sem_t  sem;
    pid_t  pid;

    sem_init(&sem, 1, 0);
    if ((pid = fork()) < 0) {
        perror("fork error");
        exit(-1);
    } else if (pid == 0) {
        sleep(1);
        sem_post(&sem);
        printf("child\n");
        exit(0);
    } else {
        sem_wait(&sem);
        printf("parent\n");
    }
    sem_destroy(&sem);
    return 0;
}
