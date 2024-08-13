//06.07.2011. drugi zadatak
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 101 // ne precizira se koliko ime grada moze imati slova, da li smsm da odredim neku const kao sad
typedef struct linije {
	int sifra;
	int brsedista;// kvanititativno, ne redni broj
	int sati;
	int minuti;
	char grad[MAX];
	int brojrezervacija;
	struct linije* sled;
}Linije;

Linije* ucitavanje(Linije* lst) {
	FILE* p;
	Linije* novi, * posl = NULL;
	int sifra1;
	int brsedista1;
	int sati1;
	int minuti1;
	char grad1[MAX];
	p = fopen("linije.txt", "r");
	if (p == NULL) {
		printf("Otvaranje datoteke nije uspelo!!!\n");
		exit(1);
	}
	/*Razmak je ubacen radi lepseg vizuelnog pregleda.*/
	while (fscanf(p, "%d %d %d:%d %s", &sifra1, &brsedista1, &sati1, &minuti1, grad1) != EOF) {
		novi = malloc(sizeof(Linije));
		if (novi == NULL) {
			printf("Alokacija memorije nije uspela!!!\n");
			exit(1);
		}
		novi->sifra = sifra1;
		novi->brsedista = brsedista1;
		novi->sati = sati1;
		novi->minuti = minuti1;
		strcpy(novi->grad, grad1);
		novi->brojrezervacija = 0;
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
Linije* obrada(Linije* lst) {
	FILE* p;
	char ime1[MAX];
	char prezime1[MAX];
	int sifraRez1;
	Linije* tek;
	p = fopen("rezervacije.txt", "r");
	if (p == NULL) {
		printf("Otvaranje datoteke nije uspelo!!!\n");
		exit(1);
	}
	/*Razmak je ubacen radi lepseg vizuelnog pregleda.*/
	while (fscanf(p, "%s %s %d", ime1, prezime1, &sifraRez1) != EOF) {
		for (tek = lst; tek != NULL; tek = tek->sled) {
			if (sifraRez1 == tek->sifra) {
				tek->brojrezervacija++;
			}
		}
	}
	fclose(p);
	return lst;
}
void ispisi(Linije* lst) {
	Linije* tek;
	for (tek = lst; tek != NULL; tek = tek->sled) {
		if (tek->brojrezervacija > tek->brsedista) {
			printf("%d %d %02d:%02d %s %d\n", tek->sifra, tek->brsedista, tek->sati, tek->minuti, tek->grad, tek->brojrezervacija - tek->brsedista);
		}
	}
}

Linije* obrisi(Linije* lst) {
	Linije* tek, * stari;
	tek = lst;
	while (tek != NULL) {
		stari = tek;
		tek = tek->sled;
		free(stari);
	}
	lst = NULL;
	return lst;
}
main() {
	Linije* lst;
	lst = NULL;
	lst = ucitavanje(lst);
	lst = obrada(lst);
	ispisi(lst);
	lst = obrisi(lst);
	system("pause");

}