<?php

class Petshop {
    protected $id;
    protected $nama_produk;
    protected $harga_produk;
    protected $stok_produk;
    protected $foto_produk;

    public function __construct($id = 0, $nama = "", $harga = 0.0, $stok = 0, $foto = "default.jpg") {
        $this->id = $id;
        $this->nama_produk = $nama;
        $this->harga_produk = $harga;
        $this->stok_produk = $stok;
        $this->foto_produk = $foto;
    }

    public function getId() { return $this->id; }
    public function getNama() { return $this->nama_produk; }
    public function getHarga() { return (int) $this->harga_produk; }
    public function getStok() { return $this->stok_produk; }
    public function getFoto() { return $this->foto_produk; }
}
?>
