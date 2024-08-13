//15.01.2015. drugi zadatak
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define GRESKA {printf("Greska!\n"); system("pause"); exit(1); }
#define PI 3.14





double najveca_povrsina(double* x, double* y, double* r, int n)
{
	double P, maks = -1;
	int i;

	for (i = 0; i < n; i++)
	{
		P = r[i] * r[i] * PI;
		if (P > maks)
			maks = P;
	}

	return maks;
}

int poklapaju(double x1, double y1, double r1, double x2, double y2, double r2)
{
	double d;
	d = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));

	if (d < r1 + r2) return 1;
	return 0;
}

int izbacivanje(double* x, double* y, double* r, int n)
{
	int i, j, k, * poklap = malloc(n * sizeof(int));
	if (poklap == NULL) GRESKA

		for (i = 0; i < n; i++)
		{
			poklap[i] = 0;
			for (j = 0; j < n; j++)
				if (i != j && poklapaju(x[i], y[i], r[i], x[j], y[j], r[j]))
				{
					poklap[i] = 1;
					break;
				}

		}

	k = 0;
	for (i = 0; i < n; i++)
	{
		if (!poklap[i])
		{
			x[k] = x[i];
			y[k] = y[i];
			r[k] = r[i];
			k++;
		}
	}

	free(poklap);
	return k;
}

int main()
{
	int i, n;
	double P, * x, * y, * r;


	printf("Koliko ima krugova?\n");
	scanf("%d", &n);
	if (n <= 0) { printf("Neispravan broj!\n"); system("pause"); exit(1); }


	x = malloc(n * sizeof(double));
	y = malloc(n * sizeof(double));
	r = malloc(n * sizeof(double));
	if (!x || !y || !r) GRESKA

		printf("Unesite podatke krugova u formatu x y r\n");
	for (i = 0; i < n; i++)
	{
		scanf("%lf%lf%lf", &x[i], &y[i], &r[i]);
		if (r[i] < 0) GRESKA
	}


	n = izbacivanje(x, y, r, n);
	if (n > 0)
	{
		P = najveca_povrsina(x, y, r, n);

		printf("Krugovi koji se ne preklapaju:\n");
		for (i = 0; i < n; i++)
			printf("%.2lf, %.2lf, %.2lf\n", x[i], y[i], r[i]);
		printf("Povrsina najveceg kruga je %.2lf.\n", P);
	}
	else
		printf("Nema ni jednog kruga koji se ne preklapa sa drugim krugom.\n");

	free(x);
	free(y);
	free(r);

	system("pause");
	return 0;
}