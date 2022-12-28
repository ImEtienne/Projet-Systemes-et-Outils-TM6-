#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/mman.h>

int main(int argc, char* argv[]) {

char buffer[1024];

int n;

int temp = atoi(argv[2]);

int pid;

for(int i=0;i<temp;i++){
	 pid=fork();
}

int fd = open(argv[1], O_RDWR );

	n=read(fd,buffer,sizeof(buffer));

	sscanf (buffer ,"%d\n",&pid);

	sprintf(buffer ,"%d\n",getpid());

	lseek(fd, SEEK_SET,sizeof(buffer));

	write(fd,buffer,n);

    write(STDOUT_FILENO,buffer,n);




close(fd);


/*
return 0;

	if (argc < 3) { 
		perror(" pas assez d'argument");
		return 1;
	}

    if (argc > 3) {   
		perror("trop d'argument");
		return 1;
	}


	if (fd == -1) {
		perror("fichier vide!\n");
		return 1;
	}


*/
/*
    int fd=0;
    int n =0;
    char buffer [1024];

//O_WRONLY | O_TRUNC | O_CREAT, S_IRUSR | S_IWUSR
	fd = open(argv[1],O_RDONLY);
   
	while ((n = read(fd,  buffer, sizeof(buffer))) > 0) {
		if ( write(int argv[2], buffer, sizeof(buffer)) == -1) {
			perror("Write error\n");
		}
	}
*/

 //printf("notre entier est egale à : %s\n",argv[2]);
  //  return 0 ;





  //   sscanf(buffer, "%i" , &fd2);
     //printf("%i\n",fd2);

    //sprintf(buffer,fd);

    /*partie gestion erreur*/

	return 0;
}