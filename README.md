# Sistem Akademik & KHS Mahasiswa

## Anggota
- Nama / NIM:
- Salwa hayatul fitri / 260810701100036
- Ariel Rania Shafa / 260810701100014
- Chalif Aulya / 260810701100077
- Derizki Aditya / 260810701100095
- Muhammad Hanif Baihaqi / 260810701100047

## Fitur
- Tambah data mahasiswa beserta mata kuliah, IPK dihitung otomatis
- Simpan/muat database biner (`data/data_mhs.bin`) dengan `fwrite`/`fread`
- Ekspor KHS per mahasiswa ke `data/KHS_[NIM].txt` dengan `fprintf`

## Struct
- `MataKuliah` (nama, sks, nilai)
- `Mahasiswa` (nim, nama, prodi, array MataKuliah, jumlah_mk, ipk)

## Kompilasi
```
gcc src/main.c src/fitur.c -Iinclude -o program
```

## Menjalankan
