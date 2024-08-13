#include<stdio.h>
#include<math.h>

#define MAX 101

void main() {
	char c, unetiNiz[MAX], * p, * q;
	int i, duzinaZaglavlja, stepen;

	printf("Unesite string: ");
	for (i = 0; (c = getchar()) != '\n'; i++) {
		unetiNiz[i] = c;
	}
	unetiNiz[i] = '\0';
	printf("Uneti string je: %s\n", unetiNiz);

	p = unetiNiz;
	while (*p != '\0') {
		if (*p == ']') {
			duzinaZaglavlja = 0;
			stepen = 0;
			p--;
			while (*p != '[') {
				duzinaZaglavlja = duzinaZaglavlja + ((*p - '0') * pow(10, stepen)); // *p-'0' oduzima ASCII kodove i vraca broj
				stepen++;
				p--;
			}
			q = p;
			while (*q != '\0') {
				*q = *(q + duzinaZaglavlja);
				q++;
			}
			*q = '\0';
		}
		p++;
	}

	printf("String nakon obrade: %s\n", unetiNiz);
	system("pause");
}