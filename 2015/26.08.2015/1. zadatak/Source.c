//26.08.2015. prvi zadatak
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 100

char* ucitajRec() {
	char* novaRec, * staraRec = NULL;
	char c;
	int i;

	i = 0;
	while (1) {
		c = getchar();
		if (c != '\n') {
			novaRec = realloc(staraRec, (i + 2) * sizeof(char));
			if (novaRec == NULL) {
				printf("Neuspesna realokacija");
				exit(1);
			}
			staraRec = novaRec;
			staraRec[i] = c;
			i++;
		}
		else {
			if (i != 0)
				staraRec[i] = '\0';
			break;
		}
	}
	return staraRec;
}
int ucitavanje(char* niz[MAX]) {
	int i, brojElemenata;
	char* rec;

	i = 0;
	brojElemenata = 0;
	while (1) {
		rec = ucitajRec();
		if (rec != NULL) {
			niz[i] = rec; //niz[i++]=rec, prvo se upise rec a zatim se inkrementira i
			i++;
			brojElemenata++;
		}
		else
			break;
	}
	return brojElemenata;
}

void ispisi(char* niz[MAX], int n) {
	int i;

	printf("Datoteke su: \n");
	for (i = 0; i < n; i++)
		printf("%s\n", niz[i]);
}
int obrada(char* niz[MAX], int n) {
	int i, k;
	char* ekstenzija;
	char* p;
	printf("Unesite ekstenziju:\n");
	ekstenzija = ucitajRec();
	for (i = 0; i < n; i++) {
		p = niz[i] + strlen(niz[i]) - 1;
		while (*(p - 1) != '.') p--;
		if (!strcmp(p, ekstenzija)) {
			for (k = i; k < n; k++) {
				niz[k] = niz[k + 1];
			}
			n--;
		}
	}
	return n;
}
void main() {
	char* niz[MAX];
	int n;
	n = ucitavanje(niz);
	n = obrada(niz, n);
	ispisi(niz, n);
	system("pause");


}