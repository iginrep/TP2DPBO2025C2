#include "header.hpp"

PetShop::Produk::Produk(int id, string namaProduk, string kategori, double harga) {
    this->id = id;
    this->namaProduk = namaProduk;
    this->kategori = kategori;
    this->harga = harga;
}

int PetShop::Produk::getId() const { return id; }
string PetShop::Produk::getNamaProduk() const { return namaProduk; }
string PetShop::Produk::getKategori() const { return kategori; }
double PetShop::Produk::getHarga() const { return harga; }
void PetShop::Produk::setNamaProduk(string nama) { this->namaProduk = nama; }
void PetShop::Produk::setKategori(string kategori) { this->kategori = kategori; }
void PetShop::Produk::setHarga(double harga) { this->harga = harga; }
void PetShop::Produk::display() const {
    cout << left << setw(10) << id
         << setw(25) << namaProduk
         << setw(20) << kategori
         << "Rp " << setw(6) << static_cast<int>(harga) << endl;
}

void PetShop::tambahProduk(int id, string nama, string kategori, double harga) {
    produkList.push_back(Produk(id, nama, kategori, harga));
    cout << "Produk berhasil ditambahkan!\n";
}

void PetShop::tampilkanProduk() const {
    if (produkList.empty()) {
        cout << "Tidak ada produk yang tersedia\n";
        return;
    }
    cout << left << setw(10) << "ID"
         << setw(25) << "Nama Produk"
         << setw(20) << "Kategori"
         << "Harga\n";
    cout << string(65, '-') << endl;
    for (const auto &produk : produkList) {
        produk.display();
    }
}

void PetShop::ubahProduk(int id, string namaBaru, string kategoriBaru, double hargaBaru) {
    for (auto &produk : produkList) {
        if (produk.getId() == id) {
            produk.setNamaProduk(namaBaru);
            produk.setKategori(kategoriBaru);
            produk.setHarga(hargaBaru);
            cout << "Produk dengan ID " << id << " berhasil diperbarui!\n";
            return;
        }
    }
    cout << "Produk dengan ID " << id << " tidak ditemukan\n";
}

void PetShop::hapusProduk(int id) {
    auto it = remove_if(produkList.begin(), produkList.end(), [id](const Produk &p) { return p.getId() == id; });
    if (it != produkList.end()) {
        produkList.erase(it, produkList.end());
        cout << "Produk dengan ID " << id << " berhasil dihapus!\n";
    } else {
        cout << "Produk dengan ID " << id << " tidak ditemukan\n";
    }
}

void PetShop::cariProduk(string nama) const {
    bool ditemukan = false;
    cout << string(55, '-') << endl;
    for (const auto &produk : produkList) {
        if (produk.getNamaProduk().find(nama) != string::npos) {
            produk.display();
            ditemukan = true;
        }
    }
    if (!ditemukan) {
        cout << "Produk tidak ditemukan\n";
    }
}