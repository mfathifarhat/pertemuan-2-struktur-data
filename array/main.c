#include <stdio.h>
#include "dynarray.h"

int main() {
    DynArray arr;

    // 1. init / create 
    createArray(&arr, 2);
    printf("Dynamic array dibuat.\n");

    // 2. isEmpty 
    if (isEmpty(arr))
        printf("Array masih kosong.\n");

    // 3. insert (allocate otomatis saat penuh) 
    insert(&arr, 10);
    insert(&arr, 20);
    insert(&arr, 30); // trigger realloc
    insert(&arr, 40);

    display(arr);

    // 4. length 
    printf("Jumlah elemen: %d\n", length(arr));
    printf("Kapasitas: %d\n", arr.capacity);

    // 5. search 
    int cari = 20;
    int idx = search(arr, cari);
    if (idx != -1)
        printf("Data %d ditemukan di index %d\n", cari, idx);

    // 6. remove 
    removeData(&arr, 20);
    display(arr);

    // 7. destroy (deallocate nyata) 
    destroy(&arr);
    printf("Array dihancurkan.\n");

    if (isEmpty(arr))
        printf("Array sekarang kosong.\n");

    printf("\nTekan ENTER untuk keluar...");
    getchar();

    return 0;
}
