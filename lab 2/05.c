#include <assert.h>
#include <helper.c>
#include <stdio.h>
#include <stdlib.h>

char charAt(Node *head, int index)
{
    Node *temp = head;
    for (int i = 0; i < index; i++)
    {
        temp = temp->next;
    }
    return temp->data;
}

int isPalindrome(Node *head)
{
    int length = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        temp = temp->next;
        length++;
    }
    for (int i = 0; i < length / 2; i++)
    {
        if (charAt(head, i) != charAt(head, length - i - 1))
        {
            return 0;
        }
    }
    return 1;
}

// Function definition goes here
int main(void)
{
    Node *head = readList();
    int palin = isPalindrome(head);
    printf("%d\n", palin);
    freeList(head);

    return 0;
}
