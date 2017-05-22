#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    pid_t pid;

    pid = fork();
    if (pid == 0) {
        printf("Here is child, my pid = %d, parent's pid = %d\n", getpid(), getppid());
        exit(0);
    } else if(pid > 0) {
        printf("Here is parent, my pid = %d, child's pid = %d\n", getpid(), pid);
    } else {
        perror("fork error\n");
    }
    return 0;
}
