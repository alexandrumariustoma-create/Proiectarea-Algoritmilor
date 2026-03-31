#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

void MergeInt(int v[], int left, int mid, int right) 
{
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int vl[n1], vr[n2];
    for (int i = 0; i < n1; i++)
        vl[i] = v[left + i];
    for (int j = 0; j < n2; j++)
        vr[j] = v[mid + 1 + j];
    int i = 0;
    int j = 0;
    int k = left;
    while (i < n1 && j < n2) 
    {
        if (vl[i] <= vr[j]) {
            v[k] = vl[i];
            i++;
        } else {
            v[k] = vr[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        v[k] = vl[i];
        i++;
        k++;
    }
    while (j < n2) {
        v[k] = vr[j];
        j++;
        k++;
    }
}

void MergeSortInt(int v[], int left, int right) 
{
    if (left < right) 
    {
        int mid = left + (right - left) / 2;
        MergeSortInt(v, left, mid);
        MergeSortInt(v, mid + 1, right);
        MergeInt(v, left, mid, right);
    }
}

int main()
{
    int V1[10000];
    for(int i = 0; i < 10000; i++)
        V1[i] = rand() % 10000;
    clock_t start = clock();
    MergeSortInt(V1, 0, 9999);
    clock_t end = clock();
    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("%f seconds\n", time_taken);
}