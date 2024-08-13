//14.01.2016. prvi zadatak
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#define MAX 81
#define CONST 26
void formiranjeniza(char kript[CONST]) {
	int i, j, n;
	char c;
	int ima;
	n = 0;
	for (i = 'a'; i <= 'z'; i++) {
		c = 'a' + rand() % 26; // da generise broj od 0 - 25 jer to moze biti ost pri deljenju sa 26
		ima = 0;
		for (j = 0; j < n; j++) {
			if (c == kript[j]) {
				ima = 1;
				break;
			}
		}
		if (ima == 0) {
			kript[n] = c;
			n++;
		}
		else {
			i--;
		}
	}
}


void main() {
	char niz[MAX];
	char kript[CONST];
	char c;
	int i, n;
	int index;
	srand(time(NULL));
	printf("Unesite tekst:\n");
	for (i = 0; (c = getchar()) != '\n'; i++) {
		niz[i] = c;
	}
	n = i;
	formiranjeniza(kript);
	printf("a b c d e f g h i j k l m n o p q r s t u v w x y z\n");
	for (i = 0; i < CONST; i++) {
		printf("%c ", kript[i]);
	}
	printf("\n");
	//kriptovanje
	for (i = 0; i < n; i++) {
		if (islower(niz[i])) {
			index = niz[i] - 'a';
			printf("%c", kript[index]);
		}
		else
			printf("%c", niz[i]);
	}
	puts(" ");
	system("pause");
}