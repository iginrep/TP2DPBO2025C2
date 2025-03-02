<?php
require_once "Aksesoris.php";

class Baju extends Aksesoris {
    protected $untuk_hewan;
    protected $size_baju;
    protected $merk_baju;

    public function __construct($id = 0, $nama = "", $harga = 0.0, $stok = 0, $foto = "default.jpg", $jenis = "", $bahan = "", $warna = "", $untuk = "", $size = "", $merk = "") {
        parent::__construct($id, $nama, $harga, $stok, $foto, $jenis, $bahan, $warna);
        $this->untuk_hewan = $untuk;
        $this->size_baju = $size;
        $this->merk_baju = $merk;
    }

    public function getUntuk() { return $this->untuk_hewan; }
    public function getSize() { return $this->size_baju; }
    public function getMerk() { return $this->merk_baju; }
}
?>