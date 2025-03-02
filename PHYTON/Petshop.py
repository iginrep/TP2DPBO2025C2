class Petshop:
    def __init__(self, id=0, nama="", harga=0.0, stok=0):
        self._id = id
        self._nama_produk = nama
        self._harga_produk = harga
        self._stok_produk = stok
    
    def set_id(self, id):
        self._id = id
    
    def set_nama(self, nama):
        self._nama_produk = nama
    
    def set_harga(self, harga):
        self._harga_produk = harga
    
    def set_stok(self, stok):
        self._stok_produk = stok
    
    def get_id(self):
        return self._id
    
    def get_nama(self):
        return self._nama_produk
    
    def get_harga(self):
        return int(self._harga_produk)
    
    def get_stok(self):
        return self._stok_produk
