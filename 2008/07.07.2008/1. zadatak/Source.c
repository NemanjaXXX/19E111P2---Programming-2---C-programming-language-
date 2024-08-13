//07.07.2008. popravni kolokvijum
#include <stdio.h>
#define BROJ_ELEMENATA_SKUPA 16

void main() {
	//skupove cemo pamtiti u nizovima tako sto cemo za svaki element skupa
	//zapamtiti da li se pojavljuje ili ne
	//index niza predstavlja vrednost elementa skupa, a vrednost 0 znaci
	//da se taj element ne nalazi u skupu, dok vrednost 1 znaci da se nalazi
	//nizovi su u pocetku postavljeni na vrednosti 0 (prazni skupovi)
	//npr: skup {1,3,4,15} ce biti predstavljen
	//nizom {0,1,0,1,1,0,0,0,0,0,0,0,0,0,0,1}
	int skup1[BROJ_ELEMENATA_SKUPA] = { 0 }, skup2[BROJ_ELEMENATA_SKUPA] = { 0 };
	int i, radi, jednaki;

	do {
		//ucitavanje skupa 1
		printf("Unesite elemente skupa 1 u opsegu [0..15]\n(za kraj unesite vrednost izvan opsega):\n");
		while (1) {
			//citamo broj koji se dodaje u skup
			int broj;
			scanf("%d", &broj);

			//prekidamo dodavanje broja ako je izvan opsega manji od 0
			if (broj < 0 || broj > 15) break;

			//ako je broj u odgovarajucem opsegu dodajemo ga u skup tako sto upisujemo 1
			//na odgovarajuce mesto u nizu (mesto je element ciji je index ucitani broj)
			skup1[broj] = 1;
		}

		//ucitavanje skupa 2
		printf("Unesite elemente skupa 2 u opsegu [0..15]\n(za kraj unesite vrednost izvan opsega):\n");
		while (1) {
			//citamo broj koji se dodaje u skup
			int broj;
			scanf("%d", &broj);

			//prekidamo dodavanje broja ako je izvan opsega manji od 0
			if (broj < 0 || broj > 15) break;

			//ako je broj u odgovarajucem opsegu dodajemo ga u skup tako sto upisujemo 1
			//na odgovarajuce mesto u nizu (mesto je element ciji je index ucitani broj)
			skup2[broj] = 1;
		}

		//proveravamo da li su jednaki tako sto uporedjuemo odgovarajuce elemente
		//pretpostavicemo da su jednaki i ako nadjemo par koji je razlicit to
		//znaci da nisu jednaki i da je pretpostavka bila losa
		jednaki = 1;
		for (i = 0; i < BROJ_ELEMENATA_SKUPA; i++) {
			if (skup1[i] != skup2[i]) {
				jednaki = 0;
				break;
			}
		}

		//ispis rezultata
		if (jednaki) printf("\nSkupovi su jednaki\n");
		else printf("\nSkupovi nisu jednaki\n");

		//pitamo korisnika da li da nastavimo sa radom
		printf("\nDa li zelite da ponovite program? (0 - prekini, 1 - nastavi): ");
		scanf("%d", &radi);
	} while (radi);
}