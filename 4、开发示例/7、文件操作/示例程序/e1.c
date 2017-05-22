#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(void)
{
	int fd;
	char buff[101];
	int iCount;
	buff[100] = '\0';  
	fd = open("/etc/inittab", O_RDONLY);
	iCount = read(fd, buff, 100);
	printf("I'v read %d bytes from /etc/inittab, as bellow:\n", iCount);
	printf("%s\n", buff);
	close(fd);
}
