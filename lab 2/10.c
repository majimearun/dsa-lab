#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Country_t
{
    char *name;
    int gold;
    int silver;
    int bronze;
};

typedef struct Country_t Country;

void swap(Country **countries, int i, int j)
{
    Country *temp;
    temp = countries[j];
    countries[j] = countries[i];
    countries[i] = temp;
}

void sort_countries(Country **countries, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            Country *c1 = countries[j];
            Country *c2 = countries[j + 1];
            if (c1->gold < c2->gold)
            {
                swap(countries, j, j + 1);
            }
            else if (c1->gold == c2->gold)
            {
                if (c1->silver < c2->silver)
                {
                    swap(countries, j, j + 1);
                }
                else if (c1->silver == c2->silver)
                {
                    if (c1->bronze < c2->bronze)
                    {
                        swap(countries, j, j + 1);
                    }
                }
            }
        }
    }
}

Country **get_countries(int n)
{
    Country **countries = (Country **)malloc(n * sizeof(Country *));

    for (int i = 0; i < n; i++)
    {
        countries[i] = (Country *)malloc(sizeof(Country));
        countries[i]->name = (char *)malloc(100 * sizeof(char));
        scanf("%s", countries[i]->name);
        scanf("%d", &countries[i]->gold);
        scanf("%d", &countries[i]->silver);
        scanf("%d", &countries[i]->bronze);
    }

    return countries;
}

int main()
{
    int n;
    scanf("%d", &n);

    Country **countries = get_countries(n);
    sort_countries(countries, n);

    for (int i = 0; i < n; i++)
    {
        printf("%s\n", countries[i]->name);
    }
    return 0;
}