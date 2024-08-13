// 06.07.2016. drugi zadatak
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 20

typedef struct rad {
	char ime[MAX];
	char prezime[MAX];
	double br_poena;
	struct rad* sled;
}Rad;

Rad* ucitavanje(Rad* lst) {
	FILE* p;
	Rad* novi, * posl=NULL, * tek;
	char ime1[MAX] = { "" };
	char prezime1[MAX] = { "" };
	char naziv_rada;
	int br_autora;
	int i, ima;
	p = fopen("radovi.txt", "r");
	if (p == NULL) {
		printf("Otvaranje datoteke nije uspelo!!!\n");
		exit(1);
	}
	while (fscanf(p, "%d", &br_autora) != EOF) {
		for (i = 0; i < br_autora; i++) {
			fscanf(p, "%s %s", ime1, prezime1);
			ima = 0;
			for (tek = lst; tek != NULL; tek = tek->sled) {
				if (!strcmp(tek->ime, ime1) && !strcmp(tek->prezime, prezime1)) { // Zasto nece da procita tek->ime?????
					tek->br_poena += 2. / br_autora;
					ima = 1;
					break;
				}

			}
			if (ima == 0) {
				novi = malloc(sizeof(Rad));
				if (novi == NULL) {
					printf("Alokacija memorije nije uspela!!!\n");
					exit(1);
				}
				strcpy(novi->ime, ime1);
				strcpy(novi->prezime, prezime1);
				novi->br_poena = 2 / br_autora;
				novi->sled = NULL;
				if (lst == NULL) {
					lst = novi;
				}
				else {
					posl->sled = novi;
				}
				posl = novi;
			}
		}
		// da procita ime rada
		fscanf(p, "%c", &naziv_rada);
		while (!(naziv_rada == '\n')) {

			if (fscanf(p, "%c", &naziv_rada) == EOF)break;
		}
	}
	fclose(p);
	return lst;
}

void ispisi(Rad* lst) {
	FILE* p;
	Rad* tek;
	p = fopen("izlaz.txt", "w");
	if (p == NULL) {
		printf("Kreiranje datoteke nije uspelo!!!\n");
		exit(1);
	}
	for (tek = lst; tek != NULL; tek = tek->sled) {
		if (tek->br_poena >= 1 && tek->br_poena < 2) {
			fprintf(p, "%s %s %s\n", tek->ime, tek->prezime, "docent");
		}
		if (tek->br_poena >= 2 && tek->br_poena < 3) {
			fprintf(p, "%s %s %s\n", tek->ime, tek->prezime, "vanredni profesor");
		}
		if (tek->br_poena >= 3) {
			fprintf(p, "%s %s %s\n", tek->ime, tek->prezime, "redovni profesor");
		}
	}
}
Rad* obrisi(Rad* lst) {
	Rad* stari, * tek;
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
	Rad* lst;
	lst = NULL;
	lst = ucitavanje(lst);
	ispisi(lst);
	lst = obrisi(lst);

}
