#include <iostream>  // library untuk input output
#include <vector>       // library untuk vector
#include <algorithm>    // library untuk remove_if
#include <iomanip>    // library untuk setw

using namespace std;    // menggunakan namespace std untuk mempersingkat penulisan

class PetShop   // class PetShop
{
private:    // atribut private
    class Produk    // class Produk
    {
    private:    // atribut private
        int id;    // atribut id untuk menyimpan id produk
        string namaProduk;  // atribut namaProduk untuk menyimpan nama produk
        string kategori;    // atribut kategori untuk menyimpan kategori produk
        double harga;   // atribut harga untuk menyimpan harga produk

    public:    // atribut public
        Produk(int id, string namaProduk, string kategori, double harga)    // constructor untuk class Produk
        {
            this->id = id;  // inisialisasi atribut id dengan parameter id
            this->namaProduk = namaProduk;  // inisialisasi atribut namaProduk dengan parameter namaProduk
            this->kategori = kategori;  // inisialisasi atribut kategori dengan parameter kategori
            this->harga = harga;    // inisialisasi atribut harga dengan parameter harga
        }

        // getter
        int getId() const { return id; }    // getter untuk atribut id
        string getNamaProduk() const { return namaProduk; }   // getter untuk atribut namaProduk
        string getKategori() const { return kategori; }  // getter untuk atribut kategori
        double getHarga() const { return harga; }   // getter untuk atribut harga

        // setter
        void setNamaProduk(string nama) { this->namaProduk = nama; }    // setter untuk atribut namaProduk
        void setKategori(string kategori) { this->kategori = kategori; }    // setter untuk atribut kategori
        void setHarga(double harga) { this->harga = harga; }    // setter untuk atribut harga

        // method untuk menampilkan data produk
        void display() const
        {
            cout << left << setw(10) << id  // menampilkan id
                 << setw(25) << namaProduk  // menampilkan nama produk
                 << setw(20) << kategori    // menampilkan kategori
                 << "Rp " << setw(6) << static_cast<int>(harga) << endl;    // menampilkan harga
        }
    };

    vector<Produk> produkList;  // vector untuk menyimpan data produk

public:   // atribut public
    void tambahProduk(int id, string nama, string kategori, double harga)   // method untuk menambahkan produk
    {
        produkList.push_back(Produk(id, nama, kategori, harga));    // menambahkan produk ke dalam vector produkList
        cout << "Produk berhasil ditambahkan!\n";   // menampilkan pesan produk berhasil ditambahkan
    }

    void tampilkanProduk() const    // method untuk menampilkan data produk
    {
        if (produkList.empty())   // jika produkList kosong
        {
            cout << "Tidak ada produk yang tersedia\n"; 
            return;
        }

        // Header tabel
        cout << left << setw(10) << "ID"    // menampilkan baris ID
             << setw(25) << "Nama Produk"       // menampilkan baris Nama Produk
             << setw(20) << "Kategori"        // menampilkan baris Kategori
             << "Harga\n";  // menampilkan baris Harga
        cout << string(65, '-') << endl;    // menampilkan garis pemisah

        // Menampilkan data produk
        for (const auto &produk : produkList)
        {
            produk.display();
        }
    }

    void ubahProduk(int id, string namaBaru, string kategoriBaru, double hargaBaru)   // method untuk mengubah data produk
    {
        for (auto &produk : produkList)   // loop untuk setiap produk dalam produkList
        {
            if (produk.getId() == id)   // jika id produk sama dengan id yang dicari
            {
                produk.setNamaProduk(namaBaru);   // set nama produk baru
                produk.setKategori(kategoriBaru);   // set kategori produk baru
                produk.setHarga(hargaBaru);  // set harga produk baru
                cout << "Produk dengan ID " << id << " berhasil diperbarui!\n";
                return;
            }
        }
        cout << "Produk dengan ID " << id << " tidak ditemukan\n";  // jika produk tidak ditemukan
    }

