#ifndef FUNCTIONS_H
#define FUNCTIONS_H

typedef struct alkohol {
	int id;
	char kategorija[25];
	char ime[25];
	int cijena;
	int kolicina;
}ALKOHOL;

int izbornik();
int izbornikPretrazivanje();
int izbornikSortiranje();
void kreiranjeDatoteke();
void dodavanjeAlkoholnogPica();
void azuriranje();
void* ucitavanjeAlkoholnogPica();
void ispisivanje(ALKOHOL*);
void* pretragaIme(ALKOHOL*);
void* pretragaCijena(ALKOHOL*);
void* pretragaKategorija(ALKOHOL*);
void zamjena(ALKOHOL*, ALKOHOL*);
void selectionSortNajjefCijena(ALKOHOL*);
void selectionSortNajskupCijena(ALKOHOL*);

void brisanjeAlkoholnogPica(ALKOHOL*);

void brisanjeDatoteke(ALKOHOL*);


#endif // HEADER_H


