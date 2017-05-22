#include <stdio.h>

int main(void)
{
	FILE *fp;
	char buff[101];
	buff[100] = '\0';

	fp = fopen("/etc/passwd", "r");
	
	while(fgets(buff, 100, fp) != NULL){
		printf("%s", buff);
	}
	fclose(fp);
}
