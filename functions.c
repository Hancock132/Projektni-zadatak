#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "functions.h"

void Izbornik (void)			//Glavni izbornik
{
  int a = 0;
  do
    {
      printf("Odaberite opciju:\n1. Pokreni igru\n2. Ljestvica\n3. Upute za igranje\n4. Izlaz\n\n");
      scanf ("%d", &a);
      switch (a)
	{
	   case 1:
	   {
	   int BrojBodova = PacMan();                      //case 1 pokrece Pacman igru
	   }; break; 
	case 2:
	{
	  Ljestvica ();		                           //case 2 prikazuje ljestvicu
	};
      break;
case 3:
      {
	Upute ();		                           //case 3 prikazuje pravila Pacman igre
      };
      break;
case 4:
      {
	Izlaz ();		                           //case 4 izlazi iz programa
      };
      break;
default:
      {
	system ("cls");
	while ((getchar ()) != '\n');
	printf ("Molim da unesete broj izmedu 1 i 4.\n\n");	//ako upisemo nesto drugo zamolit ce nas da upisemo broj izmedu 1 i 4
      };
    }
  }
  while(1);
}


/* void Upute(void)         //pravila/upute za igranje vjesala
{
	system("cls");
	printf("\nIgrac kontrolira Pac-Mana, koji mora pojesti sve tocke unutar zatvorenog labirinta, izbjegavajuci duhove. Bodovi se dobivaju za svaku pojedenu tocku. Igrac gubi ako ga pojede jedan od duhova\n\n");
	NatragNaIzbornik();
}*/

int PacMan(void)  			// ovo se treba razvrstat u datoteke i uklopit sa ostatkom programa/izbornikom
{
#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include<MMsystem.h>
#define H 30
#define W 60
#define gho1 5

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
                           },
                           .vx = 0,
                           .vy = 0,
                           .food_coll = 0,
                         };

char playfield[H][W] =
{
   { "############################################################" },
   { "#                                                          #" },
   { "#   ##################     ######    ###################   #" },
   { "#                  ####      ##     ####                   #" },
   { "#    ####   ###    ####      ##     ####    ###    ####    #" },
   { "#    ####   ###    ####    ######   ####    ###    ####    #" },
   { "#    ####                                          ####    #" },
   { "#     ##################     ##     ##################     #" },
   { "#                            ##                            #" },
   { "#   ###############   ###    ##    ###   ###############   #" },
   { "#   ###               ###          ###               ###   #" },
   { "#   ###  ###   ##########  ##  ##  ##########  ###   ###   #" },
   { "#   ###               ###          ###               ###   #" },
   { "#   ###############   ###  ##  ##  ###   ###############   #" },
   { "#                                                          #" },
   { "#   ####    ###   #######   ####   #######   ###    ####   #" },
   { "#   ####    ###   #######   ####   #######   ###    ####   #" },
   { "#   ####    ###       ###   ####   ###       ###    ####   #" },
   { "#   ####                    ####                    ####   #" },
   { "#   ####     ############          ############     ####   #" },
   { "#   ####     ###                            ###     ####   #" },
   { "#   ####     ###                            ###     ####   #" },
   { "#   ####     ##################################     ####   #" },
   { "#   ####                                            ####   #" },
   { "#   ####   #############     ##     #############   ####   #" },
   { "#   ####   #############     ##     #############   ####   #" },
   { "#   ####        ####         ##          ####       ####   #" },
   { "#               ####     ##########      ####              #" },
   { "#       ####             ##########             ####       #" },
   { "############################################################" }
};
void display();
void SetColor(int ForgC);
//
void initialize()
{
   // 1. replace each empty field in the playfield with a food field
   int i;

   for(i = 0; i < H; i++)
   {
       int j;
      for( j = 0; j < W; j++)
      {
         if (playfield[i][j]==' ')
            playfield[i][j] = '.';
      }
   }

   // 2. initialize all ghosts

   for ( i = 0; i <gho1; i++)
   {
      allGhosts[i].vx = 0;
      allGhosts[i].vy = 0;
      // try to find a (x,y) coordinate randomly where a food piece is
      int x,y;
      do
     {
         x = 1 + rand() % (W-1);
         y = 1 + rand() % (H-1);

     } while (playfield[y][x] != '.');
      allGhosts[i].position.x = x;
      allGhosts[i].position.y = y;
      playfield[y][x] = '%';

   }
     for ( i = 0; i < gho1; i++)
   {
      allGhosts2[i].vx = 0;
      allGhosts2[i].vy = 0;
      // try to find a (x,y) coordinate randomly where a food piece is
      int x,y;
      do
     {
         x = 1 + rand() % (W-1);
         y = 1 + rand() % (H-1);

     } while (playfield[y][x] != '.');
      allGhosts2[i].position.x = x;
      allGhosts2[i].position.y = y;
      playfield[y][x] = '%';

   }



}

