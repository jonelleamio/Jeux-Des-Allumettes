#ifndef FONCTIONSJEU_H
#define FONCTIONSJEU_H
#pragma once

#include "screen.h"

typedef struct {
	int longueur; // longueur du plateau
	int nbAllumPlateau; // nombre d'allumettes restant
	int *plateau; // liste chainée contenant la position des allumettes restant
}PlateauJeu;

typedef struct {
	int position;// case de la première allumette
	int nombre;// nombre d'allumette(s) a enleve
}Coup;

/**
 *	initialise le plateu de jeu
 *	-> rempli le plateau de jeu d'allumettes
 *
 *	PlateauJeu *plateau :: Plateau jeu a initialiser
 *	size :: La taille de plateau de jeu
**/
void initialiserPlateauJeu(PlateauJeu *plateau, int size);

/**
 *	initialise le coup
 *	-> met les valeurs a 0
 *
 *	Coup *monCoup :: coup a initialiser
**/
void initialiserCoup(Coup *monCoup);

/**
 *	Affiche le plateau du jeu
 *
 *	PlateauJeu plateau :: Plateau de jeu a afficher
**/
void affichePlateau(PlateauJeu plateau);

/**
 *	Affiche le Coup
 *
 *	Coup coup :: Coup a afficher
**/
void afficheCoup(Coup coup);

/**
 *	Duplique un plateau de jeu
 *
 *	PlateauJeu partie :: Plateau de jeu a dupliquer
 *	PlateauJeu *copyPartie :: duplique de plateu de jeu 
**/
void copyPlateau(PlateauJeu partie, PlateauJeu *copyPartie);

/**
 *	Demande a un joueur de saisir son coup
 *	et verifier si le coup saisi est valable
 *
 *	int sizePlateau :: taille de plateau de jeu courant
 *	Coup *coupJouer :: variable qui va stocker le coup de joueur
**/
void getCoupJouer(int sizePlateau, Coup *coupJouer);

/**
 *	vérifie si le coup monCoup est possible étant donné la position des allumettes sur le plateau de jeu.
 *
 *	PlateauJeu partie :: plateau de la partie
 *	Coup monCoup :: coup a essayer sur le plateau de jeu
 *
 *	return 1 :: si le coup est possible
 *	return 0 :: si le coup n'est pas possible
**/
int coupPossible(PlateauJeu partie, Coup monCoup);

/**
 *	Modifie le plateau du jeu en fonction du coup (si le coup est possible)
 *	=> enleve des allumettes sur le plateau de jeu
 *
 *	PlateauJeu *partie :: Plateau de jeu courant
 *	Coup monCoup ::  Coup de joueur
**/
void jouerCoup(PlateauJeu *partie, Coup monCoup);

#endif // !FONCTIONSJEU_H