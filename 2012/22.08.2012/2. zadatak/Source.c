//22.08.2012. drugi zadatak
#include <stdio.h>
#include <stdlib.h>
typedef struct agencije {
	int redag;
	int redap;
	int cenapodanu; //receno u zadatku da je i cena ceo broj
	struct agencije* sled;
}Agencije;
Agencije* ucitaj(Agencije* lst) {
	FILE* p;
	Agencije* novi, * posl = NULL;
	int redag1;
	int redap1;
	int cenapodanu1;
	p = fopen("agencije.txt", "r");
	if (p == NULL) {
		printf("Neuspesno otvaranje datoteke!!!\n");
		exit(1);
	}
	while (fscanf(p, "%d%d%d", &redag1, &redap1, &cenapodanu1) != EOF) {
		novi = malloc(sizeof(Agencije));
		if (novi == NULL) {
			printf("Alokacija memorije nije uspela!!!\n");
			exit(1);
		}
		novi->redag = redag1;
		novi->redap = redap1;
		novi->cenapodanu = cenapodanu1;
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
Agencije* obrada(Agencije* lst) {
	FILE* p;
	Agencije* tek;
	int redap2;
	int redag2;
	int trajdana2;
	int zarada = 0;
	p = fopen("najam.txt", "r");
	if (p == NULL) {
		printf("Neuspesno otvaranje datoteke!!!\n");
		exit(1);
	}
	while (fscanf(p, "%d%d%d", &redap2, &redag2, &trajdana2) != EOF) {
		for (tek = lst; tek != NULL; tek = tek->sled) {
			if (redag2 == tek->redag && redap2 == tek->redap) {
				zarada += trajdana2 * tek->cenapodanu;
			}
		}
	}
	printf("Vasa zarada iznosi: %d\n", zarada);
	fclose(p);
	return lst;
}
Agencije* brisanje(Agencije* lst) {
	Agencije* tek, * stari;
	tek = lst;
	while (tek != NULL) {
		stari = tek;
		tek = tek->sled;
		free(stari);
	}
	lst == NULL;
	return lst;

}
void main() {
	Agencije* lst;
	lst = NULL;
	lst = ucitaj(lst);
	lst = obrada(lst);
	lst = brisanje(lst);


}