//
void user_input()
{
   if (_kbhit())
   {
      char c1 = _getch();

      if (c1 == -32)
      {
         char c2 = _getch();

         myPacMan.vx = 0;
         myPacMan.vy = 0;
         int i;
         for(i=0;i<gho1;i++)
        {
             allGhosts[i].vx=0;
             allGhosts[i].vy=0;
             allGhosts2[i].vx=0;
             allGhosts2[i].vy=0;

        }

         switch (c2)
         {
            case 72: myPacMan.vy = -1; break; // cursor up
            case 80: myPacMan.vy = +1; break; // cursor down
            case 75: myPacMan.vx = -1; break; // cursor left
            case 77: myPacMan.vx = +1; break; // cursor right
         }
         for(i=0;i<gho1;i++)
         {
             allGhosts[i].vx=+1;
             allGhosts[i].vy=+1;
             allGhosts2[i].vx=0;
             allGhosts2[i].vy=+1;
         }
      }




   }

}
void display()
{
    SetColor(1);
printf("                                        _______   ______    _____   ___      ___   ______   ___       \n");
printf("                                       ||     || ||    ||  ||      ||  |    |  || ||    || ||  |    ||\n");
printf("                                       ||     || ||    ||  ||      ||   |  |   || ||    || ||   |   ||\n");
printf("                                       ||_____|| ||____||  ||      ||    ||    || ||____|| ||    |  ||\n");
printf("                                       ||        ||    ||  ||      ||          || ||    || ||     | ||\n");
printf("                                       ||        ||    ||  ||____  ||          || ||    || ||      |||\n");
SetColor(15);
}

