//09.07.2014. drugi zadatak
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX 31
typedef struct original {
	char recO[MAX];
	int brojacO;
	struct original* sled;
}Original;
typedef struct kopija {
	char recK[MAX];
	int brojacK;
	struct kopija* sled;
}Kopija;

char* ucitajRec(FILE* dat, char* c) {
	char* novaRec, * staraRec = NULL;
	int i = 0;
	while (1) {
		*c = fgetc(dat);
		if (isalpha(*c)) {
			novaRec = realloc(staraRec, (i + 2) * sizeof(char));
			if (novaRec == NULL) {
				printf("Greska!!");
				exit(1);
			}
			else {
				staraRec = novaRec;
				if (isupper(*c))
					*c = tolower(*c);
				staraRec[i++] = *c;
			}
		}
		else {
			if (i != 0)
				staraRec[i] = '\0';
			break;
		}
	}
	return staraRec;
}
Original* ucitavanje(Original* lst) {
	FILE* p;
	Original* novi, * posl = NULL, * tek;
	char* rec1, c;
	int ima;
	p = fopen("original.txt", "r");
	if (p == NULL) {
		printf("Neuspesno otvaranje datoteke!!!\n");
		exit(1);
	}
	rec1 = ucitajRec(p, &c);
	while (c != EOF) {
		if (rec1 != NULL) {
			ima = 0;
			for (tek = lst; tek != NULL; tek = tek->sled) {
				if (!strcmp(tek->recO, rec1)) {
					tek->brojacO++;
					ima = 1;
					break;
				}
			}
			if (ima == 0) {
				novi = malloc(sizeof(Original));
				if (novi == NULL) {
					printf("Alokacija memorije nije uspela!!!\n");
					exit(1);
				}
				strcpy(novi->recO, rec1);
				novi->brojacO = 1;
				novi->sled = NULL;
				if (lst == NULL) {
					lst = novi;
				}
				else {
					posl->sled = novi;
				}

				posl = novi;
			}
		}
		rec1 = ucitajRec(p, &c);
	}
	fclose(p);
	return lst;
}
Kopija* ucitavanje1(Kopija* lst1) {
	FILE* p;
	Kopija* novi, * posl = NULL, * tek;
	char* rec2, c;
	int ima2;
	p = fopen("kopija.txt", "r");
	if (p == NULL) {
		printf("Otvaranje datoteke nije uspelo!!!\n");
		exit(1);
	}
	rec2 = ucitajRec(p, &c);
	while (c != EOF) {
		if (rec2 != NULL) {
			ima2 = 0;
			for (tek = lst1; tek != NULL; tek = tek->sled) {
				if (!strcmp(tek->recK, rec2)) {
					tek->brojacK++;
					ima2 = 1;
					break;
				}
			}
			if (ima2 == 0) {
				novi = malloc(sizeof(Kopija));
				if (novi == NULL) {
					printf("Alokacija memorije nije uspela!!!\n");
					exit(1);
				}
				strcpy(novi->recK, rec2);
				novi->brojacK = 1;
				novi->sled = NULL;
				if (lst1 == NULL) {
					lst1 = novi;
				}
				else {
					posl->sled = novi;
				}
				posl = novi;
			}
		}
		rec2 = ucitajRec(p, &c);
	}
	fclose(p);
	return lst1;
}

Kopija* brisiElement(Kopija* lst1, Kopija* izbaci) {
	Kopija* tek, * pret = NULL, * stari;

	if (izbaci == lst1) {
		stari = izbaci;
		lst1 = izbaci->sled;
	}
	else {
		tek = lst1;
		while (tek != izbaci) {
			pret = tek;
			tek = tek->sled;
		}
		stari = tek;
		pret->sled = tek->sled;
	}
	free(stari);
	return lst1;
}
Kopija* obrada(Original* lst, Kopija* lst1) {
	Original* pomO;
	Kopija* pomK;
	int brojacN = 0, isto, original, kopija;
	int brojacM = 0, nasao;

	isto = original = kopija = 0;
	for (pomO = lst; pomO != NULL; pomO = pomO->sled) {
		nasao = 0;
		for (pomK = lst1; pomK != NULL; pomK = pomK->sled) {
			if (!strcmp(pomO->recO, pomK->recK)) {
				brojacN += pomO->brojacO;
				brojacM += pomK->brojacK;
				lst1 = brisiElement(lst1, pomK);
				nasao = 1;
				break;
			}
		}
		if (nasao == 1) {
			if (brojacN == brojacM)
				isto += brojacN;
			if (brojacN > brojacM) {
				isto += brojacM;
				original += (brojacN - brojacM);
			}
			if (brojacN < brojacM) {
				isto += brojacN;
				kopija += brojacM - brojacN;
			}
			brojacM = 0;
			brojacN = 0;
		}
		else
			original += pomO->brojacO;
	}
	if (lst1 != NULL) {
		pomK = lst1;
		while (pomK) {
			kopija += pomK->brojacK;
			pomK = pomK->sled;
		}
	}

	printf("isto - %d\n", isto);
	printf("original - %d\n", original);
	printf("kopija - %d\n", kopija);

	return lst1;
}
Original* obrisi(Original* lst) {
	Original* tek, * stari;
	tek = lst;
	while (tek != NULL) {
		stari = tek;
		tek = tek->sled;
		free(stari);

	}
	lst = NULL;
	return lst;
}
Kopija* obrisi1(Kopija* lst1) {
	Kopija* tek, * stari;
	tek = lst1;
	while (tek != NULL) {
		stari = tek;
		tek = tek->sled;
		free(stari);
	}
	lst1 = NULL;
	return lst1;
}
void ispisiListu(Original* lst) {
	while (lst != NULL) {
		printf("%s %d\n", lst->recO, lst->brojacO);
		lst = lst->sled;
	}
}
void ispisiListu1(Kopija* lst) {
	while (lst != NULL) {
		printf("%s %d\n", lst->recK, lst->brojacK);
		lst = lst->sled;
	}
}
void main() {
	Original* lst;
	Kopija* lst1;
	FILE* dat;
	lst = NULL;
	lst1 = NULL;
	lst = ucitavanje(lst);
	lst1 = ucitavanje1(lst1);
	printf("Elementi originala:\n");
	ispisiListu(lst);
	printf("\n\n");
	printf("Elementi kopije:\n");
	ispisiListu1(lst1);
	printf("\n\n");
	printf("Rezultat:\n");
	lst1 = obrada(lst, lst1);
	lst = obrisi(lst);
	lst1 = obrisi1(lst1);
	system("pause");

}