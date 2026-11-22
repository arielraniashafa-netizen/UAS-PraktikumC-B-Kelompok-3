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
