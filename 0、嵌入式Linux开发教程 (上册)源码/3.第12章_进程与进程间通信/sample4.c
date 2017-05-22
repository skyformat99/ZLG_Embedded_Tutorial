#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void print_exit_status(int status) {
    if (WIFEXITED(status))
        printf("normal termination, exit status = %d\n",
                WEXITSTATUS(status));
    else if (WIFSIGNALED(status)) 
        printf("abnormal termination, signal number = %d\n",
                WTERMSIG(status));
    else 
        printf("other status\n");
}
int main(int argc, char *argv[]) {

    pid_t pid;
    int status;

    if ((pid = fork()) < 0) {
        perror("fork error");
        exit(-1);
    } else if (pid == 0) {
        exit(7);
    }

    if (wait(&status) != pid) {
        perror("fork error");
        exit(-1);
    }
    print_exit_status(status);

    if ((pid = fork()) < 0) {
        perror("fork error");
        exit(-1);
    } else if (pid == 0) {
        abort();
    }

    if (wait(&status) != pid) {
        perror("fork error");
        exit(-1);
    }
    print_exit_status(status);
    return 0;
}
