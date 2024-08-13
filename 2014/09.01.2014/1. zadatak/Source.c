//09.01.2014. prvi zadatak

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

float* oceni(int** mat, float* niz, int n)
{
	float* izlaz;
	int i, j;
	if ((izlaz = malloc(n * sizeof(float))) == NULL)
		exit(1);
	for (j = 0; j < n; j++) //prolazi za svaki restoran
		for (i = 0; i < 5; i++) //prolaz za svaki kriterijum
		{
			izlaz[j] += mat[j][i] * niz[i]; //Cena se racuna kao ocena * tezinski faktor   
		}
	return izlaz;
}

void izunistavaj(int** mat, int n)
{
	int i;
	for (i = 0; i < n; i++)
		free(mat[i]);
	free(mat);
}

void main()
{
	int** mat;
	int* pomniz;
	float krit[5];
	float* izlaz;
	int n, i, j, p;
	printf("Molim Vas, uvazeni korisnice, unesite broj restorana\n");
	scanf("%d", &n);
	//Alokacija matrice: Prvo se alocira niz pokazivaca, pa onda svaki pokazivac
	//u tom nizu posebno
	if ((mat = malloc(n * sizeof(int*))) == NULL) exit(1);
	for (i = 0; i < n; i++)
	{
		if ((mat[i] = malloc(5 * sizeof(int))) == NULL) exit(1);
	}

	printf("Unesite ocene\n");
	//Ucitavanje matrice
	for (i = 0; i < n; i++)
		for (j = 0; j < 5; j++)
			scanf("%d", &mat[i][j]);
	//Ucitavanje niza tezina      
	printf("Unesite tezinske faktore\n");
	for (i = 0; i < 5; i++)
		scanf("%f", &krit[i]);
	izlaz = oceni(mat, krit, n);
	pomniz = malloc(n * sizeof(int));
	for (i = 0; i < n; i++)
		pomniz[i] = i;
	/*Sortiranje izlaznog niza po sumarnim ocenama. Istovremeno se sortira i niz koji je popunjen
	brojevima od 1 do n kako bismo mogli da znamo na koji se restoran odnosi data sumarna ocena
	NPR: ako restoran br. 3 ima najnizu sumarnu ocenu, posle sortiranja ce se u tom drugom nizu na 0-toj
	poziciji naci br. 3
	*/
	for (i = 0; i < n - 1; i++)
		for (j = i + 1; j < n; j++)
			if (izlaz[i] > izlaz[j])
			{
				p = izlaz[i];
				izlaz[i] = izlaz[j];
				izlaz[j] = p;
				p = pomniz[i];
				pomniz[i] = pomniz[j];
				pomniz[j] = p;
			}


	//Trazeni ispis

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 5; j++)
		{
			printf("%d ", mat[pomniz[i]][j]);
		}
		printf("\n");
	}
	izunistavaj(mat, n);
	free(pomniz);
	free(izlaz);
	system("pause");
}