#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int find_posn(char c, char *arr)
{
    int i = 0;
    while (arr[i] != '\0')
    {
        if (arr[i] == c)
        {
            return i;
        }
        i++;
    }
    return -1;
}

typedef struct
{
    char *unique;
    int nunique;
    int *reps;
} string_info;

string_info *get_unique_chars(char *string, int n)
{
    char *unique = (char *)malloc(1001 * sizeof(char));
    int *reps = (int *)malloc(1000 * sizeof(int));
    memset(reps, 0, sizeof(reps));
    unique[0] = '\0';
    int t = 0;
    for (int i = 0; i < n; i++)
    {
        int posn = find_posn(string[i], unique);
        if (posn == -1)
        {
            unique[t] = string[i];
            unique[t + 1] = '\0';
            reps[t] = 1;
            t++;
        }
        else
        {
            reps[posn] += 1;
        }
    }
    string_info *result = (string_info *)malloc(sizeof(string_info));
    result->reps = reps;
    result->unique = unique;
    result->nunique = t;
    return result;
}

int all_non_postive(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > 0)
        {
            return 0;
        }
    }
    return 1;
}

int *copy_array(int *arr, int n)
{
    int *copy = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        copy[i] = arr[i];
    }
    return copy;
}

int main()
{

    char string[1001];
    char set[1001];

    fgets(string, 1001, stdin);
    fgets(set, 1001, stdin);

    string[strcspn(string, "\n")] = 0;
    set[strcspn(set, "\n")] = 0;

    int string_len = strlen(string);
    int set_len = strlen(set);

    string_info *info = get_unique_chars(set, set_len);
    int *reps = copy_array(info->reps, info->nunique);

    char *left = string;
    char *right = string;

    int start, end, min, min_start, min_end;
    start = end = 0;
    min = 9999;
    int no_window = 0;
    while ((start <= end) && end < string_len)
    {
        int posn;
        // move right pointer
        while (!all_non_postive(reps, info->nunique) && end < string_len)
        {
            posn = find_posn(*right, info->unique);
            if (posn != -1)
            {
                reps[posn]--;
            }
            right++;
            end++;
        }
        // check if no window
        if (!all_non_postive(reps, info->nunique))
        {
            no_window = 1;
            break;
        }
        // move left pointer
        while (all_non_postive(reps, info->nunique) && start <= end)
        {
            posn = find_posn(*left, info->unique);
            if (posn != -1)
            {
                reps[posn]++;
            }
            left++;
            start++;
        }
        left--;
        start--;

        // update min window if necessary
        if (min > (end - start + 1))
        {
            min = end - start + 1;
            min_end = end - 1;
            min_start = start;
        }
        // check other window possibilites
        end = ++start;
        right = ++left;
        reps = copy_array(info->reps, info->nunique);
    }
    if (no_window)
    {
        printf("NO WINDOW\n");
        exit(0);
    }
    printf("%d %d\n", min_start, min_end);
    return 0;
}