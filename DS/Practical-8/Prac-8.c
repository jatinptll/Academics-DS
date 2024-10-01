#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

int main()
{
    int n, data;
    struct Node *head = NULL, *temp = NULL, *newNode = NULL;

    printf("Input the number of nodes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        newNode = (struct Node *)malloc(sizeof(struct Node));
        printf("Input data for node %d: ", i + 1);
        scanf("%d", &newNode->data);
        newNode->next = NULL;

        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            temp->next = newNode;
        }
        temp = newNode;
    }

    printf("Data entered in the list:\n");
    temp = head;
    while (temp)
    {
        printf("Data = %d\n", temp->data);
        temp = temp->next;
    }

    return 0;
}
