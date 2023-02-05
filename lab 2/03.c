#include <assert.h>
#include <helper.c>
#include <stdio.h>
#include <stdlib.h>

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
