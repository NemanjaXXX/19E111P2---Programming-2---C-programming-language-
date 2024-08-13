//22.09.2010. prvi zadatak
#include <stdio.h>

int obrada(char* podstr, char* str)
{
	int i, j, p;
	i = 0;
	p = 0;
	while (str[i] != '\0')
	{
		if (str[i] == podstr[0])
		{
			for (j = 0; podstr[j] != '\0'; i++, j++)
				if (str[i] != podstr[j]) break;
			if (podstr[j] == '\0') p++;
		}

		i++;
	}

	return p;
}

int main()
{
	char* str, * podstr, c;
	int i, j, p, duz = 20;
	str = malloc(duz);
	podstr = malloc(duz);
	printf("Unesite string: \n");
	i = 0;
	while ((c = getchar()) != '\n')
	{
		if (i == duz - 1)
		{
			duz += 5;
			str = realloc(str, duz);
			podstr = realloc(podstr, duz);
		}
		str[i++] = c;
	}
	str[i] = '\0';
	printf("Unesite podstring: \n");
	scanf("%s", podstr);

	p = obrada(podstr, str);
	printf("Podstring se pojavljuje %d puta.\n", p);

	system("pause");
	return 0;
}
