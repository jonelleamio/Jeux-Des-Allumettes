#include "screen.h"
#define LARGEUR_CONSOLE 80

void centrer(const char* str)
{
	unsigned int n;
	for (n = 0; n < (LARGEUR_CONSOLE - strlen(str)) / 2; n++)
	{
		putchar(' ');
	}
	printf("%s", str);
}

void header()
{
	system("cls");
	printf("\n\n");
	centrer("**********************\n");
	centrer("* Jeu des allumettes *\n");
	centrer("**********************\n");
	printf("\n\n");
}