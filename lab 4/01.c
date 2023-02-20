#include <stdio.h>
#include <stdlib.h>

struct slot
{
    int start;
    int end;
};

typedef struct slot slot;

void mergeSort(slot *slots, int start, int end)
{
    if (start >= end)
    {
        return;
    }
    int mid = (start + end) / 2;
    mergeSort(slots, start, mid);
    mergeSort(slots, mid + 1, end);
    slot *temp = malloc(sizeof(slot) * (end - start + 1));
    int i = start;
    int j = mid + 1;
    int k = 0;
    while (i <= mid && j <= end)
    {
        if (slots[i].end < slots[j].end)
        {
            temp[k] = slots[i];
            i++;
        }
        else
        {
            temp[k] = slots[j];
            j++;
        }
        k++;
    }
    while (i <= mid)
    {
        temp[k] = slots[i];
        i++;
        k++;
    }
    while (j <= end)
    {
        temp[k] = slots[j];
        j++;
        k++;
    }
    for (int i = start; i <= end; i++)
    {
        slots[i] = temp[i - start];
    }
    free(temp);
}

int main()
{
    int n;
    scanf("%d", &n);
    slot slots[n];
    for (int i = 0; i < n; i++)
    {
        int s, e;
        scanf("%d %d", &s, &e);
        slot *newSlot = malloc(sizeof(slot));
        newSlot->start = s;
        newSlot->end = e;
        slots[i] = *newSlot;
    }
    mergeSort(slots, 0, n - 1);
    slot newSlots[n];
    int newSlotsCount = 0;
    for (int i = 0; i < n; i++)
    {
        if (newSlotsCount == 0)
        {
            newSlots[newSlotsCount] = slots[i];
            newSlotsCount++;
        }
        else
        {
            if (slots[i].start <= newSlots[newSlotsCount - 1].end)
            {
                newSlots[newSlotsCount - 1].end = slots[i].end;
            }
            else
            {
                newSlots[newSlotsCount] = slots[i];
                newSlotsCount++;
            }
        }
    }
    printf("------\n");
    for (int i = 0; i < newSlotsCount; i++)
    {
        printf("%d %d\n", newSlots[i].start, newSlots[i].end);
    }
    return 0;
}