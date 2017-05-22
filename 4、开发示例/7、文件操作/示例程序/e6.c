#include <stdio.h>

int main(void)
{
	FILE *fp;
	int iCount;
	char *str = "Hello world!";

	fp = fopen("./test2", "w");
	iCount = fwrite(str, 12, 1, fp);
	printf("%d block(12 bytes per block) read, check it out!\n", iCount);
	fclose(fp);
}
