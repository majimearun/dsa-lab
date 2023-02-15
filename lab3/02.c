#include <stdio.h>
#include <stdlib.h>

struct Node_t
{
    int data;
    struct Node_t *prev;
    struct Node_t *next;
};

typedef struct Node_t Node;

Node *create_node(int val)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->next = NULL;
    node->prev = NULL;
    node->data = val;
    return node;
}

Node *add_to_list(Node *head, int val)
{
    Node *node = create_node(val);
    if (head == NULL)
    {
        return node;
    }
    else
    {
        while (head->next != NULL)
        {
            head = head->next;
        }
        head->next = node;
        node->prev = head;
        return node;
    }
}

Node *read_list()
{
    int n, d;
    Node *head = NULL;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &d);
        if (head == NULL)
        {
            head = add_to_list(head, d);
        }
        else
        {
            add_to_list(head, d);
        }
    }
    return head;
}

void print_list(Node *head)
{
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

void print_curr(Node *curr)
{
    if (curr == NULL)
    {
        printf("No song in playlist\n");
    }
    else
    {
        printf("song: %d\n", curr->data);
    }
}

Node *play_next(Node *curr)
{
    if (curr != NULL)
    {
        if (curr->next != NULL)
        {
            return curr->next;
        }
        else
        {
            return curr;
        }
    }
    else
    {
        return curr;
    }
}

Node *play_prev(Node *curr)
{
    if (curr != NULL)
    {
        if (curr->prev != NULL)
        {
            return curr->prev;
        }
        else
        {
            return curr;
        }
    }
    else
    {
        return curr;
    }
}

Node *exists_in_playlist(Node *head, int song)
{
    while (head != NULL)
    {
        if (head->data == song)
        {
            return head;
        }
        head = head->next;
    }
    return NULL;
}

Node *add_to_next(Node *head, Node *curr, int song)
{
    if (head == NULL)
    {
        Node *song_node = create_node(song);
        return song_node;
    }

    Node *exists = exists_in_playlist(head, song);

    if (exists == NULL)
    {
        Node *song_node = create_node(song);
        song_node->next = curr->next;
        song_node->prev = curr;
        if (curr->next != NULL)
        {
            curr->next->prev = song_node;
        }
        else
        {
            song_node->next = NULL;
        }
        curr->next = song_node;
        return head;
    }

    else
    {
        if (exists->next != NULL)
        {
            exists->next->prev = exists->prev;
            if (exists->prev != NULL)
            {
                exists->prev->next = exists->next;
            }
            else
            {
                head = exists->next;
            }
        }
        else
        {
            exists->prev->next = NULL;
        }
        exists->next = curr->next;
        exists->prev = curr;
        if (curr->next != NULL)
        {
            curr->next->prev = exists;
        }
        else
        {
            exists->next = NULL;
        }
        curr->next = exists;
        return head;
    }
}

Node *menu(Node *head, Node *curr)
{
    int input = 0, song = 0;
    while (input != 5)
    {
        scanf("%d", &input);
        switch (input)
        {
        case 1:
            scanf("%d", &song);
            if (head == NULL)
            {
                head = add_to_list(head, song);
                curr = head;
            }
            else
            {
                add_to_list(head, song);
            }
            break;
        case 2:
            print_curr(curr);
            break;
        case 3:
            curr = play_next(curr);
            break;
        case 4:
            curr = play_prev(curr);
            break;
        case 6:
            scanf("%d", &song);
            head = add_to_next(head, curr, song);
            break;
        case 5:
            break;
        default:
            break;
        }
    }
    return head;
}

int main()
{
    Node *head = read_list();
    Node *curr = head;
    menu(head, curr);
    return 0;
}