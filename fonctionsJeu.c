#include "fonctionsJeu.h"

void initialiserPlateauJeu(PlateauJeu *plateau, int size)
{
	plateau->longueur = size;
	plateau->nbAllumPlateau = size;
	plateau->plateau = malloc(size * sizeof(int));
	for (int i = 0; i <= size; i++)
	{
		plateau->plateau[i] = 1;
	}
	return;
}

void initialiserCoup(Coup *monCoup)
{
	monCoup->nombre = 0;
	monCoup->position = 0;
	return;
}

void affichePlateau(PlateauJeu plateau)
{
	int j;
	printf("\nnb allum: %d\n\n", plateau.nbAllumPlateau);

	for (j = 0; j < plateau.longueur; j++) { printf("***"); }

	printf("\n");
	for (j = 0; j < plateau.longueur; j++)   //parcourir les 2 lignes
	{
		if (j>9)
			printf("|%d", j);
		else
			printf("|%d ", j);
	}

	printf("\n");
	for (j = 0; j < plateau.longueur; j++) { printf("|**"); }

	printf("\n");
	for (j = 0; j < plateau.longueur; j++)
	{
		if (plateau.plateau[j] == 1) { printf("|i "); }
		else { printf("|  "); }
	}

	printf("\n");
	for (j = 0; j < plateau.longueur; j++) { printf("***"); }

	printf("\n");
	return;
}

void afficheCoup(Coup coup)
{
	printf("Nombre d'allumette(s) a enleve : %d\n", coup.nombre);
	printf("Position de la premiere allumette a enleve : %d\n", coup.position);
}

void copyPlateau(PlateauJeu partie, PlateauJeu *copyPartie)
{
	int i;
	initialiserPlateauJeu(copyPartie, partie.longueur);
	copyPartie->longueur = partie.longueur;
	copyPartie->nbAllumPlateau = partie.nbAllumPlateau;
	for (i = 0; i < partie.longueur; i++) { copyPartie->plateau[i] = partie.plateau[i]; }
}

void getCoupJouer(int sizePlateau, Coup *coupJouer)
{
	int nombre = 0, position = 0;

	while (nombre < 1 || nombre > 3)
	{
		printf("\nNombre d'allumettes a enlever : ");
		scanf("%d", &nombre);
		if (nombre < 1 || nombre > 3)
			printf("\nNon! Tu ne peut pas ! :/\n\n");
	}

	position = sizePlateau + 1;
	while (position < 0 || position > sizePlateau)
	{
		printf("Position de premiere allumettes a enlever : ");
		scanf("%d", &position);
		if (position < 0 || position > sizePlateau)
			printf("\nNon! Tu ne peut pas ! :/\n\n");
	}

	if ((nombre + position) > sizePlateau)
	{
		printf("\nNon! Coup non possible ! :/\n\n");
		printf("\nLa case %d n'existe pas !", (nombre + position));
		getCoupJouer(sizePlateau, coupJouer);
	}
	coupJouer->nombre = nombre;
	coupJouer->position = position;
	return;
}

int coupPossible(PlateauJeu partie, Coup monCoup)
{
	if (monCoup.nombre == 0) { return 1; }
	else if (partie.plateau[monCoup.position] == 0) { return 0; }
	else if ((monCoup.nombre + monCoup.position) > partie.longueur) { return 0; }
	else if (monCoup.position < 0 || monCoup.position > partie.longueur) { return 0; }
	else if (monCoup.nombre < 0 || monCoup.nombre > 3) { return 0; }
	else
	{
		monCoup.nombre--;
		monCoup.position++;
		coupPossible(partie, monCoup);
	}
}

void jouerCoup(PlateauJeu *partie, Coup monCoup)
{
	if (monCoup.nombre <= 0)
		return;

	if (partie->plateau[monCoup.position] == 1)
	{
		partie->nbAllumPlateau--;
		partie->plateau[monCoup.position] = 0;
		monCoup.nombre--;
		monCoup.position++;
		jouerCoup(partie, monCoup);
	}
	else
		return;
}