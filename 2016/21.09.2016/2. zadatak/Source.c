//21.09.2016. drugi zadatak
#include<stdio.h>
#include<stdlib.h>

typedef struct occurence {
	int ucitani_broj;
	int brojac;
	struct occurrence* sled;
}Occurence;

void addOccurrence(Occurence** lst, int num) {
	int postoji = 0;
	Occurence* tek, * novi;
	for (tek = *lst; tek != NULL; tek = tek->sled) {
		if (tek->ucitani_broj == num) {
			tek->brojac++;
			postoji = 1;
			break;
		}
		else postoji = 0;
	}
	if (postoji == 0) {
		novi = malloc(sizeof(Occurence));
		if (novi == NULL) {
			printf("Alokacija memorije nije uspela!!!\n");
			exit(1);
		}
		novi->ucitani_broj = num;
		novi->brojac = 1;
		novi->sled = NULL;
		if (*lst == NULL) {
			*lst = novi;
		}
		else {
			novi->sled = *lst;
			*lst = novi;
		}
	}
}

void obrada(Occurence* lst) {
	Occurence* tek;
	int najveci_br_pon;
	najveci_br_pon = lst->brojac;
	for (tek = lst; tek != NULL; tek = tek->sled) {
		if (tek->brojac > najveci_br_pon) {
			najveci_br_pon = tek->brojac;
		}
	}
	for (tek = lst; tek; tek = tek->sled) {
		if (tek->brojac == najveci_br_pon) {
			printf("%d %d\n", tek->ucitani_broj, tek->brojac);
		}
	}
}

Occurence* obrisi(Occurence* lst) {
	Occurence* tek, * stari;
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
	Occurence* lst, * tek;
	lst = NULL;
	int num = 1;
	while (num != 0) {
		scanf("%d", &num);
		if (num != 0) {
			addOccurrence(&lst, num);
		}
		else break;
	}
	obrada(lst);
	lst = obrisi(lst);
	system("pause");
}