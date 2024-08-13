//22.08.2012. prvi zadatak
#include<stdio.h>
#include<stdlib.h>
#include <math.h>
typedef struct tacka {
	float x;
	float y;
	float z;
}Tacka;
Tacka* ucitavanje(Tacka* pok, int duzina) {
	int i;
	pok = malloc(duzina * sizeof(Tacka));
	if (pok == NULL) {
		printf("Alokacija memorije nije uspela!!!\n");
		exit(1);
	}
	for (i = 0; i < duzina; i++) {
		printf("Unesite koordinate tacke:");
		scanf("%f %f %f", &pok[i].x, &pok[i].y, &pok[i].z);
	}
	return pok;
}
float obrada(Tacka* pok, int duzina, int* index1, int* index2) {
	float rastojanje, rastojanjemax = 0;
	int i, j;
	for (i = 0; i < duzina; i++) {
		for (j = i + 1; j < duzina; j++) {
			rastojanje = sqrt(pow(pok[i].x - pok[j].x, 2) + pow(pok[i].y - pok[j].y, 2) + pow(pok[i].z - pok[j].z, 2));
			if (rastojanje > rastojanjemax) {
				rastojanjemax = rastojanje;
				*index1 = i;
				*index2 = j;
			}
		}
	}
	return rastojanjemax;
}
int main() {
	Tacka* pok;
	int duzina;
	int index1, index2;
	float rastojanje;
	pok = NULL;
	printf("Unesite duzinu:");
	scanf("%d", &duzina);
	pok = ucitavanje(pok, duzina);
	rastojanje = obrada(pok, duzina, &index1, &index2);
	printf("Najvece rastojanje je: %.2f, iizmedju tacaka(%.2f,%.2f,%.2f) i (%.2f,%.2f,%.2f)\n", rastojanje, pok[index1].x, pok[index1].y, pok[index1].z, pok[index2].x, pok[index2].y, pok[index2].x, pok[index1].z);
	system("pause");
}
