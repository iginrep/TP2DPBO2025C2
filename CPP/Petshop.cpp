#include <iostream>
#include <string>

class PetShop {
private:
    int id[100];
    std::string namaProduk[100];
    std::string kategori[100];
    double harga[100];
    int jumlahProduk;

public:
    PetShop() {
        this->jumlahProduk = 0;
    }

    void tambahProduk(int _id, std::string _nama, std::string _kategori, double _harga) {
        if (this->jumlahProduk < 100) {
            this->id[this->jumlahProduk] = _id;
            this->namaProduk[this->jumlahProduk] = _nama;
            this->kategori[this->jumlahProduk] = _kategori;
            this->harga[this->jumlahProduk] = _harga;
            this->jumlahProduk++;
            std::cout << "Produk berhasil ditambahkan!\n";
        } else {
            std::cout << "Kapasitas produk penuh!\n";
        }
    }

    void tampilkanProduk() {
        if (this->jumlahProduk == 0) {
            std::cout << "Tidak ada produk yang tersedia\n";
            return;
        }
        
        std::cout << "\nDaftar Produk:\n";
        for (int i = 0; i < this->jumlahProduk; i++) {
            std::cout << "ID: " << this->id[i] << ", Nama: " << this->namaProduk[i] 
                      << ", Kategori: " << this->kategori[i] 
                      << ", Harga: Rp " << this->harga[i] << "\n";
        }
    }

    void ubahProduk(int _id, std::string _nama, std::string _kategori, double _harga) {
        for (int i = 0; i < this->jumlahProduk; i++) {
            if (this->id[i] == _id) {
                this->namaProduk[i] = _nama;
                this->kategori[i] = _kategori;
                this->harga[i] = _harga;
                std::cout << "Produk berhasil diperbarui!\n";
                return;
            }
        }
        std::cout << "Produk tidak ditemukan!\n";
    }

    void hapusProduk(int _id) {
        for (int i = 0; i < this->jumlahProduk; i++) {
            if (this->id[i] == _id) {
                for (int j = i; j < this->jumlahProduk - 1; j++) {
                    this->id[j] = this->id[j + 1];
                    this->namaProduk[j] = this->namaProduk[j + 1];
                    this->kategori[j] = this->kategori[j + 1];
                    this->harga[j] = this->harga[j + 1];
                }
                this->jumlahProduk--;
                std::cout << "Produk berhasil dihapus!\n";
                return;
            }
        }
        std::cout << "Produk tidak ditemukan!\n";
    }

    void cariProduk(std::string _nama) {
        bool ditemukan = false;
        for (int i = 0; i < this->jumlahProduk; i++) {
            if (this->namaProduk[i].find(_nama) != std::string::npos) {
                std::cout << "ID: " << this->id[i] << ", Nama: " << this->namaProduk[i] 
                          << ", Kategori: " << this->kategori[i] 
                          << ", Harga: Rp " << this->harga[i] << "\n";
                ditemukan = true;
            }
        }
        if (!ditemukan) {
            std::cout << "Produk tidak ditemukan!\n";
        }
    }
};