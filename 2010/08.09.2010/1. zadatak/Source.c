//08.09.2010. prvi zadatak
#include <stdio.h>
#include <ctype.h>

typedef enum { malo, veliko } Stanje;

void main() {
	FILE* ulaz, * izlaz;
	int c;
	Stanje stanje = veliko;

	ulaz = fopen("ulaz.txt", "r");
	izlaz = fopen("izlaz.txt", "w");

	while ((c = fgetc(ulaz)) != EOF) {
		switch (stanje) {
		case veliko:
			if (isalpha(c)) {
				fputc(toupper(c), izlaz);
				stanje = malo;
			}
			else fputc(c, izlaz);
			break;
		case malo:
			if (isalpha(c)) {
				fputc(tolower(c), izlaz);
				stanje = veliko;
			}
			else if (c == '\n') {
				fputc(c, izlaz);
				stanje = veliko;
			}
			else fputc(c, izlaz);
			break;
		}
	}

	fclose(ulaz);
	fclose(izlaz);
}