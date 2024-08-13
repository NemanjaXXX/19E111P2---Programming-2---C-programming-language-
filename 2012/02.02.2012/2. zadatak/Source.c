#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 51
typedef struct proizvod {
	int sifra, zapremina;
	char naziv[MAX];
	struct proizvod* sled;
}Proizvodi;
//ucitavanje elemenata iz datoteke po nerastucoj vrednosti zapremine
Proizvodi* ucitavanje(Proizvodi* lst) {
	FILE* p;
	Proizvodi* tek, * novi, * pret = NULL;
	int sifra1, zapremina1;
	char naziv1[MAX];
	p = fopen("posiljka.txt", "r");
	if (p == NULL) {
		printf("Otvaranje datoteke nije uspelo.\n");
		exit(1);
	}
	while (fscanf(p, "%d %d %s", &sifra1, &zapremina1, naziv1) != EOF) { // ne treba ampers jer je ime niza staticki pokazivac na prvi element

		novi = malloc(sizeof(Proizvodi));
		if (novi == NULL) {
			printf("Alikacija memorije nije uspela.\n");
			exit(1);
		}
		strcpy(novi->naziv, naziv1); // strcpy(destinacion, source);
		novi->sifra = sifra1;
		novi->zapremina = zapremina1;
		novi->sled = NULL;

		if (lst == NULL) {
			lst = novi;
		}
		else {
			tek = lst;
			while (tek != NULL) {
				if (tek->zapremina < novi->zapremina) {
					if (tek == lst) { // ubacivanje na pocetak
						novi->sled = lst;
						lst = novi;
					}
					else {
						pret->sled = novi;
						novi->sled = tek;
					}
					break;
				}
				else {
					pret = tek;
					if (tek->sled == NULL) {
						tek->sled = novi;
						break;
					}
					tek = tek->sled;
				}

			}
		}

	}
	fclose(p);
	return lst;
}
// pakovanje
Proizvodi* obrada(Proizvodi* lst) {
	int zaprpaketa = 10000, punjenje = 0, brpaketa = 1;
	Proizvodi* tek;
	tek = lst;

	while (tek) {
		if ((punjenje + tek->zapremina) <= zaprpaketa) {
			punjenje += tek->zapremina;
			printf("Element %d. paketa: %d %d %s\n", brpaketa, tek->sifra, tek->zapremina, tek->naziv);
			tek = tek->sled;
		}
		else {
			punjenje = 0;
			brpaketa++;
		}
	}
	printf("Broj paketa je: %d\n", brpaketa);
}

void main() {
	Proizvodi* lst;
	lst = NULL;
	lst = ucitavanje(lst);
	lst = obrada(lst);

	system("pause");

}