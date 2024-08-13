//06.07.2011. prvi zadatak
#include <stdio.h>
#include <math.h>
#define MAX 21
void ucitavanje(int niz[MAX], int n) {
	int i;
	printf("Unesite koeficijente:");
	for (i = 0; i <= n; i++) {
		scanf("%d", &niz[i]);
	}
}
void ispis(int niz[MAX], int n) {
	int i;
	printf("Polinom je:\n");
	for (i = 0; i <= n; i++) {
		if (niz[i] != 0 && n != 0) {
			printf(" %d*x^%d+", niz[i], n - 1);
		}
		if (i == n) {
			printf("%d", niz[i]);
		}
	}
}
void tabeliranje(int niz[MAX], int n) {
	int x, i;
	float suma;
	for (x = 1; x <= 100; x++) {
		suma = 0;
		for (i = 0; i <= n; i++) {
			suma += niz[i] * pow(x, n - 1);
		}
		printf(" P(%d)= %.2f\n", x, suma);
	}
}
void main() {
	int i, n;
	int niz[MAX];
	while (1) {
		printf("Unesite stepen polinoma:\n");
		scanf("%d", &n);
		if (n > 20 || n == -1) {
			printf("ERROR!");
			exit(1);
		}
		ucitavanje(niz, n);
		ispis(niz, n);
		tabeliranje(niz, n);
	}
	system("pause");
}