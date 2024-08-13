//04.04.2009. kolokvijum
#include <stdio.h>
#define MAX_DUZ 100

#include <stdio.h>
#define MAX_DUZ 100

void main() {
	int niz[MAX_DUZ], n;
	int i, j;

	//ucitavanje niza
	printf("Unesite elemente niza (za kraj unesite vrednost manju od 0): ");
	n = 0; //broj elemenata u nizu
	while (n < 100) {
		//citamo broj
		int broj;
		scanf("%d", &broj);

		//prekidamo unos ako je broj manji od 0
		if (broj < 0) break;

		//ako smo ucitali dobru vrednost dodajemo ga u niz
		//najpre cemo pronaci mesto na koje ubacujemo element
		//(prvi element manji od naseg broja)
		for (i = 0; i < n; i++) {
			//ako smo dosli da broja koji je veci ili jednak nasem
			//to znaci da smo nasli poziciju za umetanje i da prekidamo
			//brojanje, brojac 'i' predstavlja poziciju na koju umecemo
			if (broj >= niz[i]) break;
		}

		//ako nismo prosli sve elemente niza, i ako smo naisli na broj
		//koji je jednak nasem, to znaci da je on vec u nizu i da treba
		//da predjemo na sledecu iteraciju petlje (citamo novi broj,
		//ovaj se ne dodaje)
		if (i < n&& broj == niz[i]) continue;

		//kada smo nasli mesto na koje ga dodajemo, moramo da
		//pomerimo sve elemente pocevsi od tog mesta, za po jedno
		//mesto udesno, i tako napravimo mesta za novi element
		//smer pomeranja je vazan, zato krecemo od nazad
		for (j = n; j > i; j--)
			niz[j] = niz[j - 1];

		//kada smo napravili mesto upisujemo ucitani broj
		niz[i] = broj;
		n++; //povecavamo broj dodatih elemenata
	}

	//ispis niza
	printf("Niz: ");
	for (i = 0; i < n; i++)
		printf("%d ", niz[i]);
}