#include "jeu1vs1.h"

int jeu1vs1(PlateauJeu partie, int tourJoueur1, int tourJoueur2, int N)
{
	int tourDeJoueur = 0, coupJoueurPossible = 0;
	Coup coupJouer;
	initialiserCoup(&coupJouer);

	if (tourJoueur1 == tourJoueur2) { tourDeJoueur = 1; }
	else { tourDeJoueur = 2; }

	while (coupJoueurPossible == 0)
	{
		header();
		affichePlateau(partie);
		
		printf("Tour de J%d", tourDeJoueur);
		getCoupJouer(partie.longueur, &coupJouer);
		
		coupJoueurPossible = coupPossible(partie, coupJouer);
	}

	jouerCoup(&partie, coupJouer);

	if (tourDeJoueur == 1) { tourJoueur1++; }
	else if (tourDeJoueur == 2) { tourJoueur2++; }

	if (partie.nbAllumPlateau == 1) { return tourDeJoueur; }
	else if (partie.nbAllumPlateau < 1) 
	{ 
		if (tourDeJoueur == 1) { return 2; }
		else { return 1; }
	}
	else { jeu1vs1(partie, tourJoueur1, tourJoueur2, N); }
	return 0;
}