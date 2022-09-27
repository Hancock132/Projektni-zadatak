#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

static int brojAlkoholnogPica = 0;
static int i;
static int j;
static int br = 0;

int izbornik() {
	int uvjet = 0;
	static ALKOHOL* polje = NULL;

	printf("Odaberite jednu od opcija.");
	printf("\n***************************\n");
	printf("Opcija 1: Dodaj alkoholno pice\n");
	printf("Opcija 2: Azuriranje alkoholnog pica\n");
	printf("Opcija 3: Ispisivanje alkoholnog pica\n");
	printf("Opcija 4: Pretrazivanje alkoholnog pica\n");
	printf("Opcija 5: Sortiranje alkoholnih pica\n");
	printf("Opcija 6: Brisanje alkoholnog pica\n");
	printf("Opcija 7: Izlaz iz programa\n");
	printf("***************************\n");

	printf("ODABIR: ");
	scanf("%d", &uvjet);
	system("cls");

	switch (uvjet) {
	case 1:	ucitavanjeAlkoholnogPica();
		if (brojAlkoholnogPica == 0) {
		kreiranjeDatoteke();
	}
			dodavanjeAlkoholnogPica();
			break;

	case 2: azuriranje(); break;

	case 3: if (polje != NULL) {
		free(polje);
		polje = NULL;
	}
		  polje = (ALKOHOL*)ucitavanjeAlkoholnogPica();
			ispisivanje(polje);
		  break;

	case 4:
		while (uvjet != 90) {
			uvjet = izbornikPretrazivanje();
		}
		  break;

	case 5: while (uvjet != 89)
		uvjet = izbornikSortiranje();
		break;

	case 6: if(polje == NULL)
				printf("Nema unesenih alkoholnih pica\n\n");
			else
				brisanjeAlkoholnogPica(polje);
		break;

	case 7: brisanjeDatoteke(polje);
		return 99;
		break;
	default: printf("\nPogresan unos!\n\n");
	}

	return uvjet;
}

int izbornikPretrazivanje() {
	int uvjet = 0;
	ALKOHOL* polje = NULL;
	polje = (ALKOHOL*)ucitavanjeAlkoholnogPica();
		printf("Pretrazivanje.\n\n");
		printf("Opcija 1: Cijena\n");
		printf("Opcija 2: Kategorija\n");
		printf("Opcija 3: Ime\n");
		printf("Opcija 4: Povratak\n");
		printf("ODABIR: ");
		scanf("%d", &uvjet);
		system("cls");

		switch (uvjet) {
		case 1: pretragaCijena(polje); break;
		case 2: pretragaKategorija(polje); break;
		case 3:	pretragaIme(polje); break;
		case 4: return 90;
		default: printf("\nPogresan unos!\n");

		}

		return uvjet;
	}

int izbornikSortiranje() {
	int uvjet = 0;
	ALKOHOL* polje = NULL;
	polje = (ALKOHOL*)ucitavanjeAlkoholnogPica();
	printf("Sortiranje.\n\n");
	printf("Opcija 1: Cijena od najjeftinijeg do najskupljeg\n");
	printf("Opcija 2: Cijena od najskupljeg do najjeftinijeg\n");
	printf("Opcija 3: Povratak\n");
	printf("ODABIR: ");
	scanf("%d", &uvjet);
	system("cls");

	switch (uvjet) {
	case 1: selectionSortNajjefCijena(polje); break;
	case 2: selectionSortNajskupCijena(polje); break;
	case 3: return 89;
	default: printf("\nPogresan unos!\n");

	}

	return uvjet;
}

void kreiranjeDatoteke() {
	FILE* fp = NULL;
	fp = fopen("AlkoholnaPica.bin", "wb");

	if (fp == NULL) {
		perror("Kreiranje");
	}

	fwrite(&brojAlkoholnogPica, sizeof(int), 1, fp);
	fclose(fp);
}

void dodavanjeAlkoholnogPica() {
	FILE* fp = NULL;
	fp = fopen("AlkoholnaPica.bin", "rb+");

	if (fp == NULL)
		perror("Dodavanje");

	fread(&brojAlkoholnogPica, sizeof(int), 1, fp);
	printf("Trenutni broj artikala: %d", brojAlkoholnogPica);

	ALKOHOL alkoholi;
	alkoholi.id = brojAlkoholnogPica+1;
	br++;
	getchar();
	printf("\nUnesite kategoriju alkoholnog pica: ");
	scanf("%24[^\n]", alkoholi.kategorija);
	getchar();
	printf("\nUnesite ime alkoholnog pica: ");
	scanf("%24[^\n]", alkoholi.ime);
	printf("\nUnesite cijenu alkoholnog pica: ");
	scanf("%d", &alkoholi.cijena);
	printf("\nUnesite kolicinu alkoholnog pica: ");
	scanf("%d", &alkoholi.kolicina);
	fseek(fp, sizeof(ALKOHOL) * brojAlkoholnogPica, SEEK_CUR);
	fwrite(&alkoholi, sizeof(ALKOHOL), 1, fp);
	rewind(fp);
	brojAlkoholnogPica++;
	fwrite(&brojAlkoholnogPica, sizeof(int), 1, fp);
	fclose(fp);
}

