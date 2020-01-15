#include "ncurses.h"

#include <stdlib.h>    /* Pour exit, EXIT_FAILURE */

/**
 * Initialisation de ncurses.
 */
void ncurses_initialiser() {
  initscr();	        /* Demarre le mode ncurses */
  cbreak();	        /* Pour les saisies clavier (desac. mise en buffer) */
  noecho();             /* Desactive l'affichage des caracteres saisis */
  keypad(stdscr, TRUE);	/* Active les touches specifiques */
  refresh();            /* Met a jour l'affichage */
  curs_set(FALSE);      /* Masque le curseur */
}

/**
 * Fin de ncurses.
 */
void ncurses_stopper() {
  endwin();
}

/**
 * Initialisation des couleurs.
 */
void ncurses_couleurs() {
  /* Verification du support de la couleur */
  if(has_colors() == FALSE) {
    ncurses_stopper();
    fprintf(stderr, "Le terminal ne supporte pas les couleurs.\n");
    exit(EXIT_FAILURE);
  }

  /* Activation des couleurs */
  start_color();

  /* Definition de la palette */
  init_pair(1, COLOR_BLUE, COLOR_WHITE);
  init_pair(2, COLOR_BLACK, COLOR_RED);
  init_pair(3, COLOR_GREEN, COLOR_GREEN);
}

/**
 * Initialisation de la souris.
 */
void ncurses_souris() {
  if(!mousemask(ALL_MOUSE_EVENTS, NULL)) {
    ncurses_stopper();
    fprintf(stderr, "Erreur lors de l'initialisation de la souris.\n");
    exit(EXIT_FAILURE);
  }
 
  if(has_mouse() != TRUE) {
    ncurses_stopper();
    fprintf(stderr, "Aucune souris n'est détectée.\n");
    exit(EXIT_FAILURE);
  }
}

/**
 * Recupere la position x et y de la souris.
 * @param[out] x la position en x
 * @param[out] y la position en y
 * @param[out] bouton l'évenement associé au clic (ou NULL)
 * @return OK si reussite
 */
int souris_getpos(int *x, int *y, int *bouton) {
  MEVENT event;
  int resultat = getmouse(&event);
 
  if(resultat == OK) {
    *x = event.x;
    *y = event.y;
    if(bouton != NULL) *bouton = event.bstate;
  }
  return resultat;
}

WINDOW* creer_fenetre( int hauteur , int largeur , int y , int x , int boole){
  WINDOW* fenetre =newwin(hauteur, largeur, y, x);
  if (boole ==1)
  {
    box(fenetre, 0, 0);
  }
  return fenetre;
}

void colorer_fenetre(WINDOW* fenetre,int i){
  wbkgd(fenetre, COLOR_PAIR(i));
}

WINDOW* creer_sous_fenetre(WINDOW* fenetre, int hauteur , int largeur , int y , int x , int scroll){
  WINDOW* sous_fenetre = derwin(fenetre,hauteur,largeur,y,x);
  if (scroll == 1)
  {
    scrollok(sous_fenetre,TRUE);
  }
  return sous_fenetre;
}

int obstacle(int** tab, int x , int y){
  int repo=0; /*ok*/
  if (tab[x][y]==1 && tab[x-1][y]!=1)/*gauche*/
  {
    repo=-1;
  }
  if (tab[x][y]==1 && tab[x+1][y]!=1)/*droite*/
  {
    repo=1;
  }
  if (tab[x][y]==1 && tab[x-1][y]==1 && tab[x+1][y]==1)/*bloque*/
  {
    repo=2;
  }  
  

  return repo;
  
}
