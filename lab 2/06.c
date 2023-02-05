#include <assert.h>
#include <helper.c>
#include <stdio.h>
#include <stdlib.h>

Node *rearrangeList(Node *head)
{
}

// Function definition goes here
int main(void)
{
    Node *head = readList();
    head = rearrangeList(head);
    printList(head);
    freeList(head);
    return 0;
}
