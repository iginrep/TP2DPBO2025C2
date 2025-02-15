#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

class PetShop {
private:
    class Produk {
    private:
        int id;
        string namaProduk;
        string kategori;
        double harga;
    public:
        Produk(int id, string namaProduk, string kategori, double harga);
        int getId() const;
        string getNamaProduk() const;
        string getKategori() const;
        double getHarga() const;
        void setNamaProduk(string nama);
        void setKategori(string kategori);
        void setHarga(double harga);
        void display() const;
    };

    vector<Produk> produkList;

public:
    void tambahProduk(int id, string nama, string kategori, double harga);
    void tampilkanProduk() const;
    void ubahProduk(int id, string namaBaru, string kategoriBaru, double hargaBaru);
    void hapusProduk(int id);
    void cariProduk(string nama) const;
};