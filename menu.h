#ifndef MENU_H
#define MENU_H
#pragma once

#include "test.h"

/**
 *	Affiche le menu de depart
 *	1 - Jouer
 *	2 - Voir les regles du jeu
 *	3 - Voir les credits
 *	4 - Test les fonctions du jeu
 *	5 - Quitter
**/
void menu();

/**
 *	Affiche le menu de configuration de nombre d'allumettes
 *	1 - Utiliser un nombre aleatoire d'alumettes
 *	2 - Utiliser le nombre d'alumettes predefini
 *	3 - Choisir le nombre d'allumettes
**/
void menuPlateau();

/**
 *	Affiche le menu de mode de jeu
 *	1 - Humain VS Humain
 *	2 - Humain VS AI
 *		Choix de difficulte:
 *		1 - Facile
 *		2 - Difficile
 *		3 - IMPOSSIBLE
**/
void menuJeu(PlateauJeu partie);

/**
 *	Menu de fin de partie
 *	lance / relance le jeu vs ordi ou vs humain
 *	retourne vers le menu de depart :: menu()
**/
void menuGagne(PlateauJeu partie, int mode, int nv);

/**
*	Affiche les regles et le fonctionnement du jeu
**/
void regles();

/**
*	Affiche les credits du jeu
**/
void credits();

#endif // !MENU_H
