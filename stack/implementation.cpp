#include <iostream>
using namespace std;

struct Stack
{
    int size;
    int top;
    int *arr;
};

void createStack(struct Stack *st, int size)
{
    st->size = size;
    st->arr = (int *)malloc(st->size * (sizeof(int)));
    st->top = -1;
}

void push(struct Stack *st, int data)
{
    if (st->top == st->size - 1)
        printf("Stack Overflowed!\n");
    else
    {
        st->top += 1;
        st->arr[st->top] = data;
    }
}

int pop(struct Stack *st)
{
    int x;
    if (st->top == -1)
        printf("Stack Underflow!");
    else
    {
        x = st->arr[st->top--];
    }
    return x;
}

int peek(struct Stack st, int index)
{
    int x = -1;
    if (st.top - index + 1 < 0)
        printf("Invalid Index!");
    x = st.arr[st.top - index + 1];
    return x;
}

void displayStack(struct Stack st)
{
    while (st.top != -1)
    {
        printf("%d ", st.arr[st.top]);
        st.top--;
    }
}

int main()
{
    struct Stack *s;
    createStack(s, 5);
    push(s, 1);
    push(s, 2);
    push(s, 3);
    push(s, 4);
    push(s, 5);
    displayStack(*s);
    pop(s);
    pop(s);
    pop(s);
    printf("\n");
    displayStack(*s);
    printf("\n\n");
    printf("%d ", peek(*s, 0));
    return 0;
}