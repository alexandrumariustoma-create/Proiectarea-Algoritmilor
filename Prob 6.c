#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node;

void reverseIterative(node** head) {
    node* prev = NULL;
    node* current = *head;
    node* next = NULL;

    while (current != NULL) {
        next = current->next;

        current->next = prev;

        prev = current;
        current = next;
    }

    *head = prev;
}

node* reverseRecursive(node* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    node* rest = reverseRecursive(head->next);

    head->next->next = head;

    head->next = NULL;

    return rest;
}

node* createNode(int data) {
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertlast(node** head, int data) {
    node* newNode = createNode(data);

    if (*head == NULL) {
        *head = newNode;
        return;
    }
    node* temp = *head;
    while (temp -> next != NULL) {
        temp = temp -> next;
    }
    temp -> next = newNode;
}

void printlist(node* head) {
    node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp -> data);
        temp = temp -> next;
    }
    printf("\n");
}

int main() {
    node* head = NULL;
    int n, val;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        insertlast(&head, val);
    }
    printlist(head);
    reverseIterative(&head);
    printlist(head);
    head = reverseRecursive(head);
    printlist(head);
}