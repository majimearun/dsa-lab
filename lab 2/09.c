#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Info_t
{
    char *email;
    char *branch;
    char *id;
};

typedef struct Info_t Info;

void gen_id(Info *info)
{

    char *id = (char *)malloc(13 * sizeof(char));
    int i = 0;
    for (int j = 1; j < 5; ++j)
    {
        id[i++] = info->email[j];
    }
    if (strcmp(info->branch, "CS") == 0)
    {
        id[i++] = 'A';
        id[i++] = '7';
    }
    else if (strcmp(info->branch, "ECE") == 0)
    {
        id[i++] = 'A';
        id[i++] = 'A';
    }
    else if (strcmp(info->branch, "EEE") == 0)
    {
        id[i++] = 'A';
        id[i++] = '3';
    }
    id[i++] = 'P';
    id[i++] = 'S';
    for (int j = 5; j < 9; ++j)
    {
        id[i++] = info->email[j];
    }
    id[i++] = 'H';
    info->id = id;
}

int main()
{
    Info *info = (Info *)malloc(sizeof(Info));
    info->email = (char *)malloc(100 * sizeof(char));
    info->branch = (char *)malloc(100 * sizeof(char));
    info->id = (char *)malloc(13 * sizeof(char));
    scanf("%s", info->email);
    scanf("%s", info->branch);
    gen_id(info);
    printf("%s\n", info->id);
    return 0;
}