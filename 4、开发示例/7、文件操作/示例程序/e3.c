#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(void)
{
	int fd;
	int iCount;
	fd = open("/etc/inittab", O_RDONLY);
	iCount = lseek(fd, 0, SEEK_END);
	printf("%d bytes total!\n", iCount);
	close(fd);
}
