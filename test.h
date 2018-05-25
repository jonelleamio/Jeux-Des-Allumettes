#ifndef TEST_H_INCLUDED
#define TEST_H_INCLUDED

#include "jeu1vs1.h"
#include "jeu1vsordi.h"

/**
 *	Programme pilote pour tester les fonctions du jeu
**/
int TestGameFunctions();

/**
 *	Programme pilote pour tester initialiserPlateauJeu()
**/
int testInitialiserPlateauJeu();

/**
 *	Programme pilote pour tester initialiserCoup()
**/
int testInitialiserCoup();

/**
 *	Programme pilote pour tester copyPlateau()
**/
int testCopyPlateau();

/**
 *	Programme pilote pour tester jouerCoup()
**/
int testJouerCoup();

/**
 *	Programme pilote pour tester coupPossible()
**/
int testCoupPossible();

/**
 *	Programme pilote pour tester coupGagnant()
**/
int testCoupGagnant();

/**
 *	Programme pilote pour tester coupAi()
**/
int testCoupAi();

#endif
