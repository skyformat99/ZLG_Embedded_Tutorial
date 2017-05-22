#include <stdio.h>

int main(void)
{
	FILE *fp;
	int iCount;
	char buff[101];
	buff[100] = '\0';
	fp = fopen("/etc/passwd", "r");
	iCount = fread(buff, 50, 2, fp);
	printf("%d blocks(50 bytes per block) read, as bellow:\n", iCount);
	printf("%s\n", buff);
	fclose(fp);
}
