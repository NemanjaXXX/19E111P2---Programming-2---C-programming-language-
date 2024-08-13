/* 2010-septembar-drugi*/


#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct tacka {
	float x;
	float y;
	struct Tacka* sled;
} Tacka;


Tacka* ucitaj() {
	Tacka t, * novi = NULL, * glava = NULL, * pret = NULL;
	printf("Unosite x pa y koordinatu. Koordinate (0,0) prekidaju unos\n");
	while (scanf("%f%f", &t.x, &t.y), t.x != 0 && t.y != 0) {
		novi = malloc(sizeof(Tacka));
		if (!novi) { printf("Neuspesna alokacija"); exit(1); }
		*novi = t;
		if (!glava) { glava = novi; pret = novi; novi->sled = NULL; }
		else
		{
			pret->sled = novi; pret = novi; novi->sled = NULL;
		}

	}
	return glava;

}



void obrada(Tacka* lista) {
	Tacka* pom = NULL;
	float max = 0, xdl, ydl, xgd, ygd, t;
	while (lista) {
		pom = lista->sled;
		while (pom) {
			if (lista->x != pom->x && lista->y != pom->y) {
				if ((t = fabs((lista->x - pom->x) * (lista->y - pom->y))) > max) {
					max = t;
					if (lista->x < pom->x && lista->y < pom->y) {
						xdl = lista->x; ydl = lista->y;
						xgd = pom->x; ygd = pom->y;
					}
					if (pom->x < lista->x && pom->y < lista->y) {
						xdl = pom->x; ydl = pom->y;
						xgd = lista->x; ygd = lista->y;
					}
					if (lista->x < pom->x && lista->y > pom->y) {
						xdl = lista->x; ydl = pom->y;
						xgd = pom->x; ygd = lista->y;
					}
					if (lista->x > pom->x&& lista->y < pom->y) {
						xdl = pom->x; ydl = lista->y;
						xgd = lista->x; ygd = pom->y;
					}
				}
			}
			pom = pom->sled;
		}
		lista = lista->sled;
	}
	printf("Pravougaonik sa najvecom povrsinom ima povrsinu: %.2f .\nKoordinate donjeg levog temena su mu: (%.2f,%.2f),\na donjeg desnog: (%.2f,%.2f)\n", max, xdl, ydl, xgd, ygd);

}


void brisanje(Tacka* lista) {

	Tacka* t = NULL;
	while (lista) {
		t = lista;
		lista = lista->sled;
		free(t);
	}
}

int main() {

	Tacka* lista;

	lista = ucitaj();
	obrada(lista);
	brisanje(lista);
}