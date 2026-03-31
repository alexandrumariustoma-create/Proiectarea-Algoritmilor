#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

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

bool palindrome(node* head) {
    node* slow = head;
    node* fast = head;

    while (fast != NULL && fast -> next != NULL) {
        slow = slow -> next;
        fast = fast -> next -> next;
        node* secnd = reverse(&slow);
        node *frst = head;
        bool palindrome = true;
        while (secnd != NULL) {
            if (frst-> data != secnd -> data) {
                palindrome = false;
                break;
            }
            frst = frst -> next;
            secnd = secnd -> next;
        }
    }
    return palindrome;
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
    if (palindrome(head)) {
        printf("palindrome\n");
    }
    else {
        printf("not palindrome\n");
    }
}