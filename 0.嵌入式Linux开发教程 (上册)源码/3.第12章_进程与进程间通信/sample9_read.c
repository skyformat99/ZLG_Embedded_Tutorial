#include <unistd.h>  
#include <stdlib.h>  
#include <stdio.h>  
#include <fcntl.h>  
#include <sys/types.h>  
#include <sys/stat.h>  
#include <limits.h>  
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
    pipefd = open(fifoname, O_RDONLY);  
    datafd = open(argv[1], O_WRONLY|O_CREAT, 0644);  
  
    if((pipefd > 0) && (datafd > 0)) {  
        bytes = read(pipefd, buffer, BUFSIZE);  
        while(bytes > 0)  {  
            ret = write(datafd, buffer, bytes);  
            if(ret < 0) {  
                perror("write error");
                exit(EXIT_FAILURE);  
            }  
            bytes = read(pipefd, buffer, BUFSIZE);  
        } 
        close(pipefd);  
        close(datafd);  
    } else  {
        exit(EXIT_FAILURE);  
    }
    return 0;  
}  
