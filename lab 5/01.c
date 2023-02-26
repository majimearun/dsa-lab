#include <stdio.h>
#include <stdlib.h>

int bracket_possibilities(int n, char **perms, int count, int open, int close, char *temp)
{
    if (open + close == n)
    {
        perms[count] = malloc(sizeof(char) * (n + 1));
        perms[count][n] = '\0';
        for (int i = 0; i < n; i++)
        {
            perms[count][i] = temp[i];
        }
        return count + 1;
    }
    if (open < n / 2)
    {
        temp[open + close] = '(';
        count = bracket_possibilities(n, perms, count, open + 1, close, temp);
    }
    if (close < open)
    {
        temp[open + close] = ')';
        count = bracket_possibilities(n, perms, count, open, close + 1, temp);
    }
    return count;
}

int main()
{
    int n;
    scanf("%d", &n);
    int possible = 0;
    char **perms = malloc(sizeof(char *) * 500);
    for (int i = 0; i < 500; i++)
    {
        perms[i] = malloc(sizeof(char) * n);
    }
    possible = bracket_possibilities(n, perms, 0, 0, 0, malloc(sizeof(char) * (n + 1)));
    printf("%d\n", possible);
    for (int i = 0; i < possible; i++)
    {
        printf("%s\n", perms[i]);
    }
}