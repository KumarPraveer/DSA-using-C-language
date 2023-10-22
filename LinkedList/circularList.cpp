#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
} *head;

int number_of_nodes(struct Node *p)
{
    int count = 0;
    while (p->next != head)
    {
        count++;
        p = p->next;
    }
    return count;
}

void insert_last(struct Node *p, int x)
{
    struct Node *temp;
    temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = NULL;
    if (!head)
    {
        head = temp;
        head->next = head;
    }
    else
    {
        while (p->next != head)
            p = p->next;
        p->next = temp;
        temp->next = head;
    }
}

void display_list(struct Node *p)
{
    do
    {
        printf("%d ", p->data);
        p = p->next;
    } while (p != head);
}

void insert_start(struct Node *p, int x)
{
    struct Node *temp;
    temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = NULL;
    while (p->next != head)
    {
        p = p->next;
    }
    p->next = temp;
    temp->next = head;
    head = temp;
}

void insert_at_given_pos(struct Node *p, int pos, int x)
{
    struct Node *temp, *prev;
    temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = NULL;
    if (pos == 1)
    {
        while (p->next != head)
        {
            p = p->next;
        }
        p->next = temp;
        temp->next = head;
        head = temp;
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

void delete_head(struct Node *p)
{
    struct Node *temp;
    temp = head;
    while (p->next != head)
        p = p->next;
    head = head->next;
    p->next = head;
    free(temp);
}

void deleteLast(struct Node *p)
{
    struct Node *temp;
    while (p->next != head)
    {
        temp = p;
        p = p->next;
    }
    temp->next = head;
    free(p);
}

int main()
{
    insert_last(head, 1);
    insert_last(head, 2);
    insert_last(head, 3);
    insert_last(head, 4);
    insert_last(head, 5);
    delete_head(head);
    display_list(head);

    return 0;
}