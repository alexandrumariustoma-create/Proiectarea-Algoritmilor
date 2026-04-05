#include <stdio.h>
#include <stdbool.h>

typedef struct {

    int v[10];
    int top;

}stack;

bool push(stack *s, int n)
{
    if(s->top == 9)
        return 0;
    else
    {
        s->top = s->top+1;
        s->v[s->top] = n;
    }
}

bool pop(stack *s, int *data)
{
    if(s->top < 0)
        return 0;
    else
    {
        *data = s->v[s->top];
        s->top = s->top-1;
    }
}

typedef struct
{
    int v[10];
    int front;
    int rear;
}queue;

bool enqueue(queue *q, int n)
{
    if(q->rear == 9)
        return 0;
    else
    {
        q->rear = q->rear + 1;
        q->v[q->rear] = n;
    }
}

bool dequeue(queue *q, int *n)
{
    if(q->front > q->rear)
        return 0;
    else
    {
        *n = q->v[q->front];
        q->front = q->front + 1;
    }
}

int main()
{
    stack s;
    s.top = -1;

    push(&s, 10);
    push(&s, 20);
    push(&s, 30);

    int data;
    pop(&s, &data);
    printf("%d\n", data);
    pop(&s, &data);
    printf("%d\n", data);
    pop(&s, &data);
    printf("%d\n", data);

    queue q;
    q.front = 0;
    q.rear = -1;

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);

    int n;
    dequeue(&q, &n);
    printf("%d\n", n);
    dequeue(&q, &n);
    printf("%d\n", n);
    dequeue(&q, &n);
    printf("%d\n", n);

}