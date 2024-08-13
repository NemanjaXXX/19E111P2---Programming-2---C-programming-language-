//04.09.2013. prvi zadatak
#include<stdio.h>
#define MAX 20
void ucitavanje(int mat[MAX][MAX], int* dimenzija) {
	int i;
	int j;
	printf("Unesite dimenziju matrice(max 20x20):\n");
	scanf("%d", dimenzija);
	if (*dimenzija > MAX || *dimenzija <= 0) {
		printf("Pogresan unos!!!\n");
		exit(1);
	}
	printf("Unesite elemente matrice:\n");
	for (i = 0; i < *dimenzija; i++) {
		for (j = 0; j < *dimenzija; j++) {
			scanf("%d", &mat[i][j]);
		}
	}
}
void obrada(int mat[MAX][MAX], int dimenzija) {
	int i;
	int j;
	int pom;
	for (i = 0; i < dimenzija - 1; i++) {
		for (j = i + 1; j < dimenzija; j++) {
			if (mat[i][j] > mat[j][i]) {
				pom = mat[i][j];
				mat[i][j] = mat[j][i];
				mat[j][i] = pom;
			}
		}
	}
}
void ispis(int mat[MAX][MAX], int dimenzija) {
	int i;
	int j;
	int brojac; // da bi bilo po n u redu
	for (i = 0; i < dimenzija; i++) {
		for (j = 0; j < dimenzija; j++) {
			printf("%d ", mat[i][j]);
		}
		printf("\n");
	}

}
void main() {
	int mat[MAX][MAX];
	int dimenzija;
	ucitavanje(mat, &dimenzija);
	obrada(mat, dimenzija);
	ispis(mat, dimenzija);
	system("pause");

}
