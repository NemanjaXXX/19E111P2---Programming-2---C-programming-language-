//15.06.2011. drugi zadatak
#include <stdio.h>
#include <stdlib.h>

#define MAX_EL 20

typedef struct {
	int m, n;
	int data[MAX_EL][MAX_EL];
} Matrica;

int UcitajMatricu(Matrica* matrica);
int NadjiMinimum(Matrica* matrica);
void IspisiVrste(Matrica* matrica, int minimum);

int main(int argc, char** argv) {
	Matrica matrica;
	int minimum;

	while (UcitajMatricu(&matrica)) {
		minimum = NadjiMinimum(&matrica);
		IspisiVrste(&matrica, minimum);
	}

	system("PAUSE");
	return 0;
}

//vraca 0 u slucaju nekorektnih dimenzija
int UcitajMatricu(Matrica* matrica) {
	int m, n, i, j;
	printf("Unesite broj vrsta matrice: ");
	scanf("%d", &m);
	if ((m < 1) || (m > MAX_EL))
		return 0;
	printf("Unesite broj kolona matrice: ");
	scanf("%d", &n);
	if ((n < 1) || (n > MAX_EL))
		return 0;
	matrica->m = m;
	matrica->n = n;
	for (i = 0; i < m; i++) {
		printf("Unesite elemente %d. reda: ", i + 1);
		for (j = 0; j < n; scanf("%d", &matrica->data[i][j++]));
	}
	return 1;
}

//vraca minimalan element matrice
int NadjiMinimum(Matrica* matrica) {
	int i, j, min;
	min = matrica->data[0][0];
	for (i = 0; i < matrica->m; i++)
		for (j = 0; j < matrica->n; j++)
			if (min > matrica->data[i][j])
				min = matrica->data[i][j];
	return min;
}

void IspisiVrste(Matrica* matrica, int minimum) {
	int i, j, nasao;
	for (i = 0; i < matrica->m; i++) { //prodji kroz sve redove
		nasao = 0;
		for (j = 0; j < matrica->n; j++) //proveri svaki element i-og reda
			if (matrica->data[i][j] == minimum) { //ako ima minimalan element
				nasao = 1;                       //ne treba ispisati
				break;
			}
		if (!nasao) { //ako nije nasao minimalan element u i-om redu -> ispisi
			for (j = 0; j < matrica->n; j++)
				printf("%d ", matrica->data[i][j]);
			putchar('\n');
		}
	}
}