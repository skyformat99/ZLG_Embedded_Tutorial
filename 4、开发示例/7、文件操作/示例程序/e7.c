#include <stdio.h>

int main(void)
{
	FILE *fp;
	int iCount;
	char buff[1];

	fp = fopen("/etc/passwd", "r");
	fseek(fp, 0, SEEK_END);
	iCount = ftell(fp);
	printf("%d bytes total!\n", iCount);
	rewind(fp);
	while(fread(buff, 1, 1, fp) == 1){
		printf("%c", buff[0]);
	}	
	fclose(fp);
}