//swaroop
void move_figures()
{
   // 1. delete PacMan from old position
   playfield[myPacMan.position.y][myPacMan.position.x] = ' ';
   int i;
   for(i=0;i<gho1;i++)
   {
       playfield[allGhosts[i].position.y][allGhosts[i].position.x] = ' ';
        playfield[allGhosts2[i].position.y][allGhosts2[i].position.x] = ' ';
   }

   // 2. compute new desired coordinate (nx,ny)
   int nx = myPacMan.vx + myPacMan.position.x;
   int ny = myPacMan.vy + myPacMan.position.y;
   int mx[5];
   int my[5];
   int mx1[5];
   int my1[5];
 for(i=0;i<gho1;i++)
   {
        mx[i] = allGhosts[i].vx + allGhosts[i].position.x;
        my[i] = allGhosts[i].vy + allGhosts[i].position.y;
        mx1[i] = allGhosts2[i].vx + allGhosts2[i].position.x;
        my1[i] = allGhosts2[i].vy + allGhosts2[i].position.y;
   }
   // 3. test whether there is a wall at (nx,ny)
   if (playfield[ny][nx] == '#')
   {
      myPacMan.vx = 0;
      myPacMan.vy = 0;
   }
   for(i=0;i<gho1;i++)
   {

   if(playfield[my[i]][mx[i]]=='#')
      {
          if(allGhosts[i].vx>0 || allGhosts[i].vy>0)
          {

                allGhosts[i].vx=-1;
                allGhosts[i].vy=-1;
            }
            else
            {
                allGhosts[i].vx=+1;
                allGhosts[i].vy=+1;
            }
      }
    if(playfield[my1[i]][mx1[i]]=='#')
    {
        if(allGhosts2[i].vy<0)
          {

                allGhosts2[i].vx=0;
                allGhosts2[i].vy=+1;
            }
            else
            {
                allGhosts2[i].vx=0;
                allGhosts2[i].vy=-1;
            }
    }



}



   // 4. update PacMan's coordinate

   myPacMan.position.x += myPacMan.vx;
   myPacMan.position.y += myPacMan.vy;
    for(i=0;i<gho1;i++)
      {
          allGhosts[i].position.x+=allGhosts[i].vx;
          allGhosts[i].position.y+=allGhosts[i].vy;
          allGhosts2[i].position.x+=allGhosts2[i].vx;
          allGhosts2[i].position.y+=allGhosts2[i].vy;

      }

   // 5. check for a food piece at the new location
   if (playfield[ny][nx] == '.')
   {
      myPacMan.food_coll++;
   }
   for(i=0;i<gho1;i++)

   {

    if(playfield[my[i]][mx[i]] == '.')
    {

            playfield[my[i]-allGhosts[i].vy][mx[i]-allGhosts[i].vx]='.';
    }
    if(playfield[my1[i]][mx1[i]] == '.')
    {

            playfield[my1[i]-allGhosts2[i].vy][mx1[i]-allGhosts2[i].vx]='.';
    }
    }


   // 6. put PacMan back again to playfield

   playfield[myPacMan.position.y][myPacMan.position.x] = '@';
    for(i=0;i<gho1;i++)
    {
        playfield[allGhosts[i].position.y][allGhosts[i].position.x]='%';
        playfield[allGhosts2[i].position.y][allGhosts2[i].position.x]='%';
    }

}

void show_playfield()
{
    int i;
   for ( i = 0; i < H; i++)
   {
       printf("                                       ");
       int j;
      for ( j = 0; j < W; j++)
      {
          if(playfield[i][j]=='.')
          {
              SetColor(4);
            printf("%c", playfield[i][j]);
                SetColor(15);
          }
            else if(playfield[i][j]=='%')
            {
                SetColor(9);
                printf("%c", playfield[i][j]);
                SetColor(15);
            }
            else if(playfield[i][j]=='@')
            {
                SetColor(14);
                printf("%c", playfield[i][j]);
                SetColor(15);
            }
            else
            {
                printf("%c", playfield[i][j]);
            }
      }
      printf("\n");
   }

   printf("                                       Score: %d\n", myPacMan.food_coll);
}
void check_coll()
{
    int i=0;
     for(i=0;i<gho1;i++)
   {
       if((allGhosts[i].position.x==myPacMan.position.x && allGhosts[i].position.y==myPacMan.position.y) || (allGhosts2[i].position.x==myPacMan.position.x && allGhosts2[i].position.y==myPacMan.position.y))
        {
            system("cls");
            display();
            printf("\n\n\n");
            printf("     \t\t\t\t\t\t\t\t\tYOUR SCORE IS:%d",myPacMan.food_coll);
            // PlaySound(TEXT("death.wav"),NULL,SND_SYNC);
            getchar();
            exit(0);
        }
        if(myPacMan.food_coll>=250)
        {
            system("cls");
            display();
            printf("\n\n\n");
            printf("     \t\t\t\t\t\t\t\tYOUR SCORE IS:%d",myPacMan.food_coll);
            // PlaySound(TEXT("fireworks.wav"),NULL,SND_SYNC);
            getchar();
            exit(0);
            }
   }
}

//
void set_cursor_position(int x, int y)
{
   //Initialize the coordinates
   COORD coord = { x, y };
   //Set the position
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

} // set_cursor_position


