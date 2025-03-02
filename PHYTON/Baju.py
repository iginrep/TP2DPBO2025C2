from Aksesoris import Aksesoris

class Baju(Aksesoris):
    def __init__(self, id=0, nama="", harga=0.0, stok=0, jenis="", bahan="", warna="", untuk="", size="", merk=""):
        super().__init__(id, nama, harga, stok, jenis, bahan, warna)
        self._untuk_hewan = untuk
        self._size_baju = size
        self._merk_baju = merk
    
    def set_untuk(self, untuk):
        self._untuk_hewan = untuk
    
    def set_size(self, size):
        self._size_baju = size
    
    def set_merk(self, merk):
        self._merk_baju = merk
    
    def get_untuk(self):
        return self._untuk_hewan
    
    def get_size(self):
        return self._size_baju
    
    def get_merk(self):
        return self._merk_baju