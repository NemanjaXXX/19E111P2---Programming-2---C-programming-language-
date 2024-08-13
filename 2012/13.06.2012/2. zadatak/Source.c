// 13.06.2012. drugi zadatak 0 errors 4 warnings
#include <stdio.h>
#include <stdlib.h>
#define MAX 81
typedef struct kalendar {
	int satip;
	int minutip;
	int satik;
	int minutik; // minutik- k kao kraj p kao pocetak, moze novi typedef ali msm da nisu tako mislili
	char opis[MAX];
	struct kalendar* sled;
}Kalendar;
Kalendar* ucitaj(Kalendar* lst) {
	Kalendar* novi, * pret = NULL, * tek;
	int satip1;
	int minutip1;
	int satik1;
	int minutik1;
	char opis1[MAX];
	FILE* p;
	p = fopen("kalendar.txt", "r");
	if (p == NULL) {
		printf("Neuspesno otvaranje datoteke!!!\n");
		exit(1);
	}
	while (fscanf(p, "%d:%d-%d:%d", &satip1, &minutip1, &satik1, &minutik1) != EOF) {
		fgets(opis1, 70, p); // 81-11 zbog termina koji su procitani
		novi = malloc(sizeof(Kalendar));
		if (novi == NULL) {
			printf("Alokacija memorije nije uspela!!!\n");
			exit(1);
		}
		novi->satip = satip1;
		novi->minutip = minutip1;
		novi->satik = satik1;
		novi->minutik = minutik1;
		strcpy(novi->opis, opis1); // strcpy(destination,source);
		novi->sled = NULL;
		if (lst == NULL) {
			lst = novi;
		}
		else {
			for (tek = lst; tek != NULL && (tek->satip < novi->satip || (tek->satip == novi->satip && tek->minutip < novi->minutip)); tek = tek->sled) { // tek je tu zbog dodavanja na kraj ako nista ne bude ispunjeno on ce nekada postati NULL
				pret = tek;
			}

			if (tek == lst) {
				novi->sled = lst;
				lst = novi;

			}
			else {
				novi->sled = tek;
				pret->sled = novi;
			}
		}
	}
	fclose(p);
	return lst;
}
Kalendar* obrada(Kalendar* lst) {
	Kalendar* tek, * stari;
	FILE* p;
	p = fopen("preklapanja.txt", "w");
	if (p == NULL) {
		printf("Neuspesno kreiranje datoteke!!!\n");
		exit(1);
	}
	for (tek = lst; tek->sled != NULL;) {
		if ((tek->satik > tek->sled->satip) || (tek->satik == tek->sled->satip && tek->satik > tek->sled->minutip)) {
			fprintf(p, "%02d:%02d-%02d:%02d %s\n", tek->sled->satip, tek->sled->minutip, tek->sled->satik, tek->sled->minutik, tek->sled->opis);
			stari = tek->sled;
			tek->sled = stari->sled;
			free(stari);
		}
		else {
			tek = tek->sled;
		}
	}

	fclose(p);
	return lst;
}
Kalendar* brisanje(Kalendar* lst) {
	Kalendar* stari, * tek;
	tek = lst;
	while (tek != NULL) {
		stari = tek;
		tek = tek->sled;
		free(stari);
	}
	lst = NULL;
	return lst;
}
void main() {
	Kalendar* lst;
	lst = NULL;
	lst = ucitaj(lst);
	lst = obrada(lst);
	lst = brisanje(lst);
	system("pause");
}
