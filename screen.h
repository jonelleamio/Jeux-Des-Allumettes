#ifndef SCREEN_H
#define SCREEN_H
#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

/**
 *	Centre le texte donné en calculant la largeur de la console
 *
 *	const char* str:: le String a afficher au centre de la console
**/
void centrer(const char* str);

/**
 *	Rafraichir la console puis affiche "Jeu des allumettes" au centre
**/
void header();

#endif // !SCREEN_H