void azuriranje() {
	FILE* fp = NULL;
	int ispravak;
	fp = fopen("AlkoholnaPica.bin", "rb+");
	if (fp == NULL)
		printf("Nema unesenog alkoholnog pica\n\n");
	else {
		printf("Unesi broj alkoholnog pica koji zelite ispraviti.\n");
		scanf("%d", &ispravak);
		fseek(fp, sizeof(int) + (sizeof(ALKOHOL) * (ispravak - 1)), SEEK_SET);
		ALKOHOL ispravljenAlkohol;
		ispravljenAlkohol.id = ispravak;
		getchar();
		printf("\nUnesite ispravljenu kategoriju alkoholnog pica: ");
		scanf("%24[^\n]", ispravljenAlkohol.kategorija);
		getchar();
		printf("\nUnesite ime alkoholnog pica: ");
		scanf("%24[^\n]", ispravljenAlkohol.ime);
		printf("\nUnesite cijenu alkoholnog pica: ");
		scanf("%d", &ispravljenAlkohol.cijena);
		printf("\nUnesite kolicinu alkoholnog pica: ");
		scanf("%d", &ispravljenAlkohol.kolicina);
		fwrite(&ispravljenAlkohol, sizeof(ALKOHOL), 1, fp);
		rewind(fp);
		fwrite(&brojAlkoholnogPica, sizeof(int), 1, fp);
		fclose(fp);

	}
}

void* ucitavanjeAlkoholnogPica() {
	FILE* fp = fopen("AloholnaPica.bin", "rb");
	if (fp == NULL) {
		printf("Nema unesenih alkoholnih pica.\n\n");
		return NULL;
	}
	fread(&brojAlkoholnogPica, sizeof(int), 1, fp);
	ALKOHOL* polje = NULL;
	polje = (ALKOHOL*)calloc(brojAlkoholnogPica, sizeof(ALKOHOL));
	if (polje == NULL) {
		perror("Zauzimanje memorije");
		return NULL;
	}
	fread(polje, sizeof(ALKOHOL), brojAlkoholnogPica, fp);
	fclose(fp);
	return polje;
}

void ispisivanje(ALKOHOL* polje) {
	for (i = 0; i < brojAlkoholnogPica; i++)
	{
		printf("Alkoholno pice broj %d:\tID: %d\tKategorija: %s\tIme: %s\tCijena: %d\tKolicina: %d\n", i + 1, (polje + i)->id, (polje + i)->kategorija, (polje + i)->ime, (polje + i)->cijena, (polje + i)->kolicina);
	}
}

void* pretragaIme(ALKOHOL* polje) {
	char trazenoIme[25];
	int brojac = 0;

	printf("Upisite ime alkoholnog pica koje zelite pronaci.\n");
	getchar();
	scanf("%24[^\n]", trazenoIme);

	for (i = 0; i < brojAlkoholnogPica; i++) {
		if (!strcmp(trazenoIme, (polje + i)->ime)) {
			printf("\nIme alkoholnog pica je pronadeno!\n\n");
			printf("Kategorija: %s\tIme: %s\tCijena: %d\tKolicina: %d\n\n", (polje + i)->kategorija, (polje + i)->ime, (polje + i)->cijena, (polje + i)->kolicina);
			brojac++;
		}
	}
	if (brojac == 0)
		printf("\nIme alkoholnog pica nije pronadeno!\n\n");
	return NULL;
}

void* pretragaKategorija(ALKOHOL* polje) {
	char trazenaKategorija[25];
	int brojac=0;

	printf("Upisite kategoriju alkoholnog pica koju zelite pronaci.\n");
	getchar();
	scanf("%24[^\n]", trazenaKategorija);

	for (i = 0; i < brojAlkoholnogPica; i++) {
		if (!strcmp(trazenaKategorija, (polje + i)->kategorija)) {
			printf("\nKategorija alkoholnog pica je pronadena!\n\n");
			printf("Kategorija: %s\tIme: %s\tCijena: %d\tKolicina: %d\n\n", (polje + i)->kategorija, (polje + i)->ime, (polje + i)->cijena, (polje + i)->kolicina);
			brojac++;
		}
	}
	if (brojac == 0)
		printf("\nKategorija alkoholnog pica nije pronadena!\n\n");
	return NULL;
}

void* pretragaCijena(ALKOHOL* polje) {
	int trazenaCijena;
	int brojac = 0;

	printf("Upisite cijenu alkoholnog pica kojeg zelite pronaci.\n");
	scanf("%d", &trazenaCijena);

	for (i = 0; i < brojAlkoholnogPica; i++) {
		if (trazenaCijena == (polje + i)->cijena) {
			printf("\nCijena alkoholnog pica je pronadena!\n\n");
			printf("Kategorija: %s\tIme: %s\tCijena: %d\tKolicina: %d\n\n", (polje + i)->kategorija, (polje + i)->ime, (polje + i)->cijena, (polje + i)->kolicina);
			brojac++;
		}
	}
	if (brojac == 0)
		printf("\nCijena alkoholnog pica nije pronadena!\n\n");
	return NULL;
}

