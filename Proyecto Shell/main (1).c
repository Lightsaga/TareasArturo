#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
DIR *currentDirectory;
    DIR *rootDirectory;
    struct dirent *currentFile;
    char directoryPath[300];
    char rootPath[300];

void lsFunction()
{
    currentDirectory = opendir(directoryPath);
    if(currentDirectory != NULL)
    {
        while(currentFile =readdir(currentDirectory))
        {
            puts(currentFile->d_name);
        }

    }
}
int childPID;
void executeProgram(char *programName)
{
    char *filePath[300];
    strcpy(filePath,directoryPath);
	currentDirectory = opendir(directoryPath);

    if(currentDirectory != NULL)
    {
        while(currentFile =readdir(currentDirectory))
        {
            if(currentFile->d_name == programName);
            {
                strcat(filePath,programName);
                childPID = fork();
                if(childPID == 0)
                    {
                    childPID = execlp(filePath,"hola",NULL);
                    printf("%d", childPID);
                    }
             break;
            }
        }
    }
}

void cdFunction(char *folder)
{
    currentDirectory = opendir(directoryPath);
    if(currentDirectory != NULL)
    {
        while(currentFile =readdir(currentDirectory))
        {
            if(currentFile->d_name == folder);
            {
                if(*folder!='/')
                {
                 strcat(directoryPath,"/");
                 strcat(directoryPath,folder);
                }
                else
                {
                    int i = 0;
                    for(;i<300;i++)
                    {
                        directoryPath[i]='\000';
                    }
                    i=0;
                    while(*folder !='\000')
                    {
                        directoryPath[i]=*folder;
                        folder++;
                        i++;
                    }
                }
                currentDirectory = opendir(directoryPath);
                if(currentDirectory==NULL)
                {
                    printf("Directorio Invalido\n");
                    currentDirectory = rootDirectory;
                    strcpy(directoryPath,rootPath);
                }
                else
                {
                    puts(directoryPath);
                }
             break;
            }
        }
    }
}


typedef struct _word
{
char c[250];
}Word;

int compareArray(char *a,char*b,int n)
{
    int c =1;
    int i =0;
    char *A=a;
    char *B=b;
    for(;i<n;i++)
    {
        if(*A!=*B)
        {
            c=0;
        }
        A++;
        B++;
    }
    if(*A!='\000')
    {
        c=0;
    }
    return c;
}


int main()
{
     //Obtaining the path of main.c
    *getcwd(directoryPath,300);
    strcpy(rootPath,directoryPath);

    //Setting the initial directories
    rootDirectory = opendir(directoryPath);
    currentDirectory = rootDirectory;

    int c = 1;
    char d ='\0';
    char l[250];
    Word Words[30];
    printf("[TuriShell]");
    while(c!=0)
    {
        int i=0;
        int j=0;
        while((l[0]=getchar())!='\n')
        {
            if(l[0]!=' ')
            {
                Words[j].c[i]=l[0];
                i++;
            }
            else
            {
                j++;
                i=0;
            }
        }
       /*if(l[0]=='\377')
       {
            printf("LOOOL");
       }*/
        if(compareArray(&Words[0].c,&"cd",2)==1)
        {

            if(Words[1].c[0]=='\000')
            {
                currentDirectory = rootDirectory;
                strcpy(directoryPath,rootPath);
                puts(directoryPath);
            }
            else
            {
                cdFunction(&Words[1].c);
            }
        }
        if(compareArray(&Words[0].c,&"ls",2)==1)
        {
            lsFunction();
        }
        if(compareArray(&Words[0].c,&"clear",5)==1)
        {
            system("clear");
        }
        if(compareArray(&Words[0].c,&"exit",4)==1)
        {
            return 0;
        }
        if(Words[0].c[0]=='.'&&Words[0].c[1]=='/')
        {
            executeProgram(&Words[0].c[1]);
        }
        if(l[0]=='\n')
        {
            printf("[TuriShell]");
        }
        else
        {
            printf("Comando no reconocido");
            printf("[TuriShell]");
        }
        //reset the commands array
        int b =0;
        for(;b<30;b++)
        {
            int p=0;
            for(;p<250;p++)
            {
                Words[b].c[p]='\000';
            }
        }
    }
    return 0;
}
