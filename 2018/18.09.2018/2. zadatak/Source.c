//18.09.2018. drugi zadatak
#include <stdio.h>
#include <stdlib.h>


typedef struct stan {
	int broj;
	float cena, sirina, duzina;
	struct stan* sled;

}Stan;


Stan* ucitaj(Stan* lst) {
	FILE* p;
	int broj1;
	float cena1, sirina1, duzina1;
	Stan* novi, * posl;

	p = fopen("stanovi.txt", "r");
	if (p == NULL) {
		printf("Neuspesno otvaranje datoteke");
		exit(1);
	}

	while (fscanf(p, "&d &f &f &f", &broj1, &cena1, &sirina1, &duzina1) != EOF) {
		novi = malloc(sizeof(Stan));
		if (novi == NULL); {
			printf("Neuspela dodela memorije");
			exit(1);
		}
		novi->broj = broj1;
		novi->cena = cena1;
		novi->sirina = sirina1;
		novi->duzina = duzina1;
		novi->sled = NULL;
		if (lst == NULL)lst = novi;
		else posl->sled = novi;
		posl = novi;



	}
	fclose(p);
	return lst;
}



Stan* izbaci(Stan* lst) {
	float radijus;
	Stan* tek, * stari, * pret;

	printf("Unesite radijus pretrage: ");
	scanf("%f", &radijus);

	tek = lst;
	pret = NULL;
	while (tek) {
		if (tek->sirina > radijus || tek->duzina > radijus) {
			stari = tek;
			tek = tek->sled;
			if (pret == NULL) lst = tek;
			else pret->sled = tek;
			free(stari);
		}
		else {
			pret = tek;
			tek = tek->sled;
		}
	}
	return lst;
}


Stan* uredi(Stan* lst) {
	Stan* tek, * tek1;
	int broj = 0;
	float cena, sirina, duzina;
	cena = sirina = duzina = 0; // Smer grupisanja sa desna na levo.

	for (tek = lst; tek; tek = tek->sled) {
		for (tek1 = tek->sled; tek1; tek1 = tek1->sled) {
			if (tek1->cena < tek->cena) {
				broj = tek->broj;
				cena = tek->cena;
				sirina = tek->sirina;
				duzina = tek->duzina;

				tek1->broj = tek->broj;
				tek1->cena = tek->cena;
				tek1->sirina = tek->sirina;
				tek1->duzina = tek->duzina;

				tek->broj = broj;
				tek->cena = cena;
				tek->sirina = sirina;
				tek->duzina = duzina;


			}
		}
	}
	return lst;
}


void ispis(Stan* lst) {
	FILE* p;
	Stan* tek = lst;

	p = fopen("stanovi_filtrirano.txt", "w");
	if (p == NULL) {
		printf("Kreiranje datotekek nije uspelo!!!\n");
		exit(1);
	}

	while (tek) {
		fprintf(p, "%d %f %f %f", tek->broj, tek->cena, tek->sirina, tek->duzina);
		tek = tek->sled;
	}

}




int main() {
	Stan* lst = NULL;
	lst = ucitaj(lst);
	lst = izbaci(lst);
	lst = uredi(lst);
	ispis(lst);
	system("pause");
	return 0;
}