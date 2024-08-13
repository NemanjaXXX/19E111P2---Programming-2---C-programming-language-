// 15.06.2011. prvi zadatak
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 31
typedef struct teniseri {
	int sifra;
	char ime[MAX];
	char prezime[MAX];
	int imaATP;
	struct teniseri* sled;

}Teniseri;
Teniseri* ucitavanje(Teniseri* lst) {
	FILE* p;
	int sifra1;
	char ime1[MAX];
	char prezime1[MAX];
	int imaATP1;
	Teniseri* novi, * posl = NULL;
	p = fopen("teniseri.txt", "r");
	if (p == NULL) {
		printf("Otvaranje datoteke nije uspelo!!!\n");
		exit(1);
	}
	while (fscanf(p, "%d %s %s %d", &sifra1, ime1, prezime1, &imaATP1) != EOF) {
		novi = malloc(sizeof(Teniseri));
		if (novi == NULL) {
			printf("Alokacija memorije nije uspela!!!\n");
			exit(1);
		}
		novi->sifra = sifra1;
		strcpy(novi->ime, ime1);
		strcpy(novi->prezime, prezime1);
		novi->imaATP = imaATP1;
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
Teniseri* obrada(Teniseri* lst) {
	FILE* q;
	int sifra1;
	int braniATP1;
	int osvoioATP1;
	Teniseri* tek;
	q = fopen("wimbledon.txt", "r");
	if (q == NULL) {
		printf("Otvaranje datoteke nije uspelo!!!\n");
		exit(1);
	}
	while (fscanf(q, "%d %d %d", &sifra1, &braniATP1, &osvoioATP1) != EOF) {
		for (tek = lst; tek != NULL; tek = tek->sled) {
			if (tek->sifra == sifra1) {
				tek->imaATP += (osvoioATP1 - braniATP1);
			}
		}
	}
	fclose(q);
	return lst;
}
void ispis(Teniseri* lst) {
	FILE* p;
	Teniseri* tek;
	p = fopen("atplista.txt", "w");
	if (p == NULL) {
		printf("Kreiranje datoteke nije uspelo!!!\n");
		exit(1);
	}
	for (tek = lst; tek != NULL; tek = tek->sled) {
		fprintf(p, "%d %s %s %d\n", tek->sifra, tek->ime, tek->prezime, tek->imaATP);
	}
}
Teniseri* obrisi(Teniseri* lst) {
	Teniseri* tek, * stari;
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
	Teniseri* lst;
	lst = NULL;
	lst = ucitavanje(lst);
	lst = obrada(lst);
	ispis(lst);
	lst = obrisi(lst);
	system("pause");

}

