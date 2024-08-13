//11.04.2010. kolokvijum
#include <stdio.h>
#include <stdlib.h>
#define MAX_DUZ 100

void main() {
	unsigned int poruka[MAX_DUZ] = { 0 };
	int n, i, j;

	while (1) {
		//ucitavanje duzine poruke
		printf("Unesite duzinu poruke: ");
		scanf("%d", &n);

		//provera i prekid petlje ako ucitana duzina nije dobra
		if (n <= 0 || n > MAX_DUZ) break;

		//ucitavanje poruke
		printf("Unesite vazu poruku (celi brojevi u opsegu [0..127]: ");
		for (i = 0; i < n; i++) {
			int broj;
			scanf("%d", &broj);
			//provera da li je uneti broj u odgovarajucem opsegu
			if (broj < 0 || broj > 127) {
				printf("Greska! Uneti brojevi moraju biti u opsegu [0..127]. Ponovite unos.\n");
				exit(1); //prekidamo program
			}
			poruka[i] = broj;
		}

		//racunanje i upis bita parnosti
		for (i = 0; i < n; i++) {
			//prvo cemo izbrojati jedinice
			int brojJedinica = 0;
			//brojimo dok ne procemo sve bite broja
			//(sizeof daje broj bajtova, pomnozeno sa 8 je broj bitova)
			for (j = 0; j < sizeof(int) * 8; j++)
				brojJedinica += (poruka[i] >> j) & 1;
			//ako je broj jedinica neparan najvisi bit se postavlja na 1
			if (brojJedinica % 2)
				poruka[i] |= 1 << (sizeof(int) * 8 - 1);
		}

		//ispis poruke
		for (i = 0; i < n; i++)
			printf("%d\n", poruka[i]);
	}
}