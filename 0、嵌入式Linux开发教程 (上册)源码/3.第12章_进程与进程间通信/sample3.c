#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

extern char **environ;
int main(int argc, char *argv[]) {
    int i;

    printf("argc = %d\n", argc);
    
    printf("args :");
    for (i = 0 ; i < argc; i++) 
        printf(" %s ", argv[i]);
    printf("\n");

    i = 0;
    while(environ[i]) 
        puts(environ[i++]);
    printf("\n");

    return 0;
}
