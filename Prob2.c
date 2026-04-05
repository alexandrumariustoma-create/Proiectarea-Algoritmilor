#include <stdio.h>

int v[21];

int top1 = -1;
int top2 = 10;
int topmax1 = 9;
int topmax2 = 20;

int push1(int n)
{
    if(top1 >= topmax1)
        return 0;
    else{
        top1 = top1+1;
        v[top1] = n;
        return 1;
    }
}

int push2(int n)
{
    if(top2 >= topmax2)
        return 0;
    else{
        top2 = top2+1;
        v[top2] = n;
        return 1;
    }
}

int pop1(int *data)
{
    if(top1 < 0)
        return 0;
    else{
        *data = v[top1];
        top1 = top1-1;
        return 1;
    }
}

int pop2(int *data)
{
    if(top2 < 11)
        return 0;
    else{
        *data = v[top2];
        top2 = top2-1;
        return 1;
    }
}

int main()
{
    push1(1);
    push1(2);
    push1(3);
    push2(11);
    push2(12);
    push2(13);

    int n;

    while(pop1(&n))
        printf("%d ", n);
    printf("\n");
    while(pop2(&n))
        printf("%d ", n);
}