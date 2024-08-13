#include<stdio.h>
#define MAX 20

typedef struct trke {
	int prijavniBroj, vremeUSekundama;
}Trke;


void main() {
	Trke niz[MAX];
	int n, i, min, sek, j, prijavniBroj1, vremeUSekundama1;
	FILE* trka, * medalje;

	trka = fopen("trke.txt", "r");
	medalje = fopen("medalje.txt", "w");
	if (trka == NULL || medalje == NULL) {
		printf("Neuspesno otvaranje datoteke!\n");
		exit(1);
	}

	while (fscanf(trka, "%d", &n) != EOF) {

		for (i = 0; i < n; i++) {
			fscanf(trka, "%d", &niz[i].prijavniBroj);
			fscanf(trka, "%d:%d", &min, &sek);
			niz[i].vremeUSekundama = min * 60 + sek;
		}

		for (i = 0; i < n - 1; i++) {
			for (j = i + 1; j < n; j++) {
				if (niz[i].vremeUSekundama > niz[j].vremeUSekundama) {
					prijavniBroj1 = niz[i].prijavniBroj;
					vremeUSekundama1 = niz[i].vremeUSekundama;
					niz[i].prijavniBroj = niz[j].prijavniBroj;
					niz[i].vremeUSekundama = niz[j].vremeUSekundama;
					niz[j].prijavniBroj = prijavniBroj1;
					niz[j].vremeUSekundama = vremeUSekundama1;
				}
			}
		}

		if (n == 1) {
			fprintf(medalje, "%d %02d:%02d ", niz[0].prijavniBroj, niz[0].vremeUSekundama / 60, niz[0].vremeUSekundama % 60);
		}
		if (n == 2) {
			fprintf(medalje, "%d %02d:%02d ", niz[0].prijavniBroj, niz[0].vremeUSekundama / 60, niz[0].vremeUSekundama % 60);
			fprintf(medalje, "%d +%02d:%02d ", niz[1].prijavniBroj, (niz[1].vremeUSekundama - niz[0].vremeUSekundama) / 60, (niz[1].vremeUSekundama - niz[0].vremeUSekundama) % 60);
		}
		if (n >= 3) {
			fprintf(medalje, "%d %02d:%02d ", niz[0].prijavniBroj, niz[0].vremeUSekundama / 60, niz[0].vremeUSekundama % 60);
			fprintf(medalje, "%d +%02d:%02d ", niz[1].prijavniBroj, (niz[1].vremeUSekundama - niz[0].vremeUSekundama) / 60, (niz[1].vremeUSekundama - niz[0].vremeUSekundama) % 60);
			fprintf(medalje, "%d +%02d:%02d ", niz[2].prijavniBroj, (niz[2].vremeUSekundama - niz[0].vremeUSekundama) / 60, (niz[2].vremeUSekundama - niz[0].vremeUSekundama) % 60);
		}
		fprintf(medalje, "\n");
	}
	fclose(trka);
	fclose(medalje);

}