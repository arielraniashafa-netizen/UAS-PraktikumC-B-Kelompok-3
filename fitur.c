#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "fitur.h"

// ---------- helper input ---------- 
static void baca_string (const char *prompt, char *buf, int ukuran) {
    printf("%s", prompt);
    if (fgets(buf, ukuran, stdin) == NULL) { buf[0] = '\0'; return; }

    if (strchr(buf, '\n') == NULL) {
        // input lebih panjang dari buffer: buang sisanya 
        int c;
        while ((c = getchar()) != '\n' && c != EOF) { }
    } else {
        buf[strcspn(buf, "\n")] = '\0';
    }
}
static float baca_float (const char *prompt) {
    char baris[64];
    float x = 0;
    do {
        baca_string(prompt, baris, sizeof(baris));
    } while (sscanf(baris, "%f", &x) != 1);
    return x;
}

// ---------- konversi nilai ---------- 
float nilai_ke_bobot (float nilai) {
    if (nilai >= 85) return 4.0f;
    if (nilai >= 75) return 3.0f;
    if (nilai >= 65) return 2.0f;
    if (nilai >= 50) return 1.0f;
    return 0.0f;
}

const char *nilai_ke_huruf (float nilai) {
    if (nilai >= 85) return "A";
    if (nilai >= 75) return "B";
    if (nilai >= 65) return "C";
    if (nilai >= 50) return "D";
    return "E";
}

//---------- manipulasi struct via pointer ----------
void hitung_ipk (Mahasiswa *m) {
    float total_mutu = 0;
    int total_sks = 0;
    for (int i = 0; i < m->jumlah_mk; i++) {
        total_mutu += nilai_ke_bobot(m->mk[i].nilai) * m->mk[i].sks;
        total_sks  += m->mk[i].sks;
    }
    m->ipk = (total_sks > 0) ? total_mutu / total_sks : 0.0f;
}

void input_mahasiswa (Mahasiswa *m) {
    memset(m, 0, sizeof(*m));
    baca_string("NIM           : ", m->nim, PANJANG_NIM);
    baca_string("Nama          : ", m->nama, PANJANG_TEKS);
    baca_string("Program Studi : ", m->prodi, PANJANG_TEKS);

    int n;
    do {
        n = (int)baca_float("Jumlah mata kuliah (1-10): ");
    } while (n < 1 || n > MAKS_MK);
    m->jumlah_mk = n;

    for (int i = 0; i < n; i++) {
        printf("-- Mata kuliah %d --\n", i + 1);
        baca_string("  Nama  : ", m->mk[i].nama, PANJANG_TEKS);
        m->mk[i].sks   = (int)baca_float("  SKS   : ");
        m->mk[i].nilai = baca_float("  Nilai (0-100): ");
    }
    hitung_ipk(m);
}

//---------- tampilan ----------
void tampilkan_mahasiswa (Mahasiswa m) {
    printf("\nNIM   : %s\nNama  : %s\nProdi : %s\n", m.nim, m.nama, m.prodi);
    printf("%-3s %-25s %-4s %-6s %-5s\n", "No", "Mata Kuliah", "SKS", "Nilai", "Huruf");
    for (int i = 0; i < m.jumlah_mk; i++) {
        printf("%-3d %-25s %-4d %-6.1f %-5s\n", i + 1, m.mk[i].nama,
               m.mk[i].sks, m.mk[i].nilai, nilai_ke_huruf(m.mk[i].nilai));
    }
    printf("IPK   : %.2f\n", m.ipk);
}

void tampilkan_semua (const Mahasiswa data[], int n) {
    if (n == 0) { printf("Belum ada data.\n"); return; }
    printf("\n%-3s %-15s %-25s %-5s\n", "No", "NIM", "Nama", "IPK");
    for (int i = 0; i < n; i++)
        printf("%-3d %-15s %-25s %.2f\n", i + 1, data[i].nim, data[i].nama, data[i].ipk);
}

int cari_nim (const Mahasiswa data[], int n, const char *nim) {
    for (int i = 0; i < n; i++)
        if (strcmp(data[i].nim, nim) == 0) return i;
    return -1;
}
