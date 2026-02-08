#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

// init / create 
void createList(Node **head) {
    *head = NULL;
}

// isEmpty 
int isEmpty(Node *head) {
    return head == NULL;
}

// allocate 
Node* allocate(int value) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode != NULL) {
        newNode->data = value;
        newNode->next = NULL;
    }
    return newNode;
}

// deallocate 
void deallocate(Node *node) {
    free(node);
}

// add / insert (di akhir list) 
void insert(Node **head, int value) {
    Node *newNode = allocate(value);
    if (newNode == NULL) return;

    if (isEmpty(*head)) {
        *head = newNode;
    } else {
        Node *temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// search 
Node* search(Node *head, int value) {
    Node *temp = head;
    while (temp != NULL) {
        if (temp->data == value)
            return temp;
        temp = temp->next;
    }
    return NULL;
}

// del / remove (berdasarkan nilai) 
void removeNode(Node **head, int value) {
    if (isEmpty(*head)) return;

    Node *temp = *head;
    Node *prev = NULL;

    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) return; // data tidak ditemukan

    if (prev == NULL) {
        *head = temp->next;
    } else {
        prev->next = temp->next;
    }

    deallocate(temp);
}

// destroy 
void destroy(Node **head) {
    Node *temp;
    while (*head != NULL) {
        temp = *head;
        *head = (*head)->next;
        deallocate(temp);
    }
}

// length 
int length(Node *head) {
    int count = 0;
    Node *temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

// display (opsional) 
void display(Node *head) {
    Node *temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
