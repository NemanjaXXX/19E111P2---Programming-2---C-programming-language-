//31.01.2013. drugi zadatak
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 11
typedef struct reci {
	char recA[MAX];
	struct reci* sled;
}Reci;
Reci* ucitavanje(Reci* lst) {
	FILE* p;
	Reci* novi, * posl = NULL;
	char recA1[MAX];
	p = fopen("a.txt", "r");
	if (p == NULL) {
		printf("Otvaranje datoteke nije uspelo!!!\n");
		exit(1);
	}
	while (fscanf(p, "%s", recA1) != EOF) {
		novi = malloc(sizeof(Reci));
		if (novi == NULL) {
			printf("Alokacija memorije nije uspela!!!\n");
			exit(1);
		}
		strcpy(novi->recA, recA1);
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
void obrada(Reci* lst) {
	FILE* p, * pok;
	Reci* tek;
	char recB1[MAX];
	p = fopen("b.txt", "r");
	pok = fopen("c.txt", "w");
	if (p == NULL || pok == NULL) {
		printf("Otvaranje datoteke nije uspelo!!!\n");
		exit(1);
	}
	while (fscanf(p, "%s", recB1) != EOF) {
		for (tek = lst; tek != NULL; tek = tek->sled) {
			fprintf(pok, "(%s,%s) ", tek->recA, recB1);
		}
		fprintf(pok, "\n");
	}
	fclose(p);
	fclose(pok);

}


Reci* brisanje(Reci* lst) {
	Reci* tek, * stari;
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
	Reci* lst;
	lst = NULL;
	lst = ucitavanje(lst);
	obrada(lst);
	lst = brisanje(lst);

}