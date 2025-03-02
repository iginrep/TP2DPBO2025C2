#include "Petshop.cpp"

class Aksesoris : public Petshop
{
    // atribut
private:
    string jenis_aksesoris;
    string bahan_aksesoris;
    string warna_aksesoris;

public:
    Aksesoris()
    {
    }

    // constructor
    Aksesoris(int id, string nama, double harga, int stok, string jenis, string bahan, string warna)
    {
        this->set_id(id);
        this->set_nama(nama);
        this->set_harga(harga);
        this->set_stok(stok);
        this->jenis_aksesoris = jenis;
        this->bahan_aksesoris = bahan;
        this->warna_aksesoris = warna;
    }

    void set_jenis(string jenis)
    {
        this->jenis_aksesoris = jenis;
    }

    void set_bahan(string bahan)
    {
        this->bahan_aksesoris = bahan;
    }

    void set_warna(string warna)
    {
        this->warna_aksesoris = warna;
    }

    string get_jenis()
    {
        return this->jenis_aksesoris;
    }

    string get_bahan()
    {
        return this->bahan_aksesoris;
    }

    string get_warna()
    {
        return this->warna_aksesoris;
    }
};
