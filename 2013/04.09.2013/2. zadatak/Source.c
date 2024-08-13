// 04.09.2013. drugi zadatak
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
typedef struct pacijent {
	int id;
	char ime[MAX];
	char prezime[MAX];
	struct pacijenti* sled;
}Pacijent;
typedef struct zub {
	int identf;
	char vilica;
	char strana;
	int redbr;
	float cena;
	int brojac;
	struct zub* sled;
}Zub;
Pacijent* ucitavanje(Pacijent* lst) {
	FILE* p;
	Pacijent* novi, * posl = NULL;
	int id1;
	char ime1[MAX];
	char prezime1[MAX];
	p = fopen("pacijenti.txt", "r");
	if (p == NULL) {
		printf("Neuspesno otvaranje datoteke!!!\n");
		exit(1);
	}
	while (fscanf(p,"%d %s %s", &id1, ime1, prezime1) != EOF) {
		novi = malloc(sizeof(Pacijent));
		if (novi == NULL) {
			printf("Alokacija nije uspela!\n");
			exit(1);
		}
		novi->id = id1;
		strcpy(novi->ime, ime1);
		strcpy(novi->prezime, prezime1);
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
Zub* ucitavanje1(Zub* lst1) {
	char vilica1;
	char strana1;
	int redbr1;
	float cena1;
	int identf1;
	int d, m, g;
	int ima;
	FILE* p;
	Zub* novi, * posl = NULL, * tek = NULL;
	p = fopen("intervencije.txt", "r");
	if (p == NULL) {
		printf("Neuspesno otvaranje datoteke!!!\n");
		exit(1);
	}
	while (fscanf(p, "%d %d.%d.%d. %c %c %d %f", &identf1, &d, &m, &g, &vilica1, &strana1, &redbr1, &cena1) != EOF) {
		ima = 0;
		for (tek = lst1; tek != NULL; tek = tek->sled) { // msm da hoce a da li ce for vracati stalno lst1 na pocetak
			if (tek->vilica == vilica1 && tek->strana == strana1 && tek->redbr == redbr1) {
				tek->brojac++;
				ima = 1;
				break;
			}

		}
		if (ima == 0) {
			novi = malloc(sizeof(Zub));
			if (novi == NULL) {
				printf("Alokacija nije uspela!!!\n");
				exit(1);
			}
			novi->identf = identf1;
			novi->vilica = vilica1;
			novi->strana = strana1;
			novi->redbr = redbr1;
			novi->cena = cena1;
			novi->brojac = 0;
			novi->sled = NULL;
			if (lst1 == NULL) {
				lst1 = novi;
				
			}
			else {
				posl->sled = novi;
				
			}
			posl = novi;
		}
	}
	fclose(p);
	return lst1;
}
void obrada(Pacijent* lst, Zub* lst1) {
	char mesto, unstrana;
	int broj;
	int pomid = 0;
	int pombr = 0;
	Zub* tek;
	Pacijent* pok;
	float ukupnacena;
	printf("Unesite oznaku jednog zuba:\n");
	scanf("%c%c%d", &mesto, &unstrana, &broj);
	for (tek = lst1; tek != NULL; tek = tek->sled) {
		if (tek->vilica == mesto && tek->strana == unstrana && tek->redbr == broj && tek->brojac > pombr) {
			pomid = tek->identf;
			pombr = tek->brojac;
			ukupnacena = tek->brojac * tek->cena;
		}
	}
	for (pok = lst; pok != NULL; pok = pok->sled) {
		if (pomid == pok->id) {
			printf("%d %s %s %f", pok->id, pok->ime, pok->prezime, ukupnacena);
		}
	}
}
Pacijent* obrisi(Pacijent* lst) {
	Pacijent* tek, * stari;
	tek = lst;
	while (tek != NULL) {
		stari = tek;
		tek = tek->sled;
		free(stari);
	}
	lst = NULL;
	return lst;
}
Zub* obrisi1(Zub* lst1) {
	Zub* tek, * stari;
	tek = lst1;
	while (tek != NULL) {
		stari = tek;
		tek = tek->sled;
		free(stari);
	}
	lst1 = NULL;
	return lst1;
}

void main() {
	Pacijent* lst;
	Zub* lst1;
	lst = NULL;
	lst1 = NULL;
	lst = ucitavanje(lst);
	lst1 = ucitavanje1(lst1);
	obrada(lst, lst1);
	lst = obrisi(lst);
	lst1 = obrisi1(lst1);

}
