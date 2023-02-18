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

void print_curr(Node *curr)
{
    printf("%d\n", curr->data);
}

Node *play_next(Node *curr)
{
    if (curr->next != NULL)
    {
        return curr->next;
    }
    else
    {
        return curr;
    }
}

Node *play_prev(Node *curr)
{
    if (curr->prev != NULL)
    {
        return curr->prev;
    }
    else
    {
        return curr;
    }
}

void menu(Node *head, Node *curr)
{
    int input = 0, song = 0;
    while (input != 5)
    {
        scanf("%d", &input);
        switch (input)
        {
        case 1:
            scanf("%d", &song);
            add_to_list(head, song);
            break;
        case 2:
            print_curr(curr);
            break;
        case 3:
            curr = play_next(curr);
            break;
        case 4:
            curr = play_prev(curr);
        case 5:
            break;
        default:
            break;
        }
    }
}

int main()
{
    Node *head = read_list();
    Node *curr = head;
    menu(head, curr);
    return 0;
}