#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

char *env_init[] = {"USER=peng", "HOME=/home/peng/", NULL};

int main(int argc, char *argv[]) {
    pid_t pid;
    if ((pid = fork()) < 0) {
        perror("fork error");
    } else if (pid == 0) {
        execle("/home/peng/sample3", "sample3", "hello", "world", (char *)0, env_init);
        perror("execle error");
        exit(-1);
    } else {
        exit(0);
    }
    return -1;
}
