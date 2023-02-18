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
    return node;
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

Node *read_list()
{
    int n, d;
    Node *head = NULL;
    scanf("%d", &n);
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

int exists_sum(Node *head, Node *tail, int target)
{
    if (head == NULL)
    {
        return 0;
    }
    if (head->data >= tail->data)
    {
        return 0;
    }
    if (head->data + tail->data > target)
    {
        return exists_sum(head, tail->prev, target);
    }
    else if (head->data + tail->data < target)
    {
        return exists_sum(head->next, tail, target);
    }
    else
    {
        return 1;
    }
}

int main()
{
    int target;
    scanf("%d", &target);
    Node *head = read_list();
    Node *tail = head;
    while (tail->next != NULL)
    {
        tail = tail->next;
    }
    printf("%d\n", exists_sum(head, tail, target));
}