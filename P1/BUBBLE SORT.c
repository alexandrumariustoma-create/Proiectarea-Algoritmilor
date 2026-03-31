#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int V1[10] = {-47, 46, -91, -64, 100, 92, -20, 83, -12, 10};
float V2[10] = {90.675, -60.980, 86.10, 4.99, 30.2682854, -29.178584028, -86.58683, -51.1535, -76.40793, 32.169};
char V3[10] = {'C', 'Y', 'E', 'B', 'D', 'W', 'a', 'O', 's', 'Y'};

bool isSortedInt(int v[])
{
    for(int i = 0; i < 9; i++)
        if (v[i] > v[i+1])
            return false;
    return true;
}

bool isSortedFloat(float v[])
{
    for(int i = 0; i < 9; i++)
        if (v[i] > v[i+1])
            return false;
    return true;
}

bool isSortedChar(char v[])
{
    for(int i = 0; i < 9; i++)
        if (v[i] > v[i+1])
            return false;
    return true;
}

void BubbleSortInt(int v[])
{
    for(int i = 0; i < 9; i++)
    {
        if (v[i] > v[i+1])
        {
            int aux = v[i];
            v[i] = v[i+1];
            v[i+1] = aux;
        }
    }
}

void BubbleSortFloat(float v[])
{
    for(int i = 0; i < 9; i++)
    {
        if (v[i] > v[i+1])
        {
            float aux = v[i];
            v[i] = v[i+1];
            v[i+1] = aux;
        }
    }
}

void BubbleSortChar(char v[])
{
    for(int i = 0; i < 9; i++)
    {
        if (v[i] > v[i+1])
        {
            char aux = v[i];
            v[i] = v[i+1];
            v[i+1] = aux;
        }
    }
}

int main()
{
    while(isSortedInt(V1) == false)
        BubbleSortInt(V1);

    while(isSortedFloat(V2) == false)
        BubbleSortFloat(V2);

    while(isSortedChar(V3) == false)
        BubbleSortChar(V3);
    
    for(int i = 0; i < 10; i++)
        printf("%d ", V1[i]);
    printf("\n");
    for(int i = 0; i < 10; i++)
        printf("%f ", V2[i]);
    printf("\n");
    for(int i = 0; i < 10; i++)
        printf("%c ", V3[i]);
    printf("\n");

}
