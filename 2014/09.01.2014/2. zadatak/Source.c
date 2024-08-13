// 09.01.2014. drugi zadatak
#include <stdio.h>
#include <stdlib.h>
typedef struct racuni {
	int idzaupl;
	float iznzaupl;
	struct racuni* sled;
}Racuni;
Racuni* ucitaj(Racuni* lst) {
	FILE* p;
	Racuni* novi, * posl = NULL;
	int idzaupl1;
	float iznzaupl1;
	p = fopen("racuni.txt", "r");
	if (p == NULL) {
		printf("Otvaranje datoteke nije uspelo!!!");
		exit(1);
	}
	while (fscanf(p, "%d%f", &idzaupl1, &iznzaupl1) != EOF) {
		novi = malloc(sizeof(Racuni));
		if (novi == NULL) {
			printf("Alokacija memorije nije uspela!!!");
			exit(1);
		}
		novi->idzaupl = idzaupl1;
		novi->iznzaupl = iznzaupl1;
		novi->sled = NULL;
		if (lst == NULL) {
			lst = novi;
		}
		else {
			posl->sled = novi; // Znam da treba ovako. Objasniti ovu liniju koda. Posl na pocetku pokazuje negde. Objasniti ovo i liniju ispod. 
		}
		posl = novi;
	}
	fclose(p);
	return(lst);
}
Racuni* obrada(Racuni* lst) {
	int iduplate1;
	float iznuplate1;
	Racuni* tek;
	FILE* p;
	p = fopen("uplate.txt", "r");
	if (p == NULL) {
		printf("Otvaranje datoteke nije uspelo!!!");
		exit(1);
	}
	while (fscanf(p, "%d%f", &iduplate1, &iznuplate1) != EOF) {
		for (tek = lst; tek != NULL; tek = tek->sled) {
			if (iduplate1 == tek->idzaupl) {
				tek->iznzaupl -= iznuplate1; // Ovim moze da se desi da su id tako rasporedjeni da uslov iz if-a nikada ne bude ispunjen. Kako to da sredim? Program nebi uradio nista.
			}
		}
	}
	fclose(p);
	return lst;
}
Racuni* ispisi(Racuni* lst) {
	Racuni* tek;
	FILE* p;
	p = fopen("duznici.txt", "w");
	if (p == NULL) {
		printf("Greska!!!");
		exit(1);
	}
	for (tek = lst; tek != NULL; tek = tek->sled) {
		if (tek->iznzaupl > 0) {
			fprintf(p, "%d -%.2f\n", tek->idzaupl, tek->iznzaupl);
		}
	}
	fclose(p);
	return lst;
}
Racuni* obrisi(Racuni* lst) {
	Racuni* tek, * stari;
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
	Racuni* lst;
	lst = NULL;
	lst = ucitaj(lst);
	lst = obrada(lst);
	ispisi(lst);
	lst = obrisi(lst);

}