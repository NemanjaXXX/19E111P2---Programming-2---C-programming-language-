//03.02.2011. drugi zadatak
#include <stdio.h>
#include <stdlib.h>



typedef struct usluga {
	int mesec;
	int dan;
	int sifra;
} Usluga;

typedef struct sifra {
	int sifra;
	float cena;
	int dohvat;
	struct sifra* sled;
} Sifra;

Sifra* ucitaj() {
	int i = 0;
	Sifra* novi = NULL, * pret = NULL, * glava = NULL, t;
	FILE* dat;
	dat = fopen("sifre.txt", "r");
	if (!dat) { printf("Neuspesno otvaranje datoteke sifre.txt\n"); exit(1); }
	while (fscanf(dat, "%d%f", &t.sifra, &t.cena) == 2) {

		novi = malloc(sizeof(Sifra));
		if (!novi) { printf("Neuspesna alokacija"); exit(1); }
		i++;
		if (i == 101) { printf("U datoteci sa siframa je previse sifara-moze da ih bude najvise 100\n"); exit(1); }
		t.dohvat = 0;
		*novi = t;
		if (!glava) { glava = novi; pret = novi; novi->sled = NULL; }
		else { pret->sled = novi; pret = novi; novi->sled = NULL; }

	}
	if (i == 0) { printf("Datoteka sa siframa je prazna\n"); exit(1); }

	fclose(dat);
	return glava;
	/*Eventualno moze da se doda pri unosu u listu provera da li se ponavlja sifra*/
}




void obradi(Sifra* lista) {
	float s = 0;
	Sifra* pom = NULL;
	Usluga t;
	FILE* dat;
	dat = fopen("medicus.txt", "r");
	if (!dat) { printf("Neuspesno otvaranje datoteke medicus.txt\n"); exit(1); }
	while (fscanf(dat, "%d%d%d", &t.mesec, &t.dan, &t.sifra) == 3) { /*Moze da se doda provera da li je dan od 1 do 31 i mesec od 1 do 12*/
		pom = lista;
		while (pom) {
			if (t.sifra == pom->sifra) {
				s += pom->cena; pom->dohvat++; break;
			}
			pom = pom->sled;
		}

	}

	printf("Bruto zarada cele klinike na godisnjem nivou je: %.2f\n", s);
	printf("Sifra usluge i broj pruzanja usluge:\n");
	pom = lista;
	while (pom) {
		printf("%d   %d\n", pom->sifra, pom->dohvat);
		pom = pom->sled;
	}


}


void brisi(Sifra* lista) {

	Sifra* t;
	while (lista) {
		t = lista;
		lista = lista->sled;
		free(t);
	}

}


int main() {
	Sifra* lista;
	lista = ucitaj();
	obradi(lista);
	brisi(lista);
	system("pause");

}