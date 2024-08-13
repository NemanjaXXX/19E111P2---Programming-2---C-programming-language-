//12.01.2012. drugi zadatak
#include<stdio.h>
#include<ctype.h>
#define MAX 81
void main() {
	FILE* p, * q;
	char niz[MAX];
	char* pok;
	p = fopen("poruka.txt", "r");
	q = fopen("telefoni.txt", "w");
	if (p == NULL || q == NULL) {
		printf("GRESKA!!!\n");
		exit(1);
	}
	while (fgets(niz, 81, p) != NULL) {//procita EOF a vrati NULL
		for (pok = niz; *pok != '\0'; pok++) {
			if (*pok == '+') {
				fprintf(q, "%c", *pok);
				pok++;
				while (isdigit(*pok)) {
					fprintf(q, "%c", *pok);
					pok++;
				}
			}
		}
		fprintf(q, "\n");
	}
}