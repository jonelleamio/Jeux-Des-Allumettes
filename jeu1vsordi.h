#ifndef JEU1VSORDI_H
#define JEU1VSORDI_H
#pragma once

#include "fonctionsJeu.h"

/**
 *	Fonction permettant à un joueur de joueur contre l’ordinateur
 *	
 *	PlateauJeu partie :: Plateu du jeu
 *	tourJoueur1 :: 0 Compteur pour savoir à qui le tour
 *	tourJoueur2 :: 0 Compteur pour savoir à qui le tour
 *	int N :: Nombre d'allumette au départ
 *	nv :: Niveau du coupAi
 *
 *	Retourne 1 si joueur gagne, 3 si ordi gagne
**/
int jeu1vsordi(PlateauJeu partie, int tourJoueur1, int tourJoueur2, int N, int nv);

/**
 *	Permet a l'ordinateur de choisir son coup
 *	PlateauJeu partie :: la partie courant
 *	Coup *monCoup :: le coup de l'ai
**/
void coupAi(PlateauJeu partie, Coup *monCoup, int methode);

/**
 *	Simuler la partie pour savoir si le coup est gagnant
 *
 *	PlateauJeu partie :: partie de jeu courant
 *	Coup monCoup :: le coup a tester
 *
 *	Retournant 1 si le coup moncoup est potentiellement gagnant et 0 sinon
**/
int coupGagnant(PlateauJeu partie, Coup monCoup);

#endif // !JEU1VSORDI_H
