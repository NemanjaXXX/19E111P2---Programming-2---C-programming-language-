// 15.06.2016. prvi zadatak
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

char* ucitaj_red() {
	char* nova_rec, * stara_rec = NULL, c;
	int i = 0;

	scanf("%c", &c);
	while (c != '\n') {
		nova_rec = (char*)realloc(stara_rec, (i + 2) * sizeof(char));
		if (nova_rec == NULL) {
			printf("Alokacija memorije nije uspela!!!\n");
			exit(1);
		}
		else {
			stara_rec = nova_rec;
			stara_rec[i++] = c;
		}
		scanf("%c", &c);
	}
	if (i != 0)
		stara_rec[i] = '\0';

	return stara_rec;
}
char* obrada_jednog_reda(char* red, int n) {
	char* p;
	int brojIspisanihReci;

	p = red;
	brojIspisanihReci = 0;
	while (*p) {
		if (isalpha(*p)) {
			printf("%c", *p);
			p++;
		}
		else {
			printf("%c", *p);
			brojIspisanihReci++;
			if (brojIspisanihReci % n == 0)
				printf("\n");
			while (*p == ' ') p++;
		}
	}
}

int main() {
	int n;
	char* red;

	printf("Unesite broj N:\n");
	scanf("%d", &n);
	if (n <= 0) {
		printf("ERROR!!!\n");
		exit(1);
	}
	getchar();
	while (1) {
		printf("Unesite red teksta za obradu: \n");
		red = ucitaj_red();
		if (red == NULL) break;
		obrada_jednog_reda(red, n);
		printf("\n\n");
	}
	free(red);

	system("pause");
	return 0;
}
