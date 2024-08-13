//03.07.2018. drugi zadatak
#include <stdio.h>
#include <stdlib.h>

typedef struct kandidat {
	int sifra;
	double poeni;
	struct kandidat* sled;
} Kandidat;

Kandidat* ucitavanje(Kandidat* lst) {
	int sifra1;
	double poeni_mat1;
	double poeni_fiz1;
	FILE* p;
	Kandidat* novi, * posl=NULL;

	p = fopen("prijemni.txt", "r");
	if (p == NULL) {
		printf("Otvaranje datoteke nije uspelo!!!\n");
		exit(1);
	}

	while (fscanf(p, "%d %lf %lf", &sifra1, &poeni_mat1, &poeni_fiz1) != EOF) {
		novi = malloc(sizeof(Kandidat));
		if (novi == NULL) {
			printf("Alokacija memorije nije uspela!!!\n");
			exit(1);
		}
		novi->sifra = sifra1;
		if (poeni_mat1 >= poeni_fiz1) {
			novi->poeni = poeni_mat1;
		}
		else {
			novi->poeni = poeni_fiz1;
		}
		novi->sled = NULL;

		if (lst == NULL) {
			lst = novi;
		}
		else {
			posl->sled = novi;
		}
		posl = novi;
	}
	fclose(p);
	return lst;

}

Kandidat* obrada(Kandidat* lst) {
	FILE* p;
	int sifra1;
	double prosek, ocene;
	int i;
	Kandidat* tek;



	p = fopen("ocene.txt", "r");
	if (p == NULL) {
		printf("Otvaranje datoteke nije uspelo!!!\n");
		exit(1);
	}

	while (fscanf(p, "%d ", &sifra1) != EOF) {
		for (i = prosek = 0; i < 4; i++) {
			fscanf(p, "%lf", &ocene);
			prosek += ocene;
		}
		prosek /= 5; // ima 5 predmeta
		for (tek = lst; tek != NULL; tek = tek->sled) {
			if (tek->sifra == sifra1) {
				tek->poeni += prosek * 2;
				break;
			}
		}
	}
	fclose(p);
	return lst;

}

void ispis(Kandidat* lst) {
	int sifra_Miki;
	int uspeh;
	int bolji = 0;
	int ispravna_sifra;
	Kandidat* tek;

	printf("Miki, molimo te pravilno unesi svoji sifru:\n");
	scanf("%d", &sifra_Miki);

	for (tek = lst; tek != NULL; tek = tek->sled) {
		if (tek->sifra == sifra_Miki) {
			uspeh = tek->poeni;
			ispravna_sifra = 1;
			break;
		}
		ispravna_sifra = 0;
	}

	tek = lst;
	if (ispravna_sifra == 0) {
		printf("Uneta sifra ne postoji!!!\n");
		exit(1);
	}
	while (tek != NULL) {
		if (tek->poeni > uspeh) {
			bolji++;
			tek = tek->sled;
		}
		else tek = tek->sled;
	}

	if (bolji <= 399) {
		printf("Cestitamo Miki, upao si na budzet.\n");
	}
	else {
		if (bolji <= 499) {
			printf("Miki, upao si na samofinansiranje.\n");
		}
		else {
			printf("Nazalost, nisi uspeo da se upises.\n");
		}
	}

}

Kandidat* obrisi(Kandidat* lst) {
	Kandidat* tek, * stari;
	tek = lst;
	while (tek != NULL) {
		stari = tek;
		tek = tek->sled;
		free(stari);
	}
	lst = NULL;
	return lst;
}

int main() {
	Kandidat* lst = NULL;
	lst = ucitavanje(lst);
	lst = obrada(lst);
	ispis(lst);
	lst = obrisi(lst);
	system("pause");
	return 0;
}