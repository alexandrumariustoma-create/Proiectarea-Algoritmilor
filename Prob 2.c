#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
    struct node *prev;
}node;

node* createnode(int data) {
    node* newnode = (node*)malloc(sizeof(node));
    newnode->data = data;
    newnode->next = NULL;
    newnode->prev = NULL;
    return newnode;
}

void insertlast(node** head, int data){
    node* newnode = createnode(data);
    if (*head == NULL) {
        *head = newnode;
        newnode->next = newnode;
        newnode->prev = newnode;
        return;
    }
    else {
        node* last = (*head)->prev;
        newnode->next = *head;
        newnode->prev = last;
        last->next = newnode;
        (*head) -> prev = newnode;
    }
}

void printlist(node* head) {
    if (head == NULL)
        return;
    else {
        node* temp = head;
        do {
            printf("%d ", temp->data);
            temp = temp->next;
        } while (temp != head);
    }
}

void parcurgere(node* head) {
    int max, min;
    if (head == NULL)
        return;
    else {
        node* temp = head;
        max = temp->data;
        min = temp->data;
        temp = temp->next;
        while (temp != head) {
            if (max < temp->data)
                max = temp->data;
            if (min > temp->data)
                min = temp->data;
            temp = temp->next;
        }
    }
    printf("maximul este %d, minimul este %d", max, min);
}

int main() {
    int n = 0, i, val;
    node* head = NULL;
    printf("Introdu numarul de elemente\n");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &val);
        insertlast(&head, val);
    }
    printlist(head);
    printf("\n");
    parcurgere(head);

}
