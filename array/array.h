#ifndef ARRAY_H
#define ARRAY_H

#include <stdbool.h>

/* Data Structure */
typedef struct {
    int *data;      /* Pointer to the data */
    int capacity;   /* Max elements currently possible */
    int neff;       /* Number of effective elements */
} DynamicList;

/* Function Prototypes */

/**
 * Initialize the struct, set capacity, and malloc the initial memory.
 * @param L Pointer to the list to initialize
 * @param capacity Initial capacity of the list
 */
void CreateList(DynamicList *L, int capacity);

/**
 * Check if the list has 0 elements.
 * @param L The list to check
 * @return true if empty, false otherwise
 */
bool IsEmpty(DynamicList L);

/**
 * Return the current number of elements (neff).
 * @param L The list
 * @return The number of elements
 */
int Length(DynamicList L);

/**
 * Add an element to the list at the specified index.
 * Handles array shifting and auto-resizing if full.
 * @param L Pointer to the list
 * @param el The element to add
 * @param index The index at which to add the element
 */
void InsertAt(DynamicList *L, int el, int index);

/**
 * Add an element to the beginning of the list.
 * @param L Pointer to the list
 * @param el The element to add
 */
void InsertFirst(DynamicList *L, int el);

/**
 * Add an element to the end of the list.
 * @param L Pointer to the list
 * @param el The element to add
 */
void InsertLast(DynamicList *L, int el);

/**
 * Find an element by value and return its index.
 * @param L The list to search
 * @param el The element to search for
 * @return The index of the element, or -1 if not found
 */
int Search(DynamicList L, int el);

/**
 * Delete an element from the list at the specified index.
 * Handles array shifting.
 * @param L Pointer to the list
 * @param index The index of the element to delete
 * @param el Pointer to store the deleted element
 */
void DeleteAt(DynamicList *L, int index, int *el);

/**
 * Delete the first element of the list.
 * @param L Pointer to the list
 * @param el Pointer to store the deleted element
 */
void DeleteFirst(DynamicList *L, int *el);

/**
 * Delete the last element of the list.
 * @param L Pointer to the list
 * @param el Pointer to store the deleted element
 */
void DeleteLast(DynamicList *L, int *el);

/**
 * Clean up everything (free memory).
 * @param L Pointer to the list to destroy
 */
void DestroyList(DynamicList *L);

/**
 * Print the array state (helper for testing).
 * @param L The list to print
 */
void PrintList(DynamicList L);

#endif
