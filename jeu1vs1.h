#ifndef JEU1VS1_H
#define JEU1VS1_H
#pragma once

#include "fonctionsJeu.h"

/**
 *	Fonction permettant à un joueur de joueur contre joueur
 *
 *	PlateauJeu partie :: Plateu du jeu
 *	tourJoueur1 :: 0 Compteur pour savoir à qui le tour
 *	tourJoueur2 :: 0 Compteur pour savoir à qui le tour
 *	int N :: Nombre d'allumette au départ
 *
 *	retourne 1 si joueur1 gagne, 2 si jouer2 gagne
**/
int jeu1vs1(PlateauJeu partie, int tourJoueur1, int tourJoueur2, int N);

#endif // !JEU1VS1_H
