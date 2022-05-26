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
	   int BrojBodova = PacMan();                //case 1 pokrece Pacman igru
	   }; break; 
	case 2:
	{
	  Ljestvica ();		                           //case 2 prikazuje ljestvicu
	};
      break;
case 3:
      {
	Upute ();		                                //case 3 prikazuje pravila Pacman igre
      };
      break;
case 4:
      {
	Izlaz ();		                                //case 4 izlazi iz programa
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

int PacMan(void)
{
    
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






