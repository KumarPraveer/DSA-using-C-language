#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
} *head;

void insertLast(struct Node *p, int x)
{
    struct Node *temp;
    temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = NULL;
    if (!head)
    {
        head = temp;
    }
    else
    {
        while (p->next)
            p = p->next;
        p->next = temp;
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

int countNode(struct Node *p)
{
    int counter = 0;
    while (p)
    {
        counter++;
        p = p->next;
    }
    return counter;
}

int main()
{
    insertLast(head, 1);
    insertLast(head, 2);
    insertLast(head, 3);
    insertLast(head, 4);
    insertLast(head, 5);
    struct Node *x = head;
    for (int i = 0; i < countNode(head) / 2; i++)
    {
        x = x->next;
    }
    printf("%d ", x->data);
    return 0;
}