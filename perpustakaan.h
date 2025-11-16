#ifndef PERPUSTAKAAN_H //Mencegah file header ini di-include lebih dari sekali
#define PERPUSTAKAAN_H

#include <stdbool.h> //Mengimpor tipe boolean (true/false)

#define MAX_BUKU 100
#define MAX_ANGGOTA 100
//Maksimum jumlah buku dan anggota yang dapat disimpan

//Struktur untuk menyimpan data buku
typedef struct {
    int id; //ID unik untuk buku
    char judul[100]; //Judul buku
    char pengarang[100]; //Nama pengarang
    int tahun; //Tahun terbit
    bool dipinjam; //Status apakah buku sedang dipinjam
} Buku;

//Struktur untuk menyimpan data anggota perpustakaan
typedef struct {
    int id; //ID unik untuk anggota
    char nama[100]; //Nama anggota
    char npm[20]; //Nomor pokok mahasiswa
} Anggota;

/* buku.c */ 
void tambahBuku(Buku daftar[], int *n); //Fungsi untuk menambah buku baru ke daftar
void hapusBuku(Buku daftar[], int *n, int id); //Fungsi untuk menghapus buku berdasarkan ID
void editBuku(Buku daftar[], int n, int id); //Fungsi untuk mengedit data buku berdasarkan ID
void tampilkanDaftarBuku(Buku daftar[], int n); //Fungsi untuk menampilkan seluruh daftar buku

/* anggota.c */
void tambahAnggota(Anggota daftar[], int *n); //Fungsi untuk menambah anggota baru
void tampilkanDaftarAnggota(Anggota daftar[], int n); //Fungsi untuk menampilkan seluruh anggota

/* peminjaman.c */
void pinjamBuku(Buku daftar[], int n, Anggota anggota[], int na);
void kembalikanBuku(Buku daftar[], int n); //Fungsi untuk mengembalikan buku yang dipinjam

/* utils.c */
int cariIndexBukuById(Buku daftar[], int n, int id); //Fungsi untuk mencari index buku berdasarkan ID 
int bacaInt(const char *prompt); //Fungsi untuk membaca input integer dengan prompt

#endif //Penutup dari header guard
