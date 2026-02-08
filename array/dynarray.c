#include <stdio.h>
#include <stdlib.h>
#include "dynarray.h"

//init / create 
void createArray(DynArray *arr, int capacity) {
    arr->data = (int *)malloc(capacity * sizeof(int));
    arr->size = 0;
    arr->capacity = capacity;
}

//isEmpty 
int isEmpty(DynArray arr) {
    return arr.size == 0;
}

//allocate (resize array) 
int allocate(DynArray *arr) {
    int newCapacity = arr->capacity * 2;
    int *temp = (int *)realloc(arr->data, newCapacity * sizeof(int));
    if (temp == NULL)
        return 0;

    arr->data = temp;
    arr->capacity = newCapacity;
    return 1;
}

//deallocate (shrink optional / demo free element not needed) 
void deallocate(DynArray *arr) {
    destroy(arr);
}

//insert 
int insert(DynArray *arr, int value) {
    if (arr->size == arr->capacity) {
        if (!allocate(arr))
            return 0;
    }
    arr->data[arr->size++] = value;
    return 1;
}

//search 
int search(DynArray arr, int value) {
    for (int i = 0; i < arr.size; i++) {
        if (arr.data[i] == value)
            return i;
    }
    return -1;
}

//del / remove 
int removeData(DynArray *arr, int value) {
    int idx = search(*arr, value);
    if (idx == -1)
        return 0;

    for (int i = idx; i < arr->size - 1; i++) {
        arr->data[i] = arr->data[i + 1];
    }
    arr->size--;
    return 1;
}

//destroy 
void destroy(DynArray *arr) {
    free(arr->data);
    arr->data = NULL;
    arr->size = 0;
    arr->capacity = 0;
}

//length 
int length(DynArray arr) {
    return arr.size;
}

//display 
void display(DynArray arr) {
    if (isEmpty(arr)) {
        printf("Array kosong\n");
        return;
    }

    for (int i = 0; i < arr.size; i++) {
        printf("%d ", arr.data[i]);
    }
    printf("\n");
}
