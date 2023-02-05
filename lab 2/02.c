#include <assert.h>
#include <helper.c>
#include <stdio.h>
#include <stdlib.h>

Node *mergeLists(Node *head1, Node *head2)
{
    Node *head1, *head2;
    Node *merged = NULL;
    while (head1 != NULL && head2 != NULL)
    {
        if (head1->data > head2->data)
        {
            if (merged != NULL)
            {
                addToList(merged, head2->data);
            }
            else
            {
                merged = addToList(merged, head2->data);
            }

            head2 = head2->next;
        }
        else
        {
            if (merged != NULL)
            {
                addToList(merged, head1->data);
            }
            else
            {
                merged = addToList(merged, head1->data);
            }
            head1 = head1->next;
        }
    }
    while (head1 != NULL)
    {
        if (merged != NULL)
        {
            addToList(merged, head1->data);
        }
        else
        {
            merged = addToList(merged, head1->data);
        }
        head1 = head1->next;
    }
    while (head2 != NULL)
    {
        if (merged != NULL)
        {
            addToList(merged, head2->data);
        }
        else
        {
            merged = addToList(merged, head2->data);
        }
        head2 = head2->next;
    }
    return merged;
}

// Function definition goes here
int main(void)
{
    Node *head1 = readList();
    Node *head2 = readList();
    Node *merged = mergeLists(head1, head2);
    printList(merged);
    freeList(merged);
    return 0;
}
