#include <stdio.h>
#include <stdlib.h>

struct Node_t
{
    int data;
    struct Node_t *next;
};

typedef struct Node_t Node;

Node *create_node(int val)
{
    Node *new_node = malloc(sizeof(Node));
    new_node->data = val;
    new_node->next = NULL;
    return new_node;
}

Node *add_to_list(Node *head, int val)
{
    Node *new_node = create_node(val);
    if (head == NULL)
    {
        return new_node;
    }
    else
    {
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new_node;
        return new_node;
    }
}

Node *read_list()
{
    int n, val;
    scanf("%d", &n);
    Node *head = NULL;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &val);
        if (head == NULL)
        {
            head = add_to_list(head, val);
        }
        else
        {
            add_to_list(head, val);
        }
    }
    return head;
}

void print_list(Node *head)
{
    if (head == NULL)
    {
        printf("EMPTY LIST");
    }
    else
    {
        while (head != NULL)
        {
            printf("%d ", head->data);
            head = head->next;
        }
        printf("\n");
    }
}

void swap(Node *prev, Node *cur, Node *nxt)
{
    prev->next = nxt;
    cur->next = nxt->next;
    nxt->next = cur;
}

Node *sort_list(Node *head)
{
    Node *count = head;
    int length = 0;
    while (count != NULL)
    {
        count = count->next;
        length++;
    }
    if (length == 0)
    {
        printf("Empty LL\n");
        return NULL;
    }
    Node *prev, *cur, *nxt;
    for (int i = 0; i < length; i++)
    {
        prev = NULL;
        cur = head;
        nxt = cur->next;
        for (int j = 0; j < length - i - 1; j++)
        {
            if (cur->data > nxt->data)
            {
                if (prev == NULL)
                {
                    Node temp = {0, head};
                    swap(&temp, cur, nxt);
                    head = temp.next;
                    prev = head;
                    nxt = cur->next;
                }
                else
                {
                    swap(prev, cur, nxt);
                    prev = nxt;
                    nxt = cur->next;
                }
            }
            else
            {
                prev = cur;
                cur = nxt;
                nxt = nxt->next;
            }
        }
    }
    return head;
}

int main()
{
    Node *head = read_list();
    print_list(head);
    head = sort_list(head);
    print_list(head);
    return 0;
}
