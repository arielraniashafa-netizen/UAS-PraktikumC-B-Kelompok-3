#include <stdio.h>
#include <string.h>
#include "fitur.h"

#define DB_DEFAULT "data/data_mhs.bin"

static Mahasiswa data[MAKS_MHS];

int main(int argc, char *argv[]) {
    const char *file_db = DB_DEFAULT;

    if (argc > 2) {
        fprintf(stderr, "Error: argumen terlalu banyak.\n");
        tampilkan_bantuan(argv[0]);
        return 1;
    }
    if (argc == 2) {
        if (strcmp(argv[1], "--help") == 0) {
            tampilkan_bantuan(argv[0]);
            return 0;
        }
        file_db = argv[1];
    }

    int n = muat_database(file_db, data);
    printf("Database: %s (%d data dimuat)\n", file_db, n);

    int pilihan;
    char baris[32], nim[PANJANG_NIM];
    do {
        printf("\n=== SISTEM KHS ===\n1. Tambah mahasiswa\n2. Daftar mahasiswa\n"
               "3. Lihat detail (cari NIM)\n4. Ekspor KHS ke teks\n0. Simpan & keluar\nPilih: ");
        if (fgets(baris, sizeof(baris), stdin) == NULL) break;
        if (sscanf(baris, "%d", &pilihan) != 1) pilihan = -1;

        switch (pilihan) {
        case 1:
            if (n >= MAKS_MHS) { printf("Database penuh.\n"); break; }
            input_mahasiswa(&data[n]);
            n++;
            break;
        case 2:
            tampilkan_semua(data, n);
            break;
        case 3:
        case 4: {
            printf("Masukkan NIM: ");
            if (fgets(nim, sizeof(nim), stdin) == NULL) break;
            nim[strcspn(nim, "\n")] = '\0';
            int idx = cari_nim(data, n, nim);
            if (idx < 0) { printf("NIM tidak ditemukan.\n"); break; }
            if (pilihan == 3) tampilkan_mahasiswa(data[idx]);
            else if (!ekspor_khs(&data[idx])) printf("Gagal menulis file.\n");
            break;
        }
        case 0:
            break;
        default:
            printf("Pilihan tidak valid.\n");
        }
    } while (pilihan != 0);

    if (simpan_database(file_db, data, n))
        printf("Data tersimpan di %s\n", file_db);
    else
        fprintf(stderr, "Gagal menyimpan ke %s (folder ada?)\n", file_db);
    return 0;
}
