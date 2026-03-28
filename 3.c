#include <stdio.h>
#define MAX 100

int stack[MAX];
int top = -1;

void push(int x) { if (top < MAX-1) stack[++top] = x; }
int pop() { return (top >= 0) ? stack[top--] : -1; }
int peek() { return (top >= 0) ? stack[top] : -1; }

void nextGreater(int arr[], int n) {
    int result[MAX];
    top = -1;
    
    for (int i = n-1; i >= 0; i--) {
        while (top >= 0 && peek() <= arr[i])
            pop();
        result[i] = (top == -1) ? -1 : peek();
        push(arr[i]);
    }
    
    for (int i = 0; i < n; i++)
        printf("%d → %d\n", arr[i], result[i]);
}

int main() {
    int arr[] = {4, 5, 2, 10, 8};
    printf("Input: 4 5 2 10 8\n");
    printf("Output:\n");
    nextGreater(arr, 5);
    return 0;
}