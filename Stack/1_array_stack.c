#include <stdio.h>

#define STACK_MAX 10
int stack[STACK_MAX];

int top = -1;

int isEmpty()
{
    return (top == -1);
}

int isFull()
{
    return (top == STACK_MAX - 1);
}


int pop()
{
    int v = 0;
    if(isEmpty() != 1)
    {
        v = stack[top];
        top--;
    }
    return v;
}

void push(int n)
{
    if(isFull() != 1)
    {
        top++;
        stack[top] = n;
    }
    return;
}

int main()
{
    push(1);
    push(2);
    push(3);

    printf("%d\n", pop());
    printf("%d\n", pop());
    printf("%d\n", pop());
}