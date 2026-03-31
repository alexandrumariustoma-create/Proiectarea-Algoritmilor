#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int V1[10] = {-47, 46, -91, -64, 100, 92, -20, 83, -12, 10};
float V2[10] = {90.675, -60.980, 86.10, 4.99, 30.2682854, -29.178584028, -86.58683, -51.1535, -76.40793, 32.169};
char V3[10] = {'C', 'Y', 'E', 'B', 'D', 'W', 'a', 'O', 's', 'Y'};

int PartitionInt(int v[], int low, int high) 
{
    int pivot = v[high];
    int i = low - 1;
    for (int j = low; j < high; j++) 
    {
        if (v[j] <= pivot) 
        {
            i++;
            int temp = v[i];
            v[i] = v[j];
            v[j] = temp;
        }
    }
    int temp = v[i + 1];
    v[i + 1] = v[high];
    v[high] = temp;
    return i + 1;
}

void QuickSortInt(int v[], int low, int high) 
{
    if (low < high) 
    {
        int pi = PartitionInt(v, low, high);
        QuickSortInt(v, low, pi - 1);
        QuickSortInt(v, pi + 1, high);
    }
}


int PartitionFloat(float v[], int low, int high) 
{
    float pivot = v[high];
    int i = low - 1;
    for (int j = low; j < high; j++) 
    {
        if (v[j] <= pivot) 
        {
            i++;
            float temp = v[i];
            v[i] = v[j];
            v[j] = temp;
        }
    }
    float temp = v[i + 1];
    v[i + 1] = v[high];
    v[high] = temp;
    return i + 1;
}

void QuickSortFloat(float v[], int low, int high) 
{
    if (low < high) 
    {
        int pi = PartitionFloat(v, low, high);
        QuickSortFloat(v, low, pi - 1);
        QuickSortFloat(v, pi + 1, high);
    }
}

int PartitionChar(char v[], int low, int high) 
{
    char pivot = v[high];
    int i = low - 1;
    for (int j = low; j < high; j++) 
    {
        if (v[j] <= pivot) 
        {
            i++;
            char temp = v[i];
            v[i] = v[j];
            v[j] = temp;
        }
    }
    char temp = v[i + 1];
    v[i + 1] = v[high];
    v[high] = temp;
    return i + 1;
}

void QuickSortChar(char v[], int low, int high) 
{
    if (low < high) 
    {
        int pi = PartitionChar(v, low, high);
        QuickSortChar(v, low, pi - 1);
        QuickSortChar(v, pi + 1, high);
    }
}


int main()
{
    QuickSortInt(V1, 0, 9);
    for(int i = 0; i < 10; i++)
        printf("%d ", V1[i]);
    printf("\n");
    QuickSortFloat(V2, 0, 9);
    for(int i = 0; i < 10; i++)
        printf("%f ", V2[i]);
    printf("\n");
    QuickSortChar(V3, 0, 9);
    for(int i = 0; i < 10; i++)
        printf("%c ", V3[i]);
}