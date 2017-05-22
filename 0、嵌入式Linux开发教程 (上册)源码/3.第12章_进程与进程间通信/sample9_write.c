#include <unistd.h>  
#include <stdlib.h>  
#include <fcntl.h>  
#include <limits.h>  
#include <sys/types.h>  
#include <sys/stat.h>  
#include <stdio.h>  
#include <string.h>  
  
#define BUFSIZE 1024
int main(int argc, char *argv[])  
{  
    const char *fifoname = "/tmp/fifo";  
    int pipefd, datafd; 
    int bytes, ret;   
    char buffer[BUFSIZE];  
  
    if (argc != 2) {
        fprintf(stderr, "Usage: %s < filename >\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if(access(fifoname, F_OK) < 0) {  
        ret = mkfifo(fifoname, 0777);  
        if(ret < 0) {   
            perror("mkfifo error");
            exit(EXIT_FAILURE);  
        }  
    }  
  
    pipefd = open(fifoname, O_WRONLY);  
    datafd = open(argv[1], O_RDONLY);
  
    if((pipefd > 0) && (datafd > 0)) {  
        bytes = read(datafd, buffer, BUFSIZE);  
        while(bytes > 0)  {  
            ret = write(pipefd, buffer, bytes);  
            if(ret < 0) {  
                perror("write error");
                exit(EXIT_FAILURE);  
            }  
            bytes = read(datafd, buffer, BUFSIZE);  
        }  
        close(pipefd);  
        close(datafd);  
    } else {
        exit(EXIT_FAILURE);  
    }
    return 0;
} 
