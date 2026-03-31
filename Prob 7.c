#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node;

node* createNode(int data) {
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
void insertEnd(node** head, int data) {
    node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void printList(node* head) {
    if (head == NULL) {
        printf("Lista este goala.\n");
        return;
    }
    node* temp = head;
    while (temp != NULL) {
        printf("%d", temp->data);
        temp = temp->next;
    }
}

void concatenate(node** head1, node** head2) {
    if (*head1 == NULL) {
        *head1 = *head2;
        *head2 = NULL;
        return;
    }

    if (*head2 == NULL) {
        return;
    }

    node* temp = *head1;

    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = *head2;
    *head2 = NULL;
}

int main() {
    node* lista1 = NULL;
    node* lista2 = NULL;
    int n, val;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        insertEnd(&lista1, val);
    }
    printList(lista1);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        insertEnd(&lista2, val);
    }
    printList(lista2);
    concatenate(&lista1, &lista2);
    printList(lista1);
}