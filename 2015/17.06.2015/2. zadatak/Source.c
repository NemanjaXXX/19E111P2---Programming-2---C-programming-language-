#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 31
typedef struct univerziteti {
	char naziv[MAX];
	float poeniponov, poenipostar;
	int rangnova, rangstara;
	int razlrangova;
	struct univerziteti* sled;
}Univerziteti;
float brpoena(int f1, int f2, int f3, int f4, float uticaj1, float uticaj2, float uticaj3, float uticaj4) {
	float rezultat;
	rezultat = f1 * uticaj1 + f2 * uticaj2 + f3 * uticaj3 + f4 * uticaj4;
	return rezultat;
}
Univerziteti* ucitaj(Univerziteti* lst) {
	FILE* p;
	Univerziteti* novi, * posl = NULL;
	char naziv1[MAX];
	int a, b, c, d;
	p = fopen("univerziteti.txt", "r");
	if (p == NULL) {
		printf("Otvaranje datoteke nije uspelo!!!\n");
		exit(1);
	}
	while (fscanf(p, "%s %d %d %d %d", naziv1, &a, &b, &c, &d) != EOF) {
		novi = malloc(sizeof(Univerziteti));
		if (novi == NULL) {
			printf("Alokacija memorije neuspesna.!!!\n");
			exit(1);
		}
		strcpy(novi->naziv, naziv1);
		novi->poenipostar = brpoena(a, b, c, d, 0.2, 0.5, 0.15, 0.15);
		novi->poeniponov = brpoena(a, b, c, d, (1 / 2.), (1 / 6.), (1 / 6.), (1 / 6.));
		novi->sled = NULL;
		if (lst == NULL) {
			lst = novi;
		}
		else {
			posl->sled = novi;
		}
		posl = novi;
	}
	fclose(p);
	return lst;
}
Univerziteti* rang(Univerziteti* lst) {
	float pom, pom1;
	char pomnaz[MAX];
	Univerziteti* tek, * tek1;
	int rang = 1;
	for (tek = lst; tek->sled != NULL; tek = tek->sled) {
		for (tek1 = tek->sled; tek1 != NULL; tek1 = tek1->sled) {
			if (tek->poeniponov > tek1->poeniponov) {
				pom = tek1->poeniponov;
				tek1->poeniponov = tek->poeniponov;
				tek->poeniponov = pom;

				pom1 = tek->poenipostar;
				tek->poenipostar = tek1->poenipostar;
				tek1->poenipostar = pom1;

				strcpy(pomnaz, tek->naziv);
				strcpy(tek->naziv, tek1->naziv);
				strcpy(tek1->naziv, pomnaz);

			}
		}
		tek->rangnova = rang;
		rang++;
	}
	tek->rangnova = rang;

	rang = 1;
	for (tek = lst; tek->sled != NULL; tek = tek->sled) {
		for (tek1 = tek->sled; tek1 != NULL; tek1 = tek1->sled) {
			if (tek->poenipostar > tek1->poenipostar) {
				pom = tek1->poeniponov;
				tek1->poeniponov = tek->poeniponov;
				tek->poeniponov = pom;

				pom1 = tek->poenipostar;
				tek->poenipostar = tek1->poenipostar;
				tek1->poenipostar = pom1;

				strcpy(pomnaz, tek->naziv);
				strcpy(tek->naziv, tek1->naziv);
				strcpy(tek1->naziv, pomnaz);

			}
		}
		tek->rangstara = rang;
		rang++;
	}
	tek->rangstara = rang;
	return lst;
}
int razlika(Univerziteti* lst) {
	Univerziteti* tek;
	int max;
	tek = lst;
	while (tek) {
		tek->razlrangova = tek->rangnova - tek->rangstara;
		tek = tek->sled;
	}
	tek = lst;
	max = tek->razlrangova;
	tek = tek->sled;
	while (tek) {
		if (max < tek->razlrangova) {
			max = tek->razlrangova;
		}
		tek = tek->sled;
	}
	return max;
}
Univerziteti* obrisi(Univerziteti* lst) {
	Univerziteti* tek, * stari;
	tek = lst;
	while (tek) {
		stari = tek;
		tek = tek->sled;
		free(stari);
	}
	lst = NULL;
	return lst;
}
void main() {
	FILE* p;
	Univerziteti* lst, * tek;
	int maxrazlika;
	lst = NULL;
	lst = ucitaj(lst);
	lst = rang(lst);
	maxrazlika = razlika(lst);
	p = fopen("izlaz.txt", "w");
	if (p == NULL) {
		printf("Neuspesno otvaranje datoteke!!!\n");
		exit(1);
	}
	tek = lst;
	while (tek) {
		if (maxrazlika == tek->razlrangova) {
			fprintf(p, "%s\n", tek->naziv);

		}
		tek = tek->sled;
	}
	lst = obrisi(lst);


}