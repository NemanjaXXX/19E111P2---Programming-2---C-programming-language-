//18.05.2008. kolokvijum
#include <stdio.h>
#define MAX_DUZ 100

void main() {
	int niz[MAX_DUZ], n;
	int i, k;
	int min, minPoz, vrednost;

	//ucitavamo niz
	printf("Unesite duzinu niza: ");
	scanf("%d", &n);
	printf("Unesite niz: ");
	for (i = 0; i < n; i++)
		scanf("%d", &niz[i]);

	//odredjujemo vrednost elementa koji treba izbaciti
	//prvo cemo odrediti minimalni element niza (taj element bio bi na
	//poziciji 0 u sortiranom nizu), a pored njega zapamticemo i njegovu
	//poziciju u originalnom nizu (da bismo to iskoristili prilikom
	//pretrage sledeceg broja)
	min = niz[0]; minPoz = 0;
	for (i = 1; i < n; i++) {
		if (niz[i] < min) {
			min = niz[i];
			minPoz = i;
		}
	}

	//Sada cemo traziti minimum medju preostalim elementima. (to je
	//element koji bi imao indeks 1 u sortiranom nizu). Zapamcenu
	//poziciju minimalnog elementa celog niza cemo iskoristiti
	//da njega iskljucimo iz ove pretrage jer nam on sada nije potreban.
	if (minPoz != 0) vrednost = niz[0]; //uzimamo vrednost 0. elementa za
										//pocetni minimum, samo ako se na
										//toj poziviji ne nalazi minimum
										//celog niza
	else vrednost = niz[1];				//u suprotnom uzimamo vrednsot
										//1. elementa kao pocetnu
	for (i = 0; i < n; i++) {
		//biramo sve elemente osim minimalnog	
		if (i != minPoz) {
			if (niz[i] < vrednost) vrednost = niz[i];
		}
	}

	//ostavljamo u nizu samo vrednosti koji su razlicite od zadate
	//pomocu 'i' ispitujemo svaki element i ako je razlicit od
	//promenljive 'vrednsot' upisujemo ga na slobodno mesto na
	//koje pokazuje brojac 'j'
	for (i = 0, k = 0; i < n; i++) {
		if (vrednost != niz[i]) {
			niz[k] = niz[i];
			k++;
		}
	}
	n = k;

	//ispis elemenata
	printf("Rezultujuci niz: ");
	for (i = 0; i < n; i++)
		printf("%d ", niz[i]);
}