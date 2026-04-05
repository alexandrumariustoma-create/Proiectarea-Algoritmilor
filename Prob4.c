#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

bool enqueue(int queue[], int *front, int *rear, int *count, int n, int x)
{
    if(*count == n)
        return 0;
    else
    {
        *rear = (*rear + 1) % n;
        queue[*rear] = x;
        *count = *count + 1;
        return 1;
    }
}

int dequeue(int queue[], int *front, int *rear, int *count, int n, int *x)
{
    if(*count == 0)
        return 0;
    else
    {
        *x = queue[*front];
        *front = (*front + 1) % n;
        *count = *count - 1;
        return 1;
    }
}

int main()
{   
    srand(time(NULL));
    int n, queue[100], front = 0, rear = -1, count = 0, x, v[100], j = 0;
    int nrrand, copien;
    scanf("%d", &n);
    copien = n;

    for(int i = 0; i < n; i++)
    {
        scanf("%d", &x);
        enqueue(queue, &front, &rear, &count, n, x);
    }

    while(copien > 0)
    {
        nrrand = rand() % copien;
        for(int i = 0; i < nrrand; i++)
        {
            dequeue(queue, &front, &rear, &count, n, &x);
            enqueue(queue, &front, &rear, &count, n, x);
        }

        dequeue(queue, &front, &rear, &count, n, &v[j]);
        copien--;
        j++;
    }
    for(j = 0; j < n; j++)
    {
        printf("%d\n", v[j]);
    }
}