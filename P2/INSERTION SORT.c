#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

void InsertionSortInt(int v[], int n) 
{
    for (int i = 1; i < n; i++) 
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

int main()
{
    int V1[10000];
    for(int i = 0; i < 10000; i++)
        V1[i] = rand() % 10000;
    clock_t start = clock();
    InsertionSortInt(V1, 10000);
    clock_t end = clock();
    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("%f seconds\n", time_taken);
}