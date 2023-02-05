#include <assert.h>
#include <helper.c>
#include <stdio.h>
#include <stdlib.h>

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
