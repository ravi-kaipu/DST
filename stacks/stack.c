#include <stdio.h>
#include <stdlib.h>

typedef struct Stack {
    int top, capacity;
    int *elements;
} stack;

stack *create_stack(int stack_capacity) {
    stack *s = (stack *) malloc(sizeof(stack));
    s->top = - 1;
    s->capacity = stack_capacity;
    s->elements = (int *)malloc(stack_capacity*sizeof(int));
    return s;
}

int isFull(stack *s) {
    return s->top == s->capacity - 1;
}

int isEmpty(stack *s) {
    return s->top == -1;
}

void push(stack *s, int elem) {
    if (isFull(s))
        return;
    s->elements[++s->top] = elem;
    printf("%d enqueue to stack.\n", elem);
}

int pop(stack *s) {
    if (isEmpty(s))
        return -1;
    return s->elements[s->top--];
}

int peek(stack *s)
{
    if (isEmpty(s))
        return -1;
    return s->elements[s->top];
}


int main() {
    stack *s;
    int stack_size = 10;

    s = create_stack(stack_size);

    push(s, 10);
    push(s, 20);
    push(s, 30);

    printf("%d popped from stack\n", pop(s));

    return 0;
}