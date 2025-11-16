#include <stdio.h>
#include "perpustakaan.h" //mengimpor header buatan sendiri

extern int cariIndexBukuById(Buku daftar[], int n, int id); // extern untuk memberi tahu compiler bahwa fungsi cariIndexBukuById ada di file lain

void pinjamBuku(Buku daftar[], int n, Anggota anggota[], int na) { // fungsi ini untuk pinjam buku
    int idb; printf("ID buku yang dipinjam: "); // disuruh inputkan ID buku yang mau di pinjam
    scanf("%d", &idb);
    getchar();
    int idx = cariIndexBukuById(daftar, n, idb); // kemudian dicari index bukunya menggunakan ID
    
    if(idx == -1) { // jika idx nya bernilai -1 yang diperoleh dari nilai yang dikembalikan fungsi cariIndexBukuById
        printf("Buku tidak ditemukan.\n"); // di print buku tidak ditemukan
        return; // keluar dari fungsi
    }
    if(daftar[idx].dipinjam) { // jika bukunya sudah dipinjam
        printf("Buku sedang dipinjam.\n"); // print buku sedang dipinjam
        return; // keluar dari fungsi
    }
    daftar[idx].dipinjam = true; // jika lolos pengecekan maka akan ditandai bahwa buku ini sedang di pinjam
    printf("Buku berhasil dipinjam.\n"); // cetak buku berhasil dipinjam
}

void kembalikanBuku(Buku daftar[], int n) { // fungsi ini untuk kembalikan buku
    int idb;
    printf("ID buku yang dikembalikan: "); // disuruh inputkan ID buku yang ingin dikembalikan
    scanf("%d", &idb);
    getchar();
    int idx = cariIndexBukuById(daftar, n, idb); // cari index buku dalam daftar
    
    if(idx == -1) {  // jika ID tidak ada
        printf("Buku tidak ditemukan.\n"); // cetak buku tidak ditemukan
        return; 
    }
    if(!daftar[idx].dipinjam) { // jika buku tidak sedang dipinjam
        printf("Buku tidak sedang dipinjam.\n"); // cetak buku tidak sedang dipinjam
        return; 
    }
    daftar[idx].dipinjam = false; // jika lolos pengecekan maka akan ditandai buku ini tidak di pinjam
    printf("Buku berhasil dikembalikan.\n"); // cetak buku berhasil di kembalikan
}