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

int check_sub(int **matrix1, int **matrix2, int m, int n, int ri, int ci, int rh, int ch)
{
    if ((m - ri - rh) >= 0 && (n - ci - ch) >= 0)
    {
        for (int i = 0; i < rh; i++)
        {
            for (int j = 0; j < ch; j++)
            {
                if (matrix2[i][j] != matrix1[ri + i][ci + j])
                {
                    return 0;
                }
            }
        }
        return 1;
    }
    else
    {
        return 0;
    }
}

int in_row_or_column(int *rows, int *columns, int p, int q, int elem)
{
    for (int i = 0; i < q; i++)
    {
        if (elem == columns[i])
        {
            return i + 1;
        }
    }
    for (int i = 0; i < p; i++)
    {
        if (elem == rows[i])
        {
            return -(i + 1);
        }
    }
    return 0;
}

int main()
{
    int m, n, p, q;
    scanf("%d %d", &m, &n);
    int **matrix1 = get_matrix(m, n, 0);
    scanf("%d %d", &p, &q);
    int **matrix2 = get_matrix(p, q, 0);
    int sub = 0;
    int partial = 0;
    int matches;
    int row_match = 0;
    int *rows = (int *)malloc(p * sizeof(int));
    for (int i = 0; i < p; i++)
    {
        rows[i] = matrix2[i][0];
    }
    int column_match = 0;
    int *columns = (int *)malloc(q * sizeof(int));
    for (int i = 0; i < q; i++)
    {
        columns[i] = matrix2[0][i];
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix1[i][j] == matrix2[0][0])
            {
                sub = check_sub(matrix1, matrix2, m, n, i, j, p, q);
                if (sub)
                {
                    printf("YES\n");
                    exit(0);
                }
            }

            matches = in_row_or_column(rows, columns, p, q, matrix1[i][j]);

            if (matches == 1)

            {
                row_match = 0;
                int **row = (int **)malloc(q * sizeof(int));
                row[0] = (int *)malloc(sizeof(int));
                for (int i = 0; i < q; i++)
                {
                    row[0][i] = matrix2[row_match][i];
                }
                partial = partial || check_sub(matrix1, row, m, n, i, j, 1, q);
            }
            if (matches > 0)
            {
                column_match = matches - 1;
                int **column = (int **)malloc(p * sizeof(int));
                for (int i = 0; i < p; i++)
                {
                    column[i] = (int *)malloc(1 * sizeof(int));
                    column[i][0] = matrix2[i][column_match];
                }
                partial = partial || check_sub(matrix1, column, m, n, i, j, p, 1);
            }
            else if (matches < 0)
            {
                row_match = -1 * (matches + 1);
                int **row = (int **)malloc(q * sizeof(int));
                row[0] = (int *)malloc(sizeof(int));
                for (int i = 0; i < q; i++)
                {
                    row[0][i] = matrix2[row_match][i];
                }
                partial = partial || check_sub(matrix1, row, m, n, i, j, 1, q);
            }
        }
    }
    if (partial)
    {
        printf("PARTIAL\n");
    }
    else
    {
        printf("NO\n");
    }
    // TODO: free pointers
    return 0;
}