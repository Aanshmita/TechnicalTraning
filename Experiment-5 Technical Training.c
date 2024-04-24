#include <stdio.h>
#include <stdlib.h>

// Define the structure for Node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new Node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert at the head of the linked list
void insertAtHead(struct Node** head, struct Node** tail, int data) {
    struct Node* newNode = createNode(data);
    
    newNode->next = *head;
    *head = newNode;
    if (*tail == NULL)
        *tail = *head;
}

// Function to print the linked list
void print(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main() {
    struct Node* head = NULL;
    struct Node* tail = NULL;

    printf("Enter the numbers to be inserted at the head:\n");
    for (int i = 0; i < 5; i++) {
        int val;
        scanf("%d", &val);
        insertAtHead(&head, &tail, val);
    }

    printf("Linked list elements:\n");
    print(head);
    printf("\n");

    return 0;
}
