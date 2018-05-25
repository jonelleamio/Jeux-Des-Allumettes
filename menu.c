#include "menu.h"

void menu()
{
	int choix;
	header();
	centrer("Bonjour et bienvenue dans le jeu des allumettes\n");
	printf("1 - Jouer\n");
	printf("2 - Voir les regles du jeu\n");
	printf("3 - Voir les credits\n");
	printf("4 - Test les fonctions du jeu\n");
	printf("5 - Quitter");
	printf("\n\nVotre choix : ");
	scanf("%d", &choix);
	switch (choix)
	{
		case 1: menuPlateau(); break;
		case 2: regles(); break;
		case 3: credits(); break;
		case 4: if (TestGameFunctions() == 1) { system("pause");menu(); } break;
		case 5: return; break;
		default: printf("\nShh dit bien...."); system("pause"); menu();
	}
	return;
}

void menuPlateau()
{
	header();
	int n; int choix;
	PlateauJeu partie;
	srand(time(NULL));
	printf("1 - Utiliser un nombre aleatoire d'alumettes\n");
	printf("2 - Utiliser le nombre d'alumettes predefini (21)\n");
	printf("3 - Choisir le nombre d'allumettes(entre 8 et 21)\n");
	printf("\nVotre choix : ");
	scanf("%d", &choix);
	switch (choix)
	{
		case 1: n = rand() % 13 + 8; break;
		case 2: n = 21; break;
		case 3: printf("\nNombre d'allumettes a utliser : ");
			scanf("%d", &n);
			while (n < 8 || n > 21) { printf("IMPOSSIBLE ! \nNombre d'allumettes a utliser : ");scanf("%d", &n); };
			break;
		default: system("cls"); printf("\nShhh dit bien...\n\n"); menuPlateau(); break;
	}
	initialiserPlateauJeu(&partie, n);
	menuJeu(partie);
	return;
}

void menuJeu(PlateauJeu partie)
{
	header();
	int choix, nv;
	printf("\nQuelle mode choisir ?\n\n");
	printf("1 - Humain VS Humain\n");
	printf("2 - Humain VS AI\n");
	printf("\nVotre choix : ");
	scanf("%d", &choix);
	switch (choix)
	{
	case 1: menuGagne(partie, 1, 0); break;
	case 2:
		printf("\nChoisir entre 3  niveaux de difficulte\n");
		printf("1 - facile\n");
		printf("2 - dificile\n");
		printf("3 - EXPERT\n");
		printf("Niveau : ");
		do { scanf("%d", &nv); } while ((nv<0) || (nv>3));
		system("cls");
		printf("Jeu contre l'ordinateur, niveau %d, avec %d allumettes au depart.\n\n", nv, partie.longueur);
		system("pause");
		if ((nv == 3) && (partie.longueur % 2)) printf("Tu peux toujours essayer... \n\n");
		menuGagne(partie, 2, nv); break;
	default: system("cls");
		printf("\nJe n'ai pas compris...\n\n");
		menuJeu(partie); break;
	}
	return;
}

void menuGagne(PlateauJeu partie, int mode, int nv)
{
	header();
	int choix, jgagnant;
	PlateauJeu copyPartie;
	copyPlateau(partie, &copyPartie);
	switch (mode)
	{
	case 1:
		jgagnant = jeu1vs1(copyPartie, 0, 0, copyPartie.longueur);
		break;
	case 2 :
		jgagnant = jeu1vsordi(copyPartie, 0, 0, copyPartie.longueur, nv);
	default:
		break;
	}
	switch (jgagnant)
	{
	case 1:
	case 2: printf("\nBravo J%d, tu as gagne !", jgagnant); break;
	default: printf("\nOrdi a gagne !");
	}
	printf("\nQue faire?\n");
	printf("1 - Rejouer avec les memes parametres\n");
	printf("2 - Revenir au menu initial\n");
	printf("3 - Quitter\n");
	scanf("%d", &choix);
	switch (choix)
	{
	case 1:
		menuGagne(partie, mode, nv);
		break;
	case 2: menuPlateau(); break;
	case 3: return; break;
	default: printf("\nJe n'ai pas compris...\n"); menuGagne(partie, mode, nv);
	}
	return;
}

void regles()
{
	int choix;
	header();
	centrer("\n\nLe but du jeu est simple:");
	printf("\n\nCe jeu se joue a deux. Vous avez un nombre n d'allumettes.\n");
	printf("A tour de role, les joueurs enlevent 1 a 3 allumettes selon ce qu'ils souhaitent.");
	printf("Le perdant est celui qui doit enlever la derniere allumette.\n");
	printf("\nAttention, il existe 3 niveaux de difficultes en version humain vs ordi.\n");
	printf("Le 1er est plutot simple a battre, donc pour les debutants. Mais le dernier.....\n");
	printf("Contactez-moi si vous avez reussi (screenshot evidemment^^), mon e-mail est dans les credits !\n\n");
	printf("Je paie un menu McDo au gagnant !\n\n");
	printf("1 - Jouer\n");
	printf("2 - Quitter");
	printf("\nAlors ? : ");
	scanf("%d", &choix);
	switch (choix)
	{
	case 1: menuPlateau(); break;
	case 2: return; break;
	default: printf("\nJe n'ai pas compris votre demande....");system("pause");regles();
	}
	return;
}

void credits()
{
	int choix;
	header();
	centrer("\n\nCe jeu a ete realise dans le cadre d'un TP de Programmation Avancee");
	centrer("\n\nLa recompense promise est bien evidemment une utopie !\n\n");
	printf("\n Mais vous pouvez quand meme jouer et vous payer un macdo\n\n");
	printf("1 - Jouer\n");
	printf("2 - Quitter");
	printf("\nTon choix : ");
	scanf("%d", &choix);
	switch (choix)
	{
	case 1: menuPlateau(); break;
	case 2: return; break;
	default: printf("\nJe n'ai pas compris votre demande....");system("pause");regles();
	}
	return;
}