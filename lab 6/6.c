#include <stdio.h>
#include <stdlib.h>

struct node_t
{
    int elem;
    struct node_t *prev;
    struct node_t *next;
};

typedef struct node_t node;

int main()
{
    int n, elem;
    scanf("%d", &n);
    node *front, *rear, *temp;
    front = rear = NULL;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &elem);
        if (front == NULL)
        {
            front = rear = (node *)malloc(sizeof(node));
            front->elem = elem;
            front->next = NULL;
            front->prev = NULL;
        }
        else
        {
            temp = (node *)malloc(sizeof(node));
            temp->elem = elem;
            if (elem > front->elem)
            {
                temp->prev = rear;
                rear->next = temp;
                temp->next = NULL;
                rear = temp;
            }
            else
            {
                temp->next = front;
                temp->prev = NULL;
                front->prev = temp;
                front = temp;
            }
        }
    }

    temp = front;
    for (int i = 0; i < n; i++)
    {
        printf("%d ", temp->elem);
        temp = temp->next;
    }
    printf("\n");
    return 0;
}