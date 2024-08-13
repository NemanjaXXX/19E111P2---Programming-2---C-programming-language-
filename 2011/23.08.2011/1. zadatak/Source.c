//23.08.2011. prvi zadatak


#include <stdio.h>


int main() {
	char a[256];
	int i, poz, da, sek = 0, num = 0;
	FILE* dat;
	dat = fopen("ulaz.txt", "r");
	if (!dat) {
		printf("Neuspesno otvaranje datoteke ulaz.txt"); exit(1);
	}

	i = 0; da = 0;
	while ((a[i++] = getc(dat)) != EOF) {

		if (!da) {
			if (isdigit(a[i - 1])) { poz = i - 1; da = 1; }
		}
		if (a[i - 1] == '\n') {    /*Program radi ispravno ako se posle poslednje numere pritisne enter da bi se preslo u novu liniju koja je prazna*/
			a[i - 1] = '\0'; sek += atoi(&a[poz]); i = 0; da = 0; num++;
		}
	}
	printf("Ukupan broj numera u plejlisti : %d\n", num);
	printf("Ukupno trajanje plejliste: %02d:%02d:%02d\n", sek / 3600, (sek / 60) % 60, sek % 60);
	system("pause");

}