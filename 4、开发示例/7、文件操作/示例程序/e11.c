#include <stdio.h>
#define Sycn_Test_On 1

int main(void)
{
    FILE *fp;
    int iCount;
    char *str = "Hello world!";
   	fp = fopen("./test_3", "w");                     // 打开文件以获得操作该文件的句柄
  	if(Sycn_Test_On){
    setvbuf(fp,NULL,_IONBF,0);
    }
   	iCount = fwrite(str, 12, 1, fp);
   	printf("%d block(12 bytes per block) read, check it out!\n", iCount);
    while(1);
        fclose(fp);
}


