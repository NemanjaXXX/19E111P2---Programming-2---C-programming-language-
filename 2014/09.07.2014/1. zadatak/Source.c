#include <stdio.h>
#include <stdlib.h>

/*Ideja je da se matrica pro?iri za jo? jednu kolonu i da se tu èuvaju podaci poput rezultata sabiranja.
Potprogram samo raèuna kolika je plata svakof radnika, a posle obrade glavni program raèuna prosek i ispisuje rezultat*/


float** obrada(float** mat, float* niz, int m, int n) {
	int i, j;
	float suma;

	for (i = 0; i < m; i++) {
		for (j = 0, suma = 0; j < n; j++) {
			suma = suma + mat[i][j] * niz[j];
		}
		mat[i][n] = suma;
	}

	for (i = 0, suma = 0; i < m; i++) {
		suma = suma + mat[i][n];
	}

	return(mat);

}


void main() {

	float** mat;
	float* niz;
	int m, n;
	int i, j;
	int suma = 0;
	float prosek;
	int count = 0;

	printf("Unesite broj radnika:\n");
	scanf("%d", &m);

	printf("Unesite broj aktivnosti:\n");
	scanf("%d", &n);

	niz = malloc(n * sizeof(float));
	if (niz == NULL) {
		printf("Alokacija nije uspela.");
		exit(EXIT_FAILURE);
	}

	for (i = 0; i < n; i++) {
		printf("Unesite cenu aktivnosti %d:  ", i + 1);
		scanf("%f", &niz[i]);
	}

	mat = malloc(m * sizeof(float*));
	if (mat == NULL) {
		printf("Alokacija nije uspela.");
		exit(EXIT_FAILURE);
	}

	for (i = 0; i < m; i++) {
		mat[i] = malloc((n + 1) * sizeof(float));
		if (mat[i] == NULL) {
			printf("Alokacija nije uspela.");
			exit(EXIT_FAILURE);
		}
		for (j = 0; j < n; j++) {
			printf("Unesite ucinak rada za %d. radnika %d. radne aktivnosti: ", i + 1, j + 1);
			scanf("%f", &mat[i][j]);
		}
	}

	mat = obrada(mat, niz, m, n);

	for (i = 0, suma = 0; i < m; i++) {
		suma = suma + mat[i][n];
	}

	prosek = suma / m;
	printf("Prosecna plata je:\n");
	printf("%.2f\n", prosek);

	for (i = 0; i < m - 1; i++)
		if (mat[i][n] < prosek) {
			count++;
			mat[i] = mat[i + 1];
		}

	if (mat[m - 1][n] < prosek) count++;

	m = m - count;


	printf("Plate radnika veæe od proseka su: \n");
	printf("\n");
	for (i = 0; i < m; i++)
		printf("%d.%6.0f   ", i + 1, mat[i][n]);


	free(niz);
	for (i = 0; i < m; i++) free(mat[i]);
	free(mat);


}