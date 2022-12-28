#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <time.h>
#include <sys/stat.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/mman.h>
#include <string.h>

const char *filename = "bovary.txt";

int main(int argc, char *argv[]) {
  int random;
  int fd;
  char *adr;
  char buffer[1024];
  char bufferMotSearch[200000];
  struct stat sb;
  
  FILE *Fichier;

  char bovary[] = "bovary.txt";
  Fichier = fopen(bovary, "r");

  if(!filename){perror("impossible d'ouvrir le fichier "); exit(2);}

  fd = open(argv[1],O_RDWR,7777);

  int temp = atoi(argv[2]);
    
  int number = (rand() % (16 - 8 + 1)) + 8;

  adr = mmap (NULL, 2000000000, PROT_READ | PROT_WRITE, MAP_SHARED, fd, (off_t)0); //permet de projectter

    if (stat(filename, &sb) == -1) {
        perror("stat");
        exit(EXIT_FAILURE);
    }

    if (adr == MAP_FAILED) { perror("mmap"); exit(2); }

    //Sauvegarde du début du mot du code et la fin du mot du code
    char* a = "0x";
    char* b = "x0";

    /* Le code stocké ici */
    sprintf(buffer, "%s%d%s", a, number, b); // création du code secret et stockage dans le buffer
    printf("buffer %s\n\n", buffer); //affichage du code secret


    //permet d'écrire aléatoirement le code secret dans le fichier (Une fois)
      random = (rand() % 117344); // nombre de caractere 117344
      lseek(fd, random, SEEK_CUR);
      write(fd, (char *)buffer, 5);
    
    
    //LA TAILLE DU FICHIER BOVARY
    printf("la taille totale du fichier est : %lu bytes\n", sb.st_size);
    printf("dernier changement de statut:       %s", ctime(&sb.st_ctime));
    printf("dernier acces au fichier:         %s", ctime(&sb.st_atime));
    printf("derniere modification:   %s", ctime(&sb.st_mtime));
    printf("Projection réussie à l'adresse %p\n", adr); //Projection du fichier
    printf("Le random donne : %d\n\n", random);
  

  //closing file
    close(fd);
    return EXIT_SUCCESS;
}