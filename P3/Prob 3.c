#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
    int v[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int nr;
    
    while(true)
    {
        printf("\nIntrodu un numar: ");
        int citire = scanf("%d", &nr);
        if(citire == 1)
        {
            bool gasit = false;
            for(int i = 0; i < 10; i++)
            {
                for(int j = i + 1; j < 10; j++)
                {
                    if (v[i] + v[j] == nr)
                    {
                        printf("%d + %d = %d\n", v[i], v[j], nr);
                        gasit = true;
                    }
                }
            }
            if(gasit == false) 
            {
                printf("Nu exista. %d\n", nr);
            }
        }
        else
        {
            printf("Nu ai introdus un numar.\n");
            return 0;
        }
    }
}