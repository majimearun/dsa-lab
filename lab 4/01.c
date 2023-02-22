#include <stdio.h>
#include <stdlib.h>

struct slot
{
    int start;
    int end;
};

typedef struct slot slot;

void merge_sort(slot *slots, int start, int end)
{
    if (start >= end)
    {
        return;
    }
    int mid = (start + end) / 2;
    merge_sort(slots, start, mid);
    merge_sort(slots, mid + 1, end);
    slot *temp = malloc(sizeof(slot) * (end - start + 1));
    int i = start;
    int j = mid + 1;
    int k = 0;
    while (i <= mid && j <= end)
    {
        if (slots[i].start < slots[j].start)
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
        slot new_slot;
        new_slot.start = s;
        new_slot.end = e;
        slots[i] = new_slot;
    }
    merge_sort(slots, 0, n - 1);
    slot new_slots[n];
    int new_slots_count = 0;
    for (int i = 0; i < n; i++)
    {
        if (new_slots_count == 0)
        {
            new_slots[new_slots_count] = slots[i];
            new_slots_count++;
        }
        else
        {
            if (slots[i].start >= new_slots[new_slots_count - 1].start &&
                slots[i].start <= new_slots[new_slots_count - 1].end)
            {
                new_slots[new_slots_count - 1].end = slots[i].end > new_slots[new_slots_count - 1].end
                                                         ? slots[i].end
                                                         : new_slots[new_slots_count - 1].end;
            }
            else
            {
                new_slots[new_slots_count] = slots[i];
                new_slots_count++;
            }
        }
    }
    printf("------\n");
    printf("%d\n", new_slots_count);
    for (int i = 0; i < new_slots_count; i++)
    {
        printf("%d %d\n", new_slots[i].start, new_slots[i].end);
    }
    return 0;
}