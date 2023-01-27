#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int main()
{
    char str[1001];
    fgets(str, 1001, stdin);
    str[strcspn(str, "\n")] = 0;
    int str_len = strlen(str);

    char delim[] = " ";

    char **palindromes = (char **)malloc(1001 * sizeof(char *));
    for (int i = 0; i < 1001; i++)
    {
        palindromes[i] = (char *)malloc(1001 * sizeof(char));
    }

    int n_palindromes = 0;

    char *ptr = strtok(str, delim);
    int len;
    char temp[1001];
    while (ptr != NULL)
    {
        len = strlen(ptr);
        for (int i = len - 1; i >= 0; i--)
        {
            temp[len - 1 - i] = ptr[i];
        }
        temp[len] = '\0';
        if (same(ptr, temp, len))
        {
            palindromes[n_palindromes] = ptr;
            n_palindromes++;
        }
        printf("%s ", temp);
        ptr = strtok(NULL, delim);
    }
    printf("\n");
    if (n_palindromes == 0)
    {
        printf("NO PALINDROMES\n");
    }
    else
    {
        for (int i = 0; i < n_palindromes; i++)
        {
            printf("%s ", palindromes[i]);
        }
        printf("\n");
    }
}