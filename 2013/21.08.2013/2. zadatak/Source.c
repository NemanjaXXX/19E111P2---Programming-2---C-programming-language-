//21.08.2013. drugi zadatak 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct nekretnine {
	int mesec;
	int godina;
	float cena;
	float prosek;
	int brojac;
	struct nekretnine* sled;
}Nekretnine;
Nekretnine* ucitavanje(Nekretnine* lst) {
	FILE* p;
	Nekretnine* novi, * sled, * tek, * pret = NULL;
	int pom, ima;
	int mesec1, godina1;
	float cena1;
	p = fopen("nekretnine.txt", "r");
	if (p == NULL) {
		printf("Otvaranje nije uspelo!!!\n");
		exit(1);
	}
	while (fscanf(p, "%d.%d.%d. %f", &pom, &mesec1, &godina1, &cena1) != EOF) {
		ima = 0;
		for (tek = lst; tek != NULL; tek = tek->sled) {
			if (tek->mesec == mesec1 && tek->godina == godina1) {
				ima = 1;
				tek->brojac++;
				tek->cena += cena1;
				break;
			}
		}
		if (ima == 0) {
			novi = malloc(sizeof(Nekretnine));
			if (novi == NULL) {
				printf("Alokacija nije uspela!!!\n");
				exit(1);
			}

			novi->mesec = mesec1;
			novi->godina = godina1;
			novi->cena = cena1;
			novi->brojac = 1;
			novi->sled = NULL;
			if (lst == NULL) {
				lst = novi;
			}
			else {
				for (tek = lst; tek != NULL && tek->mesec < novi->mesec && tek->godina < novi->godina; tek = tek->sled) {
					pret = tek;
				}
				if (tek == lst) {
					novi->sled = lst;
					lst = novi;
				}
				else {
					pret->sled = novi;
					novi->sled = tek;
				}
			}
		}
	}
	fclose(p);
	return lst;
}
void obrada(Nekretnine* lst) {
	Nekretnine* tek;
	float max;
	for (tek = lst; tek != NULL; tek = tek->sled) {
		tek->prosek = tek->cena / tek->brojac;
	}
	tek = lst;
	max = abs(tek->prosek - tek->sled->prosek);
	for (tek = lst->sled; tek->sled != NULL; tek = tek->sled) {
		if (abs(tek->prosek - tek->sled->prosek) > max) {
			max = abs(tek->prosek - tek->sled->prosek);
		}
	}
	printf("Maksimalna razlika je: %.2f\n", max);
}
Nekretnine* obrisi(Nekretnine* lst) {
	Nekretnine* tek, * stari;
	tek = lst;
	while (tek != NULL) {
		stari = tek;
		tek = tek->sled;
		free(stari);
	}
	lst = NULL;
	return lst;
}
int main() {
	Nekretnine* lst;
	lst = NULL;
	lst = ucitavanje(lst);
	obrada(lst);
	lst = obrisi(lst);
	system("pause");
	return 0;
}
