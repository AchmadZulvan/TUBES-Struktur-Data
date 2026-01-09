#ifndef DATA_MAHASISWA_H
#define DATA_MAHASISWA_H

#include <string>
using namespace std;

//Struct
struct Nilai {
    string matkul;
    float nilai;
    Nilai* next;
};
struct Mahasiswa {
    string nim;
    string nama;
    Mahasiswa* next;
    Nilai* firstNilai;
};

// Core
void init(Mahasiswa*& head);
Mahasiswa* cariMahasiswa(Mahasiswa* head, const string& nim);
void hapusMahasiswa(Mahasiswa*& head, const string& nim);
void clearAll(Mahasiswa*& head);

// Mahasiswa
void tambahMahasiswa(Mahasiswa*& head);

//Nilai
void inputNilai(Mahasiswa* mhs);
void updateNilai(Mahasiswa* mhs);

// Tampil
void tampilNilaiMahasiswa(const Mahasiswa* mhs);
void tampilPesertaMatkul(const Mahasiswa* head, const string& matkul);

//Util
bool cekLulus(float nilai);

#endif


