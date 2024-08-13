//14.09.2011. prvi zadatak

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char ime_mesta[31];
	float temperatura;
	float pritisak;
	float brzina_vetra;
	float vlaznost_vazduha;
} Podaci;

typedef struct elem {
	Podaci pod;
	struct elem* sled;
} Elem;

typedef struct lista {
	Elem* pocetak, * kraj;
} Lista;


Lista* NapraviListu() {
	Lista* lst = malloc(sizeof(Lista));

	lst->pocetak = lst->kraj = NULL;
	return lst;
}

void DodajUListu(Lista* lst, Podaci pod)
{
	Elem* novi = malloc(sizeof(Elem));

	strcpy(novi->pod.ime_mesta, pod.ime_mesta);
	novi->pod.temperatura = pod.temperatura;
	novi->pod.pritisak = pod.pritisak;
	novi->pod.brzina_vetra = pod.brzina_vetra;
	novi->pod.vlaznost_vazduha = pod.vlaznost_vazduha;

	novi->sled = NULL;

	if (!lst->pocetak)
		lst->pocetak = lst->kraj = novi;
	else
	{
		lst->kraj->sled = novi;
		lst->kraj = lst->kraj->sled;
	}
}

void Ispis(Lista lst) {
	Elem* i;

	for (i = lst.pocetak; i != NULL;)
	{
		if ((i->pod.pritisak < 1015 || i->pod.pritisak > 1010) && i->pod.brzina_vetra < 1)
			printf("\n Ime mesta je: %s, \n Temperatura je: %.2f, \n A vlaznost vazduha je: %.2f ", i->pod.ime_mesta, i->pod.temperatura, i->pod.vlaznost_vazduha);
		i = i->sled;
	}
}

void BrisiListu(Lista* lst) {
	Elem* tek, * priv;

	tek = lst->pocetak;

	while (tek)
	{
		priv = tek->sled;
		free(tek);
		tek = priv;
	}
	free(lst);
}

int main(int argc, char* argv[]) {
	FILE* ulazni;
	Podaci pod;
	Lista* lst;

	lst = NapraviListu();
	if (!lst)
		return 1;

	ulazni = fopen("meteo.txt", "r");

	if (!ulazni)
	{
		printf("Datoteka nije uspesno otvorena");
		return 2;
	}

	while (!feof(ulazni))
	{
		fscanf(ulazni, "%s %f %f %f %f ", pod.ime_mesta, &pod.temperatura, &pod.pritisak, &pod.brzina_vetra, &pod.vlaznost_vazduha);
		DodajUListu(lst, pod);
	}

	fclose(ulazni);

	Ispis(*lst);
	BrisiListu(lst);

	getchar();
	return 0;
}