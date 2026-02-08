#ifndef DYNARRAY_H
#define DYNARRAY_H

typedef struct {
    int *data;
    int size;
    int capacity;
} DynArray;

// Prosedur untuk membuat Array
void createArray(DynArray *arr, int capacity);

// Fungsi untuk mengecek apakah array kosong
int isEmpty(DynArray arr);

// Manajemen Memory
int allocate(DynArray *arr);
void deallocate(DynArray *arr);

// Prosedur untuk menambahkan data
int insert(DynArray *arr, int value);

// Fungsi untuk mencari data
int search(DynArray arr, int value);

// Prosedur untuk menghapus data
int removeData(DynArray *arr, int value);

// Prosedur untuk menghapus seluruh list
void destroy(DynArray *arr);

// Fungsi untuk mengambil jumlah node
int length(DynArray arr);

// Prosedur untuk menampilkan data
void display(DynArray arr);

#endif
