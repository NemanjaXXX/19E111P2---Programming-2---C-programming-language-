//22.04.2012. kolokvijum
#include <stdio.h>
#define MAX_DUZ 100

int main() {
	int niz1[MAX_DUZ], niz2[MAX_DUZ];
	int n, i, j, k;
	int dobijaSeRotacijom, rotiran, brojMesta;

	while (1) {
		//ucitavanje duzine nizova
		printf("n = ");
		scanf("%d", &n);

		//provera i prekid petlje ako ucitana duzina nije dobra
		if (n <= 0 || n > MAX_DUZ) break;

		//ucitavanje nizova
		printf("Niz A: ");
		for (i = 0; i < n; i++)
			scanf("%d", &niz1[i]);
		printf("Niz B: ");
		for (i = 0; i < n; i++)
			scanf("%d", &niz2[i]);

		//provera da li se niz 1 moze dobiti rotacijom niza 2

		//brojac 'i' ce nam predstavljati broj rotiranih mesta
		//pokusavacemo da rotiramo niz udesno za i=1..n-1 mesta
		dobijaSeRotacijom = 0;
		for (i = 0; i < n; i++) {
			//pretpostavimo da je ovaj niz rotiran za 'i' mesta
			//i pokusajmo da dokazemo da nije
			rotiran = 1;
			//'j' broji elemente niza 2 (od pocetka do kraja niza),
			//dok 'k' broji elemente niza 1, tako da svaki je 'k'
			//pozicija na kojoj bi element niza 2 sa pozicije 'j'
			//trebalo da se nalazi ako je izvrsena rotacija
			//npr: ako je niz 1 dobijen rotacijom niza 2 za 'i'
			//mesta onda je element niz2[0] jednak niz1[i], element
			//niz2[3] jednak niz1[i+3], itd.; rotacija je kruzna
			//sto znaci da ce posle n-tog elementa preci na 0-ti
			for (j = 0, k = i; j < n; j++, k = (k + 1) % n) {
				if (niz1[k] != niz2[j]) {
					rotiran = 0;
					break;
				}
			}
			if (rotiran) {
				dobijaSeRotacijom = 1;
				brojMesta = i;
				break;
			}
		}

		//ispis nizova
		printf("Niz A: ");
		for (i = 0; i < n; i++)
			printf("%d ", niz1[i]);
		putchar('\n');
		printf("Niz B: ");
		for (i = 0; i < n; i++)
			printf("%d ", niz2[i]);
		putchar('\n');

		//ispis rezultata
		if (dobijaSeRotacijom)
			printf("Niz A se dobija rotacijom niza B za %d mesta udesno!\n", brojMesta);
		else
			printf("Niz A se ne moze dobiti rotacijom niza B!\n");
	}
	return 0;
}