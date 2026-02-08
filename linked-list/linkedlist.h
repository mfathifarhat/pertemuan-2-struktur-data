#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct Node {
    int data;
    struct Node *next;
} Node;

// Prosedur untuk membuat List
void createList(Node **head);

// Fungsi untuk mengecek apakah List kosong
int isEmpty(Node *head);

// Manajemen Memory
Node* allocate(int value);
void deallocate(Node *node);

// Prosedur untuk menambahkan data
void insert(Node **head, int value);

// Fungsi untuk mencari data
Node* search(Node *head, int value);

// Prosedur untuk menghapus data
void removeNode(Node **head, int value);

// Prosedur untuk menghapus seluruh list
void destroy(Node **head);

// Fungsi untuk mengambil jumlah node
int length(Node *head);

// 
void display(Node *head);

#endif
