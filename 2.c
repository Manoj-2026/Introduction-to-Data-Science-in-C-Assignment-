#include <stdio.h>
#define MAX 100

char stack[MAX];
int top = -1;

void push(char c) { if (top < MAX-1) stack[++top] = c; }
char pop() { return (top >= 0) ? stack[top--] : '\0'; }
int isEmpty() { return top == -1; }

int isBalanced(char *expr) {
    for (int i = 0; expr[i]; i++) {
        if (expr[i] == '(') push('(');
        else if (expr[i] == ')') {
            if (isEmpty() || pop() != '(') return 0;
        }
    }
    return isEmpty();
}

int main() {
    char expr[] = "(A+B)*(C-D)";
    printf("Input: %s\n", expr);
    printf("Output: %s\n", isBalanced(expr) ? "Balanced Expression" : "Unbalanced");
    return 0;
}