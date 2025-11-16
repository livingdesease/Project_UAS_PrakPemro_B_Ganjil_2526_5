#include <stdio.h>
#include <string.h>
#include "perpustakaan.h" //mengimpor header buatan sendiri

void tambahAnggota(Anggota daftar[], int *n) { // fungsi ini untuk menambah anggota baru
    if(*n >= MAX_ANGGOTA) { // Anggota ga boleh lebih dari MAX_ANGGOTA, di cek dulu
        printf("Kapasitas anggota penuh.\n");
        return;
    }
    Anggota a; // jika tidak penuh maka harus buat id, input nama dan NPM di struct Anggota yang terdapat di header perpustakaan.h
    a.id = (*n) + 1; // proses buat idnya
    
    //proses input nama
    printf("Nama: ");
    fgets(a.nama, sizeof a.nama, stdin);
    a.nama[strcspn(a.nama,"\n")] = 0;
    

    //proses input NPM
    printf("NPM: ");
    fgets(a.npm, sizeof a.npm, stdin);
    a.npm[strcspn(a.npm,"\n")] = 0;

    daftar[*n] = a; // memasukkan data anggota baru ke array Daftar[*n]
    (*n)++; // jumlah anggota ditambah 1
    printf("Anggota ditambahkan.\n");
}

void tampilkanDaftarAnggota(Anggota daftar[], int n) { // fungsi ini untuk melihat daftar anggota
    if(n == 0) { // jika banyak anggota 0 di tampilkan belum ada anggota
        printf("Belum ada anggota.\n");
        return;
    }
    printf("\nDaftar Anggota:\n");
    for(int i = 0; i < n; i++) { // menggunakan looping for untuk mencetak ID | NAMA | NPM satu persatu
        printf("ID: %d | %s | %s\n", daftar[i].id, daftar[i].nama, daftar[i].npm);
    }
}