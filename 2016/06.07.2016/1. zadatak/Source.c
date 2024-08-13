// 06.07.2016. prvi zadatak
#include <stdio.h>
#include <stdlib.h>

int Palindrom(unsigned int b) {
	int* bin = NULL, i, j;

	bin = calloc(10, sizeof(int));
	i = 0;
	while (1) {
		if (i % 10 == 0) {
			bin = realloc(bin, (i + 10) * sizeof(int));
			if (bin == NULL) {
				printf("Realokacija memorije nije uspela!!!\n");
				exit(1);
			}
		}
		bin[i++] = b % 2;
		b = b / 2;
		if (b == 0)
			break;
	}
	bin = realloc(bin, i * sizeof(int));
	if (bin == NULL) {
		printf("Realokacija memorije nije uspela!!!\n");
		exit(1);
	}

	for (j = 0, i = i - 1; j < i; j++, i--) {
		if (bin[j] != bin[i])
			return 0;
	}
	return 1;
}

int main() {
	unsigned int* niz = NULL, i, j, t;

	niz = calloc(10, sizeof(unsigned int));
	if (niz == NULL) {
		printf("Alokacvija memorije nije uspela!!!\n");
		exit(1);
	}
	printf("Unesite niz (0 za kraj unosa):\n");
	i = 0;
	while (1) {
		if (i % 10 == 0) {
			niz = realloc(niz, (i + 10) * sizeof(unsigned int));
			if (niz == NULL) {
				printf("Realokacija memorije nije uspela!!!\n");
				exit(1);
			}
		}
		scanf("%u", &niz[i]);
		if (niz[i] == 0)
			break;
		i++;
	}
	niz = realloc(niz, i * sizeof(unsigned int));
	if (niz == NULL) {
		printf("Realokacija memorije nije uspela!!!\n");
		exit(1);
	}
	printf("Palindromi su:\n");
	for (j = 0; j < i; j++) {
		t = Palindrom(niz[j]);
		if (t)
			printf("%u\n", niz[j]);
	}
	free(niz);
	system("pause");
}