#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <time.h>
#include <sys/stat.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/mman.h>
#include <string.h>

//reponse c'est la planque & requete c'est l'espion 

int main(int argc, char *argv[]){
    int fd;
    char *adr;
    struct stat bufStat;
    //int temp;

    fd = open(argv[1],O_RDWR,7777); //Open fichier
    //temp = atoi(argv[2]); // récupère le second argument 
    adr = mmap (NULL, 2000000000, PROT_READ | PROT_WRITE, MAP_SHARED, fd, (off_t)0); //La projection

    fstat(fd, &bufStat);

    if(adr == MAP_FAILED) { perror(argv[1]); exit(2); }

    for (int i = 0; i < 200000; i++){ //GERER les espions si number == 2
        truncate(adr, 200000);
        if (adr[i] == '0' && adr[i + 1] == 'x')
        {
            for (int j = i ; j < i+5; j++)
            {
                
                printf("%c", adr[j]);
            }
            printf("\n");
        }
    }
    return 0;
}