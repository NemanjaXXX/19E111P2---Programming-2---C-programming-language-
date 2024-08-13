#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 21
typedef struct zelje { //lst
	char ime[MAX];
	char poklon[MAX];
	struct zelje* sled;
}Zelje;
typedef struct adresar {
	char imeadr[MAX];
	char ulica[MAX];
	int broj;
}Adresar;
typedef struct elem { // lst1
	Adresar adr;
	struct elem* sled;
}Elem;

void napraviBinarnu() {
	FILE* bin;
	Adresar a;
	char ime[MAX], ulica[MAX];
	int i, broj, n;

	bin = fopen("adresar.dat", "wb");
	if (bin == NULL) {
		printf("Neuspesno otvaranje datoteke!!!");
		exit(1);
	}
	i = 0;
	while (i != 5) { // jer 5 linija ima u datoteci iz primera
		printf("Unesi adresu: ");
		scanf("%s%s%d", ime, ulica, &broj);
		strcpy(a.imeadr, ime);
		strcpy(a.ulica, ulica);
		a.broj = broj;
		fwrite(&a, sizeof(Adresar), 1, bin);
		i++;
	}
	fclose(bin);
}
Zelje* ucitavanje(Zelje* lst) {
	FILE* p;
	char ime1[MAX];
	char poklon1[MAX];
	Zelje* novi, * posl = NULL;
	p = fopen("zelje.txt", "r");
	if (p == NULL) {
		printf("Otvaranje datoteke nije uspelo!!!\n");
		exit(1);
	}
	while (fscanf(p, "%s %s", ime1, poklon1) != EOF) {
		novi = malloc(sizeof(Zelje));
		if (novi == NULL) {
			printf("Alokacija memorije nije uspela!!!\n");
			exit(1);
		}
		strcpy(novi->ime, ime1);
		strcpy(novi->poklon, poklon1);
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
Adresar* ucitavanje1(Adresar* lst1) {
	FILE* p;
	Adresar a;
	Elem* novi, * posl = NULL;
	p = fopen("adresar.dat", "rb");
	if (p == NULL) {
		printf("Otvaranje nije uspelo!!!\n");
		exit(1);
	}
	while (fread(&a, sizeof(Adresar), 1, p) == 1) { //fread(adresa gde smestam, velicina elementa u koji smestam, koliko takvih elemenata citam u jednom citanju, pointer na dat iz koje citam) == 1)
		novi = malloc(sizeof(Elem));//Ako je uspeo da procita on ce vratiti broj procitanih podataka (struktura).
		if (novi == NULL) {
			printf("Alokacija memorije nije uspela!!!\n");
			exit(1);
		}
		novi->adr = a;
		novi->sled = NULL;
		if (lst1 == NULL) {
			lst1 = novi;
		}
		else {
			posl->sled = novi;
		}
		posl = novi;
	}
	fclose(p);
	return lst1;
}
Elem* obrada(Adresar* lst1) {
	char ulicaN[MAX]; // ulica najvise
	Elem* tek, * tek1, * pret = NULL, * stari;
	Adresar pom;
	int brojac = 0;
	int najvise = 0;
	for (tek = lst1; tek != NULL; tek = tek->sled) {
		strcpy(ulicaN, tek->adr.ulica);
		for (tek1 = tek->sled; tek1 != NULL; tek1 = tek1->sled) {
			brojac = 1;
			if (!strcmp(tek->adr.ulica, tek1->adr.ulica)) {
				brojac++;
			}
			if (brojac > najvise) {
				najvise = brojac;
				strcpy(ulicaN, tek->adr.ulica);
			}

		}
	}
	printf("%s\n", ulicaN);

	tek = lst1;
	while (tek) {
		if (strcmp(ulicaN, tek->adr.ulica) != 0) {
			stari = tek;
			if (tek == lst1) // ako izbacujem sa pocetka samo ga prevezem na sledeci
				lst1 = tek->sled;
			else
				pret->sled = tek->sled;
			tek = tek->sled;
			free(stari);
		}
		else {
			pret = tek;
			tek = tek->sled;
		}
	}
	///brisanje svih elemenata koji ne sadrze ulicu koja se najvise puta pojavljuje, kraj


	//sortitranje po broju
	for (tek = lst1; tek->sled != NULL; tek = tek->sled) {
		for (tek1 = tek->sled; tek1 != NULL; tek1 = tek1->sled) {
			if (tek->adr.broj > tek1->adr.broj) {
				pom = tek->adr;
				tek->adr = tek1->adr;
				tek1->adr = pom;
			}
		}
	}

	return lst1;
}
void ispisi(Zelje* lst, Elem* lst1) {
	Elem* tek;
	Zelje* tek1;
	for (tek = lst1; tek != NULL; tek = tek->sled) {
		for (tek1 = lst; tek1 != NULL; tek1 = tek1->sled) {
			if (!strcmp(tek->adr.imeadr, tek1->ime)) {
				printf("%d %s %s\n", tek->adr.broj, tek->adr.imeadr, tek1->poklon);
				break;
			}
		}
	}
}
void main() {
	//napraviBinarnu();
	Zelje* lst;
	Adresar* lst1;
	char* ulica;
	lst = NULL;
	lst1 = NULL;
	lst = ucitavanje(lst);
	lst1 = ucitavanje1(lst1);
	lst1 = obrada(lst1);// sortirana lista od elemenata koji trebaju da se ispisu
	ispisi(lst, lst1);
	system("pause");
}
