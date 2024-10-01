#include <stdio.h>
#include <stdlib.h>

#define MAX 9

int stack[MAX];
int top = -1;

void push(int num) {
    if (top == MAX - 1) {
        printf("\nStack is full, so no elements will be added\n\n");
    } else {
        stack[++top] = num;
        printf("Element %d inserted successfully\n", num);
    }
}

void pop() {
    if (top == -1) {
        printf("\nThe Stack is already empty.\n\n");
    } else {
        int x = stack[top--];
        printf("Element deleted successfully: %d\n", x);
    }
}

void display() {
    if (top == -1) {
        printf("\nThe Stack is already empty.\n\n");
    } else {
        printf("Stack elements are as follows:\n");
        for (int i = 0; i <= top; i++) {
            printf("%d\n", stack[i]);
        }
    }
}

int main() {
    push(1);
    push(4);
    push(3);
    push(6);
    push(2);
    pop();
    pop();
    push(7);
    push(8);
    push(5);
    push(10);
    push(9);

    printf("====================================\n");
    printf("\nFinal stack state:\n");
    display();

    return 0;
}
