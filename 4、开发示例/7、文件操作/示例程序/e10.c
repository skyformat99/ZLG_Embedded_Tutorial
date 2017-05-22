#include <stdio.h>
#define Sync_Test_On  0

int main(void)
{
	  FILE *fp;
	  int iCount;
	  char *str = "Hello world!";
	  fp = fopen("./test_2", "w");                     // 打开文件以获得操作该文件的句柄
	  iCount = fwrite(str, 12, 1, fp);
	  printf("%d block(12 bytes per block) read, check it out!\n", iCount);
	  if (Sync_Test_On) {
	  fflush(fp);
	  while(1);
	  } else {
	  while(1);
	  }
  fclose(fp);
}

