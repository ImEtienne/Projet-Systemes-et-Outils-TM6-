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
 // int random;
  int fd;
  char *adr;
  char buffer[1024];
  char bufferMotSearch[200000];
  struct stat sb;
  //char motR[] = "0x";
  FILE *Fichier;
  char bovary[] = "bovary.txt";
  char a = '0';
  char b = 'x';  //char -> %c - char comme chaine de caractère avec " .. " ->  %s
  //int temp;
  int number;

  if(!filename){perror("impossible d'ouvrir le fichier "); exit(2);}

  fd = open(argv[1],O_RDWR,7777); //Open fichier bovary

  //temp = atoi(argv[2]); // récupère le second argument [int]

  Fichier = fopen(bovary, "r");
    
  number = (rand() % (16 - 8 + 1)) + 8; // random

  adr = mmap (NULL, 2000000000, PROT_READ | PROT_WRITE, MAP_SHARED, fd, (off_t)0); //La projection

  if (stat(filename, &sb) == -1) {perror("stat"); exit(EXIT_FAILURE);}

  if (adr == MAP_FAILED) { perror("mmap"); exit(2); }
    

  /* Le code stocké ici */
  

    // permet d'écrire aléatoirement le code secret dans le fichier (N fois)
   /* for (int i = 0; i < temp; i++){
        random = (rand() % 117344); // nombre de caractere 117344
        lseek(fd, random, SEEK_CUR);
        write(fd, (char *)buffer, 5); 
    }*/

    
    //Stockage specifique avec mmap ou écriture - ECRIT LE CODE SECRET
    sprintf(buffer, "%c%c%d%c%c", a, b, number, b, a);
    printf("%s\n", buffer);
    int j = 0;
    for (int i = 0; i < 6; i++){
      adr[i] = buffer[j];
      j++;
    }

    // Affiche en détail la projection du fichier
    printf("la taille totale du fichier est : %lu bytes\n", sb.st_size);
    printf("dernier changement de statut:       %s", ctime(&sb.st_ctime));
    printf("dernier acces au fichier:         %s", ctime(&sb.st_atime));
    printf("derniere modification:   %s", ctime(&sb.st_mtime));
    printf("Projection réussie à l'adresse %p\n", adr);
   // printf("Le random donne : %d\n", random);
    
  //Retrouvons le code secret par ici RECHERCHE LE CODE SECRET
    int pid = fork();
    if(pid == 0){
      while(fgets(bufferMotSearch, 6, Fichier) != NULL){
          if(strstr(bufferMotSearch, buffer))
          {
            printf("le code trouvé : %s\n\n", bufferMotSearch);
            exit(2);
          }
          
      }
    } else {
      sleep(1);
    }


//Closing file
  close(fd);
  return EXIT_SUCCESS;

}