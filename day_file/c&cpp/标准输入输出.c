#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[])
{
	int ch;
	FILE *fp;
	unsigned long count = 0;
	if (argc != 2) {
		printf("usage:%s filename\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	errno_t err;
	if (err=fopen_s(&fp,argv[1],"r") !=0 ){
		printf("Can't open %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while ((ch = getc(fp)))
	{
		putc(ch, stdout);
		count++;
	}
	fclose(fp);
	printf("File %s has %lu characters\n", argv[1], count);
	system("pause");

	return 0;
}