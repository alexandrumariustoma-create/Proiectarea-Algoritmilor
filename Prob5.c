#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>

int v[52] = {2, 3, 4 , 5, 6, 7, 8, 9, 10, 11, 12, 13, 14,
             2, 3, 4 , 5, 6, 7, 8, 9, 10, 11, 12, 13, 14,
             2, 3, 4 , 5, 6, 7, 8, 9, 10, 11, 12, 13, 14,
             2, 3, 4 , 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};

typedef struct
{
    int q[52];
    int front;
    int rear;
}queue;

bool enqueue(queue *q, int n)
{
    {
        q->rear = q->rear + 1;
        q->q[q->rear] = n;
        return 1;
    }
}

bool dequeue(queue *q, int *n)
{
    if(q->front > q->rear)
        return 0;
    else
    {
        *n = q->q[q->front];
        q->front = q->front + 1;
        return 1;
    }
}

void shuffle(int v[], int size)
{
    for(int i = 0; i < size; i = i+1)
    {
        int j = rand() % size;
        int temp = v[i];
        v[i] = v[j];
        v[j] = temp;
    }
}

void split_cards(queue *p1,queue *p2, int v[])
{
    for(int i = 0; i < 26; i = i+1)
        enqueue(p1, v[i]);
    for(int i = 26; i < 52; i = i+1)
        enqueue(p2, v[i]);
}

int main()
{
    srand((unsigned int)time(NULL));

    int n;
    int cycles = 0;
    queue player1;
    queue player2;

    player1.front = 0;
    player1.rear = -1;
    player2.front = 0;
    player2.rear = -1;

    shuffle(v, 52);

    split_cards(&player1, &player2, v);

    while (player1.front <= player1.rear && player2.front <= player2.rear)
    {
        cycles = cycles + 1;

        if (player1.q[player1.front] > player2.q[player2.front])
        {
            dequeue(&player1, &n);
            enqueue(&player1, n);
            dequeue(&player2, &n);
            enqueue(&player1, n);
        }
        else if (player1.q[player1.front] < player2.q[player2.front])
        {
            dequeue(&player2, &n);
            enqueue(&player2, n);
            dequeue(&player1, &n);
            enqueue(&player2, n);
        }
        else
        {
            dequeue(&player1, &n);
            dequeue(&player2, &n);
        }
    }

    if (player1.front > player1.rear)
        printf("Jucatorul 2 a castigat (%d)", cycles);
    else if(player2.front > player2.rear)
        printf("Jucatorul 1 a castigat (%d)", cycles);
    else
        printf("Remiza (%d)", cycles);

    printf("\nCartile jucatorului 1: ");
    while (player1.front <= player1.rear)
    {
        int card;
        dequeue(&player1, &card);
        printf("%d ", card);

    }
    printf("\nCartile jucatorului 2:");
    while (player2.front <= player2.rear)
    {
        int card;
        dequeue(&player2, &card);
        printf("%d ", card);
    }
}