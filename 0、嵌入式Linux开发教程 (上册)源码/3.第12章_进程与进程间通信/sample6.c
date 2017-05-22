#include <unistd.h>
#include <stdio.h>
#include <signal.h>

void ouch(int sig) {
    printf("\nOuch! - I got signal %d\n", sig);
}

int main(int argc, char *argv[]) {
    struct sigaction act;

    act.sa_handler = ouch;
    sigemptyset(&act.sa_mask);
    act.sa_flags = SA_RESETHAND;

    sigaction(SIGINT, &act, NULL);

    while (1) {
        printf("sleeping\n");
        sleep(1);
    }
    return 0;
}