    void hapusProduk(int id)    // method untuk menghapus data produk
    {
        auto it = remove_if(produkList.begin(), produkList.end(),[id](const Produk &p){ return p.getId() == id; });   // menghapus produk dengan id yang sesuai

        if (it != produkList.end())  // jika produk ditemukan
        {
            produkList.erase(it, produkList.end());  // hapus produk
            cout << "Produk dengan ID " << id << " berhasil dihapus!\n";
        }
        else    // jika produk tidak ditemukan
        {
            cout << "Produk dengan ID " << id << " tidak ditemukan\n";
        }
    }

    void cariProduk(string nama) const  // method untuk mencari data produk
    {
        bool ditemukan = false;  // inisialisasi variabel ditemukan dengan false
        cout << string(55, '-') << endl;    // menampilkan garis pemisah

        for (const auto &produk : produkList)   // loop untuk setiap produk dalam produkList
        {
            if (produk.getNamaProduk().find(nama) != string::npos)  // jika nama produk ditemukan
            {
                produk.display();   // tampilkan data produk
                ditemukan = true;   // set ditemukan menjadi true
            }
        }

        if (!ditemukan)  // jika produk tidak ditemukan
        {
            cout << "Produk tidak ditemukan\n";
        }
    }
};

int main()
{
    PetShop petshop;    // membuat objek petshop dari class PetShop
    int pilihan, id;    // deklarasi variabel pilihan dan id
    string nama, kategori;  // deklarasi variabel nama dan kategori
    double harga;   // deklarasi variabel harga

    do
    {
        cout << "\nMENU PETSHOP\n";   // menampilkan menu petshop
        cout << "1. Tambah Produk\n";   // menampilkan menu tambah produk
        cout << "2. Tampilkan Produk\n";    // menampilkan menu tampilkan produk
        cout << "3. Ubah Produk\n";   // menampilkan menu ubah produk
        cout << "4. Hapus Produk\n";    // menampilkan menu hapus produk
        cout << "5. Cari Produk\n"; // menampilkan menu cari produk
        cout << "0. Keluar\n";  // menampilkan menu keluar
        cout << "Pilih menu: ";   // menampilkan pesan pilih menu
        cin >> pilihan; // input pilihan
        cin.ignore();   // mengabaikan karakter newline

        switch (pilihan)    // switch case untuk pilihan menu
        {
        case 1: // case 1 untuk menu tambah produk
            cout << "\nTambah Produk\n";
            cout << "ID: ";
            cin >> id;
            cin.ignore();
            cout << "Nama Produk: ";
            getline(cin, nama);
            cout << "Kategori: ";
            getline(cin, kategori);
            cout << "Harga: Rp ";
            cin >> harga;
            petshop.tambahProduk(id, nama, kategori, harga);
            break;

        case 2: // case 2 untuk menu tampilkan produk
            cout << "\nDaftar Produk PetShop\n";
            petshop.tampilkanProduk();
            break;

        case 3: // case 3 untuk menu ubah produk
            cout << "\nUbah Produk\n";
            cout << "ID Produk yang akan diubah: ";
            cin >> id;
            cin.ignore();
            cout << "Nama Baru: ";
            getline(cin, nama);
            cout << "Kategori Baru: ";
            getline(cin, kategori);
            cout << "Harga Baru: Rp ";
            cin >> harga;
            petshop.ubahProduk(id, nama, kategori, harga);
            break;

        case 4: // case 4 untuk menu hapus produk
            cout << "\nHapus Produk\n";
            cout << "ID Produk yang akan dihapus: ";
            cin >> id;
            petshop.hapusProduk(id);
            break;

        case 5: // case 5 untuk menu cari produk
            cout << "\nCari Produk\n";
            cout << "Masukkan nama produk: ";
            cin.ignore();
            getline(cin, nama);
            petshop.cariProduk(nama);
            break;

        case 0: // case 0 untuk menu keluar
            cout << "Keluar dari program petshop. Terima kasih!\n";
            break;

        default:    // default jika pilihan tidak valid
            cout << "Pilihan tidak valid. Coba lagi\n";
            break;
        }
    } while (pilihan != 0); // loop hingga pilihan 0

    return 0;
}
