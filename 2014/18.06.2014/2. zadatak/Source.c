#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct prodavnica {
	char naziv[31];
	int kol;
	float cena;
	struct prodavnica* sled;
}Prodavnica;

Prodavnica* ucitaj(Prodavnica* lst) {
	FILE* prod;
	char naziv1[31];
	int kol1;
	float cena1;
	Prodavnica* novi, * posl = NULL;

	prod = fopen("prodavnica.txt", "r");
	if (prod == NULL) {
		printf("Neuspesno otvaranje! \n");
		exit(1);
	}

	while (fscanf(prod, "%s %d %f", naziv1, &kol1, &cena1) != EOF) { // fscanf(pokazivac na datoteku, "konverzije", gdeSmestamo1, gdeSmestamo2, gdeSmestamoItd)!=krajaDatoteke
		novi = malloc(sizeof(Prodavnica)); //malloc vraca pokazivac na alocirani prostor
		if (novi == NULL) {
			printf("Alokacija neuspesna!\n");
			exit(1);
		}
		// popunjavamo element liste, strukturu na koju pokazuje novi
		strcpy(novi->naziv, naziv1); // strcpy(gde kopiramo, odakle kopiramo)
		novi->kol = kol1;
		novi->cena = cena1;
		novi->sled = NULL;

		//ulancavanje liste, dodavanje na kraj
		if (lst == NULL)
			lst = novi;
		else
			posl->sled = novi;

		//izvan if-a
		posl = novi;
	}
	fclose(prod);
	return lst;
}

Prodavnica* obrada(Prodavnica* lst) {
	Prodavnica* tek;
	FILE* potr, * fakt;
	char naziv2[31];
	int kol2;
	float ukupanRacun;

	potr = fopen("potrepstine.txt", "r");
	fakt = fopen("faktura.txt", "w");
	if (potr == NULL || fakt == NULL) {
		printf("Neuspesno otvaranje!!\n");
	}

	ukupanRacun = 0;
	while (fscanf(potr, "%s %d", naziv2, &kol2) != EOF) {
		tek = lst;
		while (tek) {
			if ((strcmp(tek->naziv, naziv2) == 0) && (tek->kol >= kol2)) { // strcmp(pokazivac na prvi string, pokazivac na drugi string), ako su isti vraca 0 u suprotnom nesto razlicito od 0
				fprintf(fakt, "%s %d %.2f %.2f\n", naziv2, kol2, tek->cena, tek->cena * kol2); // fprintf(pokazivac na datoteku, "konverzija", odakle citamo 1, odakle citamo 2, odakle citamo itd.); 
				ukupanRacun += tek->cena * kol2;
				tek->kol = tek->kol - kol2;
			}
			tek = tek->sled;
		}
	}
	fprintf(fakt, "%.2f\n", ukupanRacun);
	fclose(potr);
	fclose(fakt);
	return lst;
}

Prodavnica* obrisi(Prodavnica* lst) {
	Prodavnica* tek, * stari;

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
	Prodavnica* lst;
	lst = NULL;

	lst = ucitaj(lst);
	lst = obrada(lst);
	lst = obrisi(lst);


	system("pause");
}
