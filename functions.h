#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

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

#endif 
