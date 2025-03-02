<?php
require_once "Baju.php";
session_start(); // Gunakan session untuk menyimpan daftar produk sementara

// Buat folder 'uploads/' jika belum ada
$upload_dir = "uploads/";
if (!file_exists($upload_dir)) {
    mkdir($upload_dir, 0777, true);
}

// Inisialisasi data jika belum ada dalam session
if (!isset($_SESSION['baju_list'])) {
    $_SESSION['baju_list'] = [
        new Baju(1, "Baju", 50000, 10, "uploads/baju1.jpg", "Kaos", "Katun", "Putih", "Kucing", "S", "Kucing"),
        new Baju(2, "Gelang", 60000, 10, "uploads/gelang.jpg", "Tali", "Woll", "Hitam", "Anjing", "M", "Anjing"),
        new Baju(3, "Kalung", 70000, 10, "uploads/kalung.jpg", "Tali", "Woll", "Merah", "Hamster", "L", "Hamster"),
        new Baju(4, "Topi", 80000, 10, "uploads/topi.jpg", "Kain", "Katun", "Biru", "Kelinci", "XL", "Kelinci"),
        new Baju(5, "Sepatu", 90000, 10, "uploads/sepatu.jpg", "Kulit", "Kulit", "Hijau", "Burung", "XXL", "Burung")
    ];
}

// Hapus Produk
if (isset($_GET['hapus'])) {
    $index = $_GET['hapus'];
    if (isset($_SESSION['baju_list'][$index])) {
        unset($_SESSION['baju_list'][$index]);
        $_SESSION['baju_list'] = array_values($_SESSION['baju_list']); // Reset indeks array setelah penghapusan
    }
    header("Location: main.php");
    exit();
}

// Tambah Produk Baru dengan Upload Foto
if (isset($_POST['tambah'])) {
    $id = count($_SESSION['baju_list']) + 1;
    $nama = $_POST['nama'];
    $harga = $_POST['harga'];
    $stok = $_POST['stok'];
    $jenis = $_POST['jenis'];
    $bahan = $_POST['bahan'];
    $warna = $_POST['warna'];
    $untuk = $_POST['untuk'];
    $size = $_POST['size'];
    $merk = $_POST['merk'];

    // Proses Upload Foto
    $foto = "uploads/default.jpg";
    if (!empty($_FILES['foto']['name'])) {
        $foto_nama = time() . "_" . basename($_FILES['foto']['name']);
        $foto_path = $upload_dir . $foto_nama;
        if (move_uploaded_file($_FILES['foto']['tmp_name'], $foto_path)) {
            $foto = $foto_path;
        }
    }

    $produk_baru = new Baju($id, $nama, $harga, $stok, $foto, $jenis, $bahan, $warna, $untuk, $size, $merk);
    $_SESSION['baju_list'][] = $produk_baru;

    header("Location: main.php");
    exit();
}

// Cetak daftar produk dalam bentuk tabel
function printTable($baju_list) {
    echo "<table border='1'>";
    echo "<tr><th>ID</th><th>Nama</th><th>Harga</th><th>Stok</th><th>Jenis</th><th>Bahan</th><th>Warna</th><th>Untuk</th><th>Size</th><th>Merk</th><th>Foto</th><th>Aksi</th></tr>";
    foreach ($baju_list as $key => $b) {
        echo "<tr>";
        echo "<td>" . $b->getId() . "</td>";
        echo "<td>" . $b->getNama() . "</td>";
        echo "<td>Rp " . number_format($b->getHarga(), 0, ',', '.') . "</td>";
        echo "<td>" . $b->getStok() . "</td>";
        echo "<td>" . $b->getJenis() . "</td>";
        echo "<td>" . $b->getBahan() . "</td>";
        echo "<td>" . $b->getWarna() . "</td>";
        echo "<td>" . $b->getUntuk() . "</td>";
        echo "<td>" . $b->getSize() . "</td>";
        echo "<td>" . $b->getMerk() . "</td>";
        echo "<td><img src='" . $b->getFoto() . "' width='100'></td>";
        echo "<td><a href='?hapus=$key' onclick='return confirm(\"Apakah Anda yakin ingin menghapus produk ini?\")'>Hapus</a></td>";
        echo "</tr>";
    }
    echo "</table>";
}
?>

<!DOCTYPE html>
<html>
<head>
    <title>Petshop - Baju</title>
</head>
<body>
    <h2>Daftar Produk</h2>
    <?php printTable($_SESSION['baju_list']); ?>

    <h3>Tambah Produk Baru</h3>
    <form method="post" enctype="multipart/form-data">
        <label for="nama">Nama Produk:</label>
        <input type="text" name="nama" required><br>

        <label for="harga">Harga:</label>
        <input type="number" name="harga" required><br>

        <label for="stok">Stok:</label>
        <input type="number" name="stok" required><br>

        <label for="jenis">Jenis:</label>
        <input type="text" name="jenis" required><br>

        <label for="bahan">Bahan:</label>
        <input type="text" name="bahan" required><br>

        <label for="warna">Warna:</label>
        <input type="text" name="warna" required><br>

        <label for="untuk">Untuk Hewan:</label>
        <input type="text" name="untuk" required><br>

        <label for="size">Size:</label>
        <input type="text" name="size" required><br>

        <label for="merk">Merk:</label>
        <input type="text" name="merk" required><br>

        <label for="foto">Foto Produk:</label>
        <input type="file" name="foto"><br>

        <input type="submit" name="tambah" value="Tambah Produk">
    </form>
</body>
</html>
