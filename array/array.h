#ifndef ARRAY_H
#define ARRAY_H

#define MAX 100

typedef struct {
    int data[MAX];
    int size;
} Array;

// Prosedur untuk membuat Array
void createArray(Array *arr);

// Fungsi untuk mengecek apakah array kosong
int isEmpty(Array arr);

// Manajemen Memory
int allocate(Array *arr, int value);
void deallocate(Array *arr);

// Prosedur untuk menambahkan data
int insert(Array *arr, int value);

// Fungsi untuk mencari data
int search(Array arr, int value);

// Prosedur untuk menghapus data
int removeData(Array *arr, int value);

// Prosedur untuk menghapus seluruh list
void destroy(Array *arr);

// Fungsi untuk mengambil jumlah node
int length(Array arr);

// Prosedur untuk menampilkan data
void display(Array arr);

#endif
