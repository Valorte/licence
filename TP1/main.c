/**
 * Ce programme illustre le fonctionnement des fenetres ncurses.
 * Le programme cree une fenêtre, la colorie dans une couleur.
 * Pour quitter le programme, l'utilisateur doit cliquer dans la fenetre.
 * @author Cyril Rabat
 * @version 18/01/2017
 **/

#include <stdlib.h>  /* Pour EXIT_FAILURE */
#include <ncurses.h> /* Pour printw, attron, attroff, COLOR_PAIR, getch */
#include <time.h>
#include <unistd.h>

#include "ncurses.h"

#define LARGEUR 20 /* Largeur de la fenêtre */
#define HAUTEUR 10 /* Hauteur de la fenêtre */
#define POSX 20    /* Position horizontale de la fenêtre */
#define POSY 5     /* Position verticale de la fenêtre */

int main()
{
  int i, x, y, j, nbflo,k;
  int **tab;
  int *taby;
  int ob;
  WINDOW *fenetre;
  WINDOW *sous_fenetre;
  WINDOW *fenetre2;
  WINDOW *sous_fenetre2;
  WINDOW *fenetre3;
  WINDOW *sous_fenetre3;

  /* Initialisation de ncurses */
  ncurses_initialiser();
  ncurses_souris();
  ncurses_couleurs();

  /* Création de la fenêtre */
  fenetre = creer_fenetre(5, COLS, 0, 0, 1);

  fenetre2 = creer_fenetre(15, 30, 5, 0, 1);

  fenetre3 = creer_fenetre(7, COLS - 30, 5, 30, 1);

  /* Colore le fond de la fenêtre */
  wbkgd(fenetre, COLOR_PAIR(1));
  mvwprintw(fenetre, 0, 1, "Information");

  mvwprintw(fenetre2, 0, 1, "Simulation");
  wbkgd(fenetre2, COLOR_PAIR(1));

  sous_fenetre = creer_sous_fenetre(fenetre, 5 - 1, COLS - 2, 1, 1, 1);
  sous_fenetre2 = creer_sous_fenetre(fenetre2, 14, 29, 1, 1, 1);
  sous_fenetre3 = creer_sous_fenetre(fenetre3, 0, 0, 1, 1, 1);
  scrollok(sous_fenetre, TRUE);

  wrefresh(fenetre);
  wrefresh(sous_fenetre);
  wrefresh(fenetre2);
  wrefresh(sous_fenetre2);
  wrefresh(fenetre3);
  wrefresh(sous_fenetre3);

  wbkgd(fenetre3, COLOR_PAIR(1));
  mvwprintw(fenetre3, 0, 1, "Etat");
  wrefresh(fenetre3);
  getch();
  mvwprintw(sous_fenetre3, 0, 0, "Nombre de flocon : 0");
  mvwprintw(sous_fenetre3, 2, 0, "flocon : *");
  mvwprintw(sous_fenetre3, 1, 0, "obstacle: ");
  wattron(sous_fenetre3, COLOR_PAIR(3));
  wprintw(sous_fenetre3, "o");
  wattroff(sous_fenetre3, COLOR_PAIR(3));

  wrefresh(sous_fenetre3);

  getmaxyx(sous_fenetre2, y, x);
  tab = malloc(sizeof(int *) * 14);

  for (i = 0; i < x; i++)
  {
    tab[i] = malloc(sizeof(int) * 29);
  }

  srand(time(NULL));
  for ( k = 0; k < 20; k++)
  {
    i=rand()%27+1;
    j=rand()%12;
    tab[i][j] = 1;
  }
  
  

  for (i = 0; i < x; i++)
  {
    for (j = 0; j < x; j++)
    {
      if (tab[i][j] == 1)
      {
        wattron(sous_fenetre2, COLOR_PAIR(3));
        mvwprintw(sous_fenetre2, j, i, "o");
        wattroff(sous_fenetre2, COLOR_PAIR(3));
      }
    }
  }
  taby = (int *)malloc(sizeof(int) * x);
  for (i = 0; i < x; i++)
  {
    taby[i] = y;
  }

  nbflo = 0;
  wrefresh(sous_fenetre2);
  i = x;
  /*timeout(1000) changer 1 en ch=getch();*/
  while (1)
  {
    
    nbflo++;
    mvwprintw(sous_fenetre3, 0, 0, "Nombre de flocon : %d", nbflo);
    wrefresh(sous_fenetre3);
    i = rand() % 27;
    j = 0;
    wprintw(sous_fenetre, "flocon colonne : %d \n", i);
    wrefresh(sous_fenetre);
    wmove(sous_fenetre2, j, i);
    while (j < taby[i] - 2 && i < x-1)
    {
      /*wattron(sous_fenetre2, COLOR_PAIR(3));*/
      wprintw(sous_fenetre2, "*");
      /*wattroff(sous_fenetre2, COLOR_PAIR(3));*/
      wrefresh(sous_fenetre2);
      /*sleep(1);*/
      mvwprintw(sous_fenetre2, j, i, " ");
      j++;
      ob = obstacle(tab, i, j);
      switch (ob)
      {
      case -1:
        i--;
        wmove(sous_fenetre2, j, i);
        break;
      case 1:
        i++;
        wmove(sous_fenetre2, j, i);
        break;
      case 2:
        mvwprintw(sous_fenetre2, j - 1, i, "*");
        taby[i] = j - 1;
        j = y;
        i = x;
        break;
      default:
        wmove(sous_fenetre2, j, i);
        break;
      }
    }
    mvwprintw(sous_fenetre2, j, i, "*");
    taby[i]--;
    tab[i][j]=1;
    getch();
  }
  getch();
  /* Suppression de la fenêtre */
  delwin(fenetre);
  delwin(sous_fenetre);
  delwin(fenetre2);
  delwin(sous_fenetre2);
  delwin(fenetre3);
  delwin(sous_fenetre3);

  /* Arrêt de ncurses */
  ncurses_stopper();

  return EXIT_FAILURE;
}