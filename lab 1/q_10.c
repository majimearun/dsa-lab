#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int find_posn(char c, char *arr, int start)
{
    int i = start;
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

void bubble_sort_wrt(int *arr, char *wrt, int n)
{
    int temp;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (wrt[j + 1] <= wrt[j])
            {
                temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;

                temp = wrt[j + 1];
                wrt[j + 1] = wrt[j];
                wrt[j] = temp;
            }
        }
    }
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
        int posn = find_posn(string[i], unique, 0);
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

char *copy_char_array(char *arr, int n)
{
    char *copy = (char *)malloc(n * sizeof(char));
    for (int i = 0; i < n; i++)
    {
        copy[i] = arr[i];
    }
    return copy;
}

int *copy_int_array(int *arr, int n)
{
    int *copy = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        copy[i] = arr[i];
    }
    return copy;
}

int same(char *s1, char *s2, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (s1[i] != s2[i])
        {
            return 0;
        }
    }
    return 1;
}

int same_int(int *s1, int *s2, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (s1[i] != s2[i])
        {
            return 0;
        }
    }
    return 1;
}

void find_matching_perm(char *s1, char *s2, int n)
{
    int unused[n], posn, start;
    memset(unused, 1, sizeof(unused));
    for (int i = 0; i < n; i++)
    {
        start = 0;
        while (start < n)
        {
            posn = find_posn(s1[i], s2, start);
            if (unused[posn])
            {
                printf("%d ", posn + 1);
                unused[posn] = 0;
                break;
            }
            start = posn + 1;
        }
    }
    printf("\n");
}

int main()
{
    char s[1001], a[1001];
    scanf("%s", s);
    scanf("%s", a);

    s[strcspn(s, "\n")] = 0;
    a[strcspn(a, "\n")] = 0;

    int s_len = strlen(s);
    int a_len = strlen(a);

    if (s_len != a_len)
    {
        printf("NOT POSSIBLE\n");
        exit(0);
    }

    string_info *s_info = get_unique_chars(s, s_len);
    string_info *a_info = get_unique_chars(a, a_len);

    if (a_info->nunique != s_info->nunique)
    {
        printf("NOT POSSIBLE\n");
        exit(0);
    }

    char *a_unique = copy_char_array(a_info->unique, a_len);
    char *s_unique = copy_char_array(s_info->unique, s_len);

    int *a_reps = copy_int_array(a_info->reps, a_len);
    int *s_reps = copy_int_array(s_info->reps, s_len);

    bubble_sort_wrt(a_reps, a_unique, a_len);
    bubble_sort_wrt(s_reps, s_unique, s_len);

    if (!(same(a_unique, s_unique, s_info->nunique) && same_int(a_reps, s_reps, s_info->nunique)))
    {
        printf("NOT POSSIBLE\n");
        exit(0);
    }
    else
    {
        find_matching_perm(a, s, s_len);
    }
}