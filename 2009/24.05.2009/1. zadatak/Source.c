//24.05.2009. popravni kolokvijum
#include <stdio.h>
#include <stdlib.h>
#define MAX_DUZ 100

void main() {
	double v[MAX_DUZ], t[MAX_DUZ];
	double vpr, suk, smin, smax;
	int n, i;

	//ucitavanje broja deonica
	printf("Unesite broj deonica: ");
	scanf("%d", &n);

	//provera i prekid programa ako ucitana duzina nije dobra
	if (n <= 0 || n > MAX_DUZ) exit(1);

	//ucitavanje deonica
	printf("Unesite deonice...\n");
	for (i = 0; i < n; i++) {
		printf("deonica %d:\n", i);
		printf("v = ");
		scanf("%lf", &v[i]);
		printf("t = ");
		scanf("%lf", &t[i]);
	}

	//odredjivanje prosecne brine
	//napomena: racunamo prosek brzina na svim deonicama, a ne srednju brzinu)
	vpr = 0;
	for (i = 0; i < n; i++)
		vpr += v[i];
	vpr /= n;

	//odredjivanje ukupne duzine puta (u km)
	suk = 0;
	for (i = 0; i < n; i++)
		suk += v[i] * t[i] / 3600; //[km/h]*[s/3600] = [km/h]*h = [km]

	//odredjivanje minimalne i maksimalne duzine puta
	smin = smax = v[0] * t[0] / 3600; //pretpostavimo da je prva deonica max i min
	for (i = 0; i < n; i++) {
		double s;
		s = v[i] * t[i] / 3600;
		if (s < smin) smin = s;
		if (s > smax) smax = s;
	}

	//ispis rezultata
	printf("Prosecna brzina: %.2lf km/h\n", vpr);
	printf("Ukupna duzina puta: %.2lf km\n", suk);
	printf("Minimalna duzina puta: %.2lf km\n", smin);
	printf("Maksimalna duzina puta: %.2lf km\n", smax);
}