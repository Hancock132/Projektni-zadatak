#define _CRT_SECURE_NO_WARNINGS
#ifndef FUNCTIONS
#define FUNCTIONS

typedef struct
{
	char ime[20];
	int bodovi;
}PLAYER;
PLAYER igrac;

void Izbornik(void);
int PacMan(void);
void Ljestvica(void);
void Upute(void);
void Izlaz(void);
void UpisBodova(int);
void PokusajPonovno(int);
void Zamjena(PLAYER*, PLAYER*);
void SelectionSortIme(PLAYER*, const int);
void SelectionSortBodovi(PLAYER*, const int);
void IspisLjestviceIme(PLAYER*, const int);
void IspisLjestviceBodovi(PLAYER*, const int);
void NatragNaIzbornik(void);
void BrojIgraca(void);
void PretrazivanjeIgraca(void);
void PonovnoPretrazi(void);


#endif 
