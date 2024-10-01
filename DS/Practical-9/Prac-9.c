#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void append(struct Node **head_ref, int data)
{
    struct Node *newNode = createNode(data);
    struct Node *temp = *head_ref;

    if (*head_ref == NULL)
    {
        *head_ref = newNode;
        return;
    }

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
}

void displayList(struct Node *head)
{
    struct Node *temp = head;
    printf("NULL");

    while (temp != NULL)
    {
        printf(" > %d", temp->data);
        temp = temp->next;
    }

    printf(" > NULL\n");
}

int main()
{
    struct Node *head = NULL;
    int numNodes, data;

    printf("Enter the number of nodes: ");
    scanf("%d", &numNodes);

    for (int i = 0; i < numNodes; i++)
    {
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &data);
        append(&head, data);
    }

    displayList(head);

    return 0;
}
