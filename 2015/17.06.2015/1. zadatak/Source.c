// Ispit iz programiranja 2, 17.06.2015.
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include <ctype.h>


int provera(char* rec) {
	char* p;

	p = rec;
	while (*p != '\0') {
		if (isupper(*p))
			p++;
		else
			return 0;

		if (*p == '@')
			p++;
		else
			return 0;

		while (isdigit(*p))
			p++;

		if (isupper(*p))
			return 1;
		else
			return 0;

	}
}

void main() {
	char* unetiNiz = NULL, * noviNiz, c, * p, * izdvojenaRec, * q;
	int i, sifrovanihReci, n;
	float procenat, ukupnoReci;

	printf("Unesite niz:");
	for (i = 0; (c = getchar()) != '\n'; i++) {
		noviNiz = realloc(unetiNiz, (i + 2) * sizeof(char)); // oslobadjamo prostor za karatkter i terminalni znak (zato je i+2)
		if (noviNiz == NULL) {
			printf("Realokacija neuspesna!! \n");
			exit(1);
		}
		unetiNiz = noviNiz;
		unetiNiz[i] = c;
	}
	unetiNiz[i] = '\0';

	p = unetiNiz;
	ukupnoReci = 0;
	sifrovanihReci = 0;
	while (*p != '\0') {
		izdvojenaRec = NULL;
		i = 0;
		if (*p == ' ') p++; // Ne moras pisati na ispitu
		while (*p != ' ' && *p != '\0') {
			noviNiz = realloc(izdvojenaRec, (i + 2) * sizeof(char)); // oslobadjamo prostor za karatkter i terminalni znak (zato je i+2)
			if (noviNiz == NULL) {
				printf("Realokacija neuspesna!! \n");
				exit(1);
			}
			izdvojenaRec = noviNiz; //izdvojenaRec pokazuje na realocirani prostor
			izdvojenaRec[i] = *p;
			i++;
			p++;
		}
		izdvojenaRec[i] = '\0';
		ukupnoReci++;
		if (provera(izdvojenaRec)) {
			sifrovanihReci++;
			n = strlen(izdvojenaRec);
			q = p;
			p = p - n;
			while (*q != '\0') {
				*(q - n) = *q;
				q++;
			}
			*(q - n) = '\0';
		}
	}

	procenat = (sifrovanihReci / ukupnoReci) * 100;
	printf("Rezultat:%s\n", unetiNiz);
	printf("Procenat: %f\n", procenat);

	system("pause");
}