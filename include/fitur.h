#ifndef FITUR_H
#define FITUR_H

#define MAKS_MHS     100
#define MAKS_MK      10
#define PANJANG_NIM  20
#define PANJANG_TEKS 50

// Struct 1: satu mata kuliah 
typedef struct {
    char  nama[PANJANG_TEKS];
    int   sks;
    float nilai;            // nilai angka 0-100 
} MataKuliah;

// Struct 2: data mahasiswa
typedef struct {
    char       nim[PANJANG_NIM];
    char       nama[PANJANG_TEKS];
    char       prodi[PANJANG_TEKS];
    MataKuliah mk[MAKS_MK];
    int        jumlah_mk;
    float      ipk;
} Mahasiswa;

// Konversi nilai (pass by value)
float       nilai_ke_bobot(float nilai);
const char *nilai_ke_huruf(float nilai);

// Manipulasi struct (pass by pointer)
void hitung_ipk(Mahasiswa *m);
void input_mahasiswa(Mahasiswa *m);

// Tampilan 
void tampilkan_mahasiswa(Mahasiswa m);                  // pass by value
void tampilkan_semua(const Mahasiswa data[], int n);
int  cari_nim(const Mahasiswa data[], int n, const char *nim);
void tampilkan_bantuan(const char *prog);

// File handling
int muat_database(const char *file, Mahasiswa data[]);                 // binary, fread  
int simpan_database(const char *file, const Mahasiswa data[], int n);  // binary, fwrite 
int ekspor_khs(const Mahasiswa *m);                                    // teks,printf

#endif
