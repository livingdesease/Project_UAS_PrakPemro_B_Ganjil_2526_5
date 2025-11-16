#include <stdio.h>      // Library standar untuk fungsi input-output (printf, scanf)
#include <stdlib.h>     // Library standar untuk fungsi umum (malloc, free, exit)
#include "perpustakaan.h" // Mengimpor header buatan sendiri berisi struct & prototype fungsi

// Fungsi untuk menampilkan menu utama perpustakaan
void tampilkanMenuUtama(Buku daftar[], int *nb, Anggota daftarA[], int *na) {
    int pilihan; // Variabel untuk menyimpan menu yang dipilih user

    do { // Menu ditampilkan berulang sampai user memilih 0
        printf("\n=== PERPUSTAKAAN ===\n");
        printf("1. Tambah Buku\n");          // Menu tambah buku
        printf("2. Hapus Buku\n");          // Menu hapus buku
        printf("3. Edit Buku\n");           // Menu edit buku
        printf("4. Tampilkan Buku\n");      // Menampilkan seluruh buku
        printf("5. Tambah Anggota\n");      // Tambah data anggota
        printf("6. Tampilkan Anggota\n");   // Menampilkan daftar anggota
        printf("7. Pinjam Buku\n");         // Fitur peminjaman buku
        printf("8. Kembalikan Buku\n");     // Fitur pengembalian buku
        printf("0. Keluar\n");              // Keluar dari program
        printf("Pilihan: ");

        scanf("%d", &pilihan); // Menerima input pilihan menu dari user
        getchar();             // Menghapus karakter newline yang tersisa dari buffer input

        switch(pilihan) { // Mengecek pilihan dan mengeksekusi fungsi yang sesuai
            case 1:
                tambahBuku(daftar, nb); // Menambah buku baru, nb sebagai pointer agar berubah di main()
                break;

            case 2: {
                int id;
                printf("Masukkan ID buku yang dihapus: ");
                scanf("%d", &id);        // Meminta user memasukkan ID buku untuk dihapus
                hapusBuku(daftar, nb, id); // Menghapus buku berdasarkan ID
                break;
            }

            case 3: {
                int id;
                printf("Masukkan ID buku yang diedit: ");
                scanf("%d", &id);         // Meminta ID buku yang ingin diedit
                editBuku(daftar, *nb, id); // Mengedit buku, jumlah buku dikirim sebagai nilai (*nb)
                break;
            }

            case 4:
                tampilkanDaftarBuku(daftar, *nb); // Menampilkan semua buku yang tersimpan
                break;

            case 5:
                tambahAnggota(daftarA, na); // Menambah anggota baru
                break;

            case 6:
                tampilkanDaftarAnggota(daftarA, *na); // Menampilkan seluruh anggota
                break;

            case 7:
                pinjamBuku(daftar, *nb, daftarA, *na); // Anggota meminjam buku
                break;

            case 8:
                kembalikanBuku(daftar, *nb); // Mengembalikan buku yang dipinjam
                break;

            case 0:
                printf("Keluar...\n"); // Menampilkan pesan keluar
                break;

            default:
                printf("Pilihan tidak valid\n"); // Jika input bukan 0–8
        }

    } while (pilihan != 0); // Loop berhenti jika user memasukkan 0
}

// Fungsi utama program
int main(void) {
    Buku daftarBuku[MAX_BUKU];            // Array untuk menyimpan daftar buku
    Anggota daftarAnggota[MAX_ANGGOTA];   // Array untuk menyimpan daftar anggota

    int nb = 0; // Menyimpan jumlah buku (awal = 0)
    int na = 0; // Menyimpan jumlah anggota (awal = 0)

    // Memanggil fungsi menu utama dan membawa array + alamat jumlah data
    tampilkanMenuUtama(daftarBuku, &nb, daftarAnggota, &na);

    return 0; // Mengakhiri program tanpa error
}
