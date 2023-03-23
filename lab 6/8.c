#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int *data;
    int front;
    int rear;
} Queue;

void init(Queue *q, int n)
{
    q->front = -1;
    q->rear = -1;
    q->data = (int *)malloc(n * sizeof(int));
}

int is_empty(Queue *q)
{
    return (q->front == -1 && q->rear == -1);
}

int is_full(Queue *q, int n)
{
    return ((q->rear + 1) % n == q->front);
}

void enqueue(Queue *q, int x, int n)
{
    if (is_full(q, n))
    {
        printf("Error: Queue is full\n");
        return;
    }
    else if (is_empty(q))
    {
        q->front = q->rear = 0;
    }
    else
    {
        q->rear = (q->rear + 1) % n;
    }
    q->data[q->rear] = x;
}

// Remove an element from the front of the queue
int dequeue(Queue *q, int n)
{
    int x;
    if (is_empty(q))
    {
        printf("Error: Queue is empty\n");
        return -1;
    }
    else if (q->front == q->rear)
    {
        x = q->data[q->front];
        q->front = q->rear = -1;
    }
    else
    {
        x = q->data[q->front];
        q->front = (q->front + 1) % n;
    }
    return x;
}

// Find the position of the friend who should be seated to win the game
int find_position(int n, int k)
{
    // Initialize the queue with the numbers 1 to n
    Queue q;

    init(&q, n);
    for (int i = 1; i <= n; i++)
    {
        enqueue(&q, i, n);
    }
    // Keep removing every kth person until only one person is left
    while (!is_empty(&q))
    {
        for (int i = 1; i < k; i++)
        {
            enqueue(&q, dequeue(&q, n), n);
        }
        int out = dequeue(&q, n);
        if (q.front == q.rear)
        {
            return out;
        }
    }
    return -1;
}

int main()
{
    int n, k;
    scanf("%d", &n);
    scanf("%d", &k);
    int position = find_position(n, k);
    printf("%d\n", position);
    return 0;
}
