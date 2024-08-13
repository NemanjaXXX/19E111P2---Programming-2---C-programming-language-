//22.09.2010. drugi zadatak
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct deo {

	int sifra;
	int kolicina;
	struct deo* sled;
} Deo;

Deo* ucitaj() {
	Deo* novi = NULL, * glava = NULL, * pret = NULL, t;
	FILE* dat = NULL;
	dat = fopen("magacin.txt", "r");

	while ((fscanf(dat, "%d%d", &t.sifra, &t.kolicina)) == 2) {

		novi = malloc(sizeof(Deo));
		if (!novi) { printf("Neuspesna alokacija\n"); exit(1); }
		*novi = t;
		if (!glava) { glava = novi; pret = novi; novi->sled = NULL; }
		else
		{
			pret->sled = novi; pret = novi; novi->sled = NULL;
		}



	}
	fclose(dat);
	return glava;

}

void obrada(Deo* lista) {
	int i = 0, k = 0;
	Deo t, * pom = NULL;
	FILE* dat = NULL;
	dat = fopen("proizvod.txt", "r");
	while ((fscanf(dat, "%d%d", &t.sifra, &t.kolicina)) == 2) {
		i++;
		pom = lista;
		while (pom) {

			if (pom->sifra == t.sifra) {
				if (pom->kolicina >= t.kolicina) { k++; break; }
				else break;
			}
			pom = pom->sled;

		}
		if (k < i) {
			printf("Nije moguce sklopiti proizvod.\n"); fclose(dat); return;
		}
	}
	printf("Moguce je sklopiti proizvod.\n"); fclose(dat); return;

}




void brisi(Deo* lista) {

	Deo* t;
	while (lista) {
		t = lista;
		lista = lista->sled;
		free(t);
	}
}


int main() {
	Deo* lista;


	lista = ucitaj();
	obrada(lista);
	brisi(lista);
	system("pause");
}