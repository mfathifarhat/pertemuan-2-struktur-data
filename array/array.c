#include <stdio.h>
#include <stdlib.h>
#include "array.h"

// Define initial capacity if needed, but we pass it in CreateList
#define INITIAL_CAPACITY 10

/* Initialize the list */
void CreateList(DynamicList *L, int capacity) {
    L->data = (int *)malloc(capacity * sizeof(int));
    if (L->data == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    L->capacity = capacity;
    L->neff = 0;
}

/* Check if list is empty */
bool IsEmpty(DynamicList L) {
    return L.neff == 0;
}

/* Return current number of elements */
int Length(DynamicList L) {
    return L.neff;
}

/* Helper function to resize the array */
void Resize(DynamicList *L) {
    int newCapacity = L->capacity * 2;
    int *newData = (int *)realloc(L->data, newCapacity * sizeof(int));
    if (newData == NULL) {
        printf("Memory reallocation failed!\n");
        exit(1);
    }
    L->data = newData;
    L->capacity = newCapacity;
    printf("-> Array resized to capacity: %d\n", newCapacity);
}

/* Insert at specific index */
void InsertAt(DynamicList *L, int el, int index) {
    if (index < 0 || index > L->neff) {
        printf("Index out of bounds!\n");
        return;
    }

    /* Auto-resize if full */
    if (L->neff == L->capacity) {
        Resize(L);
    }

    /* Shift elements to the right */
    for (int i = L->neff; i > index; i--) {
        L->data[i] = L->data[i - 1];
    }

    L->data[index] = el;
    L->neff++;
}

/* Insert at the beginning */
void InsertFirst(DynamicList *L, int el) {
    InsertAt(L, el, 0);
}

/* Insert at the end */
void InsertLast(DynamicList *L, int el) {
    InsertAt(L, el, L->neff);
}

/* Search for an element */
int Search(DynamicList L, int el) {
    for (int i = 0; i < L.neff; i++) {
        if (L.data[i] == el) {
            return i;
        }
    }
    return -1;
}

/* Delete at specific index */
void DeleteAt(DynamicList *L, int index, int *el) {
    if (index < 0 || index >= L->neff) {
        printf("Index out of bounds or list is empty!\n");
        return;
    }

    *el = L->data[index];

    /* Shift elements to the left */
    for (int i = index; i < L->neff - 1; i++) {
        L->data[i] = L->data[i + 1];
    }

    L->neff--;
    
    // Optional: Downsize if neff is significantly smaller than capacity
    // For this implementation, we will stick to growing only as per common simple dynamic array implementations
}

/* Delete first element */
void DeleteFirst(DynamicList *L, int *el) {
    DeleteAt(L, 0, el);
}

/* Delete last element */
void DeleteLast(DynamicList *L, int *el) {
    DeleteAt(L, L->neff - 1, el);
}

/* Destroy the list */
void DestroyList(DynamicList *L) {
    if (L->data != NULL) {
        free(L->data);
        L->data = NULL;
    }
    L->capacity = 0;
    L->neff = 0;
    printf("-> List destroyed and memory freed.\n");
}

/* Print the list state */
void PrintList(DynamicList L) {
    printf("[ ");
    for (int i = 0; i < L.neff; i++) {
        printf("%d ", L.data[i]);
    }
    printf("]");
    printf(" (Size: %d, Cap: %d)\n", L.neff, L.capacity);
}
