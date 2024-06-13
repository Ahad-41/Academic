#include <stdio.h>
#define N 100

typedef struct {
    int head, tail;
    int data[N];
} queue;

void enqueue(queue *q, int item) {
    if ((q->tail + 1) % (N+1) == q->head) {
        printf("Queue is full\n");
        return;
    }
    q->data[q->tail] = item;
    q->tail = (q->tail + 1) % (N+1);
}

int dequeue(queue * q) {
    int item;
    if (q->tail == q->head) {
        printf("Queue is empty\n");
        return -1;
    }

    item = q->data[q->head];
    q->head = (q->head + 1) % (N+1);
    return item;
}


int main()
{
    queue q;
    q.head = 0;
    q.tail = 0;

    enqueue(&q, 1);
    printf("tail = %d\n", q.tail);
    enqueue(&q, 2);
    printf("tail = %d\n", q.tail);
    enqueue(&q, 3);
    printf("tail = %d\n", q.tail);
    enqueue(&q, 4);
    printf("tail = %d\n", q.tail);
    enqueue(&q, 5);
    printf("tail = %d\n", q.tail);
    enqueue(&q, 6);
    printf("tail = %d\n", q.tail);

    printf("beginning head = %d\n", q.head);
    
    int item = dequeue(&q);
    printf("item = %d,  head = %d\n", item, q.head);
    item = dequeue(&q);
    printf("item = %d,  head = %d\n", item, q.head);
    item = dequeue(&q);
    printf("item = %d,  head = %d\n", item, q.head);
    item = dequeue(&q);
    printf("item = %d,  head = %d\n", item, q.head);
    item = dequeue(&q);
    printf("item = %d,  head = %d\n", item, q.head);
    item = dequeue(&q);
    printf("item = %d,  head = %d\n", item, q.head);
}