#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

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

int main()
{
    int V1[10000];
    for(int i = 0; i < 10000; i++)
        V1[i] = rand() % 10000;
    clock_t start = clock();
    QuickSortInt(V1, 0, 9999);
    clock_t end = clock();
    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("%f seconds\n", time_taken);
}