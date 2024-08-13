// 03.07.2013. drug zadatak
#include <stdio.h>
#include <stdlib.h>
typedef struct racuni {
	int idracuna;
	float iznos;
	struct racuni* sled;

}Racuni;

Racuni* ucitaj(Racuni* lst) {
	FILE* p;
	Racuni* novi, * posl = NULL;
	int idracuna1;
	float iznos1;
	p = fopen("racuni.txt", "r");
	if (p == NULL) exit(1);
	while (fscanf(p, "%d%f", &idracuna1, &iznos1) != EOF) {
		novi = malloc(sizeof(Racuni));
		if (novi == NULL) {
			printf("Alokacija nije uspela.");
			exit(1);
		}
		novi->idracuna = idracuna1;
		novi->iznos = iznos1;
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
Racuni* obrada(Racuni* lst) {
	int idsakog, idenakoji;
	float iznostrans;
	Racuni* tek;
	FILE* p;
	p = fopen("transakcije.txt", "r");
	if (p == NULL) {
		printf("Neuspesno otvaranje.");
		exit(1);
	}
	while (fscanf(p, "%d%d%f", &idsakog, &idenakoji, &iznostrans) != EOF) {
		for (tek = lst; tek != NULL; tek = tek->sled) {
			if (idsakog == tek->idracuna) {
				tek->iznos -= iznostrans;
			}
			if (idenakoji == tek->idracuna) {
				tek->iznos += iznostrans;
			}

		}

	}
	fclose(p);
	return lst;
}
void ispis(Racuni* lst) {
	Racuni* tek;
	FILE* pok;
	pok = fopen("minusi.txt", "w");
	if (pok == NULL) {
		printf("Neuspesno kreiranje datoteke.");
		exit(1);
	}
	for (tek = lst; tek != NULL; tek = tek->sled) {
		if (tek->iznos < 0) {
			fprintf(pok, "%d %.2f\n", tek->idracuna, tek->iznos);
		}
	}
	fclose(pok);
}
Racuni* obrisi(Racuni* lst) {
	Racuni* tek, * stari;
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
	Racuni* lst;
	lst = NULL;
	lst = ucitaj(lst);
	lst = obrada(lst);
	ispis(lst);
	lst = obrisi(lst);


}