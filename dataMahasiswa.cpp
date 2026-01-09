#include "dataMahasiswa.h"
#include <iostream>
using namespace std;

// Init
void init(Mahasiswa*& head) {
    head = nullptr;
}

// Cari Mahasiswa
Mahasiswa* cariMahasiswa(Mahasiswa* head, const string& nim) {
    while (head) {
        if (head->nim == nim) return head;
        head = head->next;
    }
    return nullptr;
}

// Tambah Mahasiswa
void tambahMahasiswa(Mahasiswa*& head) {
    Mahasiswa* m = new Mahasiswa;
    cout << "NIM  : "; getline(cin, m->nim);
    cout << "Nama : "; getline(cin, m->nama);

    if (m->nim.empty() || m->nama.empty()) {
        cout << "Data tidak boleh kosong!\n";
        delete m;
        return;
    }

    m->firstNilai = nullptr;
    m->next = head;
    head = m;
}

// Input Nilai
void inputNilai(Mahasiswa* mhs) {
    if (!mhs) {
        cout << "Mahasiswa tidak ditemukan!\n";
        return;
    }

    Nilai* n = new Nilai;
    cout << "Mata Kuliah : "; getline(cin, n->matkul);
    cout << "Nilai       : ";
    cin >> n->nilai;

    if (cin.fail()) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Input nilai tidak valid!\n";
        delete n;
        return;
    }
    cin.ignore();

    // Cegah duplikasi matkul
    Nilai* temp = mhs->firstNilai;
    while (temp) {
        if (temp->matkul == n->matkul) {
            cout << "Mata kuliah sudah ada!\n";
            delete n;
            return;
        }
        temp = temp->next;
    }

    n->next = mhs->firstNilai;
    mhs->firstNilai = n;
}

// Update Nilai
void updateNilai(Mahasiswa* mhs) {
    if (!mhs) {
        cout << "Mahasiswa tidak ditemukan!\n";
        return;
    }

    string matkul;
    cout << "Mata kuliah yang diupdate: ";
    getline(cin, matkul);

    Nilai* n = mhs->firstNilai;
    while (n && n->matkul != matkul) {
        n = n->next;
    }

    if (!n) {
        cout << "Mata kuliah tidak ditemukan!\n";
        return;
    }

    cout << "Nilai lama: " << n->nilai << endl;
    cout << "Nilai baru: ";
    cin >> n->nilai;

    if (cin.fail()) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Input nilai tidak valid!\n";
        return;
    }
    cin.ignore();

    cout << "Nilai berhasil diperbarui.\n";
}

// Tampil Nilai
void tampilNilaiMahasiswa(const Mahasiswa* mhs) {
    if (!mhs) {
        cout << "Mahasiswa tidak ditemukan!\n";
        return;
    }

    cout << "\nNIM  : " << mhs->nim;
    cout << "\nNama : " << mhs->nama << endl;

    if (!mhs->firstNilai) {
        cout << "Belum ada nilai.\n";
        return;
    }

    Nilai* n = mhs->firstNilai;
    while (n) {
        cout << "  " << n->matkul << " : " << n->nilai
             << (cekLulus(n->nilai) ? " (Lulus)" : " (Tidak Lulus)") << endl;
        n = n->next;
    }
}

// Perserta Mata Kuliah
void tampilPesertaMatkul(const Mahasiswa* head, const string& matkul) {
    bool found = false;
    while (head) {
        Nilai* n = head->firstNilai;
        while (n) {
            if (n->matkul == matkul) {
                cout << head->nim << " - " << head->nama << endl;
                found = true;
                break;
            }
            n = n->next;
        }
        head = head->next;
    }
    if (!found) cout << "Tidak ada peserta.\n";
}

// hapus Mahasiswa
void hapusMahasiswa(Mahasiswa*& head, const string& nim) {
    Mahasiswa *curr = head, *prev = nullptr;

    while (curr && curr->nim != nim) {
        prev = curr;
        curr = curr->next;
    }

    if (!curr) {
        cout << "Mahasiswa tidak ditemukan!\n";
        return;
    }

    Nilai* n = curr->firstNilai;
    while (n) {
        Nilai* del = n;
        n = n->next;
        delete del;
    }

    if (!prev) head = curr->next;
    else prev->next = curr->next;

    delete curr;
    cout << "Mahasiswa berhasil dihapus.\n";
}

// Clear All
void clearAll(Mahasiswa*& head) {
    while (head) {
        hapusMahasiswa(head, head->nim);
    }
}

// Cek Lulus
bool cekLulus(float nilai) {
    return nilai >= 60;
}
