#include <stdio.h>
#include "array.h"

// init / create 
void createArray(Array *arr) {
    arr->size = 0;
}

// isEmpty 
int isEmpty(Array arr) {
    return arr.size == 0;
}

// allocate (cek kapasitas) 
int allocate(Array *arr, int value) {
    if (arr->size >= MAX)
        return 0;
    arr->data[arr->size] = value;
    return 1;
}

// deallocate (dummy, karena array statis) 
void deallocate(Array *arr) {
    // tidak perlu free memori
}

// add / insert 
int insert(Array *arr, int value) {
    if (!allocate(arr, value))
        return 0;
    arr->size++;
    return 1;
}

// search 
int search(Array arr, int value) {
    for (int i = 0; i < arr.size; i++) {
        if (arr.data[i] == value)
            return i;
    }
    return -1;
}

// del / remove 
int removeData(Array *arr, int value) {
    int idx = search(*arr, value);
    if (idx == -1)
        return 0;

    for (int i = idx; i < arr->size - 1; i++) {
        arr->data[i] = arr->data[i + 1];
    }
    arr->size--;
    return 1;
}

// destroy 
void destroy(Array *arr) {
    arr->size = 0;
}

// length 
int length(Array arr) {
    return arr.size;
}

// display 
void display(Array arr) {
    if (isEmpty(arr)) {
        printf("Array kosong\n");
        return;
    }

    for (int i = 0; i < arr.size; i++) {
        printf("%d ", arr.data[i]);
    }
    printf("\n");
}
