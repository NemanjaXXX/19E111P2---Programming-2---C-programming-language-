//04.07.2012.prvi zadatak
#include <stdio.h>
#include <stdlib.h>
typedef struct tacka {
	float x;
	float y;
	struct tacka* sled;
}Tacka;
Tacka* ucitaj(Tacka* lst) {
	Tacka* novi, * posl = NULL;
	float x1;
	float y1;
	while (1) {
		scanf("%f%f", &x1, &y1);
		if (x1 == 0 && y1 == 0) {
			return lst;
		}
		novi = malloc(sizeof(Tacka));
		if (novi == NULL) {
			printf("Alokacija nije uspela!!!\n");
			exit(1);

		}
		novi->x = x1;
		novi->y = y1;
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
void obrada(Tacka* lst) {
	Tacka* tek1, * tek2, * tek3;
	for (tek1 = lst; tek1 != NULL; tek1 = tek1->sled) {
		for (tek2 = tek1->sled; tek2 != NULL; tek2 = tek2->sled) {
			for (tek3 = tek2->sled; tek3 != NULL; tek3 = tek3->sled) {
				if (!((tek1->x * (tek2->y - tek3->y) + tek2->x * (tek3->y - tek1->y) + tek3->x * (tek1->y - tek2->y)) == 0)) {
					printf("(%.2f,%.2f),(%.2f,%.2f),(%.2f,%.2f)\n", tek1->x, tek1->y, tek2->x, tek2->y, tek3->x, tek3->y);
				}
			}
		}
	}
}
Tacka* obrisi(Tacka* lst) {
	Tacka* tek, * stari;
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
	Tacka* lst;
	lst = NULL;
	lst = ucitaj(lst);
	obrada(lst);
	lst = obrisi(lst);
	system("pause");

}