void hidecursor()
{
   HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
   CONSOLE_CURSOR_INFO info;
   info.dwSize = 100;
   info.bVisible = FALSE;
   SetConsoleCursorInfo(consoleHandle, &info);
}
void SetColor(int ForgC)
{
     WORD wColor;
     //This handle is needed to get the current background attribute

     HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
     CONSOLE_SCREEN_BUFFER_INFO csbi;
     //csbi is used for wAttributes word

     if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
     {
          //To mask out all but the background attribute, and to add the color
          wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
          SetConsoleTextAttribute(hStdOut, wColor);
     }
     return;
}


int main()
{
   system("cls");
   hidecursor();
   initialize();
   // PlaySound(TEXT("pacman.wav"),NULL,SND_SYNC);

   while (1)
   {
      user_input();
      move_figures();
      display();
      show_playfield();
      check_coll();
      Sleep( 10/ 30 );
      set_cursor_position(0,0);
   }

}
    
}

/* void PokusajPonovno(int BrojBodova)
{
	char da[] = "da";
	char ne[] = "ne";
	char odluka[3];
	printf("\nBroj bodova: %d\n", BrojBodova);
	printf("Pokusaj ponovno?\nda/ne\n\n");                   //Opcija da pokusamo ponovno odigrati PacMan ako nismo zadovoljni s dobivenim bodovima
	scanf("%s", &odluka);
	if (_strcmpi(da, odluka) == 0)                            //ako upisemo "da" ponovno se pokrece PacMan
	{
		PacMan();
	}
	if (_strcmpi(ne, odluka) == 0)                           //ako upisemo "ne" program ide dalje s upisivanjem bodova i korisnickog imena
	{
		UpisBodova(BrojBodova);
	}
	else
	{
		system("cls");
		printf("\nUpisite 'da' ili 'ne'\n\n");              //ako upisemo nesto sto nije "da" ili "ne" 
		PokusajPonovno(BrojBodova);
	}
} */


/* void Izlaz(void)
{
	char da[] = "da";
	char ne[] = "ne";
	char odluka[3];
	printf("Jeste li sigurni zelite li izaci iz igre?\nda/ne\n\n");
	scanf("%s", &odluka);
	if (_strcmpi(da, odluka) == 0)                                        //ako upisemo "da" izaci cemo potpuno iz programa
	{
		exit(EXIT_SUCCESS);
	}
	if (_strcmpi(ne, odluka) == 0)                                       //ako upisemo "ne" vracamo se natrag u izbornik
	{
		system("cls");
		Izbornik();
	}
	else
	{
		system("cls");
		printf("\nUpisite 'da' ili 'ne'.\n");                          //ako napisemo nesto sto nije "da" ili "ne" dobit cemo ovu poruku i ponovno cemo moci napisati "da" ili "ne"*/
	}
}
		
/* void UpisBodova(int BrojBodova)
{
	FILE* Test = NULL;
	Test = fopen("Ljestvica.bin", "rb");                    //Program provjerava postoji li Ljestvica.bin 
	if (Test == NULL)
	{
		fflush(Test);
		Test = fopen("Ljestvica.bin", "wb");                //Ako ne postoji Ljestvica.bin program ju napravi, u suprotnom ako vec postoji Ljestvica.bin program ide dalje
		int Broj = 0;
		fwrite(&Broj, sizeof(int), 1, Test);
	}
	fclose(Test);
	PLAYER* igrac = NULL;
	igrac = (PLAYER*)calloc(1, sizeof(PLAYER));
	FILE* fp = NULL;
	fp = fopen("Ljestvica.bin", "rb+");
	if (fp == NULL)
	{
		perror("Otvaranje");
	}
	else
	{
		int x = 0;
		fread(&x, sizeof(int), 1, fp);
		x++;
		fseek(fp, 0, SEEK_SET);
		fwrite(&x, sizeof(int), 1, fp);
		fseek(fp, 0, SEEK_END);
		printf("Osvojeni bodovi: %d\n", BrojBodova);
		printf("Unesite vase ime: ");
		scanf(" %[^\n]%*c", igrac->ime);
		igrac->bodovi = BrojBodova;
		fwrite(igrac, sizeof(PLAYER), 1, fp);
		system("cls");
	}
	fclose(fp);
} */


