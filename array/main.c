#include <stdio.h>
#include <stdlib.h>
#include "array.h"

int main() {
    /* Set buffer to NULL to ensure immediate output */
    setbuf(stdout, NULL);

    DynamicList myList;
    int deletedVal;

    printf("--- Dynamic Array List ADT Test ---\n\n");

    /* 1. Initialize List */
    printf("1. Initializing List with capacity 4:\n");
    CreateList(&myList, 4);
    if (IsEmpty(myList)) {
        printf("-> List is empty.\n");
    }
    PrintList(myList);

    /* 2. Add Elements (InsertLast) */
    printf("\n2. Adding elements (InsertLast 10, 20, 30):\n");
    InsertLast(&myList, 10);
    InsertLast(&myList, 20);
    InsertLast(&myList, 30);
    PrintList(myList);

    /* 3. Add Element (InsertFirst) */
    printf("\n3. Adding element (InsertFirst 5):\n");
    InsertFirst(&myList, 5);
    PrintList(myList);

    /* 4. Add Element (InsertAt) - Should NOT trigger resize yet (4 elements, cap 4) */
    printf("\n4. Adding element (InsertAt 25 at index 3) - CURRENTLY FULL:\n");
    /* Note: Index 3 is between 20 and 30. Current: 5, 10, 20, 30.
       After insert at 3: 5, 10, 20, 25, 30. 
       WAIT! Capacity is 4. Inserting the 5th element should trigger RESIZE. 
    */
    InsertAt(&myList, 25, 3);
    PrintList(myList);

    /* 5. Trigger Resize explicitly by adding more */
    printf("\n5. Adding more elements to verify capacity growth:\n");
    InsertLast(&myList, 40);
    InsertLast(&myList, 50);
    InsertLast(&myList, 60);
    PrintList(myList);

    /* 6. Search */
    printf("\n6. Searching for element 25:\n");
    int index = Search(myList, 25);
    if (index != -1) {
        printf("-> Element 25 found at index: %d\n", index);
    } else {
        printf("-> Element 25 not found.\n");
    }

    /* 7. Delete First */
    printf("\n7. Delete First:\n");
    DeleteFirst(&myList, &deletedVal);
    printf("-> Deleted: %d\n", deletedVal);
    PrintList(myList);

    /* 8. Delete Last */
    printf("\n8. Delete Last:\n");
    DeleteLast(&myList, &deletedVal);
    printf("-> Deleted: %d\n", deletedVal);
    PrintList(myList);

    /* 9. Delete At */
    printf("\n9. Delete At index 2:\n");
    DeleteAt(&myList, 2, &deletedVal);
    printf("-> Deleted: %d\n", deletedVal);
    PrintList(myList);

    /* 10. Check Length */
    printf("\n10. Final Length: %d\n", Length(myList));

    /* 11. Destroy */
    printf("\n11. Destroying List:\n");
    DestroyList(&myList);
    
    return 0;
}
