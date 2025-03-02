#include "Aksesoris.cpp"

class Baju : public Aksesoris
{
    // atribut
private:
    string untuk_hewan;
    string size_baju;
    string merk_baju;

public:
    Baju()
    {
    }

    // constructor
    Baju(int id, string nama, double harga, int stok, string jenis, string bahan, string warna, string untuk, string size, string merk)
    {
        this->set_id(id);
        this->set_nama(nama);
        this->set_harga(harga);
        this->set_stok(stok);
        this->set_jenis(jenis);
        this->set_bahan(bahan);
        this->set_warna(warna);
        this->untuk_hewan = untuk;
        this->size_baju = size;
        this->merk_baju = merk;

    }

    void set_untuk(string untuk)
    {
        this->untuk_hewan = untuk;
    }

    void set_size(string size)
    {
        this->size_baju = size;
    }

    void set_merk(string merk)
    {
        this->merk_baju = merk;
    }

    string get_untuk()
    {
        return this->untuk_hewan;
    }

    string get_size()
    {
        return this->size_baju;
    }

    string get_merk()
    {
        return this->merk_baju;
    }


     
};
