<?php
require_once 'Petshop.php';
session_start(); // Mulai sesi untuk menyimpan data secara sementara

$upload = "uploads/";
if (!file_exists($upload)) {
    mkdir($upload);
}

// Inisialisasi data jika belum ada dalam sesi
if (!isset($_SESSION['petshop'])) {
    $_SESSION['petshop'] = [
        new Petshop(1, 'Kucing', 'Hewan', 100000, 'image.png'),
        new Petshop(2, 'Anjing', 'Hewan', 200000, 'anjing.jpg'),
        new Petshop(3, 'Ikan', 'Hewan', 50000, 'ikan.jpg')
    ];
}

// Fungsi untuk menampilkan data dalam tabel
function tampilkanData($keyword = '')
{
    echo "<table border='1' class='styled-table'>";
    echo "<thead><tr><th>ID</th><th>Nama Product</th><th>Kategori</th><th>Harga</th><th>Foto</th><th>Aksi</th></tr></thead>";
    echo "<tbody>";
    foreach ($_SESSION['petshop'] as $key => $p) {
        if ($keyword === '' || stripos($p->getNamaProduct(), $keyword) !== false) {
            echo "<tr>";
            echo "<td>" . $p->getId() . "</td>";
            echo "<td>" . $p->getNamaProduct() . "</td>";
            echo "<td>" . $p->getKategori() . "</td>";
            echo "<td>Rp " . number_format($p->getHarga(), 0, ',', '.') . "</td>";
            echo "<td><img src='uploads/" . $p->getFoto() . "' width='100'></td>";
            echo "<td>
                    <a href='?hapus=$key' class='btn-delete'>Hapus</a> |
                    <a href='?edit=$key' class='btn-edit'>Edit</a>
                  </td>";
            echo "</tr>";
        }
    }
    echo "</tbody></table>";
}

// Tambah Data
if (isset($_POST['tambah'])) {
    $id = count($_SESSION['petshop']) + 1;
    $nama = $_POST['nama'];
    $kategori = $_POST['kategori'];
    $harga = $_POST['harga'];
    
    if (!empty($_FILES['foto']['name'])) {
        $foto = $_FILES['foto']['name'];
        move_uploaded_file($_FILES['foto']['tmp_name'], "uploads/" . $foto);
    }

    $_SESSION['petshop'][] = new Petshop($id, $nama, $kategori, $harga, $foto);
    header("Location: main.php");
}

// Hapus Data
if (isset($_GET['hapus'])) {
    unset($_SESSION['petshop'][$_GET['hapus']]);
    $_SESSION['petshop'] = array_values($_SESSION['petshop']); // Reset array keys
    header("Location: main.php");
}

// Edit Data
if (isset($_POST['update'])) {
    $index = $_POST['index'];
    $_SESSION['petshop'][$index]->setNamaProduct($_POST['nama']);
    $_SESSION['petshop'][$index]->setKategori($_POST['kategori']);
    $_SESSION['petshop'][$index]->setHarga($_POST['harga']);
    
    if (!empty($_FILES['foto']['name'])) {
        $foto = $_FILES['foto']['name'];
        move_uploaded_file($_FILES['foto']['tmp_name'], "uploads/" . $foto);
        $_SESSION['petshop'][$index]->setFoto($foto);
    }
    
    header("Location: main.php");
}
?>

<!DOCTYPE html>
<html>
<head>
    <title>Petshop</title>
    <style>
        body {
            font-family: Arial, sans-serif;
        }
        table {
            width: 100%;
            border-collapse: collapse;
            margin-bottom: 20px;
        }
        table, th, td {
            border: 1px solid black;
        }
        th, td {
            padding: 10px;
            text-align: center;
        }
        th {
            background-color: #f2f2f2;
        }
        img {
            border-radius: 5px;
        }
        fieldset {
            width: 50%;
            margin: auto;
            padding: 15px;
            border-radius: 10px;
            border: 1px solid #ccc;
            background: #f9f9f9;
        }
        legend {
            font-weight: bold;
            font-size: 18px;
        }
        input, select {
            width: 100%;
            padding: 8px;
            margin: 5px 0;
            border: 1px solid #ccc;
            border-radius: 5px;
        }
        input[type="submit"] {
            background-color: #28a745;
            color: white;
            border: none;
            cursor: pointer;
            padding: 10px;
            font-size: 16px;
        }
        input[type="submit"]:hover {
            background-color: #218838;
        }
        .search-container {
            width: 50%;
            margin: auto;
            text-align: center;
            padding: 10px;
        }
        .search-container input {
            width: 70%;
            padding: 8px;
            border: 1px solid #ccc;
            border-radius: 5px;
        }
        .search-container button {
            padding: 8px 15px;
            background-color: #007bff;
            color: white;
            border: none;
            cursor: pointer;
            border-radius: 5px;
        }
        .search-container button:hover {
            background-color: #0056b3;
        }
    </style>
</head>
<body>

    <h2 style="text-align: center;">Daftar Produk</h2>

    <div class="search-container">
        <form method="GET">
            <input type="text" name="search" placeholder="Cari produk..." value="<?= isset($_GET['search']) ? $_GET['search'] : '' ?>">
            <button type="submit">Cari</button>
        </form>
    </div>

    <?php 
    tampilkanData(isset($_GET['search']) ? $_GET['search'] : "");
    ?>

    <fieldset>
        <legend>Tambah Produk</legend>
        <form method="post" enctype="multipart/form-data">
            <label for="nama">Nama:</label>
            <input type="text" name="nama" required>

            <label for="kategori">Kategori:</label>
            <input type="text" name="kategori" required>

            <label for="harga">Harga:</label>
            <input type="number" name="harga" required>

            <label for="foto">Foto:</label>
            <input type="file" name="foto" required>

            <input type="submit" name="tambah" value="Tambah">
        </form>
    </fieldset>

    <?php if (isset($_GET['edit'])): ?>
    <fieldset>
        <legend>Edit Produk</legend>
        <form method="post" enctype="multipart/form-data">
            <?php $index = $_GET['edit']; $produk = $_SESSION['petshop'][$index]; ?>
            <input type="hidden" name="index" value="<?php echo $index; ?>">

            <label for="nama">Nama:</label>
            <input type="text" name="nama" value="<?php echo $produk->getNamaProduct(); ?>" required>

            <label for="kategori">Kategori:</label>
            <input type="text" name="kategori" value="<?php echo $produk->getKategori(); ?>" required>

            <label for="harga">Harga:</label>
            <input type="number" name="harga" value="<?php echo $produk->getHarga(); ?>" required>

            <label for="foto">Foto:</label>
            <input type="file" name="foto">
            
            <input type="submit" name="update" value="Update">
        </form>
    </fieldset>
    <?php endif; ?>

</body>
</html>
