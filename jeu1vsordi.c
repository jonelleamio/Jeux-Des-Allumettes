#include "jeu1vsordi.h"

int jeu1vsordi(PlateauJeu partie, int tourJoueur1, int tourJoueur2, int N, int nv)
{
	int coupJoueurPossible = 0;
	Coup coupJouer;
	initialiserCoup(&coupJouer);

	if (tourJoueur1 == tourJoueur2)
	{ 
		while (coupJoueurPossible == 0)
		{
			header();
			affichePlateau(partie);

			printf("C'est votre tour");
			getCoupJouer(partie.longueur, &coupJouer);

			coupJoueurPossible = coupPossible(partie, coupJouer);
		}
		jouerCoup(&partie, coupJouer);
		tourJoueur1++;

		if (partie.nbAllumPlateau == 1) { return 1; }
		else if (partie.nbAllumPlateau < 1){ return 3; }
		else { jeu1vsordi(partie, tourJoueur1, tourJoueur2, N, nv); }
	}
	else 
	{
		header();
		affichePlateau(partie);

		PlateauJeu copyPartie;
		copyPlateau(partie, &copyPartie);
		printf("C'est au tour d'ordinateur !\n\n");
		switch (nv)
		{
			case 1: coupAi(copyPartie, &coupJouer, 3); break;
			case 2: coupAi(copyPartie, &coupJouer, 2); break;
			case 3: coupAi(copyPartie, &coupJouer, 1); break;
			default: break;
		}
		printf("Ordi enleve allumettes %d allumettes\n", coupJouer.nombre);
		printf("Ordi enleve allumette de position %d \n", coupJouer.position);
		system("pause");
		
		jouerCoup(&partie, coupJouer);
		tourJoueur2++;
		
		if (partie.nbAllumPlateau == 1) { return 3; }
		else if (partie.nbAllumPlateau < 1) { return 1; }
		else { jeu1vsordi(partie, tourJoueur1, tourJoueur2, N, nv); }
	}
}

void coupAi(PlateauJeu partie, Coup *monCoup, int methode)
{
	int i, j, resAi;
	PlateauJeu copyPartie;

	if (methode == 1) {
		copyPlateau(partie, &copyPartie);
		if (partie.nbAllumPlateau <= 4)
		{
			monCoup->nombre = partie.nbAllumPlateau - 1;
			for (i = 0; i < partie.longueur; i++) {
				monCoup->position = i;
				if (coupPossible(partie, *monCoup) == 1) { return; }
			}
			coupAi(copyPartie, monCoup, 2);
		}
		else if ((partie.nbAllumPlateau > 5) && (partie.nbAllumPlateau <= 8))
		{
			monCoup->nombre = partie.nbAllumPlateau - 5;
			for (i = 0; i < partie.longueur; i++) {
				monCoup->position = i;
				if (coupPossible(partie, *monCoup) == 1) { return; }
			}
			coupAi(copyPartie, monCoup, 2);
		}
		else if (partie.nbAllumPlateau % 4 == 0)
		{
			monCoup->nombre = 3;
			for (i = 0; i < partie.longueur; i++) {
				monCoup->position = i;
				if (coupPossible(partie, *monCoup) == 1) { return; }
			}
			coupAi(copyPartie, monCoup, 2);
		}
		else if (partie.nbAllumPlateau % 4 == 2)
		{
			monCoup->nombre = 1;
			for (i = 0; i < partie.longueur; i++) {
				monCoup->position = i;
				if (coupPossible(partie, *monCoup) == 1) { return; }
			}
			coupAi(copyPartie, monCoup, 2);
		}
		else if (partie.nbAllumPlateau % 4 == 3)
		{
			monCoup->nombre = 2;
			for (i = 0; i < partie.longueur; i++) {
				monCoup->position = i;
				if (coupPossible(partie, *monCoup) == 1) { return; }
			}
			coupAi(copyPartie, monCoup, 2);
		}
		else
		{
			coupAi(copyPartie, monCoup, 2);
		}
	}
	else if (methode == 2) {
		copyPlateau(partie, &copyPartie);
		if (partie.nbAllumPlateau <= 4)
		{
			monCoup->nombre = partie.nbAllumPlateau - 1;
			for (i = 0; i < partie.longueur; i++) {
				monCoup->position = i;
				if (coupPossible(partie, *monCoup) == 1) { return; }
			}
			coupAi(copyPartie, monCoup, 3);
		}
		else if ((partie.nbAllumPlateau > 5) && (partie.nbAllumPlateau <= 8))
		{
			monCoup->nombre = partie.nbAllumPlateau - 5;
			for (i = 0; i < partie.longueur; i++) {
				monCoup->position = i;
				if (coupPossible(partie, *monCoup) == 1) { return; }
			}
			coupAi(copyPartie, monCoup, 3);
		}
		else if (partie.nbAllumPlateau % 4 == 0)
		{
			monCoup->nombre = 3;
			for (i = 0; i < partie.longueur; i++) {
				monCoup->position = i;
				if (coupPossible(partie, *monCoup) == 1) { return; }
			}
			coupAi(copyPartie, monCoup, 3);
		}
		else if (partie.nbAllumPlateau % 4 == 2)
		{
			monCoup->nombre = 1;
			for (i = 0; i < partie.longueur; i++) {
				monCoup->position = i;
				if (coupPossible(partie, *monCoup) == 1) { return; }
			}
			coupAi(copyPartie, monCoup, 3);
		}
		else if (partie.nbAllumPlateau % 4 == 3)
		{
			monCoup->nombre = 2;
			for (i = 0; i < partie.longueur; i++) {
				monCoup->position = i;
				if (coupPossible(partie, *monCoup) == 1) { return; }
			}
			coupAi(copyPartie, monCoup, 3);
		}
		else
		{
			coupAi(copyPartie, monCoup, 3);
		}
	}
	else if(methode == 3)
	{
		for (i = 0; i < partie.longueur; i++)
		{
			for (j = 3; j > 0; j--)
			{
				monCoup->nombre = j;
				monCoup->position = i;
				copyPlateau(partie, &copyPartie);
				resAi = coupGagnant(copyPartie, *monCoup);
				if (resAi == 1) { return; }
			}
		}
		if(resAi != 1)
		{
			for (i = 0; i < partie.longueur; i++)
			{
				for (j = 3; j > 0; j--)
				{
					monCoup->nombre = j;
					monCoup->position = i;
					if (coupPossible(partie, *monCoup) == 1) { return; }
				}
			}
		}
	}
	return;
}

int coupGagnant(PlateauJeu partie, Coup monCoup)
{
	if (coupPossible(partie, monCoup) == 1)
	{
		jouerCoup(&partie, monCoup);
		if (partie.nbAllumPlateau == 1) { return 1; }
		else
		{
			int i, j, resAdv;
			for (i = 0; i < partie.longueur; i++)
			{
				for (j = 3; j > 0; j--)
				{
					monCoup.nombre = j;
					monCoup.position = i;
					resAdv = coupGagnant(partie, monCoup);
					if (resAdv == 1) { return 0; }
				}
			}
			if (resAdv == 0) { return 1; }
		}
	}
	return 0;
}