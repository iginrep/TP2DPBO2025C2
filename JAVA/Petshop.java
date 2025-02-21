import java.util.Scanner;

// class untuk mengelola data produk di petshop
class PetShop {
    private int[] id = new int[100];    // array untuk menyimpan id produk
    private String[] namaProduk = new String[100];  // array untuk menyimpan nama produk
    private String[] kategori = new String[100];    // array untuk menyimpan kategori produk
    private double[] harga = new double[100];   // array untuk menyimpan harga produk
    private int jumlahProduk;   // jumlah produk yang tersedia
    
    public PetShop() {  // constructor
        this.jumlahProduk = 0;  // set jumlah produk awal
    }

    public void tambahProduk(int _id, String _nama, String _kategori, double _harga) {  // method untuk menambahkan produk
        if (this.jumlahProduk < 100) {  // jika jumlah produk kurang dari 100
            this.id[this.jumlahProduk] = _id;   // set id produk
            this.namaProduk[this.jumlahProduk] = _nama; // set nama produk
            this.kategori[this.jumlahProduk] = _kategori;   // set kategori produk
            this.harga[this.jumlahProduk] = _harga; // set harga produk
            this.jumlahProduk++;    // tambah jumlah produk
            System.out.println("Produk berhasil ditambahkan!");
        } else {
            System.out.println("Kapasitas produk penuh!");
        }
    }

    public void tampilkanProduk() { // method untuk menampilkan produk
        if (this.jumlahProduk == 0) {   // jika jumlah produk 0
            System.out.println("Tidak ada produk yang tersedia");
            return;
        }

        System.out.println("\nDaftar Produk:");     // tampilkan daftar produk
        for (int i = 0; i < this.jumlahProduk; i++) {   // loop sebanyak jumlah produk
            System.out.println("ID: " + this.id[i] + ", Nama: " + this.namaProduk[i] +
                    ", Kategori: " + this.kategori[i] + ", Harga: Rp " + this.harga[i]);
        }
    }

    public void ubahProduk(int _id, String _nama, String _kategori, double _harga) {    // method untuk mengubah produk
        for (int i = 0; i < this.jumlahProduk; i++) {   // loop sebanyak jumlah produk
            if (this.id[i] == _id) {    // jika id produk sama dengan id yang dicari
                this.namaProduk[i] = _nama; // set nama produk baru
                this.kategori[i] = _kategori;   // set kategori produk baru
                this.harga[i] = _harga; // set harga produk baru
                System.out.println("Produk berhasil diperbarui!");
                return;
            }
        }
        System.out.println("Produk tidak ditemukan!");
    }

    public void hapusProduk(int _id) {  // method untuk menghapus produk
        for (int i = 0; i < this.jumlahProduk; i++) {   // loop sebanyak jumlah produk
            if (this.id[i] == _id) {    // jika id produk sama dengan id yang dicari
                for (int j = i; j < this.jumlahProduk - 1; j++) {   // loop sebanyak jumlah produk - 1
                    this.id[j] = this.id[j + 1];    // geser id produk
                    this.namaProduk[j] = this.namaProduk[j + 1];    // geser nama produk
                    this.kategori[j] = this.kategori[j + 1];    // geser kategori produk
                    this.harga[j] = this.harga[j + 1];  // geser harga produk
                }
                this.jumlahProduk--;    // kurangi jumlah produk
                System.out.println("Produk berhasil dihapus!");
                return;
            }
        }
        System.out.println("Produk tidak ditemukan!");
    }

    public void cariProduk(String _nama) {  // method untuk mencari produk
        boolean ditemukan = false;  // set ditemukan menjadi false
        for (int i = 0; i < this.jumlahProduk; i++) {   // loop sebanyak jumlah produk
            if (this.namaProduk[i] != null && this.namaProduk[i].contains(_nama)) {   // jika nama produk mengandung nama yang dicari
                System.out.println("ID: " + this.id[i] + ", Nama: " + this.namaProduk[i] +
                        ", Kategori: " + this.kategori[i] + ", Harga: Rp " + this.harga[i]);
                ditemukan = true;   // set ditemukan menjadi true
            }
        }
        if (!ditemukan) {
            System.out.println("Produk tidak ditemukan!");
        }
    }
}
