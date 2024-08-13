//14.05.2011. popravni kolokvijum
#include <stdio.h>
#define MAX_DUZ 100

void main() {
	double niz[MAX_DUZ];
	int n, i, k;
	double min, max;
	double aritmetickaSredina;

	while (1) {
		//ucitavanje duzine niza
		printf("n = ");
		scanf("%d", &n);

		//provera i prekid petlje ako ucitana duzina nije dobra
		if (n <= 0 || n > MAX_DUZ) break;

		//ucitavanje niza
		printf("Niz: ");
		for (i = 0; i < n; i++)
			scanf("%lf", &niz[i]);


		//odredjuje minimum i maksimum
		min = max = niz[0];
		for (i = 1; i < n; i++) {
			if (niz[i] < min) min = niz[i];
			if (niz[i] > max) max = niz[i];
		}

		//izbacivanje elemenata iz niza
		//'i' ispituje svaki element niza, 'k' se koristi da oznaci
		//praznu poziciju na koju se prepisuju elementi koje ne izbacujemo
		for (i = 0, k = 0; i < n; i++) {
			//ako element ostaje u nizu prepisujemo ga na poziciju 'k'
			if (niz[i] != min && niz[i] != max) {
				niz[k] = niz[i];
				k++; //sledeca pozicija se obelezava kao slobodna
			}
		}
		n = k; //broj elemenata je smanjen, prepisali smo 'k' elemenata

		//racunanje aritmeticke sredine
		aritmetickaSredina = 0;
		for (i = 0; i < n; i++)
			aritmetickaSredina += niz[i];
		//provera da ne delimo nulom i racunanje sredine
		if (n != 0) aritmetickaSredina /= n;

		//ispis rezultata
		printf("Aritmeticka sredina je %.2lf.\n", aritmetickaSredina);
	}
}