#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>
#include <semaphore.h>
#include <string.h>
#include <errno.h>

#define MAPSIZE 100
int main(int argc,char **argv)
{
	int shmid;
	char *ptr;
	sem_t *semid;

	if (argc != 2) {
		printf("usage: %s <pathname>\n", argv[0]);
		return -1;
	}

	shmid = shm_open(argv[1], O_RDWR, 0);
	if (shmid == -1) {
		printf( "open shared memory error.\n");
		return -1;
	} 

	ftruncate(shmid, MAPSIZE);

	semid = sem_open(argv[1], 0);
	if (semid == SEM_FAILED) {
		printf("open semaphore error\n");
		return -1;
	}

	ptr = mmap(NULL, MAPSIZE, PROT_READ | PROT_WRITE, MAP_SHARED, shmid, 0);
    	printf("client input:");
	fgets(ptr, MAPSIZE, stdin);
	sem_post(semid);

    	munmap(ptr, MAPSIZE);
    	close(shmid);
    	sem_close(semid);
	return 0;
} 
