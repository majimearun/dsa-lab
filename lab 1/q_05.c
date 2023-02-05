#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _OPEN_SYS_ITOA_EXT

void create_spiral(int **matrix, int n, int *done, int r, int c, int num, int count, int max, int rep_count)
{
    // printf("left: %d\nup: %d\nright: %d\ndown: %d\n", done[0], done[1], done[2], done[3]);
    if (num == 0)
    {
        return;
    }
    if (done[0])
    {
        if (done[1])
        {
            if (done[2])
            {
                if (done[3])
                {
                    done[0] = done[1] = done[2] = done[3] = 0;
                    create_spiral(matrix, n, done, r, c, num, count, max, rep_count);
                }
                else
                {
                    // printf("%d %d\n", r, c);
                    matrix[r][c] = num;
                    count++;
                    if (count == max)
                    {
                        done[3] = 1;
                        rep_count--;
                        // -1 is for -
                        matrix[r][c - 1] = -1;
                        if (!rep_count)
                        {
                            create_spiral(matrix, n, done, r, c - 2, num - 2, 0, max - 1, 2);
                        }
                        else
                        {
                            create_spiral(matrix, n, done, r, c - 2, num - 2, 0, max, rep_count);
                        }
                    }
                    else
                    {
                        // -2 is for |
                        matrix[r + 1][c] = -2;
                        create_spiral(matrix, n, done, r + 2, c, num - 2, count, max, rep_count);
                    }
                }
            }
            else
            {
                // printf("%d %d\n", r, c);
                matrix[r][c] = num;
                count++;
                if (count == max)
                {
                    done[2] = 1;
                    rep_count--;
                    // -2 is for |
                    if (num != 2)
                    {
                        matrix[r + 1][c] = -2;
                    }

                    if (!rep_count)
                    {
                        create_spiral(matrix, n, done, r + 2, c, num - 2, 0, max - 1, 2);
                    }
                    else
                    {
                        create_spiral(matrix, n, done, r + 2, c, num - 2, 0, max, rep_count);
                    }
                }
                else
                {
                    // -1 is for -
                    matrix[r][c + 1] = -1;
                    create_spiral(matrix, n, done, r, c + 2, num - 2, count, max, rep_count);
                }
            }
        }
        else
        {
            // printf("%d %d\n", r, c);
            matrix[r][c] = num;
            count++;
            if (count == max)
            {
                done[1] = 1;
                rep_count--;
                // -1 is for -
                matrix[r][c + 1] = -1;
                if (!rep_count)
                {
                    create_spiral(matrix, n, done, r, c + 2, num - 2, 0, max - 1, 2);
                }
                else
                {
                    create_spiral(matrix, n, done, r, c + 2, num - 2, 0, max, rep_count);
                }
            }
            else
            {
                // -2 is for |
                matrix[r - 1][c] = -2;
                create_spiral(matrix, n, done, r - 2, c, num - 2, count, max, rep_count);
            }
        }
    }
    else
    {
        // printf("%d %d\n", r, c);
        matrix[r][c] = num;
        count++;
        if (count == max)
        {
            done[0] = 1;
            rep_count--;
            // -2 is for |
            if (num != 2)
            {
                matrix[r - 1][c] = -2;
            }
            if (!rep_count)
            {
                create_spiral(matrix, n, done, r - 2, c, num - 2, 0, max - 1, 2);
            }
            else
            {
                create_spiral(matrix, n, done, r - 2, c, num - 2, 0, max, rep_count);
            }
        }
        else
        {
            // -1 is for -
            matrix[r][c - 1] = -1;
            create_spiral(matrix, n, done, r, c - 2, num - 2, count, max, rep_count);
        }
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    int **matrix = (int **)malloc(((2 * n) - 1) * sizeof(int *));
    for (int i = 0; i < (2 * n) - 1; i++)
    {
        matrix[i] = (int *)malloc(((2 * n) - 1) * sizeof(int));
    }
    for (int i = 0; i < (2 * n) - 1; i++)
    {
        for (int j = 0; j < (2 * n) - 1; j++)
        {
            matrix[i][j] = 0;
        }
    }
    // format: left, up, right, down
    int done[] = {0, 0, 0, 0};
    int start = (2 * n) - 2, end = (2 * n) - 2, reps = 1;
    if(n%2 == 0){
        done[0] = done[1] = 1;
        start = end = 0;
        reps = 2;
    }

    create_spiral(matrix, n, done, start, end, 2 * (n * n), 0, n, reps);

    for (int i = 0; i < (2 * n) - 1; i++)
    {
        for (int j = 0; j < (2 * n) - 1; j++)
        {
            if (matrix[i][j] > 0)
            {
                printf(" %3d ", matrix[i][j]);
            }
            else if (matrix[i][j] == 0)
            {
                printf("     ");
            }
            else
            {
                char dash = matrix[i][j] == -1 ? '-' : '|';
                printf("  %c  ", dash);
            }
        }
        printf("\n");
    }
}