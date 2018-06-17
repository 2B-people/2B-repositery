#include<stdio.h>

int main()
{
	char swap[6];
	FILE *fp1, *fp2;
	fp1 = fopen("input.txt", "r");
	fp2 = fopen("output.txt", "a");

	fscanf(fp1, "%s", swap);
	fprintf(fp2, "%s", swap);

	fclose(fp1);
	fclose(fp2);
	getchar();
	return 0;
	
}