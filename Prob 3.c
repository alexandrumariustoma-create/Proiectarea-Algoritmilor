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

void finddupes(node* head) {
    if (head == NULL || head->next == NULL) {
        return;
    }

    node* current = head;

    while (current != NULL) {
        node* runner = current->next;
        node* prev = current;

        while (runner != NULL) {
            if (current->data == runner->data) {
                prev->next = runner->next;
                free(runner);
                runner = prev->next;
            }
            else {
                prev = runner;
                runner = runner->next;
            }
        }
        current = current->next;
    }
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
    node *head = NULL;
    int n, val;
    printf("Cate elemente? \n");
    scanf("%d", &n);
    printf("elemente? \n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        insertlast(&head, val);
    }
    printlist(head);
    finddupes(head);
    printlist(head);
}