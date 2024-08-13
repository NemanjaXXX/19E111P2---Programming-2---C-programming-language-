#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 21

typedef struct tim {
	char tim[MAX];
	int domaci;
	int gosti;
	int brojac_domaci;
	int brojac_gosti;
	struct tim* sled;
}Tim;


Tim* ucitavanje(Tim* lst) {
	FILE* p;
	char tim1[MAX] = { "" }; // domaci
	char tim2[MAX] = { "" }; // gosti
	int poseta;
	int ima1;
	int ima2;
	Tim* novi, * posl=NULL, * tek;

	p = fopen("tekme.txt", "r");
	if (p == NULL) {
		printf("Otvaranje datoteke bnije uspelo!!!\n");
		exit(1);
	}

	while (fscanf(p, "%s %s %d", tim1, tim2, &poseta) != EOF) {
		ima1 = 0;
		ima2 = 0;

		for (tek = lst; tek != NULL; tek = tek->sled) {
			if (!strcmp(tek->tim, tim1)) {
				tek->domaci += poseta;
				tek->brojac_domaci++;
				ima1 = 1;
			}

			if (!strcmp(tek->tim, tim2)) {
				tek->gosti += poseta;
				tek->brojac_gosti++;
				ima2 = 1;
			}


		}





		if (ima1 == 0) {
			novi = calloc(1, sizeof(Tim));
			if (novi == NULL) {
				printf("Alokacioja memorije nije uspla!!!\n");
				exit(1);
			}
			strcpy(novi->tim, tim1);
			novi->domaci = poseta;
			novi->brojac_domaci = 1;
			novi->sled = NULL;
			if (lst == NULL) {
				lst = novi;
			}
			else {
				posl->sled = novi;
			}
			posl = novi;
		}


		if (ima2 == 0) {
			novi = calloc(1, sizeof(Tim));
			if (novi == NULL) {
				printf("Alokacioja memorije nije uspla!!!\n");
				exit(1);
			}
			strcpy(novi->tim, tim2);
			novi->gosti = poseta;
			novi->brojac_gosti = 1;
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





	fclose(p);
	return lst;

}

void ispisi(Tim* lst) {
	Tim* tek;
	FILE* p;

	p = fopen("poseta.txt", "w");
	if (p == NULL) {
		printf("Kreiranje datoteke nije uspleo!!!\n");
		exit(1);
	}

	for (tek = lst; tek != NULL; tek = tek->sled) {
		if (tek->brojac_domaci != 0 && tek->brojac_gosti != 0) {
			fprintf(p, "%s %d %d\n", tek->tim, tek->domaci / tek->brojac_domaci, tek->gosti / tek->brojac_gosti);
		}

		if (tek->brojac_domaci == 0) {
			fprintf(p, "%s %d %d\n", tek->tim, tek->domaci, tek->gosti / tek->brojac_gosti);
		}

		if (tek->brojac_gosti == 0) {
			fprintf(p, "%s %d %d\n", tek->tim, tek->domaci / tek->brojac_domaci, tek->gosti);
		}

	}

	fclose(p);


}


Tim* obrisi(Tim* lst) {
	Tim* tek, * stari;
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
	Tim* lst = NULL;
	lst = ucitavanje(lst);
	ispisi(lst);
	lst = obrisi(lst);

	return 0;
}