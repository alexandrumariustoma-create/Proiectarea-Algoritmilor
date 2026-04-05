#include <stdio.h>

int push(int v[], int *top, int n)
{
    if(*top >= 4)
        return 0;
    else{
        *top = *top+1;
        v[*top] = n;
        return 1;
    }
}

int pop(int v[], int *top, int *data)
{
    if(*top < 0)
        return 0;
    else{
        *data = v[*top];
        *top = *top-1;
        return 1;
    }
}

int main()
{
    int a[5];
    int b[5];
    int topa = -1;
    int topb = -1;
    int n;

    push(a, &topa, 1);
    push(a, &topa, 2);
    push(a, &topa, 3);
    push(a, &topa, 11);
    push(a, &topa, 12);

    while(topa >= 0)
    {
        pop(a, &topa, &n);
        push(b, &topb, n);
    }

    while(topb >= 0)
    {
        pop(b, &topb, &n);
        printf("%d\n", n);
    }

}