void zamjena(ALKOHOL* veci, ALKOHOL* manji) {
	ALKOHOL temp = { 0 };
	temp = *manji;
	*manji = *veci;
	*veci = temp;
}

void selectionSortNajjefCijena(ALKOHOL* polje) {
	int min = -1;
	printf("Sortirana alkoholna pica po cijeni od najjeftinijeg do najskupljeg.\n");
	for (i = 0; i < brojAlkoholnogPica - 1; i++)
	{
		min = i;
		for (j = i + 1; j < brojAlkoholnogPica; j++)
		{
			if ((polje + j)->cijena < (polje + min)->cijena) {
				min = j;
			}
		}
		zamjena((polje + i), (polje + min));
	}

	for (i = 0; i < brojAlkoholnogPica; i++)
	{
		if (i == 0) {
			printf("Kategorija: %s\tIme: %s\tCijena: %d\tKolicina: %d\n", (polje + i)->kategorija, (polje + i)->ime, (polje + i)->cijena, (polje + i)->kolicina);

		}
		else if (i > 0 && i < brojAlkoholnogPica - 1) {
			printf("Kategorija: %s\tIme: %s\tCijena: %d\tKolicina: %d\n", (polje + i)->kategorija, (polje + i)->ime, (polje + i)->cijena, (polje + i)->kolicina);

		}
		else {
			printf("Kategorija: %s\tIme: %s\tCijena: %d\tKolicina: %d\n", (polje + i)->kategorija, (polje + i)->ime, (polje + i)->cijena, (polje + i)->kolicina);

		}
	}
	printf("\n");
}

void selectionSortNajskupCijena(ALKOHOL* polje) {
	int min = -1;
	printf("Sortirana alkoholna pica po cijeni od najskupljeg do najjeftinijeg.\n");
	for (i = 0; i < brojAlkoholnogPica - 1; i++)
	{
		min = i;
		for (j = i + 1; j < brojAlkoholnogPica; j++)
		{
			if ((polje + j)->cijena > (polje + min)->cijena) {
				min = j;
			}
		}
		zamjena((polje + i), (polje + min));
	}

	for (i = 0; i < brojAlkoholnogPica; i++)
	{
		if (i == 0) {
			printf("Kategorija: %s\tIme: %s\tCijena: %d\tKolicina: %d\n", (polje + i)->kategorija, (polje + i)->ime, (polje + i)->cijena, (polje + i)->kolicina);

		}
		else if (i > 0 && i < brojAlkoholnogPica - 1) {
			printf("Kategorija: %s\tIme: %s\tCijena: %d\tKolicina: %d\n", (polje + i)->kategorija, (polje + i)->ime, (polje + i)->cijena, (polje + i)->kolicina);

		}
		else {
			printf("Kategorija: %s\tIme: %s\tCijena: %d\tKolicina: %d\n", (polje + i)->kategorija, (polje + i)->ime, (polje + i)->cijena, (polje + i)->kolicina);

		}
	}
	printf("\n");
}

void brisanjeAlkoholnogPica(ALKOHOL* polje){
	FILE* fp=NULL;
	fp=fopen("AlkoholnaPica.bin","wb");
	if(fp == NULL){
		perror("  Brisanje alkoholnog pica");
	}

	rewind(fp);
	fseek(fp, sizeof(int),SEEK_CUR);

	int brojac = 0;
	int trazenoAlkoholnoPice;

	printf("\nUnesi ID alkoholnog pica koji zelite obrisati\n");
	scanf("%d",&trazenoAlkoholnoPice);

	for(i=0; i < brojAlkoholnogPica; i++){
		if(trazenoAlkoholnoPice != (polje + i)->id){
			fwrite((polje + i), sizeof(ALKOHOL), 1, fp);
			brojac++;
	}
	}
	rewind(fp);
	fwrite(&brojac, sizeof(int), 1, fp);
	fclose(fp);
}

void brisanjeDatoteke(ALKOHOL* polje) {
	printf("Zelite li pri izlasku programa izbrisati datoteku ili zadrzati?\n");
	printf("Ako zelite izbrisati datoteku upisite \"da\", u suprotnome upisite \"ne\" te datoteku zadrzavate.\n\n");

	char upit[3] = { '\0' };
	scanf("%2s", upit);

	if (!strcmp("da", upit)) {
		remove("AlkoholnaPica.bin") == 0 ? printf("\nUspjesno obrisana datoteka!\n") : printf("\nNeuspjesno brisanje datoteke ili datoteka uopce ne postoji!\n");
		printf("\nIzlaz iz programa!!\n");
		free(polje);

	}
	else printf("\nDatoteka zadrzana.\n\nIzlaz iz programa!!\n");
}
