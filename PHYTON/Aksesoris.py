from Petshop import Petshop

class Aksesoris(Petshop):
    def __init__(self, id=0, nama="", harga=0.0, stok=0, jenis="", bahan="", warna=""):
        super().__init__(id, nama, harga, stok)
        self._jenis_aksesoris = jenis
        self._bahan_aksesoris = bahan
        self._warna_aksesoris = warna
    
    def set_jenis(self, jenis):
        self._jenis_aksesoris = jenis
    
    def set_bahan(self, bahan):
        self._bahan_aksesoris = bahan
    
    def set_warna(self, warna):
        self._warna_aksesoris = warna
    
    def get_jenis(self):
        return self._jenis_aksesoris
    
    def get_bahan(self):
        return self._bahan_aksesoris
    
    def get_warna(self):
        return self._warna_aksesoris
