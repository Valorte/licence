#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
void main(int argc, char const *argv[])
{
    int fd;
    off_t taille;
    
    /* 1*/
     
    if (argc<2)
    {
        fprintf(stderr,"il manque un argument\n");
        exit(EXIT_FAILURE);
    }
    

    if((fd=open(argv[1],O_APPEND))<=-1)
    {
        if (errno==ENOENT)
        {
            fprintf(stderr,"fichier inexistant\n");
        }
        
        exit(EXIT_FAILURE);
    }
    else
    {

        fprintf(stderr,"fichier existant\n");

        taille =lseek(fd,0,SEEK_END);

        fprintf(stderr,"taille :%ld\n",taille);
        

        close(fd);
        exit(EXIT_SUCCESS);
    }


    
    
}
