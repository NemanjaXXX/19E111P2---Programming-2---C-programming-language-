//01.06.2012. popravni kolokvijum
#include <stdio.h>
#define MAX_DUZ 100

void main() {
	int niz1[MAX_DUZ], niz2[MAX_DUZ];
	int n1, n2, i, j, k;
	int sadrziSe, jednaki;

	while (1) {
		//ucitavanje duzina nizova
		printf("n1=");
		scanf("%d", &n1);
		printf("n2=");
		scanf("%d", &n2);

		//provera i prekid petlje ako ucitane duzine nisu zadovoljavajuce
		if (n1 <= 0 || n1 > MAX_DUZ || n2 <= 0 || n2 > MAX_DUZ) break;

		//ucitavanje nizova
		printf("Niz1: ");
		for (i = 0; i < n1; i++)
			scanf("%d", &niz1[i]);
		printf("Niz2: ");
		for (i = 0; i < n2; i++)
			scanf("%d", &niz2[i]);

		//provera da li se drugi niz sadrzi u prvom u obrnutom poretku
		//pretpostavimo da se ne sadrzi i pokusajmo da dokazemo suprotno
		sadrziSe = 0;

		//obilazicemo prvi niz pomocu brojaca 'i', od pocetka, pa do elementa koji je udaljen
		//za duzinu drugog niza od kraja prvog niza (poslednjeg elementa koji moze biti pocetak
		//zadatog podniza, jer nakon njega ima premalo elemenata da bi cinili podniz)
		//pokusavacemo da uparimo drugi niz sa prvim (unazad), ako uspemo to znaci da se sadrzi,
		//ali ako do kraja prvog niza (tj. ni za jedan element koji proveravamo) ne uspemo da
		//uparimo drugi niz u prvi to znaci da se ne sadrzi
		for (i = 0; i <= n1 - n2; i++) {
			//pretpostavimo da su svi elementi drugog niza jednaki odgovarajucim
			//elementima prvog niza, i probamo da dokazemo suprotno
			jednaki = 1;
			//pokusavamo da uklopimo ceo drugi niz u prvi, unazad, pocevsi od pozicije 'i'
			//brojac 'j' nam pokazuje na elemente drugog niza, unaza, a brojac 'k', na elemente
			//prvog niza, pocevsi od pozicije 'i' u prvom nizu, pa nadalje
			for (j = n2 - 1, k = i; j >= 0; j--, k++) {
				if (niz1[k] != niz2[j]) {
					jednaki = 0;
					break;
				}
			}
			//ako su elementi bili jednaki tokom cele provere to znaci da smo nasli podniz
			if (jednaki) {
				sadrziSe = 1;
				break;
			}
		}

		//ispis nizova
		printf("Niz1 = {");
		for (i = 0; i < n1 - 1; i++)
			printf("%d, ", niz1[i]);
		printf("%d}\n", niz1[n1 - 1]); //ispis poslednjeg

		printf("Niz2 = {");
		for (i = 0; i < n2 - 1; i++)
			printf("%d, ", niz2[i]);
		printf("%d}\n", niz2[n2 - 1]); //ispis poslednjeg

		//ispis rezultata
		if (sadrziSe) printf("Niz1 sadrzi Niz2 u obrnutom poretku.\n");
		else printf("Niz1 ne sadrzi Niz2 u obrnutom poretku.\n");
	}
}