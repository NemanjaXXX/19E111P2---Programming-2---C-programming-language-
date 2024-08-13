//03.07.2013. prvi zadatak
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

void nadji(int* a, int n, int k, int* inx, int* len);

void main()
{
	int n, k, inx, len, * a, i;

	printf("Uneiste broj elemenata: ");
	scanf("%d", &n);

	if (n < 1)
	{
		printf("Neispravan broj.\n");
		system("pause");
		exit(1);
	}

	a = calloc(n, sizeof(int));
	if (a == NULL)
	{
		printf("Neuspela alokacija.\n");
		system("pause");
		exit(1);
	}

	printf("Unesite elemente niza:\n");
	for (i = 0; i < n; i++)
		scanf("%d", &a[i]);

	printf("Uneiste K: ");
	scanf("%d", &k);

	nadji(a, n, k, &inx, &len);
	if (inx != -1)
	{
		printf("\nNajduzi podniz:\n");
		for (i = inx; i < inx + len; i++)
			printf("%d ", a[i]);
		printf("\n");
	}
	else
		printf("Ne postoji ni jedan podniz koji odgovara zadatim uslovima.\n");

	free(a);
	system("pause");
}

//aritm. sredina elemenata u opsegu [p,k] niza a
double as(int* a, int p, int k)
{
	double suma = 0; int i;

	for (i = p; i <= k; i++)
		suma += a[i];
	suma /= k - p + 1;

	return suma;
}

//nadji najduzi podniz koji ispunjava date uslove
void nadji(int* a, int n, int k, int* inx, int* len)
{
	int i, j, maxLen = -1, iMaxLen = -1;

	for (i = 0; i < n; i++)
		for (j = i; j < n; j++)
			if (as(a, i, j) >= k && j - i + 1 > maxLen)
			{
				maxLen = j - i + 1;
				iMaxLen = i;
			}

	*inx = iMaxLen;
	*len = maxLen;
}
