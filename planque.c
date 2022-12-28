#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <time.h>
#include <sys/stat.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/mman.h>
#include <string.h>


int main(int argc, char *argv[]){
    int fd;
    char buffer[1024];
    char *adr;
    struct stat bufStat;
    int number;
    char a = '0';
    char b = 'x';
    //int temp;

    fd = open(argv[1],O_RDWR,7777); //Open fichier
    //temp = atoi(argv[2]); // récupère le second argument 
    number = (rand() % (16 - 8 + 1)) + 8; // random d'écriture dans le buffer
    adr = mmap (NULL, 2000000000, PROT_READ | PROT_WRITE, MAP_SHARED, fd, (off_t)0); //La projection

    fstat(fd, &bufStat);

    if(adr == MAP_FAILED) { perror(argv[1]); exit(2); }

    sprintf(buffer, "%c%c%d%c%c", a, b, number, b, a);
    printf("Le code : %s\n", buffer);
    int j = 0;
    for (int i = 0; i < 6; i++){
      adr[i] = buffer[j];
      j++;
    }

    return 0;
}