#include <assert.h>
#include <helper.c>
#include <stdio.h>
#include <stdlib.h>

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
