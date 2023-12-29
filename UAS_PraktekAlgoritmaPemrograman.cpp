/*    Nama Tugas      : UAS Pratikum Algoritma Pemrograman
      Nama Programmer : NAILA RASYAD (23343012)
      Kasus Program   : Program Aplikasi Pemensana Tiket Kereta
*/

#include <iostream>
#include <string>
#include <cstdlib>
#include <algorithm>

using namespace std;

struct Tiket {
    int id;
    double harga;
    bool sudahDipesan;
};

struct Penumpang {
    int id;
    string nama;
    string alamat;
    string tujuan;
    Tiket tiket;
};

Penumpang* daftarPenumpang = new Penumpang[100];
int jumlahPenumpang = 0;
int kapasitasPenumpang = 100;

// Fungsi untuk menghasilkan ID penumpang secara acak
int generateId() {
    int id;
    bool apakahUnik;

    do {
       id = rand() % 1000 + 1;
       apakahUnik = true;

       for (int i = 0; i < jumlahPenumpang; i++){
        if(daftarPenumpang[i].id == id){
            apakahUnik = false;
            break;
        }
       }
    } while (!apakahUnik);

    return id;  
}

// Fungsi untuk menambahkan data penumpang
void tambahkanPenumpang() {
    if (jumlahPenumpang == kapasitasPenumpang) {
    
        Penumpang* temp = new Penumpang[kapasitasPenumpang * 2]; 
        for (int i = 0; i < jumlahPenumpang; i++) {
            temp[i] = daftarPenumpang[i];  
        }
        delete[] daftarPenumpang;  
        daftarPenumpang = temp;    
        kapasitasPenumpang *= 2;   
    }

    Penumpang p;
    p.id = generateId();
    cout << "Masukkan nama penumpang    : ";
    cin >> p.nama;
    cout << "Masukkan alamat penumpang  : ";
    cin >> p.alamat;  
    cout << "Masukkan tujuan            : ";
    cin >> p.tujuan;
    cout << "Masukkan harga tiket       : Rp. ";
    cin >> p.tiket.harga;
    p.tiket.id = p.id;
    p.tiket.sudahDipesan = false;
    daftarPenumpang[jumlahPenumpang++] = p;
    cout << "Penumpang berhasil ditambahkan dengan ID: " << p.id << endl;
}

// Fungsi untuk menampilkan data penumpang
void tampilkanDataPenumpang() {
    cout << "\n============================== Data Penumpang ==============================\n";
    cout << "ID\t| Nama\t\t| Alamat\t| Tujuan\t| Harga Tiket (Rp)\n";
    cout << "----------------------------------------------------------------------------\n";
    for (int i = 0; i < jumlahPenumpang; i++) {
        cout << daftarPenumpang[i].id << "\t| " << daftarPenumpang[i].nama << "\t\t| " << daftarPenumpang[i].alamat << "\t\t| " << daftarPenumpang[i].tujuan << "\t\t| " << daftarPenumpang[i].tiket.harga << endl;
    }
    cout << "----------------------------------------------------------------------------\n";
}

bool compareById(const Penumpang &a, const Penumpang &b) {
    return a.id < b.id;
}

// Fungsi untuk mengurutkan data penumpang berdasarkan ID
void urutkanDataPenumpang() {
    sort(daftarPenumpang, daftarPenumpang + jumlahPenumpang, compareById);
    cout << "Data pelanggan berhasil diurutkan berdasarkan ID.\n";
}

// Funsi untuk memesan tiket
void pesanTiket() {
    int id;
    cout << "Masukkan ID penumpang untuk pesan tiket: ";
    cin >> id;

    for (int i = 0; i < jumlahPenumpang; i++) {
        if (daftarPenumpang[i].id == id && !daftarPenumpang[i].tiket.sudahDipesan) {
            daftarPenumpang[i].tiket.sudahDipesan = true;
            cout << "Tiket untuk ID " << id << " berhasil dipesan!" << endl;
            return;
        }
    }
    cout << "Penumpang dengan ID " << id << " tidak ditemukan atau sudah memesan tiket." << endl;
}

// Fungsi untuk menampilkan riwayat pesanan penumpang
void tampilkanRiwayatPesanan() {
    cout << "\n===================== Riwayat Pesanan =====================\n";
    for (int i = 0; i < jumlahPenumpang; i++) {
        cout << "ID Penumpang   : " << daftarPenumpang[i].id << endl;
        cout << "Nama           : " << daftarPenumpang[i].nama << endl;
        cout << "Tujuan         : " << daftarPenumpang[i].tujuan << endl;
        cout << "Harga Tiket    : Rp. " << daftarPenumpang[i].tiket.harga << endl;
        
        if (daftarPenumpang[i].tiket.sudahDipesan) {
            cout << "Status         : Sudah dipesan" << endl;
        } else {
            cout << "Status         : Belum dipesan" << endl;
        }
        cout << "-----------------------------------------------------------\n";
    }
}

// Fungsi untuk mencari penumpang berdasarkan nama
void cariPenumpangByNama() {
    string nama;
    bool ditemukan = false;

    cout << "Masukkan Nama penumpang yang ingin dicari: ";
    cin >> nama;

    for (int i = 0; i < jumlahPenumpang; i++) {
        if (daftarPenumpang[i].nama == nama) {
            cout << "\n================ Data Penumpang ================" << endl;
            cout << "ID Penumpang   : " << daftarPenumpang[i].id << endl;
            cout << "Nama           : " << daftarPenumpang[i].nama << endl;
            cout << "Alamat         : " << daftarPenumpang[i].alamat << endl;
            cout << "Tujuan         : " << daftarPenumpang[i].tujuan << endl;
            cout << "Harga Tiket    : Rp. " << daftarPenumpang[i].tiket.harga << endl;

            if (daftarPenumpang[i].tiket.sudahDipesan) {
                cout << "Status Pesanan : Sudah dipesan" << endl;
            } else {
                cout << "Status Pesanan : Belum dipesan" << endl;
            }
            ditemukan = true;
            break;
        }
    }
    if (!ditemukan) {
        cout << "Penumpang dengan nama " << nama << " tidak ditemukan." << endl;
    }
}

// Fungsi utama dalam program
int main() {
    int pilihan;

    do {
        cout << " "<< endl;
        cout << "|========================================================|" << endl;
        cout << "|            Aplikasi Pemesanan Tiket Kereta             |" << endl;
        cout << "|========================================================|" << endl;

        cout << "Menu Pemesanan Tiket Kereta:" << endl;
        cout << "1. Tambahkan Penumpang" << endl;
        cout << "2. Tampilkan Data Penumpang" << endl;
        cout << "3. Urutkan Data Penumpang Berdasarkan ID" << endl;
        cout << "4. Pesan Tiket" << endl;
        cout << "5. Tampilkan Riwayat Pesanan" << endl;
        cout << "6. Cari Penumpang Berdasarkan Nama" << endl;
        cout << "7. Keluar" << endl;
        cout << "Pilih menu (1-6): ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                tambahkanPenumpang();
                break;
            case 2:
                tampilkanDataPenumpang();
                break;
            case 3:
                urutkanDataPenumpang();
                tampilkanDataPenumpang();
                break;
            case 4:
                pesanTiket();
                break;
            case 5:
                tampilkanRiwayatPesanan();
                break;
            case 6:
                cariPenumpangByNama();
                break;
            case 7:
                cout << "Terima kasih telah menggunakan layanan kami." << endl;
                break;
            default:
                cout << "Pilihan tidak valid!" << endl;
                break;
        }
    } while (pilihan != 7);

    delete[] daftarPenumpang;

    return 0;
}