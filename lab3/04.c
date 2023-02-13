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

struct split
{
    int a;
    int b;
};

struct split find_best_split(Node *head)
{
    Node *tail = head;
    while (tail->next != NULL)
    {
        tail = tail->next;
    }
    int length = 0;
    Node *temp = head;
    while (head != NULL)
    {
        length++;
        head = head->next;
    }
    head = temp;
    int a, b, max_equals_a, max_equals_b;
    a = b = max_equals_a = max_equals_b = 0;
    int sum_a = 0, sum_b = 0;
    while (a + b <= length)
    {
        if (sum_a < sum_b)
        {
            sum_a += head->data;
            head = head->next;
            a++;
        }
        else if (sum_a > sum_b)
        {
            sum_b += tail->data;
            tail = tail->prev;
            b++;
        }
        else
        {
            max_equals_a = a;
            max_equals_b = b;
            sum_a += head->data;
            head = head->next;
            a++;
        }
    }
    struct split answer = {max_equals_a, max_equals_b};
    return answer;
}

int main()
{
    Node *head = read_list();
    struct split answer= find_best_split(head);
    printf("%d %d\n", answer.a, answer.b);
}