#include "Baju.cpp"
#include <iterator>

int main()
{
    // tampilkan 5 data awal pada program saat pertama kali dijalankan menggunakan looping

    Baju baju1(1, "Baju", 50000, 10, "Kaos", "Katun", "Putih", "Kucing", "S", "Kucing");
    Baju baju2(2, "Kalung", 60000, 10, "Tali", "Woll", "Hitam", "Anjing", "M", "Anjing");
    Baju baju3(3, "Gelang", 70000, 10, "Tali", "Woll", "Merah", "Hamster", "L", "Hamster");
    Baju baju4(4, "Topi", 80000, 10, "Kain", "Katun", "Biru", "Kelinci", "XL", "Kelinci");
    Baju baju5(5, "Sepatu", 90000, 10, "Kulit", "Kulit", "Hijau", "Burung", "XXL", "Burung");

    vector<Baju> list_baju;
    list_baju.push_back(baju1);
    list_baju.push_back(baju2);
    list_baju.push_back(baju3);
    list_baju.push_back(baju4);
    list_baju.push_back(baju5);

    vector<Baju>::iterator it;
    // cout << "5 data awal pada program saat pertama kali dijalankan" << endl;
    // for (it = list_baju.begin(); it != list_baju.end(); it++)
    // {
    //     cout << "ID: " << it->get_id() << endl;
    //     cout << "Nama: " << it->get_nama() << endl;
    //     cout << "Harga: " << it->get_harga() << endl;
    //     cout << "Stok: " << it->get_stok() << endl;
    //     cout << "Jenis: " << it->get_jenis() << endl;
    //     cout << "Bahan: " << it->get_bahan() << endl;
    //     cout << "Warna: " << it->get_warna() << endl;
    //     cout << "Untuk: " << it->get_untuk() << endl;
    //     cout << "Size: " << it->get_size() << endl;
    //     cout << "Merk: " << it->get_merk() << endl;
    //     cout << endl;
    // }

    int id_terpanjang = 2;
    // deklarasi iterasi
    // iterasi untuk mencari id terpanjang
    for (it = list_baju.begin(); it != list_baju.end(); it++)
    {
        if (to_string(it->get_id()).length() > id_terpanjang)
        {
            id_terpanjang = to_string(it->get_id()).length();
        }
    }

    int nama_terpanjang = 4;
    // iterasi untuk mencari nama terpanjang
    for (it = list_baju.begin(); it != list_baju.end(); it++)
    {
        if (it->get_nama().length() > nama_terpanjang)
        {
            nama_terpanjang = it->get_nama().length();
        }
    }

    int harga_terpanjang = 4;
    // iterasi untuk mencari harga terpanjang
    for (it = list_baju.begin(); it != list_baju.end(); it++)
    {
        if (to_string(it->get_harga()).length() > harga_terpanjang)
        {
            harga_terpanjang = to_string(it->get_harga()).length();
        }
    }

    int stok_terpanjang = 4;
    // iterasi untuk mencari stok terpanjang
    for (it = list_baju.begin(); it != list_baju.end(); it++)
    {
        if (to_string(it->get_stok()).length() > stok_terpanjang)
        {
            stok_terpanjang = to_string(it->get_stok()).length();
        }
    }

    int jenis_terpanjang = 5;
    // iterasi untuk mencari jenis terpanjang
    for (it = list_baju.begin(); it != list_baju.end(); it++)
    {
        if (it->get_jenis().length() > jenis_terpanjang)
        {
            jenis_terpanjang = it->get_jenis().length();
        }
    }

    int bahan_terpanjang = 5;
    // iterasi untuk mencari bahan terpanjang
    for (it = list_baju.begin(); it != list_baju.end(); it++)
    {
        if (it->get_bahan().length() > bahan_terpanjang)
        {
            bahan_terpanjang = it->get_bahan().length();
        }
    }

    int warna_terpanjang = 5;
    // iterasi untuk mencari warna terpanjang
    for (it = list_baju.begin(); it != list_baju.end(); it++)
    {
        if (it->get_warna().length() > warna_terpanjang)
        {
            warna_terpanjang = it->get_warna().length();
        }
    }

    int untuk_terpanjang = 5;
    // iterasi untuk mencari untuk terpanjang
    for (it = list_baju.begin(); it != list_baju.end(); it++)
    {
        if (it->get_untuk().length() > untuk_terpanjang)
        {
            untuk_terpanjang = it->get_untuk().length();
        }
    }

    int size_terpanjang = 4;
    // iterasi untuk mencari size terpanjang
    for (it = list_baju.begin(); it != list_baju.end(); it++)
    {
        if (it->get_size().length() > size_terpanjang)
        {
            size_terpanjang = it->get_size().length();
        }
    }

    int merk_terpanjang = 4;
    // iterasi untuk mencari merk terpanjang
    for (it = list_baju.begin(); it != list_baju.end(); it++)
    {
        if (it->get_merk().length() > merk_terpanjang)
        {
            merk_terpanjang = it->get_merk().length();
        }
    }

    // cout << id_terpanjang << endl;
    // cout << nama_terpanjang << endl;
    // cout << harga_terpanjang << endl;
    // cout << stok_terpanjang << endl;
    // cout << jenis_terpanjang << endl;
    // cout << bahan_terpanjang << endl;
    // cout << warna_terpanjang << endl;
    // cout << untuk_terpanjang << endl;
    // cout << size_terpanjang << endl;
    // cout << merk_terpanjang << endl;

    int panjang_garis = id_terpanjang+nama_terpanjang+harga_terpanjang+stok_terpanjang+jenis_terpanjang+bahan_terpanjang+warna_terpanjang+untuk_terpanjang+size_terpanjang+merk_terpanjang+4;
    for (int i = 0; i < panjang_garis; i++)
    {
        cout << "-";
    }
    cout << endl;

    cout << "|ID";
    for (int i = 0; i < id_terpanjang - 2; i++)
    {
        cout << " ";
    }
    cout << "|Nama";
    for (int i = 0; i < nama_terpanjang - 4; i++)
    {
        cout << " ";
    }
    cout << "|Harga";
    for (int i = 0; i < harga_terpanjang - 5 - 7; i++)
    {
        cout << " ";
    }
    cout << "|Stok";
    for (int i = 0; i < stok_terpanjang - 4; i++)
    {
        cout << " ";
    }
    cout << "|Jenis";
    for (int i = 0; i < jenis_terpanjang - 5; i++)
    {
        cout << " ";
    }
    cout << "|Bahan";
    for (int i = 0; i < bahan_terpanjang - 5; i++)
    {
        cout << " ";
    }
    cout << "|Warna";
    for (int i = 0; i < warna_terpanjang - 5; i++)
    {
        cout << " ";
    }
    cout << "|Untuk";
    for (int i = 0; i < untuk_terpanjang - 5; i++)
    {
        cout << " ";
    }
    cout << "|Size";
    for (int i = 0; i < size_terpanjang - 4; i++)
    {
        cout << " ";
    }
    cout << "|Merk";
    for (int i = 0; i < merk_terpanjang - 4; i++)
    {
        cout << " ";
    }
    cout << "|" << endl;

    for (int i = 0; i < panjang_garis; i++)
    {
        cout << "-";
    }
    cout << endl;

    // tampilkan data baju menggunakan looping dan format seperti tabel
    for (it = list_baju.begin(); it != list_baju.end(); it++)
    {
        cout << "|" << it->get_id();
        for (int i = 0; i < id_terpanjang - to_string(it->get_id()).length(); i++)
        {
            cout << " ";
        }
        cout << "|" << it->get_nama();
        for (int i = 0; i < nama_terpanjang - it->get_nama().length(); i++)
        {
            cout << " ";
        }
        cout << "|" << it->get_harga();
        for (int i = 0; i < harga_terpanjang - to_string(it->get_harga()).length(); i++)
        {
            cout << " ";
        }
        cout << "|" << it->get_stok();
        for (int i = 0; i < stok_terpanjang - to_string(it->get_stok()).length(); i++)
        {
            cout << " ";
        }
        cout << "|" << it->get_jenis();
        for (int i = 0; i < jenis_terpanjang - it->get_jenis().length(); i++)
        {
            cout << " ";
        }
        cout << "|" << it->get_bahan();
        for (int i = 0; i < bahan_terpanjang - it->get_bahan().length(); i++)
        {
            cout << " ";
        }
        cout << "|" << it->get_warna();
        for (int i = 0; i < warna_terpanjang - it->get_warna().length(); i++)
        {
            cout << " ";
        }
        cout << "|" << it->get_untuk();
        for (int i = 0; i < untuk_terpanjang - it->get_untuk().length(); i++)
        {
            cout << " ";
        }
        cout << "|" << it->get_size();
        for (int i = 0; i < size_terpanjang - it->get_size().length(); i++)
        {
            cout << " ";
        }
        cout << "|" << it->get_merk();
        for (int i = 0; i < merk_terpanjang - it->get_merk().length(); i++)
        {
            cout << " ";
        }
        cout << "|" << endl;
    }

    for (int i = 0; i < panjang_garis; i++)
    {
        cout << "-";
    }
    cout << endl;

    // Buatkan saya input baru untuk data baju ke-6 dan tampilkan data baju ke-6 tersebut
    Baju baju6;
    int id, stok;
    double harga;
    string nama, jenis, bahan, warna, untuk, size, merk;
    cout << "Masukkan ID: ";
    cin >> id;
    cout << "Masukkan Nama: ";
    cin >> nama;
    cout << "Masukkan Harga: ";
    cin >> harga;
    cout << "Masukkan Stok: ";
    cin >> stok;
    cout << "Masukkan Jenis: ";
    cin >> jenis;
    cout << "Masukkan Bahan: ";
    cin >> bahan;
    cout << "Masukkan Warna: ";
    cin >> warna;
    cout << "Masukkan Untuk: ";
    cin >> untuk;
    cout << "Masukkan Size: ";
    cin >> size;
    cout << "Masukkan Merk: ";
    cin >> merk;

    baju6.set_id(id);
    baju6.set_nama(nama);
    baju6.set_harga(harga);
    baju6.set_stok(stok);
    baju6.set_jenis(jenis);
    baju6.set_bahan(bahan);
    baju6.set_warna(warna);
    baju6.set_untuk(untuk);
    baju6.set_size(size);
    baju6.set_merk(merk);

    list_baju.push_back(baju6);

    // tamplikan data baju dari 1-6
    for (int i = 0; i < panjang_garis; i++)
    {
        cout << "-";
    }
    cout << endl;

    cout << "|ID";
    for (int i = 0; i < id_terpanjang - 2; i++)
    {
        cout << " ";
    }
    cout << "|Nama";
    for (int i = 0; i < nama_terpanjang - 4; i++)
    {
        cout << " ";
    }
    cout << "|Harga";
    for (int i = 0; i < harga_terpanjang - 5 - 7; i++)
    {
        cout << " ";
    }
    cout << "|Stok";
    for (int i = 0; i < stok_terpanjang - 4; i++)
    {
        cout << " ";
    }
    cout << "|Jenis";
    for (int i = 0; i < jenis_terpanjang - 5; i++)
    {
        cout << " ";
    }
    cout << "|Bahan";
    for (int i = 0; i < bahan_terpanjang - 5; i++)
    {
        cout << " ";
    }
    cout << "|Warna";
    for (int i = 0; i < warna_terpanjang - 5; i++)
    {
        cout << " ";
    }
    cout << "|Untuk";
    for (int i = 0; i < untuk_terpanjang - 5; i++)
    {
        cout << " ";
    }
    cout << "|Size";
    for (int i = 0; i < size_terpanjang - 4; i++)
    {
        cout << " ";
    }
    cout << "|Merk";
    for (int i = 0; i < merk_terpanjang - 4; i++)
    {
        cout << " ";
    }
    cout << "|" << endl;

    for (int i = 0; i < panjang_garis; i++)
    {
        cout << "-";
    }
    cout << endl;

    for (it = list_baju.begin(); it != list_baju.end(); it++)
    {
        cout << "|" << it->get_id();
        for (int i = 0; i < id_terpanjang - to_string(it->get_id()).length(); i++)
        {
            cout << " ";
        }
        cout << "|" << it->get_nama();
        for (int i = 0; i < nama_terpanjang - it->get_nama().length(); i++)
        {
            cout << " ";
        }
        cout << "|" << it->get_harga();
        for (int i = 0; i < harga_terpanjang - to_string(it->get_harga()).length(); i++)
        {
            cout << " ";
        }
        cout << "|" << it->get_stok();
        for (int i = 0; i < stok_terpanjang - to_string(it->get_stok()).length(); i++)
        {
            cout << " ";
        }
        cout << "|" << it->get_jenis();
        for (int i = 0; i < jenis_terpanjang - it->get_jenis().length(); i++)
        {
            cout << " ";
        }
        cout << "|" << it->get_bahan();
        for (int i = 0; i < bahan_terpanjang - it->get_bahan().length(); i++)
        {
            cout << " ";
        }
        cout << "|" << it->get_warna();
        for (int i = 0; i < warna_terpanjang - it->get_warna().length(); i++)
        {
            cout << " ";
        }
        cout << "|" << it->get_untuk();
        for (int i = 0; i < untuk_terpanjang - it->get_untuk().length(); i++)
        {
            cout << " ";
        }
        cout << "|" << it->get_size();
        for (int i = 0; i < size_terpanjang - it->get_size().length(); i++)
        {
            cout << " ";
        }
        cout << "|" << it->get_merk();
        for (int i = 0; i < merk_terpanjang - it->get_merk().length(); i++)
        {
            cout << " ";
        }
        cout << "|" << endl;
    }

    for (int i = 0; i < panjang_garis; i++)
    {
        cout << "-";
    }
    cout << endl;

    return 0;
}
