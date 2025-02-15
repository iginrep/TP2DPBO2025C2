#include "header.hpp"

int main() {
    PetShop petshop;
    int pilihan, id;
    string nama, kategori;
    double harga;
    do {
        cout << "\nMENU PETSHOP\n";
        cout << "1. Tambah Produk\n";
        cout << "2. Tampilkan Produk\n";
        cout << "3. Ubah Produk\n";
        cout << "4. Hapus Produk\n";
        cout << "5. Cari Produk\n";
        cout << "0. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihan;
        cin.ignore();
        switch (pilihan) {
        case 1:
            cout << "\nTambah Produk\n";
            cout << "ID: "; cin >> id;
            cin.ignore();
            cout << "Nama Produk: "; getline(cin, nama);
            cout << "Kategori: "; getline(cin, kategori);
            cout << "Harga: Rp "; cin >> harga;
            petshop.tambahProduk(id, nama, kategori, harga);
            break;
        case 2:
            cout << "\nDaftar Produk PetShop\n";
            petshop.tampilkanProduk();
            break;
        case 3:
            cout << "\nUbah Produk\n";
            cout << "ID Produk yang akan diubah: "; cin >> id;
            cin.ignore();
            cout << "Nama Baru: "; getline(cin, nama);
            cout << "Kategori Baru: "; getline(cin, kategori);
            cout << "Harga Baru: Rp "; cin >> harga;
            petshop.ubahProduk(id, nama, kategori, harga);
            break;
        case 4:
            cout << "\nHapus Produk\n";
            cout << "ID Produk yang akan dihapus: "; cin >> id;
            petshop.hapusProduk(id);
            break;
        case 5:
            cout << "\nCari Produk\n";
            cout << "Masukkan nama produk: ";
            cin.ignore();
            getline(cin, nama);
            petshop.cariProduk(nama);
            break;
        case 0:
            cout << "Keluar dari program petshop. Terima kasih!\n";
            break;
        default:
            cout << "Pilihan tidak valid. Coba lagi\n";
            break;
        }
    } while (pilihan != 0);
    return 0;
}
