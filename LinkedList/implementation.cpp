#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
} *first;

// singly linked list insertion
void insertLast(struct Node *p, int x)
{
    struct Node *temp;
    temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = NULL;
    if (!p)
    {
        first = temp;
    }
    else
    {
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = temp;
    }
}

void insert_at_beg(struct Node *p, int x)
{
    struct Node *temp;
    temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = NULL;
    if (!first)
    {
        first = temp;
    }
    else
    {
        temp->next = first;
        first = temp;
    }
}

int countNode(struct Node *p)
{
    int count = 0;
    while (p)
    {
        count++;
        p = p->next;
    }
    return count;
}

void insert_at_given_pos(struct Node *p, int pos, int x)
{
    struct Node *temp, *prev;
    temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = NULL;
    if (pos > 0 && pos <= countNode(p))
    {
        if (pos == 1)
        {
            temp->next = first;
            first = temp;
        }
        else
        {
            for (int i = 1; i < pos; i++)
            {
                prev = p;
                p = p->next;
            }
            temp->next = p;
            prev->next = temp;
        }
    }
    else
    {
        printf("Invalid Position!\n");
    }
}

void delete_first(struct Node *p)
{
    struct Node *temp;
    if (!p)
    {
        printf("Empty List");
    }
    else
    {
        temp = first;
        first = first->next;
        free(temp);
    }
}

void delete_last(struct Node *p)
{
    struct Node *temp;
    while (p->next != NULL)
    {
        temp = p;
        p = p->next;
    }
    temp->next = NULL;
    free(p);
}

void delete_at_given_pos(struct Node *p, int pos)
{
    struct Node *temp;
    if (pos == 1)
    {
        temp = first;
        first = first->next;
        free(temp);
    }
    else
    {
        for (int i = 1; i < pos; i++)
        {
            temp = p;
            p = p->next;
        }
        temp->next = p->next;
        free(p);
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

int isSorted(struct Node *p)
{
    int prevData = p->data;
    while (p)
    {
        if (p->data > prevData)
        {
            return false;
        }
        prevData = p->data;
        p = p->next;
    }
    return true;
}

void remove_duplicate(struct Node *p)
{
    struct Node *temp, *q = p->next;
    while (q)
    {
        if (p->data == q->data)
        {
            temp = q;
            q = q->next;
            p->next = q;
            free(temp);
        }
        else
        {
            p = q;
            q = q->next;
        }
    }
}

void reverse_list(struct Node *p)
{
    struct Node *q = NULL, *r = NULL;
    while (p)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    first = q;
}

int main()
{
    insertLast(first, 1);
    insertLast(first, 2);
    insertLast(first, 3);
    insertLast(first, 4);
    insertLast(first, 5);
    reverse_list(first);
    display(first);
    return 0;
}