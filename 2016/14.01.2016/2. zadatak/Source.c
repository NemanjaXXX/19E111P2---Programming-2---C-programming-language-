//14.01.2016. drugi zadatak
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct elem {
	char vrstaaktivnosti;
	char* kontaktiranibroj;
	float kolicinasaobracaja;
	struct elem* sled;
}Activity;
int read_activity(FILE* p, Activity** novi) {
	char vrstaaktivnosti1;
	char* kontaktiranibroj1Stari = NULL, * kontaktiranibroj2Novi;
	float kolicinasaobracaja1;
	char kontbrpom;
	int i = 0;

	if (fscanf(p, "%c ", &vrstaaktivnosti1) != EOF) {   // procitao vrstuakt
		while ((kontbrpom = fgetc(p)) != ' ') {
			kontaktiranibroj2Novi = realloc(kontaktiranibroj1Stari, (i + 2) * sizeof(char));
			if (kontaktiranibroj2Novi == NULL) {
				return 0;
			}
			else {
				kontaktiranibroj1Stari = kontaktiranibroj2Novi;
				kontaktiranibroj1Stari[i] = kontbrpom;
				i++;
			}
		}
		kontaktiranibroj1Stari[i] = '\0';
	}
	fscanf(p, "%f ", &kolicinasaobracaja1);

	*novi = malloc(sizeof(Activity));
	if (*novi == NULL) {
		return 0;
	}
	(*novi)->vrstaaktivnosti = vrstaaktivnosti1; // zagrada zbog prioriteta * i ->
	(*novi)->kontaktiranibroj = malloc(strlen(kontaktiranibroj1Stari) * sizeof(char));
	if ((*novi)->kontaktiranibroj == NULL) {
		return 0;
	}
	strcpy((*novi)->kontaktiranibroj, *kontaktiranibroj1Stari);
	(*novi)->kolicinasaobracaja = kolicinasaobracaja1;
	(*novi)->sled = NULL;
	return 1;
}
Activity* sortiraj(Activity* lst, Activity* novi) {
	Activity* tek, * pret;
	for (tek = lst; tek && tek->kolicinasaobracaja < novi->kolicinasaobracaja; tek = tek->sled) {
		pret = tek;
	}
	if (tek == lst) {
		novi->sled = lst;
		lst = novi;
	}
	else {
		pret->sled = novi;
		novi->sled = tek;
	}
	return lst;
}
void ispis(Activity* lst, FILE* p) {
	Activity* tek;
	for (tek = lst; tek != NULL; tek = tek->sled) {
		fprintf(p, "%c %s %f \n", tek->vrstaaktivnosti, tek->kontaktiranibroj, tek->kolicinasaobracaja);
	}
}
Activity* obrisi(Activity* lst) {
	Activity* tek, * stari;
	for (tek = lst; tek != NULL; tek = tek->sled) {
		stari = tek;
		tek = tek->sled;
		free(stari);
	}
	lst = NULL;
	return lst;
}
void main(int argc, char* argv[]) { // isto je i char**argv
	FILE* p;
	FILE* pok1, * pok2, * pok3;
	Activity* novi;
	Activity* poz = NULL, * sms = NULL, * data = NULL;
	novi = NULL;
	/*
	Alternativno bi mogli ograniciti nayiv datoteke na najvise 100 karatera pa bi pisali sledece:
	char naziv[101];
	strcpy(naziv,argv[1]);
	*/
	p = fopen("argv[1]", "r");
	if (p == NULL) {
		printf("ERROR!!!\n");
		exit(1);
	}
	while (1) {
		if (read_activity(p, &novi)) {
			switch (novi->vrstaaktivnosti) {
			case 'P': poz = sortiraj(poz, novi);
				break;
			case 'S': sms = sortiraj(sms, novi);
				break;
			case 'D': data = sortiraj(data, novi);
				break;
			}
		}
		else {
			printf("ERROR!!!\n");
			exit(1);
		}
	}
	fclose(p);
	pok1 = fopen("pozivi.txt", "w");
	pok2 = fopen("sms.txt", "w");
	pok3 = fopen("podaci.txt", "w");
	if (pok1 == NULL || pok2 == NULL || pok3 == NULL) {
		printf("ERROR!!!\n");
		exit(1);
	}
	ispis(poz, pok1);
	ispis(sms, pok2);
	ispis(data, pok3);
	pok1 = obrisi(pok1);
	pok2 = obrisi(pok2);
	pok3 = obrisi(pok3);
	system("pause");

}