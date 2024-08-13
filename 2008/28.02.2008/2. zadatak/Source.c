//22.08.2008.drugi zadatak
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int sifra;
	char ime[10];
	char prezime[10];
	double suma;
} Potrosac;

typedef struct {
	int sifra;
	double uplata;
} Racun;

typedef struct elem {
	Racun racun;
	struct elem* next;
} Elem;

Elem* dodaj(Elem* lst, Racun racun) {
	Elem* novi;

	novi = malloc(sizeof(Elem));
	novi->racun = racun;
	novi->next = NULL;

	if (lst == NULL) lst = novi;
	else
	{
		Elem* tek = lst;
		while (tek->next) tek = tek->next;
		tek->next = novi;
	}
	return lst;
}

void brisi(Elem* lst) {
	Elem* tek, * stari;

	tek = lst;
	while (tek != NULL)
	{
		stari = tek;
		tek = tek->next;
		free(stari);
	}
}

double potrosnja(Elem* racuni, int sifraPotrosaca) {
	Elem* tek;
	double s = 0;

	for (tek = racuni; tek != NULL; tek = tek->next)
		if (tek->racun.sifra == sifraPotrosaca) s += tek->racun.uplata;

	return s;
}

void ispisiUplate(Elem* racuni, int sifraPotrosaca) {
	Elem* tek;

	for (tek = racuni; tek != NULL; tek = tek->next)
		if (tek->racun.sifra == sifraPotrosaca)
			printf("%d %.2lf\n", tek->racun.sifra, tek->racun.uplata);
}

int main() {
	FILE* ul1, * ul2;
	Elem* racuni = NULL;
	Racun r;
	Potrosac p;

	ul1 = fopen("potros.txt", "r");
	ul2 = fopen("ulaz.txt", "r");
	if (ul1 == NULL || ul2 == NULL)
	{
		printf("Greska pri otvaranju datoteka.");
		return 1; /* greska */
	}

	while (fscanf(ul2, "%d %lf\n", &r.sifra, &r.uplata) != EOF)
	{
		racuni = dodaj(racuni, r);
	}

	while (fscanf(ul1, "%d %s %s\n", &p.sifra, p.ime, p.prezime) != EOF)
	{
		p.suma = potrosnja(racuni, p.sifra);
		if (p.suma < 0)
		{
			printf("%d %s %s %.2lf\n", p.sifra, p.ime, p.prezime, -p.suma);
			ispisiUplate(racuni, p.sifra);
		}
	}

	fclose(ul1);
	fclose(ul2);

	brisi(racuni);
}