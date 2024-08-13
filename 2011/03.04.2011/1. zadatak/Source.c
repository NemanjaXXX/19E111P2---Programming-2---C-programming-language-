//03.04.2011. kolokvijum
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define MAX_DUZ 100

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define MAX_DUZ 100

void main() {
	double X[MAX_DUZ], Y[MAX_DUZ];
	int n, i, k;

	//postavljanje semena za generisanje slucajnih brojeva
	//(samo jednom prilikom poziva programa)
	srand(time(NULL)); //funkcija zadaje "seme" za generisanje brojeva
					   //ako se ne zada, brojevi ce uvek imati istu
					   //pocetnu sekvencu, funkcija time() daje trenutno
					   //vreme i koristi se da bismo zadali razlicito seme
					   //svaki put kada se program pozove

	while (1) {
		//ucitavanje broja tacaka
		printf("Unesite broj tacaka ");
		scanf("%d", &n);

		//provera i prekid petlje ako ucitana duzina nije dobra
		if (n <= 0 || n > MAX_DUZ) break;

		//slucajno generisanje broja tacaka
		for (i = 0; i < n; i++) {
			//rand() vraca vrednost u opsegu 0..RAND_MAX, deljenjem dobijamo
			//vrednost u opsegu od 0..1
			X[i] = rand() / (double)RAND_MAX;
			Y[i] = rand() / (double)RAND_MAX;
		}

		//izbacivanje elemenata iz niza
		for (i = 0, k = 0; i < n; i++) {
			//racunanje udaljenosti od koordinatnog pocetka
			//da bismo videli da li je manje ili jednako 1 (pripadaju krugu)
			//ili je vece od 1 (nepripadaju krugu - izbacuju se)
			double d = sqrt(pow(X[i], 2) + pow(Y[i], 2));
			//ostavljamo tacke koje su u krugu
			if (d <= 1) {
				X[k] = X[i];
				Y[k] = Y[i];
				k++;
			}
		}
		n = k;

		//ispis tacaka
		for (i = 0; i < n; i++)
			printf("(%lf,%lf)\n", X[i], Y[i]);
	}
}