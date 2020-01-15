#ifndef STRUCT_FICHIER_C 
#define STRUCT_FICHIER_C
#include "struct_fichier.h"

void* creation(char* titre ,unsigned char l_case[30][15] , unsigned char flocon[2]){
    fichier_t* fichier = malloc(sizeof(fichier_t));
    int i,j;

    fichier->title[0]=strlen(titre);
    fichier->title[1]=titre;

    for (i = 0; i < 30; i++)
    {
        for ( j = 0; j < 15; j++)
        {
            fichier->t_case[i][j]=l_case[i][j];
        }
        
    }

    fichier->pos_flocon[0]=flocon[0];
    fichier->pos_flocon[1]=flocon[1];

}

void* ecrire_fichier(fichier_t fichier,char* nom_fichier){
    int fd;
    int taille;
    
    if ((fd=open(nom_fichier,O_RDWR))<=-1)
    {
        if ((fd=open(nom_fichier,O_CREAT))>-1)
        {
            /* code */
        }
        else
        {
            
        }
        
        
    }
    else{
        
    }
    
}

#endif