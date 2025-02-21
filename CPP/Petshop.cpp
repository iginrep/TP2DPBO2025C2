#include <iostream>
#include <string>

// class PetShop
class PetShop {
private:    
    int id[100];    // array untuk menyimpan ID produk
    std::string namaProduk[100];    // array untuk menyimpan nama produk
    std::string kategori[100];  // array untuk menyimpan kategori produk
    double harga[100];  // array untuk menyimpan harga produk
    int jumlahProduk;   // jumlah produk yang tersedia

public:
    PetShop() {
        this->jumlahProduk = 0; // set jumlah produk awal
    }

    // method untuk menambahkan produk
    void tambahProduk(int _id, std::string _nama, std::string _kategori, double _harga) {
        if (this->jumlahProduk < 100) { // cek apakah kapasitas produk masih cukup
            this->id[this->jumlahProduk] = _id; // tambahkan ID produk
            this->namaProduk[this->jumlahProduk] = _nama;   // tambahkan nama produk
            this->kategori[this->jumlahProduk] = _kategori; // tambahkan kategori produk
            this->harga[this->jumlahProduk] = _harga;   // tambahkan harga produk
            this->jumlahProduk++;   // tambahkan jumlah produk
            std::cout << "Produk berhasil ditambahkan!\n";  // tampilkan pesan berhasil
        } else {
            std::cout << "Kapasitas produk penuh!\n";   // tampilkan pesan kapasitas penuh
        }
    }

    // method untuk menampilkan produk
    void tampilkanProduk() {
        if (this->jumlahProduk == 0) {  // cek apakah tidak ada produk yang tersedia
            std::cout << "Tidak ada produk yang tersedia\n";
            return;
        }
        
        std::cout << "\nDaftar Produk:\n";  // tampilkan daftar produk
        for (int i = 0; i < this->jumlahProduk; i++) {  // loop sebanyak jumlah produk
            std::cout << "ID: " << this->id[i] << ", Nama: " << this->namaProduk[i]     // tampilkan ID, nama, kategori, dan harga produk
                      << ", Kategori: " << this->kategori[i]    
                      << ", Harga: Rp " << this->harga[i] << "\n";
        }
    }

    // method untuk mengubah produk
    void ubahProduk(int _id, std::string _nama, std::string _kategori, double _harga) {
        for (int i = 0; i < this->jumlahProduk; i++) {  // loop sebanyak jumlah produk
            if (this->id[i] == _id) {   // cek apakah ID produk ditemukan
                this->namaProduk[i] = _nama;    // ubah nama produk
                this->kategori[i] = _kategori;  // ubah kategori produk
                this->harga[i] = _harga;    // ubah harga produk
                std::cout << "Produk berhasil diperbarui!\n";
                return;
            }
        }
        std::cout << "Produk tidak ditemukan!\n";
    }

    // method untuk menghapus produk
    void hapusProduk(int _id) {
        for (int i = 0; i < this->jumlahProduk; i++) {  // loop sebanyak jumlah produk
            if (this->id[i] == _id) {   // cek apakah ID produk ditemukan
                for (int j = i; j < this->jumlahProduk - 1; j++) {  // loop sebanyak jumlah produk - 1
                    this->id[j] = this->id[j + 1];  // geser ID produk
                    this->namaProduk[j] = this->namaProduk[j + 1];  // geser nama produk
                    this->kategori[j] = this->kategori[j + 1];  // geser kategori produk
                    this->harga[j] = this->harga[j + 1];    // geser harga produk
                }
                this->jumlahProduk--;   // kurangi jumlah produk
                std::cout << "Produk berhasil dihapus!\n";  // tampilkan pesan berhasil
                return;
            }
        }
        std::cout << "Produk tidak ditemukan!\n";
    }

    // method untuk mencari produk
    void cariProduk(std::string _nama) {    // parameter _nama untuk mencari nama produk
        bool ditemukan = false; // variabel untuk mengecek apakah produk ditemukan
        for (int i = 0; i < this->jumlahProduk; i++) {  // loop sebanyak jumlah produk
            if (this->namaProduk[i].find(_nama) != std::string::npos) {   // cek apakah nama produk ditemukan
                std::cout << "ID: " << this->id[i] << ", Nama: " << this->namaProduk[i]     // tampilkan ID, nama, kategori, dan harga produk
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