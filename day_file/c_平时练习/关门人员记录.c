#include<stdio.h>
#include<stdlib.h>

typedef struct men
{
	char ID[10];
	int btime[3];
	int etime[3];
}Men;

int main()
{
	//freopen("input.txt", "r", stdin);
	Men men[20];
	int n;
	scanf_s("%d", &n);
	getchar();
	for (int i = 0; i<n; i++)
	{
		scanf_s("%s", &men[i].ID, 10);
		scanf_s("%d:%d:%d", &men[i].btime[0], &men[i].btime[1], &men[i].btime[2]);
		scanf_s("%d:%d:%d", &men[i].etime[0], &men[i].etime[1], &men[i].etime[2]);
		getchar();
	}
	Men *pMen[2];
	pMen[0] = &men[0];
	pMen[1] = &men[0];
	for (int i = 1; i<n; i++) {
		if (men[i].btime[0] * 3600 + men[i].btime[1] * 60 + men[i].btime[2]<pMen[0]->btime[0] * 3600 + pMen[0]->btime[1] * 60 + pMen[0]->btime[2])
			pMen[0] = &men[i];
		if (men[i].etime[0] * 3600 + men[i].etime[1] * 60 + men[i].etime[2]>pMen[1]->etime[0] * 3600 + pMen[1]->etime[1] * 60 + pMen[1]->etime[2])
			pMen[1] = &men[i];
	}
	printf("begin: %s       ", pMen[0]->ID);
	printf("%d:%d:%d", pMen[0]->btime[0], pMen[0]->btime[1], pMen[0]->btime[2]);
	printf("\n");
	printf("end:%s       ", pMen[1]->ID);
	printf("%d:%d:%d", pMen[1]->etime[0], pMen[1]->etime[1], pMen[1]->etime[2]);
	printf("\n");

	system("pause");
	return 0;
}