#include <stdio.h>
#define MAX 100

char queue[MAX][50];
int front = -1, rear = -1;

void enqueue(char doc[]) {
    if (rear == MAX-1) return;
    if (front == -1) front = 0;
    strcpy(queue[++rear], doc);
}

void dequeue() {
    if (front == -1 || front > rear) return;
    front++;
}

void display() {
    if (front == -1) {
        printf("Queue empty\n");
        return;
    }
    printf("Pending: ");
    for (int i = front; i <= rear; i++)
        printf("%s ", queue[i]);
    printf("\n");
}

int main() {
    enqueue("Doc1.pdf");
    enqueue("Doc2.pdf");
    printf("After adding 2 docs:\n");
    display();
    dequeue();
    printf("After printing 1 doc:\n");
    display();
    return 0;
}