#include <assert.h>
#include <helper.c>
#include <stdio.h>
#include <stdlib.h>

int findMedian(Node *head)
{
    int length = 0;
    Node *temp = head;
    while (head != NULL)
    {
        head = head->next;
        length++;
    }
    if (length == 0)
    {
        printf("Empty LL\n");
        return 0;
    }
    int median = 0;
    int count = 1;
    if (length % 2)
    {
        for (int i = 1; i < (length / 2) + 1; i++)
        {
            temp = temp->next;
        }
        median = temp->data;
    }
    else
    {
        for (int i = 1; i < (length / 2); i++)
        {
            temp = temp->next;
        }
        median += temp->data;
        median += temp->next->data;
        count++;
    }
    return median / count;
}

// Function definition goes here
int main(void)
{
    Node *head = readList();
    int median = findMedian(head);
    printf("%d\n", median);
    freeList(head);
    return 0;
}
