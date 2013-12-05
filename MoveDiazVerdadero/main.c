#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/uio.h>
#include <sys/stat.h>
#include <syscall.h>
#include <string.h>

int main(int arguments, char *argv[])
{

    char directoryPath[5000];
    //*getcwd(directoryPath,300);
    int buffer[5000];
    int sourceFileAddress, targetFileAddress;
    sourceFileAddress = open(argv[1],O_RDONLY);

//Making sure there's no error with the file
if(sourceFileAddress == -1)
{
    printf("That file doesn't exist you liar.");
    return 1;
}
//strcat(directoryPath,argv[2]);
//strcat(directoryPath,argv[1]); Prueba con Full path que fracaso.
  //     printf("%s", directoryPath);
  strcat(directoryPath,argv[2]);
  strcat(directoryPath,"/");
  strcat(directoryPath,argv[1]);


targetFileAddress = open(directoryPath, O_WRONLY|O_CREAT| O_TRUNC, 0666);
if(targetFileAddress == -1)
{
printf("There was an error for some reason and the file couldn't be created");
return 1;
}

int counter = 0 ;
while((counter=read(sourceFileAddress,buffer,sizeof(buffer))) > 0)
      {
        write(targetFileAddress,buffer,counter);
      }

      close(targetFileAddress);
      close(sourceFileAddress);
      unlink((argv[1]));
    return 0;
}
