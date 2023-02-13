#include <stdio.h>
#include <stdlib.h>

struct Node_t
{
    int data;
    struct Node_t *prev;
    struct Node_t *next;
};

typedef struct Node_t Node;

Node *create_node(int val)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->next = NULL;
    node->prev = NULL;
    node->data = val;
}

Node *add_to_list(Node *head, int val)
{
    Node *node = create_node(val);
    if (head == NULL)
    {
        return node;
    }
    else
    {
        while (head->next != NULL)
        {
            head = head->next;
        }
        head->next = node;
        node->prev = head;
        return node;
    }
}

Node *read_list(int n)
{
    int d;
    Node *head = NULL;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &d);
        if (head == NULL)
        {
            head = add_to_list(head, d);
        }
        else
        {
            add_to_list(head, d);
        }
    }
    return head;
}

void print_list(Node *head)
{
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

Node *rotate(Node *head)
{

    Node *tail = head;
    while (tail->next != NULL)
    {
        tail = tail->next;
    }
    tail->next = head;
    tail->prev->next = NULL;
    tail->prev = NULL;
    head->prev = tail;
    return tail;
}
int main()
{
    int n, k;
    scanf("%d", &n);
    scanf("%d", &k);
    Node *head = read_list(n);
    for (int i = 0; i < k; i++)
    {
        head = rotate(head);
    }

    print_list(head);
}