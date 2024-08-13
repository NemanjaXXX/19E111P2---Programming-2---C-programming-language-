//31.01.2013. drugi zadatak
#include <stdio.h>
#include <stdlib.h>
int** ucitavanje(int** mat, int* vrsta, int* kolona) {
	int i;
	int j;
	printf("Unesite dimenzije matrice:");
	scanf("%d%d", vrsta, kolona);
	if (*vrsta <= 0 || *kolona <= 0) {
		printf("Greska!!!\n");
		exit(1);
	}
	mat = calloc(*vrsta, sizeof(int*)); //malloc(n*sizeof(int*))
	if (mat == NULL) {
		printf("Alokacija memorije nije uspela!!!\n");
		exit(1);
	}
	for (i = 0; i < *vrsta; i++) {
		mat[i] = calloc(*kolona, sizeof(int));
		if (mat[i] == NULL) {
			printf("Alokacija memorije nije uspela!!!\n");
			exit(1);
		}
		for (j = 0; j < *kolona; j++)
			scanf("%d", &mat[i][j]);
	}
	return mat;
}
void obrada(int** mat, int vrsta, int kolona) {
	int i;
	int j;
	int k;
	int brojac;
	printf("Unesite vrednost k:");
	scanf("%d", &k);
	for (i = vrsta - 1; i >= 0; i--) {
		brojac = 0;
		for (j = 0; j < kolona; j++) {
			if (mat[i][j] % 2 == 1) {
				brojac++;

			}
		}
		if (brojac > k) {
			printf("%d ", i);
		}
	}
}

int** obrisi(int** mat, int vrsta) {
	int i;
	for (i = 0; i < vrsta; i++) {
		free(mat[i]);
	}
	mat = NULL;
	return mat;
}


int main() {
	int** mat;
	int vrsta, kolona;
	mat = NULL;
	mat = ucitavanje(mat, &vrsta, &kolona);
	obrada(mat, vrsta, kolona);
	mat = obrisi(mat,vrsta);
	system("pause");
	return 0;
}
