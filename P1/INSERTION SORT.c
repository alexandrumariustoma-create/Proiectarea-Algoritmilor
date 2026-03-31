#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int V1[10] = {-47, 46, -91, -64, 100, 92, -20, 83, -12, 10};
float V2[10] = {90.675, -60.980, 86.10, 4.99, 30.2682854, -29.178584028, -86.58683, -51.1535, -76.40793, 32.169};
char V3[10] = {'C', 'Y', 'E', 'B', 'D', 'W', 'a', 'O', 's', 'Y'};

void InsertionSortInt(int v[]) 
{
    for (int i = 1; i < 10; i++) 
    {
        int key = v[i];
        int j = i - 1;
        while (j >= 0 && v[j] > key) 
        {
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = key;
    }
}

void InsertionSortFloat(float v[]) 
{
    for (int i = 1; i < 10; i++) 
    {
        float key = v[i];
        int j = i - 1;
        while (j >= 0 && v[j] > key) 
        {
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = key;
    }
}
void InsertionSortChar(char v[]) 
{
    for (int i = 1; i < 10; i++) 
    {
        char key = v[i];
        int j = i - 1;
        while (j >= 0 && v[j] > key) 
        {
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = key;
    }
}

int main()
{
    InsertionSortInt(V1);
    for(int i = 0; i < 10; i++)
        printf("%d ", V1[i]);
    printf("\n");
    InsertionSortFloat(V2);
    for(int i = 0; i < 10; i++)
        printf("%f ", V2[i]);
    printf("\n");
    InsertionSortChar(V3);
    for(int i = 0; i < 10; i++)
        printf("%c ", V3[i]);
    printf("\n");
}