//13.06.2012. prvi zadatak
#include <stdio.h>
#include <stdlib.h>
#define MAX 20
void ucitavanje(int mat[MAX][MAX], int* dimezija) {
	int i;
	int j;
	printf("Unesite dimenzije matrice (max 20x20):\n");
	scanf("%d", dimezija);
	if (*dimezija <= 0 || *dimezija > MAX) {
		printf("Pogresan unos!!!\n");
		exit(1);
	}

	for (i = 0; i < *dimezija; i++) {
		for (j = 0; j < *dimezija; j++) {
			scanf("%d", &mat[i][j]);
		}
	}
}
void obrada(int mat[MAX][MAX], int dimezija) {
	int niz[MAX * MAX];
	int i, j, k, d, brojac, duzina = 0, s, ima;
	for (i = 0; i < dimezija; i++) {
		for (j = 0; j < dimezija; j++) {
			brojac = 0;
			for (k = 0; k < dimezija; k++) {
				for (d = 0; d < dimezija; d++) {
					if (mat[i][j] == mat[k][d]) {
						brojac++;
					}
				}
			}
			if (brojac < 3) {
				ima = 0;
				for (s = 0; s < duzina; s++) {
					if (niz[s] == mat[i][j]) {
						ima = 1;
						break;
					}

				}
				if (ima == 0) {
					niz[duzina] = mat[i][j];
					duzina++;
				}
			}
		}
	}

	printf("Rezultujuci niz je:\n");
	for (i = 0; i < duzina; i++) {
		printf("%d ", niz[i]);
	}
}
void main() {
	int mat[MAX][MAX];
	int dimezija;
	ucitavanje(mat, &dimezija);
	obrada(mat, dimezija);
	system("pause");

}