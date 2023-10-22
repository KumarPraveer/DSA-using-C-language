#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
} *first;

void insert_last(struct Node *p, int x)
{
    struct Node *temp;
    temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = NULL;
    temp->prev = NULL;
    if (!p)
    {
        first = temp;
    }
    else
    {
        while (p->next != NULL)
            p = p->next;
        p->next = temp;
        temp->prev = p;
    }
}

void insert_first(struct Node *p, int x)
{
    struct Node *temp;
    temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = NULL;
    temp->prev = NULL;
    if (!p)
    {
        first = temp;
    }
    else
    {
        temp->next = first;
        first->prev = temp;
        first = temp;
    }
}

void insert_at_given_pos(struct Node *p, int x, int pos)
{
    struct Node *temp;
    temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = NULL;
    temp->prev = NULL;
    if (pos == 1)
    {
        temp->next = first;
        first->prev = temp;
        first = temp;
    }
    else
    {
        for (int i = 1; i < pos; i++)
            p = p->next;
        temp->next = p;
        temp->prev = p->prev;
        p->prev->next = temp;
        p->prev = temp;
    }
}

void display(struct Node *p)
{
    while (p)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}

void delete_first(struct Node *p)
{
    struct Node *temp;
    temp = p;
    first = first->next;
    first->prev = NULL;
    free(temp);
}

void delete_last(struct Node *p)
{
    struct Node *temp;
    while (p->next)
        p = p->next;
    p->prev->next = NULL;
    free(p);
}

void delete_at_given_pos(struct Node *p, int pos)
{
    struct Node *temp = p;
    if (pos == 1)
    {
        first = first->next;
        first->prev->next = NULL;
        free(p);
    }
    else
    {
        for (int i = 1; i < pos; i++)
        {
            p = p->next;
        }
         
    }
}

int main()
{
    insert_last(first, 1);
    insert_last(first, 2);
    insert_last(first, 3);
    insert_last(first, 5);
    insert_last(first, 6);
    insert_last(first, 7);
    insert_at_given_pos(first, 4, 4);
    // delete_first(first);
    delete_at_given_pos(first, 1);

    display(first);
    return 0;
}