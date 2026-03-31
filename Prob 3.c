#include <stdio.h>

int afisarevector(int v[], int n) {
    if (n == 1)
        printf("%d", v[n - 1]);
    else {
        afisarevector(v, n - 1);
    }
}


int main() {
    int v[100];
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &v[i]);
    afisarevector(v, n);
}