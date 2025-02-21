from Petshop import PetShop

def main(): # method main
    petshop = PetShop() # instance petshop
    
    while True: # loop menu
        print("\nMENU PETSHOP")
        print("1. Tambah Produk")
        print("2. Tampilkan Produk")
        print("3. Ubah Produk")
        print("4. Hapus Produk")
        print("5. Cari Produk")
        print("0. Keluar")

        pilihan = input("Pilih menu: ")

        if pilihan == "1":  # jika pilihan = 1 (Tambah Produk)
            print("\nTambah Produk")
            id_produk = int(input("ID: "))
            nama = input("Nama Produk: ")
            kategori = input("Kategori: ")
            harga = float(input("Harga: Rp "))
            petshop.tambah_produk(id_produk, nama, kategori, harga)

        elif pilihan == "2":    # jika pilihan = 2 (Tampilkan Produk)
            petshop.tampilkan_produk()

        elif pilihan == "3":    # jika pilihan = 3 (Ubah Produk)
            print("\nUbah Produk")
            id_produk = int(input("ID Produk yang akan diubah: "))
            nama = input("Nama Baru: ")
            kategori = input("Kategori Baru: ")
            harga = float(input("Harga Baru: Rp "))
            petshop.ubah_produk(id_produk, nama, kategori, harga)

        elif pilihan == "4":    # jika pilihan = 4 (Hapus Produk)
            print("\nHapus Produk")
            id_produk = int(input("ID Produk yang akan dihapus: "))
            petshop.hapus_produk(id_produk)

        elif pilihan == "5":    # jika pilihan = 5 (Cari Produk)
            print("\nCari Produk")
            nama = input("Masukkan nama produk: ")
            petshop.cari_produk(nama)

        elif pilihan == "0":    # jika pilihan = 0 (Keluar)
            print("Keluar dari program. Terima kasih!")
            break

        else:   # jika pilihan tidak valid
            print("Pilihan tidak valid! Coba lagi.")

if __name__ == "__main__":  # menjalankan method main
    main()
