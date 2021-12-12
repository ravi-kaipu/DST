#include <stdio.h>
#include <stdlib.h>

typedef struct Queue {
    int front, rear, size, capacity;
    int *elements;
} queue;

queue *create_queue(int queue_capacity) {
    queue *q = (queue *) malloc(sizeof(queue));
    q->size = 0;
    q->front = 0;
    q->rear = queue_capacity - 1;
    q->capacity = queue_capacity;
    q->elements = (int *)malloc(queue_capacity*sizeof(int));
    return q;
}

int isFull(queue *q) {
    return q->size == q->capacity;
}

int isEmpty(queue *q) {
    return q->size == 0;
}

void enqueue(queue *q, int elem) {
    if (isFull(q))
        return;
    q->rear = (q->rear + 1) % q->capacity;
    q->elements[q->rear] = elem;
    q->size += 1;
    printf("%d enqueued to queue.\n", elem);
}

int dequeue(queue *q) {
    if (isEmpty(q))
        return -1;
    int elem = q->elements[q->front];
    q->front = (q->front + 1) % q->capacity;
    q->size -= 1;
    return elem;
}

int front(queue *q)
{
    if (isEmpty(q))
        return -1;
    return q->elements[q->front];
}

int rear(queue *q)
{
    if (isEmpty(q))
        return -1;
    return q->elements[q->rear];
}

int main() {
    queue *q;
    int queue_size = 10;

    q = create_queue(queue_size);

    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    enqueue(q, 40);

    printf("%d dequeued from queue\n\n", dequeue(q));

    printf("Front item is %d\n", front(q));
    printf("Rear item is %d\n", rear(q));

    return 0;
}