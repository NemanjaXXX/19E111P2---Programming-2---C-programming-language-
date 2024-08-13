//23.08.2011. drugi zadatak
#include <stdio.h>
#include <stdlib.h>


int** ucitaj(int* n) {

	int** mat, i, j, t;
	printf("Unesite dimenziju matrice: ");
	scanf("%d", &t);
	mat = malloc(t * sizeof(int*));
	for (i = 0; i < t; i++)
		mat[i] = malloc(t * sizeof(int));
	printf("Unesite elemente matrice:\n");
	for (i = 0; i < t; i++) {
		for (j = 0; j < t; j++) {
			scanf("%d", &mat[i][j]); if (mat[i][j] < 0 || mat[i][j]>255) {
				printf("Elementi matrice moraju biti u opsegu od 0 do 255\n "); exit(1);
			}
		}
	}
	*n = t;
	return mat;

}


int obrada(int** mat, int** niz, int n) {

	int i, v, k, br = 0, da, s;
	for (i = 0; i < n; i++) {
		da = 0;
		for (v = 0, k = n - 1; v < n; v++, k--)
		{
			if (mat[i][i] == mat[v][k]) {
				if (br == 0) { (*niz)[0] = mat[i][i]; br++; break; }
				else {
					for (s = 0; s < br; s++)
					{
						if (mat[i][i] == (*niz)[s]) { da = 1; break; }
					}

					if (da) break; else {
						(*niz)[br++] = mat[i][i]; break;
					}
				}
			}
		}
	}
	return br;
}


void ispis(int* niz, int br) {
	putchar('\n');
	int i;
	for (i = 0; i < br; i++) printf("%d ", niz[i]);
	putchar('\n');
	putchar('\n');
}



int** obrisi(int** mat, int n) {
	int i;
	for (i = 0; i < n;i++) {
		free(mat[i]);
	}
	mat = NULL;
	return mat;
}




int main() {
	int** mat, * niz, br;
	int n;

	mat = ucitaj(&n);
	niz = malloc(n * sizeof(int));
	br = obrada(mat, &niz, n);
	ispis(niz, br);
	mat = obrisi(mat,n);
	system("pause");

}