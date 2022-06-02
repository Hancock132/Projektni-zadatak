#define _CRT_SECURE_NO_WARNINGS
#ifndef FUNCTIONS
#define FUNCTIONS

typedef struct
{
	char ime[20];
	int bodovi;
}PLAYER;
PLAYER igrac;

struct coord
{
	int x;
	int y;
};

struct PacMan
{
	struct coord position;
	int vx;
	int vy;
	int food_coll;
};


struct Ghost
{
	struct coord position;
	int vx;
	int vy;
};


struct Ghost allGhosts[gho1];
struct Ghost allGhosts2[gho1];

struct PacMan myPacMan = {
	{
		.x = 1,
		.y = 5,
	};
	.vx = 0,
	.vy = 0,
	.food_coll = 0;				   
};

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
void display();
void SetColor(int ForgC);
void initialize();
void user_input();
void move_figures();
void show_playfield();
void check_coll();
void set_cursor_position();
void hidecursor();
void SetColor();
int main();

#endif 
