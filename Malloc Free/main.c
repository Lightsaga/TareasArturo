#include <stdio.h>
#include <stdlib.h>

char memory[8192];

void* mallocAlterno(size_t objeto)
{
    int *i;
    int Espacio;
    int inicioDeBloque;
    int finalDeBloque

for(i=0; i<8192; i++)
{
    if(memory[i] == NULL && inicioDeBloque == NULL)
    {
        inicioDeBloque = i;
        Espacio++;
    }
    else if(memory[i] == NULL && inicioDeBloque != NULL)
    {
        Espacio++;
    }
    else if(memory[i] != NULL && inicioDeBloque != NULL)
    {
    inicioDeBloque = NULL;
    Espacio = 0;
    }

    if(Espacio == objeto)
    {
        finalDeBloque = i;
        break;
    }
}

for(i=inicioDeBloque; i <= finalDeBloque; i++)
{

}
}



}




int main()
{
    char *prueba = mallocAlterno(30);
    prueba = "Okay";

    printf("%s", prueba);


}
