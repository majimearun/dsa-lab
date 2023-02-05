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

// Node *reverseList(Node *head)
// {
//     Node *temp = createNode(0);
//     temp->next = head;
//     Node *prev = temp;
//     Node *curr = head;
//     Node *nxt = head->next;
//     while (nxt != NULL)
//     {
//         curr->next = prev;
//         prev = curr;
//         curr = nxt;
//         nxt = nxt->next;
//     }
//     curr->next = prev;
//     head->next = NULL;
//     return curr;
// }

Node *reverseList(Node *head)
{
    Node *prev = NULL;
    Node *cur = head;
    Node *nxt = NULL;
    while (cur != NULL)
    {
        nxt = cur->next;
        cur->next = prev;
        prev = cur;
        cur = nxt;
    }
    return prev;
}

// Function definition goes here
int main(void)
{
    Node *head = readList();
    head = reverseList(head);
    printList(head);
    freeList(head);
    return 0;
}
