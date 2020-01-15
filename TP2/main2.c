#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
void main(int argc, char const *argv[])
{
    int fd,i,n;
    size_t tchaine;
    char* chaine;
    char r;
    off_t taille;
    
     
    fd=open(argv[1],O_RDWR | O_APPEND | O_CREAT);

    printf("Rentrer une chaine de caractere : ");
    scanf("%127s",chaine);
    write(fd,chaine,strlen(chaine)+1);
    i=0;
    r='a';
    n=-1;
    lseek(fd,0,SEEK_SET);
    while (n!=0)
    {   
        n=read(fd,&r,sizeof(char));
        if (r=='\0')
        {
            printf("\n");
        }
        
        printf("%c",r);
    }
    
    free(chaine);
   if(close(fd)==-1){
       exit(EXIT_FAILURE);
   }
   



    
    
}
