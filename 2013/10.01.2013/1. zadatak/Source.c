//10.01.2013.prvi zadatak
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define MAX 81
int proverirec(char* izdvojenarec) {
	char* tek;
	tek = izdvojenarec;
	while (*tek != '\0') {
		if (!(isdigit(*tek)) && !(*tek >= 'A' && *tek <= 'F')) {
			return 0;
		}
		tek++;
	}

	return 1;


}
void ispisibinarnibroj(char* izdvojenarec, FILE* q) {
	char* tek;
	tek = izdvojenarec;
	while (*tek) {
		switch (*tek) {
		case '1': {
			if (tek == izdvojenarec)
				fprintf(q, "1");
			else
				fprintf(q, "0001");
			break;
		}
		case '2': {
			if (tek == izdvojenarec)
				fprintf(q, "10");
			else
				fprintf(q, "0010");
			break;
		}
		case '3': {
			if (tek == izdvojenarec)
				fprintf(q, "11");
			else
				fprintf(q, "0011");
			break;
		}
		case '4': {
			if (tek == izdvojenarec)
				fprintf(q, "100");
			else
				fprintf(q, "0100");
			break;
		}
		case '5': {
			if (tek == izdvojenarec)
				fprintf(q, "101");
			else
				fprintf(q, "0101");
			break;
		}
		case '6': {
			if (tek == izdvojenarec)
				fprintf(q, "110");
			else
				fprintf(q, "0110");
			break;
		}
		case '7': {
			if (tek == izdvojenarec)
				fprintf(q, "111");
			else
				fprintf(q, "0111");
			break;
		}
		case '8': {fprintf(q, "1000"); break; }
		case '9': {fprintf(q, "1001"); break; }
		case 'A': {fprintf(q, "1010"); break; }
		case 'B': {fprintf(q, "1011"); break; }
		case 'C': {fprintf(q, "1100"); break; }
		case 'D': {fprintf(q, "1101"); break; }
		case 'E': {fprintf(q, "1110"); break; }
		case 'F': {fprintf(q, "1111"); break; }
		}
		tek++;
	}
	fprintf(q, " ");
}
void main() {
	char niz[MAX];
	char* pok;
	int i;
	char* izdvojenarec;
	char* novarec;
	FILE* p, * q;
	p = fopen("ulaz.txt", "r");
	q = fopen("izlaz.txt", "w");
	if (p == NULL || q == NULL) {
		printf("Neuspesno otvaranje!!!\n");
		exit(1);
	}
	while (fgets(niz, MAX, p) != NULL) { // kad fgets() procita EOF vraca NULL
		pok = niz;
		while (*pok) {
			izdvojenarec = NULL;
			i = 0;
			while (*pok != ' ' && *pok) { // podrazumeva*pok!='\0';
				novarec = realloc(izdvojenarec, (i + 2) * sizeof(char));//2 je jedno slovo + \0
				if (novarec == NULL) {
					printf("Realokacija nije uspela!!!\n");
					exit(1);
				}
				else {
					izdvojenarec = novarec;
					izdvojenarec[i] = *pok++;
					i++;
				}
			}
			izdvojenarec[i] = '\0';
			if (*pok != '\0') {
				pok++;
			}
			if (proverirec(izdvojenarec)) {
				ispisibinarnibroj(izdvojenarec, q);
			}
			else {
				fprintf(q, "%s ", izdvojenarec);
			}

		}
	}
}