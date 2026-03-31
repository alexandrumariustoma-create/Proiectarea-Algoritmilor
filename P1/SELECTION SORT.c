#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int V1[10] = {-47, 46, -91, -64, 100, 92, -20, 83, -12, 10};
float V2[10] = {90.675, -60.980, 86.10, 4.99, 30.2682854, -29.178584028, -86.58683, -51.1535, -76.40793, 32.169};
char V3[10] = {'C', 'Y', 'E', 'B', 'D', 'W', 'a', 'O', 's', 'Y'};

    void SelectionSortInt(int v[])
    {
        for(int i = 0; i < 10; i++)
        {
            int min = v[i];
            int minIndex = i;
            int j;
            for(j = i; j < 10; j++)
        {
            if (v[j] < min)
                {
                    min = v[j];
                    minIndex = j;
                }
        }
            int aux = v[i];
            v[i] = v[minIndex];
            v[minIndex] = aux;
        }
    }

        void SelectionSortFloat(float v[])
    {
        for(int i = 0; i < 10; i++)
        {
            float min = v[i];
            int minIndex = i;
            int j;
            for(j = i; j < 10; j++)
        {
            if (v[j] < min)
                {
                    min = v[j];
                    minIndex = j;
                }
        }
            int aux = v[i];
            v[i] = v[minIndex];
            v[minIndex] = aux;
        }
    }

        void SelectionSortChar(char v[])
    {
        for(int i = 0; i < 10; i++)
        {
            char min = v[i];
            int minIndex = i;
            int j;
            for(j = i; j < 10; j++)
        {
            if (v[j] < min)
                {
                    min = v[j];
                    minIndex = j;
                }
        }
            int aux = v[i];
            v[i] = v[minIndex];
            v[minIndex] = aux;
        }
    }

int main()
{
    SelectionSortInt(V1);
    for(int i = 0; i < 10; i++)
        printf("%d ", V1[i]);
    printf("\n");
    SelectionSortFloat(V2);
    for(int i = 0; i < 10; i++)
        printf("%f ", V2[i]);
    printf("\n");
    SelectionSortChar(V3);
    for(int i = 0; i < 10; i++)
        printf("%c ", V3[i]);
    printf("\n");
}