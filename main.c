#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *archivo;
FILE *nuevoArchivo;

int main()
{
    const char *comentarioNormal = "//";
    const char *comentarioLargoInicio = "/*";
    const char *comentarioLargoFinal = "*/";
    char linea[1000];
    char *pLinea;
    int i;
    int u;
    int verdad = 1;
    int *pVerdad = &verdad;
    int contadorDeDiagonal = 0;

    archivo = fopen("Prueba.txt", "r");
    nuevoArchivo = fopen("NuevoTexto.txt", "w");

    if(!archivo)
    {
        return 1;
    }

    while(fgets(linea, 1000, archivo)!= NULL)
    {
     if (verdad == 0)
     {
         if(strstr(linea,comentarioLargoFinal))
         {
             for (i = strlen(linea); i > 0; i--)
            {
                if(linea[i] == '/')
                {

                       if(linea[i-1] == '*')
                       {
                           for(u=i+1; u< strlen(linea); u++)
                           {
                               printf("%c",linea[u]);
                               fprintf(nuevoArchivo,"%c",linea[u]);

                           }

                        }
                       break;
                }
            }
            printf("\n");
            fprintf(nuevoArchivo,"\n");
            verdad = 1;
         }
     }
     else
    {
        if (strstr(linea,comentarioLargoInicio))
        {
             for (i = 0; i < strlen(linea); i++)
            {
                if(linea[i] == '/')
                {
                       if(linea[i+1] == '*')
                       {
                       break;
                       }
                       else
                       {
                           printf("%c",linea[i]);
                           fprintf(nuevoArchivo,"%c",linea[i]);
                       }
                }
                else
                {
                    printf("%c", linea[i]);
                    fprintf(nuevoArchivo,"%c",linea[i]);
                }

            }
        printf("\n");
        fprintf(nuevoArchivo,"\n");
        verdad = 0;
        }
        else if(strstr(linea,comentarioNormal))
        {
            for (i = 0; i < strlen(linea); i++)
            {
                if(linea[i] == '/')
                {
                    if(contadorDeDiagonal != 1)
                    {
                       contadorDeDiagonal++;
                       if(linea[i+1] != '/')
                       {
                       printf("%c",linea[i]);
                       fprintf(nuevoArchivo,"%c",linea[i]);
                       }

                    }
                    else if (contadorDeDiagonal == 1)
                    {
                    contadorDeDiagonal = 0;
                    break;
                    }

                }
                else
                    {
                        printf("%c",linea[i]);
                        fprintf(nuevoArchivo,"%c",linea[i]);
                    }
            }
            printf("\n");
            fprintf(nuevoArchivo,"\n");
        }
            else
            {
               printf("%s", linea);
               fprintf(nuevoArchivo,"%s",linea);

            }
    }

     }
    fclose(nuevoArchivo);
    fclose(archivo);
    return 0;
}
