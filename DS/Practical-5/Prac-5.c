#include <stdio.h>
#include <string.h>

#define MAX_ACTIONS 10
#define MAX_STRING_LENGTH 50

typedef struct {
    char action[10];
    char text[MAX_STRING_LENGTH];
    int position;
} UndoAction;

typedef struct {
    UndoAction actions[MAX_ACTIONS];
    int top;
} UndoStack;

void pushAction(UndoStack *stack, const char *action, const char *text, int position) {
    if (stack->top >= MAX_ACTIONS - 1) {
        printf("Stack overflow. Cannot push any more actions.\n");
        return;
    }
    stack->top++;
    strcpy(stack->actions[stack->top].action, action);
    strcpy(stack->actions[stack->top].text, text);
    stack->actions[stack->top].position = position;
}

void popAction(UndoStack *stack) {
    if (stack->top == -1) {
        printf("Stack underflow. No actions to pop.\n");
        return;
    }
    UndoAction action = stack->actions[stack->top];
    stack->top--;
    printf("Action popped: %s '%s' at position %d\n", action.action, action.text, action.position);
}

void peekAction(const UndoStack *stack) {
    if (stack->top == -1) {
        printf("No actions to undo.\n");
        return;
    }
    UndoAction action = stack->actions[stack->top];
    printf("Next action to undo: '%s' at position %d\n", action.text, action.position);
}

int main() {
    UndoStack stack;
    stack.top = -1;

    printf("\n\n");
    pushAction(&stack, "insert", "I", 0);
    pushAction(&stack, "insert", "am", 2);
    pushAction(&stack, "insert", "Jatin", 5);
    pushAction(&stack, "insert", "Patel", 8);

    peekAction(&stack);

    popAction(&stack);

    printf("\nAfter popping:\n");
    peekAction(&stack);

    printf("Remaining actions in stack:\n");
    for (int i = 0; i <= stack.top; i++) {
        printf("Action %d: %s '%s' at position %d\n", i + 1, stack.actions[i].action, stack.actions[i].text, stack.actions[i].position);
    }

    return 0;
}
