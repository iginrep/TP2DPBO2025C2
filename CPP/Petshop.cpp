#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

class Petshop
{

private:
    int id;
    string nama_produk;
    double harga_produk;
    int stok_produk;

public:
    Petshop()
    {}

    Petshop(int id, string nama, double harga, int stok)
    {
        this->id = id;
        this->nama_produk = nama;
        this->harga_produk = harga;
        this->stok_produk = stok;
    }

    void set_id(int id)
    {
        this->id = id;
    }

    void set_nama(string nama)
    {
        this->nama_produk = nama;
    }

    void set_harga(double harga)
    {
        this->harga_produk = harga;
    }

    void set_stok(int stok)
    {
        this->stok_produk = stok;
    }

    int get_id()
    {
        return this->id;
    }

    string get_nama()
    {
        return this->nama_produk;
    }

    double get_harga()
    {
        return this->harga_produk;
    }

    int get_stok()
    {
        return this->stok_produk;
    }
    
};
