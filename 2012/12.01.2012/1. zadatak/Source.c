//03.02.2011. drugi zadatak
#include <stdio.h>
#include<stdlib.h>
int** ucitavanje(int** mat, int* dimenzija) {
	int i;
	int j;
	printf("Unesite dimenziju matrice:\n");
	scanf("%d", dimenzija);
	if (*dimenzija < 0) {
		printf("ERROR!\n");
		exit(1);
	}
	mat = malloc(*dimenzija * sizeof(int*));
	if (mat == NULL) {
		printf("Alokacija memorije nije uspela!!!\n");
		exit(1);
	}
	for (i = 0; i < *dimenzija; i++) {
		mat[i] = malloc(*dimenzija * sizeof(int));
		if (mat[i] == NULL) {
			printf("Alokacija memorije nije uspela!!!\n");
			exit(1);
		}
		for (j = 0; j < *dimenzija; j++) {
			scanf("%d", &mat[i][j]);
		}
	}
	return mat;
}
void obrada(int** mat, int dimenzija) {
	int i, j, indeksKolone, k, indeksVrste, indeksVrste1;
	int najmanji, zbir = 0;
	for (i = 0; i < dimenzija; i++) {
		najmanji = mat[i][0];
		indeksKolone = 0;
		indeksVrste = i;
		for (j = 1; j < dimenzija; j++) { // proveri za n moram na veceru
			if (najmanji > mat[i][j]) {
				najmanji = mat[i][j];
				indeksVrste = i;
				indeksKolone = j;// da zapamti indeks vrste
			}
			// kad se izvrti for i nadje se najmanji u vrsti
		}//pretrazuje kolone
		indeksVrste1 = indeksVrste;
		for (k = 0; k < dimenzija; k++) {
			if (najmanji > mat[k][indeksKolone]) {
				indeksVrste1 = k;
			}
		}
		if (indeksVrste == indeksVrste1) {
			zbir += najmanji;
		}

	}
	printf("Zbir je: %d\n", zbir);
}
int** obrisi(int** mat, int dimenzija) {
	int i, j;
	for (j = 0; j < dimenzija; j++) {
		free(mat[j]);
	}
	free(mat);
	mat = NULL;
	return mat;
}
main() {
	int** mat;
	mat = NULL;
	int dimenzija;
	mat = ucitavanje(mat, &dimenzija);
	obrada(mat, dimenzija);
	mat = obrisi(mat, dimenzija);
	system("pause");
}