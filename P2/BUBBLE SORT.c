#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>


bool isSortedInt(int v[], int n)
{
    for(int i = 0; i < n; i++)
        if (v[i] > v[i+1])
            return false;
    return true;
}

void BubbleSortInt(int v[], int n)
{
    for(int i = 0; i < n - 1; i++)
    {
        if (v[i] > v[i+1])
        {
            int aux = v[i];
            v[i] = v[i+1];
            v[i+1] = aux;
        }
    }
}

int main()
{
    int V1[10000];
    for(int i = 0; i < 10000; i++)
        V1[i] = rand() % 10000;
    clock_t start = clock();
    while(isSortedInt(V1, 10000) == false)
        BubbleSortInt(V1, 10000);
    clock_t end = clock();
    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("%f seconds\n", time_taken);
}