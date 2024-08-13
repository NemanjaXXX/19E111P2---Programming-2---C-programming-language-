#include<stdio.h>
#include<stdlib.h>


char* unos()
{
	char* s, c;
	int k = 30, i = 0;

	s = malloc(k * sizeof(char));
	c = getchar();
	while (c != '\n')
	{
		s[i] = c;
		i++;
		if (i >= 30)
		{
			k += 30;
			s = realloc(s, k * sizeof(char));
		}
		c = getchar();
	}
	s[i] = '\0';
	return s;
}

void obrada(char* s)
{
	int i = 0;
	while (s[i] != '\0')
	{
		if (('A' <= s[i] && s[i] <= 'Z') && s[i + 1] != '\0' && ('A' <= s[i + 1] && s[i + 1] <= 'Z'))
		{
			s[i + 1] = s[i + 1] + 'a' - 'A';
		}
		i += 2;
		while (s[i] != '\0' && s[i] != ' ') i++;
		while (s[i] != '\0' && s[i] == ' ') i++;
	}
}

void ispis(char* s)
{
	int i = 0;
	while (s[i] != '\0')
		printf("%c", s[i++]);
}

int main()
{
	/*alociranje matrice
	int n, i;
	int **mat;
	scanf("%d", &n);
	mat = (int **)malloc(n*sizeof(int *));
	if(mat == NULL) exit(1);

	for(i = 0; i < n; i++)
		if(!(mat[i] = (int *)malloc(n*sizeof(int)))) exit(1);

	for(i = 0; i < n; i++)
		for(j = 0; j < n; j++)
			scanf("%d", &mat[i][j]);

	kraj alociranja matrice*/

	char* s;
	s = unos();
	obrada(s);
	ispis(s);
	puts("");
	system("pause");

}