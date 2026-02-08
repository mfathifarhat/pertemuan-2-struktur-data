# Implementasi List ADT dengan Dynamic Array dalam Bahasa C

Proyek ini adalah implementasi struktur data **List (Daftar)** menggunakan **Dynamic Array (Larik Dinamis)** dalam bahasa pemrograman C.

Program ini terdiri dari tiga file utama:

1.  **array.h**: Header file yang mendefinisikan struktur data (`struct`) dan prototipe fungsi.
2.  **array.c**: File implementasi yang berisi logika fungsi-fungsi operasi list.
3.  **main.c**: Program utama untuk menguji semua fungsi yang telah dibuat.

## Struktur Data

Struktur data yang digunakan dinamakan `DynamicList` dan memiliki properti berikut:

- `data`: Pointer ke array integer (tempat penyimpanan elemen).
- `capacity`: Kapasitas maksimum array saat ini.
- `neff`: Jumlah elemen efektif yang ada di dalam list.

## Cara Kompilasi dan Menjalankan

Untuk menjalankan program ini, Anda perlu mengompilasi ketiga file tersebut menjadi satu program eksekusi. Gunakan compiler GCC dengan perintah berikut di terminal:

```bash
gcc main.c array.c -o dynamic_list
```

Setelah berhasil dikompilasi, jalankan program dengan perintah:

**Windows:**

```bash
./dynamic_list
```

**Linux/Mac:**

```bash
./dynamic_list
```

## Penjelasan Fungsi Utama

Berikut adalah fungsi-fungsi yang tersedia:

- **CreateList**: Membuat list baru dengan kapasitas awal tertentu.
- **IsEmpty**: Mengecek apakah list kosong.
- **Length**: Mengembalikan jumlah elemen saat ini.
- **InsertAt**: Menambahkan elemen pada indeks tertentu (otomatis memperbesar array jika penuh / _resize_).
- **InsertFirst**: Menambahkan elemen di awal list.
- **InsertLast**: Menambahkan elemen di akhir list.
- **DeleteAt**: Menghapus elemen pada indeks tertentu.
- **DeleteFirst**: Menghapus elemen pertama.
- **DeleteLast**: Menghapus elemen terakhir.
- **Search**: Mencari indeks dari suatu nilai.
- **DestroyList**: Menghapus list dan membebaskan memori.

## Apa yang Diharapkan (Output Program)

Program `main.c` akan melakukan serangkaian tes otomatis. Berikut adalah langkah-langkah yang akan ditampilkan di layar:

1.  **Inisialisasi**: Membuat list kosong dengan kapasitas awal 4.
2.  **Penambahan Elemen**:
    - Mengisi list dengan angka 10, 20, 30.
    - Menambahkan angka 5 di depan.
    - Menambahkan angka 25 di tengah (indeks 3).
    - _Catatan_: Saat list penuh (kapasitas 4), penambahan elemen ke-5 akan memicu **Auto-Resize** (kapasitas menjadi 8).
3.  **Pencarian**: Mencari lokasi angka 25.
4.  **Penghapusan Elemen**:
    - Menghapus elemen pertama.
    - Menghapus elemen terakhir.
    - Menghapus elemen pada indeks tertentu.
5.  **Pembersihan**: List dihancurkan dan memori dibebaskan (`free`).

Setiap langkah akan menampilkan status list saat ini, format: `[ elemen1 elemen2 ... ] (Size: X, Cap: Y)`.
