#include <stdio.h>

void push(char stack[], int *top, char ch) {
    stack[++(*top)] = ch;
}

char pop(char stack[], int *top) {
    return stack[(*top)--];
}

int main() {
    char infix[50], postfix[50], stack[50];
    int top = -1, i = 0, j = 0;

    printf("Enter an infix expression: ");
    scanf("%s", infix);

    while (infix[i] != '\0') {
        if (infix[i] == '(') {
            push(stack, &top, infix[i]);
        } else if (infix[i] == ')') {
            while (stack[top] != '(') {
                postfix[j++] = pop(stack, &top);
            }
            top--; 
        } else if (infix[i] == '+' || infix[i] == '-') {
            while (top != -1 && (stack[top] == '+' || stack[top] == '-' || stack[top] == '*' || stack[top] == '/')) {
                postfix[j++] = pop(stack, &top);
            }
            push(stack, &top, infix[i]);
        } else if (infix[i] == '*' || infix[i] == '/') {
            while (top != -1 && (stack[top] == '*' || stack[top] == '/')) {
                postfix[j++] = pop(stack, &top);
            }
            push(stack, &top, infix[i]);
        } else {
            postfix[j++] = infix[i]; // Add operand directly to postfix
        }
        i++;
    }

    while (top != -1) {
        postfix[j++] = pop(stack, &top);
    }

    postfix[j] = '\0'; // Null-terminate the postfix expression

    printf("Postfix expression: %s\n", postfix);

    return 0;
}
