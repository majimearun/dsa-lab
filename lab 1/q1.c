#include <stdio.h>
#include <stdlib.h>

int **get_matrix(int m, int n, int print)
{
    int **matrix = (int **)malloc(m * sizeof(int *));
    for (int i = 0; i < m; i++)
    {
        matrix[i] = (int *)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }
    if (print)
    {
        printf("\nInput matrix is:\n");
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                printf("%d ", matrix[i][j]);
            }
            printf("\n");
        }
    }
    return matrix;
}

int **calc_matrix(int **given_matrix, int m, int n, int print)
{
    int **matrix = (int **)malloc(m * sizeof(int *));
    int sum = 0;
    for (int i = 0; i < m; i++)
    {
        matrix[i] = (int *)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++)
        {
            sum += given_matrix[i][j];
            matrix[i][j] = sum;
        }
    }
    if (print)
    {
        printf("\nCalculated matrix is:\n");
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                printf("%d ", matrix[i][j]);
            }
            printf("\n");
        }
    }
    return matrix;
}

int main()
{
    int m, n;
    scanf("%d %d", &m, &n);
    int **input_matrix = get_matrix(m, n, 0);
    int **new_matrix = calc_matrix(input_matrix, m, n, 1);
    int ri, ci, rh, ch, sum = 0;
    scanf("%d %d %d %d", &ri, &ci, &rh, &ch);
    if ((m - ri - rh) >= 0 && (n - ci - ch) >= 0)
    {
        for (int i = 0; i < rh; i++)
        {
            for (int j = 0; j < ch; j++)
            {
                sum += new_matrix[ri + i][ci + j];
            }
        }
        printf("%d\n", sum);
    }
    else
    {
        printf("NOT POSSIBLE\n");
    }

    // free pointers
    for (int i = 0; i < m; i++)
    {
        free(input_matrix[i]);
        free(new_matrix[i]);
    }
    free(input_matrix);
    free(new_matrix);
    return 0;
}