/* void Ljestvica(void)
{
	system("cls");
	FILE* fp = NULL;
	fp = fopen("Ljestvica.bin", "rb+");
	if (fp == NULL)
	{
		perror("Error");
		printf("Nema upisanih igraca");                 //ako pokusamo otvoriti ljestvicu dok nema upisanih igraca dobit cemo poruku da trenutacno nema igraca i vratit ce nas u izbornik
		NatragNaIzbornik();
	}
	else
	{
		int k = 0;
		fread(&k, sizeof(int), 1, fp);
		PLAYER* igrac = NULL;
		igrac = (PLAYER*)calloc(k, sizeof(PLAYER));
		fread(igrac, sizeof(PLAYER), k, fp);
		int x = 0;
		do
		{
			while ((getchar()) != '\n');
			BrojIgraca();
			printf("Zelite li poredati po:\n1. imenima\n2. bodovima\n3. Pretrazi igraca\n4. Nazad\n\n\n");
			scanf("%d", &x);
			switch (x)
			{
			case 1:
			{
				system("cls");
				SelectionSortIme(igrac, k);
				IspisLjestviceIme(igrac, k);
				NatragNaIzbornik();
			} break;
			case 2:
			{
				system("cls");
				SelectionSortBodovi(igrac, k);
				IspisLjestviceBodovi(igrac, k);
				NatragNaIzbornik();
			}break;
			case 3:
			{
				system("cls");
				PretrazivanjeIgraca();
			}break;
			case 4:
			{
				system("cls");
				Izbornik();
			}
			default:
			{
				system("cls");
				printf("Molim da unesete broj izmedu 1 i 3\n\n");
			};
			}
		} while (1);
	}
} */


/* void SelectionSortBodovi(PLAYER* igrac, const int k)
{
	int min = 0;
	for (int i = 0; i < k - 1; i++)
	{
		min = i;
		for (int j = i + 1; j < k; j++)
		{
			if ((igrac + j)->bodovi > (igrac + min)->bodovi) 
			{
				min = j;
			}
		}
		Zamjena((igrac + i), (igrac + min));
	}
} */


/* void SelectionSortIme(PLAYER* igrac, const int k)
{
	int min = 0;
	for (int i = 0; i < k - 1; i++)
	{
		min = i;
		for (int j = i + 1; j < k; j++)
		{
			if (strcmp((igrac + j)->ime, (igrac + min)->ime) < 0) 
			{
				min = j;
			}
		}
		Zamjena((igrac + i), (igrac + min));
	}
} */


/* void Zamjena(PLAYER* veci, PLAYER* manji) 
{
	PLAYER temp = *manji;
	*manji = *veci;
	*veci = temp;
} */


/* void IspisLjestviceIme(PLAYER* igrac, const int k)
{
	int i;
	for (i = 0; i < k; i++)
	{
		printf("\n%d. Ime: %s   Bodovi: %d\n", (i + 1), (igrac + i)->ime, (igrac + i)->bodovi);
	}
} */


/* void IspisLjestviceBodovi(PLAYER* igrac, const int k)
{
	int i;
	for (i = 0; i < 10; i++)
	{
		printf("\n%d. Ime: %s   Bodovi: %d\n", (i + 1), (igrac + i)->ime, (igrac + i)->bodovi);
	}
} */


/* void NatragNaIzbornik(void)
{
	while ((getchar()) != '\n');
	int p = 0;
	printf("\nPritisnite broj 1 za povratak u izbornik  ");
	scanf("%d", &p);
	if (p == 1)
	{
		system("cls");
		Izbornik();
	}
	else
	{
		system("cls");
		printf("\nPogresan unos, pokusajte ponovno\n\n");
		NatragNaIzbornik();
	}
} */






