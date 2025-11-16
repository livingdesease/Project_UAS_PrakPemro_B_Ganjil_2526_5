#include <stdio.h>
#include <string.h>
#include "perpustakaan.h"  // include header perpustakaan yang berisi struct dan prototype fungsi 

// Fungsi untuk menambah buku baru ke dalam daftar buku
void tambahBuku(Buku daftar[], int *n) {
    if (*n >= MAX_BUKU) {       // Ini untuk cek apakah jumlah buku udah sampai batas maksimal
        printf("Kapasitas buku sudah penuh!\n");
        return; 
    }
    Buku b;     //unutk buat variabel buku baru
    b.id = (*n) + 1;    // Untuk set ID buku secara otomatis berdasarkan jumlah buku sekarang + 1

    printf("Masukkan judul buku: "); 
    fgets(b.judul, sizeof b.judul, stdin);  // Pakai fgets biar bisa input dengan spasi
    b.judul[strcspn(b.judul,"\n")] = 0;     // Untuk hapus newline yang ikut terbaca di fgets 

    printf("Masukkan nama pengarang: "); 
    fgets(b.pengarang, sizeof b.pengarang, stdin); 
    b.pengarang[strcspn(b.pengarang,"\n")] = 0;

    printf("Masukkan tahun buku: "); 
    scanf("%d", &b.tahun); 
    getchar();

    b.dipinjam = false;     //set status buku belum dipinjam

    daftar[*n] = b;     // Masukkin buku baru ke array daftar buku di indeks ke *n
    (*n)++;     //

    printf("Buku berhasil ditambahkan!\n");
}

//Fungsi unutk cari posisi buku dalam array berdasarkan ID
int cariIndexBukuById(Buku daftar[], int n, int id) {
    for (int i = 0; i < n; i++)     //loop unutk cek tiap elemen daftar
    if (daftar[i].id == id) 

    return i;       // kembalikan posissi index buku ditemukan 
    return -1;      // kalau nggak ketemu ID nya, kembalikan -1
}

//Fungsi unutk hapus buku berdasarkan ID
void hapusBuku(Buku daftar[], int *n, int id) {
    int idx = cariIndexBukuById(daftar, *n, id);        // cari indeks buku dulu
    if (idx == -1) {    //kalau nggak ketemu 
        printf("ID tidak dapat ditemukan!\n"); 
        return; 
    }

    // Menggeser elemen setelah indeks  idx ke kiri unutk timpa buku yang dihapus
    for (int i = idx; i < (*n)-1; i++) 
    daftar[i] = daftar[i+1];

    (*n)--;     // kurangin jumlah buku

    printf("Buku berhasil dihapus!\n");
}

//fungsi untuk edit data buku berdasarkan ID 
void editBuku(Buku daftar[], int n, int id) {
    int idx = cariIndexBukuById(daftar, n, id);
    if (idx == -1) { 
        printf("ID buku tidak dapat ditemukan!\n");
        return; 
    }

    //input data yang baru
    printf("Masukkan judul baru: "); 
    fgets(daftar[idx].judul, sizeof daftar[idx].judul, stdin); 
    daftar[idx].judul[strcspn(daftar[idx].judul,"\n")] = 0;

    printf("Masukkan pengarang baru: ");
    fgets(daftar[idx].pengarang, sizeof daftar[idx].pengarang, stdin); 
    daftar[idx].pengarang[strcspn(daftar[idx].pengarang,"\n")] = 0;

    printf("Masukkan tahun baru: ");
    scanf("%d", &daftar[idx].tahun); 
    getchar();

    printf("Data buku berhasil diperbarui!\n");
}

//fungsi untuk menampilkan daftar buku yang ada
void tampilkanDaftarBuku(Buku daftar[], int n) {
    if (n == 0) {   //kalau buku belum ada
        printf("Belum ada buku!\n");
        return; 
    }

    printf("\nDaftar Buku:\n");

    for (int i=0;i<n;i++) {     //loop unutk print detail dari setiap buku
        printf("ID: %d | %s | %s | %d | %s\n", daftar[i].id, daftar[i].judul, daftar[i].pengarang, daftar[i].tahun, daftar[i].dipinjam ? "Dipinjam" : "Tersedia");
    }
}
