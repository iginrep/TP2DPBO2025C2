<?php

class Petshop
{
    private $id;
    private $namaProduct;
    private $kategori;
    private $harga;
    private $foto;
    
    public function __construct($id, $namaProduct, $kategori, $harga, $foto)
    {
        $this->id = $id;
        $this->namaProduct = $namaProduct;
        $this->kategori = $kategori;
        $this->harga = $harga;
        $this->foto = $foto;
    }

    //Getter
    public function getId()
    {
        return $this->id;
    }

    //Setter
    public function setId($id)
    {
        $this->id = $id;
    }

    //Getter
    public function getNamaProduct()
    {
        return $this->namaProduct;
    }

    //Setter
    public function setNamaProduct($namaProduct)
    {
        $this->namaProduct = $namaProduct;
    }

    //Getter
    public function getKategori()
    {
        return $this->kategori;
    }

    //Setter
    public function setKategori($kategori)
    {
        $this->kategori = $kategori;
    }

    //Getter
    public function getHarga()
    {
        return $this->harga;
    }

    //Setter
    public function setHarga($harga)
    {
        $this->harga = $harga;
    }

    //Getter
    public function getFoto()
    {
        return $this->foto;
    }

    //Setter
    public function setFoto($foto)
    {
        $this->foto = $foto;
    }

    public function __toString()
    {
        return "ID: " . $this->id . "<br>" . "Nama Product: " . $this->namaProduct . "<br>" . "Kategori: " . $this->kategori . "<br>" . "Harga: " . $this->harga . "<br>" . "Foto: " . $this->foto . "<br>";
    }

    
   
}