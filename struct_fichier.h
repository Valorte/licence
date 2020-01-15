#ifndef STRUCT_FICHIER_H
#define STRUCT_FICHIER_H
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

typedef struct fichier_t fichier_t;
struct fichier_t
{
    unsigned char title[2];
    unsigned char t_case[30][15];
    unsigned char pos_flocon[2];
};

void* creation(char* titre ,unsigned char l_case[30][15] , unsigned char flocon[2]);

void* ecrire_fichier(fichier_t fichier, char* nom_fichier);

#endif