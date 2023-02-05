#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

struct Node_t
{
    int data;
    struct Node_t *next;
};
typedef struct Node_t Node;

// Creates a new node with given value and returns a pointer to it
Node *createNode(int value)
{
    Node *newNode = malloc(sizeof(Node));
    assert(newNode != NULL);
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Creates a new node with given value and adds it to
// the back of the given singly linked list,
// returns a pointer to the newly created node
Node *addToList(Node *head, int val)
{
    Node *newNode = createNode(val);
    if (head == NULL)
    {
        return newNode;
    }
    Node *cur = head;
    while (cur->next != NULL)
    {
        cur = cur->next;
    }
    cur->next = newNode;
    return newNode;
}

// Creates a singly linked list by reading input and
// returns a pointer the head of the newly created linked list
Node *readList()
{
    int n;
    scanf("%d", &n);
    Node *head = NULL;
    for (int i = 0; i < n; ++i)
    {
        int x;
        scanf("%d", &x);
        if (head == NULL)
        {
            head = addToList(head, x);
        }
        else
        {
            addToList(head, x);
        }
    }
    return head;
}

// Prints the values stored in the nodes of the given singly linked list
void printList(Node *head)
{
    Node *ptr = head;
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
    return;
}

// Frees the memory dynamically allocated to
// all the nodes of the given singly linked list
void freeList(Node *head)
{
    Node *cur, *nxt;
    cur = head;
    while (cur != NULL)
    {
        nxt = cur->next;
        free(cur);
        cur = nxt;
    }
}

Node *sortList(Node *head)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->next = head;
    Node *prev, *curr, *next, *swap;
    int length = 0;
    Node *count = head;
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
    int i = 0;
    while (i < length)
    {
        prev = temp;
        curr = temp->next;
        next = temp->next->next;
        for (int j = 0; j < length - 1; j++)
        {
            if (curr->data > next->data)
            {
                prev->next = next;
                curr->next = next->next;
                next->next = curr;
                swap = next;
                next = curr;
                curr = swap;
            }
            prev = prev->next;
            curr = curr->next;
            next = next->next;
        }
        i++;
    }
    return temp->next;
}

// Function definition goes here
int main(void)
{
    Node *head = readList();
    head = sortList(head);
    printList(head);
    freeList(head);
    return 0;
}
