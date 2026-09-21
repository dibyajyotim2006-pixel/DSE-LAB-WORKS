#include <stdio.h>
#include <stdbool.h>

#define MAX 5

typedef struct {
    int items[MAX];
    int front;
    int rear;
} CircularQueue;

void initQueue(CircularQueue *q) {
    q->front = -1;
    q->rear = -1;
}

bool isFull(CircularQueue *q) {
    return (q->rear + 1) % MAX == q->front;
}

bool isEmpty(CircularQueue *q) {
    return q->front == -1;
}

void enqueue(CircularQueue *q, int value) {
    if (isFull(q)) {
        printf("Circular Queue is Full! Cannot enqueue %d\n", value);
        return;
    }
    if (isEmpty(q)) {
        q->front = 0;
        q->rear = 0;
    } else {
        q->rear = (q->rear + 1) % MAX;
    }
    q->items[q->rear] = value;
    printf("Enqueued %d into circular queue\n", value);
}

int dequeue(CircularQueue *q) {
    if (isEmpty(q)) {
        printf("Circular Queue is Empty! Cannot dequeue\n");
        return -1;
    }
    int value = q->items[q->front];
    if (q->front == q->rear) {
        q->front = -1;
        q->rear = -1;
    } else {
        q->front = (q->front + 1) % MAX;
    }
    printf("Dequeued %d from circular queue\n", value);
    return value;
}

void display(CircularQueue *q) {
    if (isEmpty(q)) {
        printf("Circular Queue is Empty\n");
        return;
    }
    printf("Circular Queue elements: ");
    int i = q->front;
    while (1) {
        printf("%d ", q->items[i]);
        if (i == q->rear) break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    CircularQueue q;
    initQueue(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    enqueue(&q, 50);
    display(&q);

    enqueue(&q, 60);

    dequeue(&q);
    dequeue(&q);
    display(&q);

    enqueue(&q, 60);
    enqueue(&q, 70);
    display(&q);

    return 0;
}
