#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>

#define SHMSIZE 10
#define SHMNAME "shmtest"
int main()
{
    int fd;
    char *ptr;
    fd = shm_open(SHMNAME, O_CREAT | O_TRUNC | O_RDWR, S_IRUSR | S_IWUSR);
    if (fd<0) {
        perror("shm_open error");
        exit(-1);
    }
    ftruncate(fd, SHMSIZE);
    ptr = mmap(NULL, SHMSIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (ptr == MAP_FAILED) {
        perror("mmap error");
        exit(-1);
    }
    *ptr = 0x12;
    munmap(ptr, SHMSIZE);
    shm_unlink(SHMNAME);
    return 0;
}
