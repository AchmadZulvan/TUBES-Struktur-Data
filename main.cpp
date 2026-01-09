#include "dataMahasiswa.h"
#include <iostream>
using namespace std;

int main() {
    Mahasiswa* head;
    init(head);

    int pilih;
    string nim, matkul;

    do {
        cout << "\n===== SISTEM NILAI MAHASISWA =====\n";
        cout << "1. Tambah Mahasiswa\n";
        cout << "2. Input Nilai\n";
        cout << "3. Tampilkan Nilai Mahasiswa\n";
        cout << "4. Tampilkan Peserta Mata Kuliah\n";
        cout << "5. Hapus Mahasiswa\n";
        cout << "0. Keluar\n";
        cout << "Pilih: ";

        cin >> pilih;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Input harus angka!\n";
            continue;
        }
        cin.ignore();

        switch (pilih) {
        case 1:
            tambahMahasiswa(head);
            break;
        case 2:
            cout << "NIM: "; getline(cin, nim);
            inputNilai(cariMahasiswa(head, nim));
            break;
        case 3:
            cout << "NIM: "; getline(cin, nim);
            tampilNilaiMahasiswa(cariMahasiswa(head, nim));
            break;
        case 4:
            cout << "Nama Mata Kuliah: ";
            getline(cin, matkul);
            tampilPesertaMatkul(head, matkul);
            break;
        case 5:
            cout << "NIM: "; getline(cin, nim);
            hapusMahasiswa(head, nim);
            break;
        }
    } while (pilih != 0);

    clearAll(head);
    return 0;
}
