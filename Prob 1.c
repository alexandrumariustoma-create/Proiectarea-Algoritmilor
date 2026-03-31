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

void insert1st(node** head, int data) {
    node* newNode = createNode(data);
    newNode-> next = *head;
    *head = newNode;
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
void insertmiddle(node** head, int data, int pos) {
    if (pos == 0) {
        insert1st(head, data);
        return;
    }
    node* newNode = createNode(data);
    node* temp = *head;
    for (int i = 0; i < pos - 1 && temp != NULL; i++) {
        temp = temp -> next;
    }
    if (temp == NULL) {
        return;
    }
    newNode -> next = temp -> next;
    temp -> next = newNode;
}
void delete(node** head, int key)
{
    node *temp = *head, *prev = NULL;
    if (temp != NULL && temp -> data == key) {
        *head = temp -> next;
        free(temp);
        return;
    }
    while (temp != NULL && temp -> data != key) {
        prev = temp;
        temp = temp -> next;
    }
    if (temp == NULL) {
        return;
    }
    prev -> next = temp -> next;
    free(temp);
}

int search(node* head, int key) {
    node* temp = head;
    int pos = 0;
    while (temp != NULL) {
        if (temp -> data == key)
            return pos;
        temp = temp -> next;
        pos++;
    }
    return -1;
}

void sort(node* head) {
    if (head == NULL) {
        return;
    }
    int swapped, temp;
    node* ptrl;
    node* lptr = NULL;

    do {
        swapped = 0;
        ptrl = head;
        while (ptrl -> next != lptr) {
            if (ptrl -> data > lptr -> data) {
                temp = ptrl -> data;
                ptrl -> data = ptrl -> next -> data;
                ptrl -> next -> data = temp;
                swapped = 1;
            }
            ptrl = ptrl -> next;
        }
        lptr = ptrl;
    } while (swapped);
}

node *reverse(node **head) {
    node *prev = NULL, *current = *head, *next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
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
    int val, i, n = 10; 
    node* head = NULL;
    printf("10 elemente: \n");
    for (i = 0; i < 10; i++) {
        scanf("%d", &val);
        insertlast(&head, val);
    }
    printlist(head);

    printf("\n inserare: \n la ce pozitie vrei sa inserezi? ");
    int pozin, valin;
    scanf("%d", &pozin);
    printf("\n Ce valoare inserati? ");
    scanf("%d", &valin);
    if (n == pozin)
        insertlast(&head, valin );
    else
        if (pozin == 0)
            insert1st(&head, valin);
    else
        insertmiddle(&head, valin, pozin);
    printlist(head);


    printf("\n cautare: ");
    int valsch;
    scanf("%d", &valsch);
    int poz = search(head, valsch);
    if (poz != -1) {
        printf("\n A fost gasit la %d \n", poz);
    }
    else {
        printf("\n Nu a fost gasit \n");
    }
    printlist(head);

    printf("\n stergere: ");
    int valdel;
    scanf("%d", &valdel);
    delete(&head, valdel);
    printlist(head);
    printf("\n");

    printf("\n sortare: ");
    sort(head);
    printlist(head);

    printf("\n reverse: ");
    reverse(&head);
    printlist(head);
}