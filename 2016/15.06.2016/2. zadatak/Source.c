// 15.06.2016. drugi zadatak
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define MAX 256 // ili koliko god treba
typedef struct korisnik {
	char username[MAX];
	char email[MAX];
	int vreme_prijave;
	int ukupno_provedeno_vreme;
	struct korisnik* sled;
}Korisnik;
Korisnik* ucitavanje(Korisnik* lst) {
	FILE* p;
	Korisnik* novi, * posl = NULL;
	char username1[MAX];
	char email1[MAX];
	p = fopen("korisnici.txt", "r");
	if (p == NULL) {
		printf("Otvaranje datoteke nije uspelo!!!\n");
		exit(1);
	}
	while (fscanf(p, "%s %s", username1, email1) != EOF) {
		novi = (Korisnik*)malloc(sizeof(Korisnik));
		if (novi == NULL) {
			printf("Alokacija memorije nije uspela !!!\n");
			exit(1);
		}
		strcpy(novi->username, username1);
		strcpy(novi->email, email1);
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
Korisnik* obrada(Korisnik* lst) { // Smatram da je red u log.txt prijava pa odjava, pitao bih na ispitu
	FILE* p;
	char email1[MAX];
	char akcija;
	int vreme;
	Korisnik* tek;
	p = fopen("log.txt", "r");
	if (p == NULL) {
		printf("Otvaranje datoteke nije uspelo!!!\n");
		exit(1);
	}
	while (fscanf(p, "%s %c %d", email1, &akcija, &vreme) != EOF) {
		for (tek = lst; tek != NULL; tek = tek->sled) {
			if (!strcmp(email1, tek->email)) {
				if (akcija == 'p') {
					tek->vreme_prijave = vreme;
				}
				else { // Ako nije p onda je o jer, je receno da postoje samo te 2 mogucnosti
					tek->ukupno_provedeno_vreme += vreme - tek->vreme_prijave;
				}
			}

		}

	}
	fclose(p);
	return lst;
}
int nadji(Korisnik* lst) {
	Korisnik* tek;
	int najvise;
	najvise = lst->ukupno_provedeno_vreme;
	for (tek = lst; tek != NULL; tek = tek->sled) {
		if (tek->ukupno_provedeno_vreme > najvise) {
			najvise = tek->ukupno_provedeno_vreme;
		}
	}
	return najvise;
}
Korisnik* obrisi(Korisnik* lst) {
	Korisnik* tek, * stari;
	tek = lst;
	while (tek != NULL) {
		stari = tek;
		tek = tek->sled;
		free(stari);
	}
	lst = NULL;
	return lst;
}
void main() {
	Korisnik* lst, * tek;
	int najvise;
	int ispisao = 0;
	char c;
	lst = NULL;
	lst = ucitavanje(lst);
	lst = obrada(lst);
	najvise = nadji(lst);
	for (tek = lst; tek != NULL; tek = tek->sled) {
		//if (ispisao == 0){ // Ovako ce ispisati samo jednog ako ih ima vise.
		if (tek->ukupno_provedeno_vreme == najvise) {
			*(tek->username) = *(tek->username) + ('A' - 'a');
			printf("%s \n", tek->username);
			break;
		}
	}
	//}
	lst = obrisi(lst);
	system("pause");

}