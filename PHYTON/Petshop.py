class PetShop:  # class PetShop
    def __init__(self): # method __init__
        self.id = []    # list id
        self.nama_produk = []   # list nama_produk
        self.kategori = []  # list kategori
        self.harga = []    # list harga
        self.jumlah_produk = 0  # jumlah_produk
    
    # method tambah_produk
    def tambah_produk(self, _id, _nama, _kategori, _harga):
        if self.jumlah_produk < 100:    # jika jumlah_produk < 100
            self.id.append(_id) # menambahkan id
            self.nama_produk.append(_nama)  # menambahkan nama_produk
            self.kategori.append(_kategori) # menambahkan kategori
            self.harga.append(_harga)   # menambahkan harga
            self.jumlah_produk += 1 # jumlah_produk + 1
            print("Produk berhasil ditambahkan!")   # menampilkan pesan
        else:
            print("Kapasitas produk penuh!")

    def tampilkan_produk(self): # method tampilkan_produk
        if self.jumlah_produk == 0: # jika jumlah_produk = 0
            print("Tidak ada produk yang tersedia")
            return

        print("\nDaftar Produk:")   # menampilkan pesan
        for i in range(self.jumlah_produk): # loop untuk menampilkan produk
            print(f"ID: {self.id[i]}, Nama: {self.nama_produk[i]}, "    # menampilkan id, nama_produk, kategori, harga
                  f"Kategori: {self.kategori[i]}, Harga: Rp {self.harga[i]}")

    def ubah_produk(self, _id, _nama, _kategori, _harga):   # method ubah_produk
        for i in range(self.jumlah_produk): # loop untuk mencari produk
            if self.id[i] == _id:   # jika id produk ditemukan
                self.nama_produk[i] = _nama # mengubah nama_produk
                self.kategori[i] = _kategori    # mengubah kategori
                self.harga[i] = _harga  # mengubah harga
                print("Produk berhasil diperbarui!")    # menampilkan pesan
                return
        print("Produk tidak ditemukan!")

    def hapus_produk(self, _id):    # method hapus_produk
        for i in range(self.jumlah_produk): # loop untuk mencari produk
            if self.id[i] == _id:   # jika id produk ditemukan
                del self.id[i]  # menghapus id
                del self.nama_produk[i] # menghapus nama_produk
                del self.kategori[i]    # menghapus kategori
                del self.harga[i]   # menghapus harga
                self.jumlah_produk -= 1 # jumlah_produk - 1
                print("Produk berhasil dihapus!")
                return
        print("Produk tidak ditemukan!")

    def cari_produk(self, _nama):   # method cari_produk
        ditemukan = False   # variabel ditemukan
        for i in range(self.jumlah_produk): # loop untuk mencari produk
            if _nama.lower() in self.nama_produk[i].lower():    # jika nama_produk ditemukan
                print(f"ID: {self.id[i]}, Nama: {self.nama_produk[i]}, "    # menampilkan id, nama_produk, kategori, harga
                      f"Kategori: {self.kategori[i]}, Harga: Rp {self.harga[i]}")
                ditemukan = True
        if not ditemukan:
            print("Produk tidak ditemukan!")
