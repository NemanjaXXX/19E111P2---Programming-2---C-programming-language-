//31.01.2014. drugi zadatak
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	float x, y;
} Tacka;

typedef struct {
	Tacka a, b;
} Pravougaonik;

typedef struct elem {
	Pravougaonik p;
	struct elem* sled;
} Elem;

Elem* dodaj(Elem* lista, Pravougaonik p) {
	Elem* novi, * tek;
	novi = malloc(sizeof(Elem));
	novi->p = p;
	novi->sled = NULL;
	if (lista == NULL) {
		lista = novi;
	}
	else {
		for (tek = lista; tek->sled != NULL; tek = tek->sled);
		tek->sled = novi;
	}

	return lista;
}

Elem* obrisi(Elem* lista) {
	Elem* tek, * zaBrisanje;

	tek = lista;
	while (tek != NULL) {
		zaBrisanje = tek;
		tek = tek->sled;
		free(zaBrisanje);
	}

	return NULL;
}

Elem* ucitaj() {
	Elem* lista = NULL;
	int n, i;
	Pravougaonik p;

	printf("Unesite broj pravougaonika\n");
	scanf("%d", &n);

	if (n <= 0) return NULL;

	for (i = 0; i < n; i++) {
		scanf("%f %f %f %f", &p.a.x, &p.a.y, &p.b.x, &p.b.y);
		lista = dodaj(lista, p);
	}

	return lista;
}

float povrsina(Pravougaonik p) {
	return (p.b.x - p.a.x) * (p.a.y - p.b.y);
}

Elem* sortiraj(Elem* lista) {
	Elem* tek1, * tek2;

	for (tek1 = lista; tek1 != NULL; tek1 = tek1->sled) {
		for (tek2 = tek1->sled; tek2 != NULL; tek2 = tek2->sled) {
			if (povrsina(tek1->p) > povrsina(tek2->p)) {
				Pravougaonik p;
				p = tek1->p;
				tek1->p = tek2->p;
				tek2->p = p;
			}
		}
	}

	return lista;
}

void ispisi(Elem* lista) {
	Elem* tek;
	for (tek = lista; tek != NULL; tek = tek->sled) {
		printf(
			"(%f,%f)(%f,%f)\n",
			tek->p.a.x, tek->p.a.y,
			tek->p.b.x, tek->p.b.y
		);
	}
}

void main() {
	Elem* lista = NULL;

	lista = ucitaj();
	if (lista != NULL) {
		lista = sortiraj(lista);
		ispisi(lista);
		lista = obrisi(lista);
	}
}