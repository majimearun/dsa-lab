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

Node *removeRepeatedNodes(Node *head)
{
    Node temp = {0, head};
    Node *prev = &temp;
    Node *cur = head;
    Node *nxt = head->next;
    Node *temp_free;
    while (nxt != NULL)
    {
        if (cur->data == nxt->data)
        {
            if (cur != head)
            {
                while (nxt != NULL && cur->data == nxt->data)
                {
                    temp_free = nxt;
                    nxt = nxt->next;
                    free(temp_free);
                }
                prev->next = nxt;
                free(cur);
                cur = nxt;
                if (nxt != NULL)
                {
                    nxt = nxt->next;
                }
            }else{
                while (nxt != NULL && cur->data == nxt->data)
                {
                    temp_free = nxt;
                    nxt = nxt->next;
                    free(temp_free);
                }
                prev->next = nxt;
                free(cur);

                head = cur = nxt;
                if (nxt != NULL)
                {
                    nxt = nxt->next;
                }
            }
        }
        else
        {
            prev = cur;
            cur = nxt;
            nxt = nxt->next;
        }
    }
    return head;
}

// Function definition goes here
int main(void)
{
    Node *head = readList();
    head = removeRepeatedNodes(head);
    printList(head);
    freeList(head);

    return 0;
}
