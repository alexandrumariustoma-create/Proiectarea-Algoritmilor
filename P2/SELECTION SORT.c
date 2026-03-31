#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

void SelectionSortInt(int v[], int n)
    {
        for(int i = 0; i < n - 1; i++)
        {
            int min = v[i];
            int minIndex = i;
            int j;
            for(j = i; j < n; j++)
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
    int V1[10000];
    for(int i = 0; i < 10000; i++)
        V1[i] = rand() % 100000;
    clock_t start = clock();
    SelectionSortInt(V1, 10000);
    clock_t end = clock();
    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("%f seconds\n", time_taken);
}