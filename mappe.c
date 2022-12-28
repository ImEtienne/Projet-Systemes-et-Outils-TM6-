#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<signal.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/mman.h>


int main(int argc, char **argv){
    int desc1;
    char *abr;
    //commentaire 
    if ((desc1=open(argv[1], O_RDWR | O_CREAT)) == -1 ) { perror(argv[1]); exit(2); }

    abr = (char *)mmap(NULL, 1024, PROT_READ | PROT_WRITE, MAP_SHARED, desc1, 0);

    if(abr == MAP_FAILED){
        perror("mmap1");
        exit(2);
    }
    return 0;
}