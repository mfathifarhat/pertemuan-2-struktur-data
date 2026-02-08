#include <stdio.h>
#include "array.h"

int main() {
    Array arr;

    // 1. init / create 
    createArray(&arr);
    printf("Array dibuat.\n");

    // 2. isEmpty 
    if (isEmpty(arr))
        printf("Array masih kosong.\n");

    // 3. insert 
    printf("\nMenambahkan data...\n");
    insert(&arr, 10);
    insert(&arr, 20);
    insert(&arr, 30);
    insert(&arr, 40);

    display(arr);

    // 4. length 
    printf("Jumlah elemen: %d\n", length(arr));

    // 5. search 
    int cari = 20;
    int idx = search(arr, cari);
    if (idx != -1)
        printf("Data %d ditemukan di index %d\n", cari, idx);
    else
        printf("Data %d tidak ditemukan\n", cari);

    // 6. remove 
    printf("\nMenghapus data 20...\n");
    removeData(&arr, 20);
    display(arr);
    printf("Jumlah elemen setelah delete: %d\n", length(arr));

    // 7. allocate & deallocate
    printf("\nDemo allocate & deallocate (konseptual)...\n");
    if (allocate(&arr, 99)) {
        arr.size++;
        printf("Data 99 dialokasikan.\n");
        deallocate(&arr);
    }

    display(arr);

    // 8. destroy 
    printf("\nMenghapus seluruh array...\n");
    destroy(&arr);

    // 9. isEmpty setelah destroy 
    if (isEmpty(arr))
        printf("Array berhasil dikosongkan.\n");

    printf("\nProgram selesai. Tekan ENTER untuk keluar...");
    getchar();

    return 0;
}
