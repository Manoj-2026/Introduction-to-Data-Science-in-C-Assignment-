#include <stdio.h>
#define MAX 5

int queue[MAX], front = -1, rear = -1;

void enqueue(int x) {
    if ((rear+1)%MAX == front) {
        printf("Full\n"); return;
    }
    if (front == -1) front = 0;
    queue[++rear] = x;
}

int dequeue() {
    if (front == -1 || front > rear) {
        printf("Empty\n"); return -1;
    }
    return queue[front++];
}

int peek() {
    if (front == -1 || front > rear) {
        printf("Empty\n"); return -1;
    }
    return queue[front];
}

void display() {
    if (front == -1 || front > rear) {
        printf("Empty\n"); return;
    }
    printf("Queue: ");
    for (int i = front; i <= rear; i++)
        printf("%d ", queue[i]);
    printf("\n");
}

int main() {
    int ch, x;
    while (1) {
        printf("\n1.Enq 2.Deq 3.Peek 4.Disp 5.Exit: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1: printf("Data: "); scanf("%d", &x); enqueue(x); break;
            case 2: dequeue(); break;
            case 3: printf("Front: %d\n", peek()); break;
            case 4: display(); break;
            case 5: return 0;
        }
    }
}   