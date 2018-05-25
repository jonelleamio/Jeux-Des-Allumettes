#include "test.h"

int TestGameFunctions()
{
	header();

	if (testInitialiserPlateauJeu() == 0) {
		printf("\nErreur initialiserPlateauJeu() !\n");
		return 0;
	}
	else{ printf("\n OK itialiserPlateauJeu()\n"); }

	if (testInitialiserCoup() == 0) {
		printf("\nErreur initialiserCoup() !\n");
		return 0;
	}
	else{ printf("\n OK initialiserCoup()\n"); }

	if (testJouerCoup() == 0) {
		printf("\nErreur jouerCoup() !\n");
		return 0;
	}
	else { printf("\n OK jouerCoup()\n"); }

	if (testCoupPossible() == 0) {
		printf("\nErreur coupPossible() !\n");
		return 0;
	}
	else { printf("\n OK coupPossible()\n"); }

	if (testCoupGagnant() == 0) {
		printf("\nErreur coupGagnant() !\n");
		return 0;
	}
	else { printf("\n OK coupGagnant()\n"); }

	if (testCoupAi() == 0) {
		printf("\nErreur coupAi() !\n");
		return 0;
	}
	else { printf("\n OK coupAi()\n"); }

	if (testCopyPlateau() == 0) {
		printf("\nErreur copyPlateau() !\n");
		return 0;
	}
	else { printf("\n OK copyPlateau()\n"); }


	printf("\n\n");
	centrer("###################################\n");
	centrer("# Toutes les fonctions marchent ! #\n");
	centrer("###################################\n");
	printf("\n\n");

	return 1;
}

int testInitialiserPlateauJeu()
{
	PlateauJeu plateauTest;
	int i, size = 21;

	initialiserPlateauJeu(&plateauTest, size);
	if (plateauTest.longueur != size || plateauTest.nbAllumPlateau != size) { return 0; }
	for (i = 0; i < size; i++) {
		if (plateauTest.plateau[i] != 1) {
			return 0;
		}
	}
	return 1;
}

int testInitialiserCoup()
{
	Coup coupTest;
	initialiserCoup(&coupTest);
	if (coupTest.nombre != 0) { return 0; }
	if (coupTest.position != 0) { return 0; }

	return 1;
}

int testCopyPlateau()
{
	int y;
	PlateauJeu plateauTest, plateauTestCopy;
	plateauTest.longueur = 10;
	plateauTest.nbAllumPlateau = plateauTest.longueur;
	plateauTest.plateau = malloc(plateauTest.longueur * sizeof(int));
	for (y = 0; y < plateauTest.longueur; y++) { plateauTest.plateau[y] = 1; }

	copyPlateau(plateauTest, &plateauTestCopy);
	
	if (plateauTest.longueur != plateauTestCopy.longueur) { return 0; }
	if (plateauTest.nbAllumPlateau != plateauTestCopy.nbAllumPlateau) { return 0; }
	for (y = 0; y < plateauTest.longueur; y++) 
	{ 
		if (plateauTest.plateau[y] != plateauTestCopy.plateau[y]) { return 0; }
	}

	return 1;
}

int testJouerCoup()
{
	int i, y;
	PlateauJeu plateauTest;
	Coup coupTest;

	plateauTest.longueur = 10;
	plateauTest.nbAllumPlateau = plateauTest.longueur;
	plateauTest.plateau = malloc(plateauTest.longueur * sizeof(int));
	for (y = 0; y < plateauTest.longueur; y++) { plateauTest.plateau[y] = 1; }

	coupTest.nombre = 3;
	coupTest.position = 3;

	jouerCoup(&plateauTest, coupTest);

	if (plateauTest.nbAllumPlateau != (plateauTest.longueur - coupTest.nombre)) { return 0; }
	for (i = coupTest.position; i < (coupTest.position + coupTest.nombre); i++) 
	{
		if (plateauTest.plateau[i] == 1) { return 0; }
	}
	return 1;
}

