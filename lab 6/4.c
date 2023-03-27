#include <stdio.h>

int main()
{
    int n, elem;
    scanf("%d", &n);
    int freq[n];
    for (int i = 0; i < n; i++)
    {
        freq[i] = 0;
    }
    int queue[n];
    int front = -1;
    int rear = -1;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &elem);
        if (freq[elem] == 0)
        {
            queue[++rear] = elem;
            if (front == -1)
            {
                front = 0;
            }
            freq[elem]++;
        }
        else
        {
            freq[elem]++;
        }
        while (freq[queue[front]] > 1 && front <= rear)
        {
            front++;
        }
        if (front > rear)
        {
            printf("-1\n");
        }
        else
        {
            printf("%d\n", queue[front]);
        }
    }
}