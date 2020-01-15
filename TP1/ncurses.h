#ifndef _NCURSES_
#define _NCURSES_
#include <ncurses.h>

/**
 * Initialisation de ncurses.
 */
void ncurses_initialiser();

/**
 * Fin de ncurses.
 */
void ncurses_stopper();

/**
 * Initialisation des couleurs.
 */
void ncurses_couleurs();

/**
 * Initialisation de la souris.
 */
void ncurses_souris();

/**
 * Recupere la position x et y de la souris.
 * @param[out] x la position en x
 * @param[out] y la position en y
 * @param[out] bouton l'évenement associé au clic (ou NULL)
 * @return OK si reussite
 */
int souris_getpos(int *x, int *y, int *bouton);

/**
 * Parametre une fenetre
 * @param[out] hauteur la hauteur de la fenetre
 * @param[out] largeur la largeur de la fenetre
 * @param[out] x la position en x
 * @param[out] y la position en y
 * @param[out] boole 1=box
 * @return une fenetre configurer
 */
WINDOW* creer_fenetre(int hauteur , int largeur , int y , int x , int boole);

/**
 * Parametre la couleur de la fenetre
 * @param[out] fenetre a colorer
 * @param[out] i indice pair
 */
void colorer_fenetre(WINDOW* fenetre,int i);

/**
 * Parametre une sous_fenetre
 * @param[out] hauteur la hauteur de la sous_fenetre
 * @param[out] largeur la largeur de la sous_fenetre
 * @param[out] x la position en x
 * @param[out] y la position en y
 * @return une sous_fenetre configurer
 */
WINDOW* creer_sous_fenetre(WINDOW* fenetre,int hauteur , int largeur , int y , int x ,int scroll);

int obstacle(int** tab, int x , int y);
#endif
