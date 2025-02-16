#include "Petshop.cpp"

int main() {
    PetShop petshop;    // buat objek petshop
    int pilihan, id;    // variabel untuk menyimpan pilihan menu dan ID produk
    std::string nama, kategori; // variabel untuk menyimpan nama dan kategori produk
    double harga;   // variabel untuk menyimpan harga produk

    // tampilkan menu
    do {
        std::cout << "\nMENU PETSHOP\n";
        std::cout << "1. Tambah Produk\n";
        std::cout << "2. Tampilkan Produk\n";
        std::cout << "3. Ubah Produk\n";
        std::cout << "4. Hapus Produk\n";
        std::cout << "5. Cari Produk\n";
        std::cout << "0. Keluar\n";
        std::cout << "Pilih menu: ";
        std::cin >> pilihan;
        std::cin.ignore();

        switch (pilihan) {
        case 1:
            std::cout << "\nTambah Produk\n";
            std::cout << "ID: ";
            std::cin >> id;
            std::cin.ignore();
            std::cout << "Nama Produk: ";
            std::getline(std::cin, nama);
            std::cout << "Kategori: ";
            std::getline(std::cin, kategori);
            std::cout << "Harga: Rp ";
            std::cin >> harga;
            petshop.tambahProduk(id, nama, kategori, harga);
            break;

        case 2:
            petshop.tampilkanProduk();
            break;

        case 3:
            std::cout << "\nUbah Produk\n";
            std::cout << "ID Produk yang akan diubah: ";
            std::cin >> id;
            std::cin.ignore();
            std::cout << "Nama Baru: ";
            std::getline(std::cin, nama);
            std::cout << "Kategori Baru: ";
            std::getline(std::cin, kategori);
            std::cout << "Harga Baru: Rp ";
            std::cin >> harga;
            petshop.ubahProduk(id, nama, kategori, harga);
            break;

        case 4:
            std::cout << "\nHapus Produk\n";
            std::cout << "ID Produk yang akan dihapus: ";
            std::cin >> id;
            petshop.hapusProduk(id);
            break;

        case 5:
            std::cout << "\nCari Produk\n";
            std::cout << "Masukkan nama produk: ";
            std::cin.ignore();
            std::getline(std::cin, nama);
            petshop.cariProduk(nama);
            break;

        case 0:
            std::cout << "Keluar dari program. Terima kasih!\n";
            break;

        default:
            std::cout << "Pilihan tidak valid! Coba lagi.\n";
            break;
        }
    } while (pilihan != 0);

    return 0;
}
