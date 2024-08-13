//18.06.2014. prvi zadatak
#include<stdio.h>
#include<stdlib.h>
int** ucitaj(int** mat, int dimenzija) {
	int i, j;
	mat = malloc(dimenzija * sizeof(int*));
	if (mat == NULL) {
		printf("Alokacija memorije nije uspela!!!\n");
		exit(1);
	}
	for (i = 0; i < dimenzija; i++) {
		mat[i] = malloc(dimenzija * sizeof(int));
		if (mat[i] == NULL) {
			printf("Alokacija memorije nije uspela!!!\n");
			exit(1);
		}
		for (j = 0; j < dimenzija; j++) {
			printf("Unesite elemente:");
			scanf("%d", &mat[i][j]);
		}
	}
	return mat;
}
int** obrada(int** mat, int dimenzija) {
	int i, j;
	for (i = 1; i < dimenzija; i++) {
		for (j = dimenzija - i; j < dimenzija; j++) {
			if (mat[i][j] % 2 == 1) { // da li je broj prost
				mat[i][j] = mat[dimenzija - 1 - j][dimenzija - 1 - i];
			}
		}
	}
	return mat;
}
void ispis(int** mat, int dimenzija) {
	int i, j;
	for (i = 0; i < dimenzija; i++) {
		for (j = 0; j < dimenzija; j++) {
			printf("%d ", mat[i][j]);
		}
		printf("\n");
	}

}
int** obrisi(int** mat, int dimenzija) {
	int i;
	for (i = 0; i < dimenzija; i++) {
		free(mat[i]);
	}
	free(mat);
	mat = NULL;
	return mat;

}
int main(int argc, char* argv[]) {
	int** mat = NULL;
	int dimenzija;
	dimenzija = atoi(argv[1]);
	mat = ucitaj(mat, dimenzija);
	printf("Ucitana matrica je:\n");
	ispis(mat, dimenzija);
	mat = obrada(mat, dimenzija);
	printf("\n");
	printf("Matrica nakon obrade je:\n");
	ispis(mat, dimenzija);
	mat = obrisi(mat, dimenzija);
	system("pause");
}
