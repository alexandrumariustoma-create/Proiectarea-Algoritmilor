#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
    struct node *prev;
} node;

node* createnode(int data) {
    node* newnode = (node*)malloc(sizeof(node));
    newnode->data = data;
    newnode->next = NULL;
    newnode->prev = NULL;
    return newnode;
}

void insertlast(node** head, int data) {
    node* newnode = createnode(data);

    if (*head == NULL) {
        *head = newnode;
        return;
    }

    node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newnode;
    newnode->prev = temp;
}

void printlist(node* head) {
    node* temp = head;
    while (temp != NULL) { // Ne oprim când dăm de NULL
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void deleteNode(node** head, int key) {
    if (*head == NULL) {
        printf("Lista este goala!\n");
        return;
    }

    node* temp = *head;

    while (temp != NULL && temp->data != key) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Elementul %d nu a fost gasit in lista.\n", key);
        return;
    }

    if (temp == *head) {
        *head = temp->next;
    }

    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }

    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    }

    free(temp);
}

void middle(node** head) {
    if (*head == NULL) return;

    node* slow = *head;
    node* fast = *head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    deleteNode(head, slow->data);
}

int main() {
    int n, val;
    node* head = NULL;

    printf("Cate elemente? ");
    scanf("%d", &n);

    printf("Elemente: \n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        insertlast(&head, val);
    }

    printf("\nLista initiala: ");
    printlist(head);

    middle(&head);

    printf("Lista dupa stergerea mijlocului: ");
    printlist(head);

    return 0;
}