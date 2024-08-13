//21.08.2013. prvi zadatak
#include<stdio.h>
#include<stdlib.h>
typedef struct niz {
	int broj;
	int brojac;
}Niz;
Niz* ucitavanje(Niz* niz, int* duzina) {
	int i, broj1, j, brojTrenutnoUcitanih, ima;
	Niz* pom;
	brojTrenutnoUcitanih = 0;
	for (i = 0; i < *duzina; i++) {
		printf("Unesi element niza: ");
		scanf("%d", &broj1);
		if (broj1 < 0) exit(1);

		ima = 0;
		for (j = 0; j < brojTrenutnoUcitanih; j++) {
			if (broj1 == niz[j].broj) {
				niz[j].brojac++;
				ima = 1;
				break;
			}
		}

		if (ima == 0) {
			pom = realloc(niz, (brojTrenutnoUcitanih + 1) * sizeof(Niz));
			if (pom == NULL) {
				printf("Neuspela realokacija!! \n");
				exit(1);
			}
			niz = pom;
			niz[brojTrenutnoUcitanih].broj = broj1;
			niz[brojTrenutnoUcitanih].brojac = 1;
			brojTrenutnoUcitanih++;
		}
	}
	*duzina = brojTrenutnoUcitanih;
	return niz;
}
Niz* sortiranje(Niz* niz, int duzina) {
	int i;
	int j;
	Niz pom;
	for (i = 0; i < duzina; i++) {
		for (j = i + 1; j <= duzina; j++) {
			if (niz[i].brojac < niz[j].brojac) {
				pom = niz[i];
				niz[i] = niz[j];
				niz[j] = pom;
			}

		}
	}
	return niz;
}
void ispisi(Niz* niz, int duzina) {
	int i;
	for (i = 0; i < duzina; i++) {
		printf("%d ", niz[i].broj);
	}
}
int main() {
	Niz* niz;
	niz = NULL;
	int duzina;
	printf("Unesite duzinu niza:");
	scanf("%d", &duzina);
	if (duzina < 0) exit(1);
	niz = ucitavanje(niz, &duzina);
	niz = sortiranje(niz, duzina);
	ispisi(niz, duzina);
	free(niz);
	system("pause");
	return 0;
}