int testCoupPossible()
{
	int y;
	PlateauJeu plateauTest;
	Coup coupTest;

	plateauTest.longueur = 10;
	plateauTest.nbAllumPlateau = plateauTest.longueur;
	plateauTest.plateau = malloc(plateauTest.longueur * sizeof(int));
	for (y = 0; y < plateauTest.longueur; y++) { plateauTest.plateau[y] = 1; }



	coupTest.nombre = 3;
	coupTest.position = 11;
	if (coupPossible(plateauTest, coupTest) == 1) { return 0; }

	coupTest.nombre = 3;
	coupTest.position = 10;
	if (coupPossible(plateauTest, coupTest) == 1) { return 0; }

	coupTest.nombre = 4;
	coupTest.position = 3;
	if (coupPossible(plateauTest, coupTest) == 1) { return 0; }

	coupTest.nombre = -1;
	coupTest.position = 3;
	if (coupPossible(plateauTest, coupTest) == 1) { return 0; }

	coupTest.nombre = 3;
	coupTest.position = -1;
	if (coupPossible(plateauTest, coupTest) == 1) { return 0; }

	coupTest.nombre = -1;
	coupTest.position = -1;
	if (coupPossible(plateauTest, coupTest) == 1) { return 0; }

	coupTest.nombre = 3;
	coupTest.position = 0;
	plateauTest.plateau[0] = 0;
	if (coupPossible(plateauTest, coupTest) == 1) { return 0; }

	coupTest.nombre = 3;
	coupTest.position = 0;
	plateauTest.plateau[1] = 0;
	if (coupPossible(plateauTest, coupTest) == 1) { return 0; }

	coupTest.nombre = 3;
	coupTest.position = 0;
	plateauTest.plateau[2] = 0;
	if (coupPossible(plateauTest, coupTest) == 1) { return 0; }

	coupTest.nombre = 3;
	coupTest.position = 0;
	plateauTest.plateau[3] = 0;
	if (coupPossible(plateauTest, coupTest) == 1) { return 0; }

	return 1;
}

int testCoupGagnant()
{
	int y;
	PlateauJeu plateauTest;
	Coup coupTest;


	plateauTest.longueur = 4;
	plateauTest.nbAllumPlateau = plateauTest.longueur;
	plateauTest.plateau = malloc(plateauTest.longueur * sizeof(int));
	for (y = 0; y < plateauTest.longueur; y++) { plateauTest.plateau[y] = 1; }

	coupTest.nombre = 3;
	coupTest.position = 0;
	if (coupGagnant(plateauTest, coupTest) != 1) { return 0; }

	plateauTest.longueur = 6;
	plateauTest.nbAllumPlateau = plateauTest.longueur;
	plateauTest.plateau = malloc(plateauTest.longueur * sizeof(int));
	for (y = 0; y<plateauTest.longueur; y++) { plateauTest.plateau[y] = 1; }

	coupTest.nombre = 2;
	coupTest.position = 2;
	if (coupGagnant(plateauTest, coupTest) != 1) { return 0; }

	return 1;
}

int testCoupAi()
{
	int y;
	PlateauJeu plateauTest;
	Coup coupTest;


	plateauTest.longueur = 4;
	plateauTest.nbAllumPlateau = plateauTest.longueur;
	plateauTest.plateau = malloc(plateauTest.longueur * sizeof(int));
	for (y = 0; y < plateauTest.longueur; y++) { plateauTest.plateau[y] = 1; }

	coupAi(plateauTest, &coupTest, 1);
	if (coupTest.nombre != 3 && coupTest.position != 0) { return 0; }

	plateauTest.longueur = 6;
	plateauTest.nbAllumPlateau = plateauTest.longueur;
	plateauTest.plateau = malloc(plateauTest.longueur * sizeof(int));
	for (y = 0; y < plateauTest.longueur; y++) { plateauTest.plateau[y] = 1; }

	coupAi(plateauTest, &coupTest, 1);
	if (coupTest.nombre != 1 && coupTest.position != 0) { return 0; }

	return 1;
}