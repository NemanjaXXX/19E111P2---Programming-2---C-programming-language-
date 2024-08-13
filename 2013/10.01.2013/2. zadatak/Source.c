//10.01.2013. drugi zadatak
#include <stdio.h>
#include <stdlib.h>

int ucitaj(int*** adr_mat, int* adr_n) {
	int** mat, n, i, j;
	//ucitavanje dimenzija
	printf("Unesite velicinu matrice: ");
	scanf("%d", &n);
	//greka je ako je n<= 0 i vracamo 0
	if (n <= 0) return 0;
	//rezervisanje memorije
	mat = calloc(n, sizeof(int*));
	for (i = 0; i < n; i++) {
		mat[i] = calloc(n, sizeof(int));
	}
	//ucitavanje vrednosti u matricu
	printf("Unesite matricu:\n");
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			scanf("%d", &mat[i][j]);
		}
	}
	//upisivanje adrese pocetka matrice i
	//duzine na prosledjene lokacije
	*adr_mat = mat;
	*adr_n = n;
	//1 znaci uspeh
	return 1;
}

void obrisi(int** mat, int n) {
	int i;
	for (i = 0; i < n; i++) {
		free(mat[i]);
	}
	free(mat);
}

void provera(int** mat, int n) {
	int i, j;
	int gornja, donja;

	//proveravamo da li je gornja trougaona
	//pretpostavimo da jeste tako sto u gornja upisemo 1
	//probamo da vidimo da li ima neku nenultu vrednost
	//iznad glavne dijagonale
	//iznad glavne dijagonale se krecemo tako sto je
	//brojac i=0..n, dok je za svako i brojac j=i+1..n
	gornja = 1;
	for (i = 0; i < n; i++) {
		for (j = i + 1; j < n; j++) {
			if (mat[i][j] != 0) {
				gornja = 0;
				break;
			}
		}
	}
	if (gornja) printf("Matrica je gornja trougaona.\n");

	//isto proveravamo da li je donja, samo sto brojaci idu tako
	//da je i=1..n, dok je za svako i brojac j=0..i
	donja = 1;
	for (i = 1; i < n; i++) {
		for (j = 0; j < i; j++) {
			if (mat[i][j] != 0) {
				donja = 0;
				break;
			}
		}
	}
	if (donja) printf("Matrica je donja trougaona.\n");
}

void main() {
	int** mat, n;
	ucitaj(&mat, &n);
	provera(mat, n);
	obrisi(mat, n);
}