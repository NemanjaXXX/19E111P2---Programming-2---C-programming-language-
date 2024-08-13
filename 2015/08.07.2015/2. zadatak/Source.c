//08.07.2015. drugi zadatak
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 31

typedef struct komponenta {
	int sifra_komp;
	char naziv_komp[MAX];
	double cena_komp;
	struct komponente* sled;
}Komponenta;

Komponenta* ucitavanje(Komponenta* lst) {
	FILE* p;
	Komponenta* novi, * pret = NULL, * tek;
	int sifra_komp_1;
	char naziv_komp_1[MAX];
	double cena_komp_1;
	p = fopen("komponente.txt", "r");
	if (p == NULL) {
		printf("Otvaranje datotreke nije uspelo!!!\n");
		exit(1);
	}
	while (fscanf(p, "%d %s %lf", &sifra_komp_1, naziv_komp_1, &cena_komp_1) != EOF) {
		novi = malloc(sizeof(Komponenta));
		if (novi == NULL) {
			printf("Alokacija memorije nije uspela!!!\'n");
			exit(1);
		}
		novi->sifra_komp = sifra_komp_1;
		strcpy(novi->naziv_komp, naziv_komp_1);
		novi->cena_komp = cena_komp_1;
		novi->sled = NULL;
		if (lst == NULL) {
			lst = novi;
		}
		else {
			for (tek = lst; tek != NULL && tek->sifra_komp < novi->sifra_komp; tek = tek->sled) pret = tek;
			if (lst == tek) {  //da li treba dodati element ispred prvog elementa
				novi->sled = lst;
				lst = novi;
			}
			else { // dodavanje ispred bilo kog drugog elementa
				novi->sled = tek;
				pret->sled = novi;
			}
		}
	}
	fclose(p);
	return(lst);
}

void ucitavanje_stdinput(int** sifre, int** tezinski_faktori) {
	int br_komponenti;
	int sifra_komp;
	int tez_fakt;
	int i = 0;
	int* stara_sif = NULL, * nova_sif;
	int* stari_fakt = NULL, * novi_fakt;
	scanf("%d ", &br_komponenti);
	while (br_komponenti--) {
		scanf("%d %d", &sifra_komp, &tez_fakt);
		nova_sif = realloc(stara_sif, (i + 2) * sizeof(int));
		novi_fakt = realloc(stari_fakt, (i + 2) * sizeof(int));
		if (nova_sif == NULL || novi_fakt == NULL) {
			printf("Neuspesna realokacija!!!\n");
			exit(1);
		}
		stara_sif = nova_sif;
		stari_fakt = novi_fakt;
		stara_sif[i] = sifra_komp;
		stari_fakt[i] = tez_fakt;
		i++;
		if (i != 0) {
			stara_sif[i] = '\0';
			stari_fakt[i] = '\0';
		}

	}
	*sifre = stara_sif;
	*tezinski_faktori = stari_fakt;

}

Komponenta* nadji(Komponenta* lst, int zadata_sifra) {
	Komponenta* tek;
	for (tek = lst; tek != NULL; tek = tek->sled) {
		if (tek->sifra_komp == zadata_sifra) return tek;
	}
}

void forimranje_racuna(Komponenta* lst, int* sifre, int* tezinski_faktori, double zeljena_kolicina) {
	Komponenta* tek;
	double udeo, cena_komponente, ukupna_cena;
	int suma_faktora = 0;
	int i = 0;
	int trenutni_fakt;
	while (tezinski_faktori[i] != '\0') {
		suma_faktora += tezinski_faktori[i];
		i++;
	}
	for (tek = lst, ukupna_cena = 0, i = 0; tek != NULL; tek = tek->sled) {
		if (tek->sifra_komp == sifre[i]) {
			cena_komponente = (double)tezinski_faktori[i] / suma_faktora * zeljena_kolicina * tek->cena_komp; // umesto 2. ide tezinski_faktori[i].
			ukupna_cena += cena_komponente;
			printf("%s: %.1lf \n", tek->naziv_komp, cena_komponente);
			i++;
		}
	}
	printf("%.1lf \n", ukupna_cena);
}

Komponenta* oslobadjanje(Komponenta* lst) {
	Komponenta* tek, * stari;
	tek = lst;
	while (tek) {
		stari = tek;
		tek = tek->sled;
		free(stari);
	}
	lst = NULL;
	return lst;
}

int* oslobodi(int* sifre) {
	free(sifre);
	sifre = NULL;
	return sifre;
}

int* oslobodi1(int* tezinski_faktori) {
	free(tezinski_faktori);
	tezinski_faktori = NULL;
	return tezinski_faktori;
}

void main() {
	Komponenta* lst;
	Komponenta* odgovarajuca;
	lst = NULL;
	int* sifre;
	int* tezinski_faktori;
	int zadata_sifra;
	double zeljena_kolicina;
	char prom;
	lst = ucitavanje(lst);
	while (1) {
		scanf("%lf", &zeljena_kolicina);
		ucitavanje_stdinput(&sifre, &tezinski_faktori);
		printf("Zadajte sifru: ");
		scanf("%d", &zadata_sifra);
		odgovarajuca = nadji(lst, zadata_sifra);
		forimranje_racuna(lst, sifre, tezinski_faktori, zeljena_kolicina);
		scanf("%c", &prom);
		scanf("%c", &prom);   // ako hoce da nastavi ucitavanje mora uneti bilo sta osim praznog reda
		if (prom == '\n') break;
	}
	lst = oslobadjanje(lst);
	sifre = oslobodi(sifre);
	tezinski_faktori = oslobodi1(tezinski_faktori);//dodao kompajliraj
	system("pause");
}