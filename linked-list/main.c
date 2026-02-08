#include <stdio.h>
#include "linkedlist.h"

int main() {
    Node *head;

    // 1. init / create 
    createList(&head);
    printf("List dibuat.\n");

    // 2. isEmpty 
    if (isEmpty(head))
        printf("List masih kosong.\n");

    // 3. allocate + insert 
    printf("\nMenambahkan data ke linked list...\n");
    insert(&head, 10);
    insert(&head, 20);
    insert(&head, 30);
    insert(&head, 40);

    display(head);

    // 4. length 
    printf("Jumlah node: %d\n", length(head));

    // 5. search 
    int cari = 20;
    Node *found = search(head, cari);
    if (found != NULL)
        printf("Data %d ditemukan.\n", cari);
    else
        printf("Data %d tidak ditemukan.\n", cari);

    // 6. remove / delete 
    printf("\nMenghapus data 20...\n");
    removeNode(&head, 20);
    display(head);
    printf("Jumlah node setelah delete: %d\n", length(head));

    // 7. allocate & deallocate (manual demo) 
    printf("\nDemo allocate & deallocate manual...\n");
    Node *temp = allocate(99);
    if (temp != NULL) {
        printf("Node sementara dibuat dengan data: %d\n", temp->data);
        deallocate(temp);
        printf("Node sementara didealokasi.\n");
    }

    // 8. destroy 
    printf("\nMenghapus seluruh linked list...\n");
    destroy(&head);

    // 9. isEmpty setelah destroy 
    if (isEmpty(head))
        printf("List berhasil dikosongkan.\n");

    return 0;
}
