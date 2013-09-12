#include <stdio.h>
#include <stdlib.h>

static char memory[50];

void freeAlterno (void *posicion)
{
    char *pntrArreglo = posicion;

    while(pntrArreglo)
    {

        if(*pntrArreglo == 'e')
        {
            *pntrArreglo = NULL;
            break;
        }
        else
        {
        *pntrArreglo = NULL;
        pntrArreglo++;
        }
    }
}

void *mallocAlterno(size_t objeto)
{
    int i;
    void *pntr;
    int u = 0;
    int Espacio = 0;
    int inicioDeBloque = 0;
    int finalDeBloque = 0;
    int a = 0;

    for(i=0; i<50; i++)
    {
        if(memory[i] == NULL && inicioDeBloque == 0 && a == 0)
        {
            inicioDeBloque = i;
            pntr = &memory[i];
            Espacio++;
            a++;
        }
        else if(memory[i] == NULL && inicioDeBloque == NULL && a != 0)
        {
            Espacio++;
        }
        else if(memory[i] == NULL && inicioDeBloque != NULL && a != 0)
        {
            Espacio++;
        }
        else if(memory[i] != NULL && inicioDeBloque != NULL)
        {
            inicioDeBloque = NULL;
            Espacio = 0;
            pntr = 0;
        }
        if(Espacio == objeto)
        {
            finalDeBloque = i;
            for(u=i-Espacio+1; u<=i; u++)
            {
                if(u == i)
                {
                    memory[u] = 't';
                    memory[u]='e';
                }
                else
                    {
                        memory[u] = 't';
                    }
            }
            break;
        }
    }
    return pntr;
}

int main()
{

    void *prueba1 = mallocAlterno(5);
    printf("He aqui el bloque de memoria representado en forma de string despues de efectuar un malloc de tamano 5, e representa el final del bloque.\n");
    puts(memory);
    void *prueba2 = mallocAlterno(10);
    printf("\nHe aqui el bloque despues de insertar un segundo bloque con malloc, esta vez de tamano 10\n");
    puts(memory);
    printf("\nA continuacion se imprimira la direccion de memoria del primer y segundo bloque\n");
    int numprueba1 = (unsigned)prueba1;
    int numprueba2 = (unsigned)prueba2;
    printf("%u\n",numprueba1);
    printf("%u\n",numprueba2);

    printf("\nLo siguiente es la memoria despues de hacerle free al bloque de tamano 10\n");
    freeAlterno(prueba2);
    puts(memory);
    printf("\nY por ultimo, si se intenta imprimir la 'memoria' despues de hacer free al bloque que queda, no se imprimira nada, toda memoria esta disponible." );
    freeAlterno(prueba1);
    puts(memory);


}
