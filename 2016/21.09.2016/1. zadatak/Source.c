//21.09.2016. prvi zadatak
#include<stdio.h>
#include<ctype.h>

void main(int argc, char* argv[]) {//moze i **
	int i;
	int br_slova = 0, br_belih_znakova = 0, br_linija_teksta = 0, br_prepisanih_reci = 0;
	char prom, preth = 's';// bilo sta da moze da poredi ako krece raznmakom
	FILE* p, * izlaz;
	izlaz = fopen(argv[1], "w");
	if (izlaz == NULL) {
		printf("Kreiranje datotetke nije uspelo!!!\n");
		exit(1);
	}
	for (i = 2; i < argc; i++) {
		p = fopen(argv[i], "r");
		if (p == NULL) {
			printf("Otvaranje datoteke nije uspelo!!!\n");
			exit(1);
		}
		while (fscanf(p, "%c", &prom) != EOF) {
			if (prom != '\n') {  // preskace prazne redove
				fprintf(izlaz, "%c", prom);
				if (isalpha(prom)) { br_slova++; preth = prom; } // uvek pamti prethodno procitani karakter
				if (isspace(prom)) { br_belih_znakova++; }
				if (prom == ' ' && preth != ' ') { //ako ima prebrojivo mnogo space-ova
					br_prepisanih_reci++;
					preth = prom;
				}

			}
			else {
				br_linija_teksta++;

			}
		}
		if (isalpha(preth))br_prepisanih_reci++;
		fclose(p);
	}
	fprintf(izlaz, "%d %d %d %d", br_slova, br_belih_znakova, br_linija_teksta, br_prepisanih_reci);
	fclose(izlaz);
}