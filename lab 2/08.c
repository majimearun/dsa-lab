#include <assert.h>
#include <helper.c>
#include <stdio.h>
#include <stdlib.h>

void deleteAt(Node *head, int i)
{
    Node *cur = head;
    for (int j = 0; j < i - 1; ++j)
    {
        cur = cur->next;
    }
    Node *temp = cur->next;
    cur->next = temp->next;
    free(temp);
    return;
}

Node *removeSlide(Node *head, int k)
{
    int n = 0;
    Node *cur = head;
    while (cur != NULL)
    {
        ++n;
        cur = cur->next;
    }
    deleteAt(head, n - k);
    return head;
}

// Function definition goes here
int main(void)
{
    int k;
    scanf("%d", &k);
    Node *head = readList();
    head = removeSlide(head, k);
    printList(head);
    freeList(head);
    return 0;
}
