#include <stdio.h>
#include <stdlib.h>

int main()
{
    int customArray [16]; //array of 16 bits
    int i;
    for(i=0;i<4;i++)
        customArray[i] = 1;

    for(i=12;i<16;i++)
        customArray[i] = 1;

//Bitmaps divide the memory in blocks of 8
//So the array will be divided in two bitmaps

int bitmap=0b00000000;
int bitmap2=0b00000000;

    for(i=7;i>=0;i--)
    {
    if(customArray[i]!=0)
    {
    bitmap = bitmap | 0b00000001<<i; //Application of Bitwise Operation
    }
    }

    for(i=15;i>=8;i--)
    {
        if(customArray[i]!=0)
        {
            bitmap2 = bitmap2 | 0b00000001<<i-8;
        }
    }

    //Coding this in Code blocks, it has crashed on me 2 times right as i'm about to write the next line... ugh
    printf("16 bytes (simulated) were divided into 2 bitmaps");
printf("\nThe decimal valor of the bitmap #1 is %d", bitmap); // crahsed again...
printf("\nThe decimal valor of the bitmap #2 is %d", bitmap2);
    return 0; // FINISHED! woo.
}
