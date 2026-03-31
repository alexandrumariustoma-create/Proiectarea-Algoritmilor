#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int i, j;
    char nume[10][20] = {"Ana", "Ion", "Maria", "Vlad", "Elena", "Mihai", "Ioana", "Andrei", "Cristina", "George"};
    float timp[10] = {12.5, 15.0, 10.0, 20.0, 18.5, 14.0, 11.0, 16.5, 13.0, 19.0};

    for(i = 0; i < 10; i++)
    {
        for(j = i + 1; j < 10; j++)
        {
            if(timp[i] > timp[j])
            {
                float aux = timp[i];
                timp[i] = timp[j];
                timp[j] = aux;

                char auxN[20];
                strcpy(auxN, nume[i]);
                strcpy(nume[i], nume[j]);
                strcpy(nume[j], auxN);
            }
        }
    }

    for(i = 0; i < 10; i++)
    {
        printf("%d. ", i+1);
        for(j = 0; j < strlen(nume[i]); j++)
            printf ("%c", nume[i][j]);
        printf("\n");
        

    }

}