//09.02.2009. prvi zadatak
#include<stdio.h>
#define MAX 101
void obrada(int niz[MAX], int i) {
	int s, najveci, drugi;
	int n, k, e, m;
	najveci = niz[0];
	for (s = 1; s < i; s++) {
		if (niz[s] > najveci) {
			najveci = niz[s];
		}
	}
	if (niz[0] == najveci) {
		drugi = niz[1];
	}
	else {
		drugi = niz[0];

	}
	for (n = 0; n < i; n++) {
		if (niz[n] != najveci && niz[n] > drugi) {
			drugi = niz[n];
		}
	}

	for (k = 0; k < i; k++) {
		if (niz[k] == drugi) {
			for (e = k; e < i; e++) {
				niz[e] = niz[e + 1];

			}
			i--;
			k--;
		}
	}
	printf("Izlaz: ");
	for (m = 0; m < i; m++) {
		printf(" %d ", niz[m]);
	}
	puts(" ");
	system("pause");
}
void main() {
	int i = 0;
	int niz[MAX];
	printf("Ulaz: ");
	for (i = 0;; i++) {
		scanf("%d", &niz[i]);
		if (i >= 100) {
			printf("ERROR!!!\n");
			exit(1);
		}
		if (niz[i] <= 0) {
			break;
		}
	}
	obrada(niz, i);

}