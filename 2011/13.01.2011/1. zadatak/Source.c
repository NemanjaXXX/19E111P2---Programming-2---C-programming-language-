//13.01.2011. prvi zadatak
#include<stdio.h>
#include<stdlib.h>
int** ucitavanje(int** mat, int* vrsta, int* kolona) {
	int i;
	int j;
	printf("Unesite dimenzije matrice:");
	scanf("%d%d", vrsta, kolona);
	if (*vrsta <= 0 || *kolona <= 0 || *vrsta != *kolona) {
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
	int simetricna = 1;
	for (i = 0; i < vrsta - 1; i++) {
		for (j = i + 1; j < kolona; j++) {
			if (mat[i][j] != mat[j][i]) {
				simetricna = 0;
				break;
			}
		}
	}
	if (simetricna == 1) {
		printf("Simetricna.");
	}
	else {
		printf("Nije simetricna!!!\n");
	}


}
int** obrisi(int** mat, int vrsta) {
	int i;
	for (i = 0; i < vrsta; i++) {
		free(mat[i]);
	}
	free(mat);
	mat = NULL;
	return mat;
}
void main() {
	int** mat = NULL;
	int vrsta, kolona;
	mat = ucitavanje(mat, &vrsta, &kolona);
	obrada(mat, vrsta, kolona);
	mat = obrisi(mat, vrsta);
	system("pause");
}
