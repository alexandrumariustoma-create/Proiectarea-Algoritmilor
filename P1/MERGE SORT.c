#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int V1[10] = {-47, 46, -91, -64, 100, 92, -20, 83, -12, 10};
float V2[10] = {90.675, -60.980, 86.10, 4.99, 30.2682854, -29.178584028, -86.58683, -51.1535, -76.40793, 32.169};
char V3[10] = {'C', 'Y', 'E', 'B', 'D', 'W', 'a', 'O', 's', 'Y'};

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

void MergeFloat(float v[], int left, int mid, int right) 
{
    int n1 = mid - left + 1;
    int n2 = right - mid;
    float vl[n1], vr[n2];
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

void MergeSortFloat(float v[], int left, int right) 
{
    if (left < right) 
    {
        int mid = left + (right - left) / 2;
        MergeSortFloat(v, left, mid);
        MergeSortFloat(v, mid + 1, right);
        MergeFloat(v, left, mid, right);
    }
}

void MergeChar(char v[], int left, int mid, int right) 
{
    int n1 = mid - left + 1;
    int n2 = right - mid;
    char vl[n1], vr[n2];
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

void MergeSortChar(char v[], int left, int right) 
{
    if (left < right) 
    {
        int mid = left + (right - left) / 2;
        MergeSortChar(v, left, mid);
        MergeSortChar(v, mid + 1, right);
        MergeChar(v, left, mid, right);
    }
}

int main()
{
    MergeSortInt(V1, 0, 9);
    for(int i = 0; i < 10; i++)
        printf("%d ", V1[i]);
    printf("\n");
    MergeSortFloat(V2, 0, 9);
    for(int i = 0; i < 10; i++)
        printf("%f ", V2[i]);
    printf("\n");
    MergeSortChar(V3, 0, 9);
    for(int i = 0; i < 10; i++)
        printf("%c ", V3[i]);
    printf("\n");
}