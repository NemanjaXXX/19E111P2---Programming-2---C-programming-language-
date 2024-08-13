// 13.01.2011. drugi zadatak
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 31 // nije receno koloiko
typedef struct kandidat {
	int id;
	char ime[MAX];
	char prezime[MAX];
	int brglasova;
	struct kandidat* sled;
}Kandidat;
Kandidat* ucitavanje(Kandidat* lst) {
	FILE* p;
	int id1;
	char ime1[MAX];
	char prezime1[MAX];
	int brglasova1;
	int ima;
	Kandidat* novi, * tek, * posl = NULL;
	p = fopen("ulaz.txt", "r");
	if (p == NULL) {
		printf("Otvaranje datoteke nije uspelo!!!\n");
		exit(1);
	}
	while (fscanf(p, "%d %s %s %d", &id1, ime1, prezime1, &brglasova1) != EOF) {
		ima = 0;
		for (tek = lst; tek != NULL; tek = tek->sled) {
			if (tek->id == id1) {         //(!strcmp(tek->ime, ime1) && !strcmp(tek->prezime, prezime1)) posle sam se setio preko id-a
				tek->brglasova += brglasova1;
				ima = 1;
				break;
			}
		}
		if (ima == 0) {
			novi = malloc(sizeof(Kandidat));
			if (novi == NULL) {
				printf("Alociranje memorije nije uspelo!!!\n");
				exit(1);
			}
			novi->id = id1;
			strcpy(novi->ime, ime1);
			strcpy(novi->prezime, prezime1);
			novi->brglasova = brglasova1;
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
	fclose(p);
	return lst;
}
void obrada(Kandidat* lst) {
	Kandidat* tek; // moze i jedan element pa u polja da se upisuje msm isto je, ja sam ovako
	int najvise;
	char ime1[MAX];
	char prezime1[MAX];
	int id1;
	tek = lst;
	najvise = tek->brglasova;
	strcpy(ime1, tek->ime);
	strcpy(prezime1, tek->prezime);
	id1 = tek->id;
	for (tek = lst->sled; tek != NULL; tek = tek->sled) {
		if (najvise < tek->brglasova) {
			id1 = tek->id;
			strcpy(ime1, tek->ime);
			strcpy(prezime1, tek->prezime);
			najvise = tek->brglasova;
		}
	}
	printf("%d %s %s %d\n", id1, ime1, prezime1, najvise);
}
Kandidat* obrisi(Kandidat* lst) {
	Kandidat* tek, * stari;
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
	Kandidat* lst;
	lst = NULL;
	lst = ucitavanje(lst);
	obrada(lst);
	lst = obrisi(lst);
	system("pause");


}