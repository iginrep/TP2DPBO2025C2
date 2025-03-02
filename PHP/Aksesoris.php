<?php
require_once "Petshop.php";

class Aksesoris extends Petshop {
    protected $jenis_aksesoris;
    protected $bahan_aksesoris;
    protected $warna_aksesoris;

    public function __construct($id = 0, $nama = "", $harga = 0.0, $stok = 0, $foto = "default.jpg", $jenis = "", $bahan = "", $warna = "") {
        parent::__construct($id, $nama, $harga, $stok, $foto);
        $this->jenis_aksesoris = $jenis;
        $this->bahan_aksesoris = $bahan;
        $this->warna_aksesoris = $warna;
    }

    public function getJenis() { return $this->jenis_aksesoris; }
    public function getBahan() { return $this->bahan_aksesoris; }
    public function getWarna() { return $this->warna_aksesoris; }
}
?>
