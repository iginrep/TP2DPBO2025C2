public class Petshop {
    private int id;
    private String namaProduk;
    private int hargaProduk;
    private int stokProduk;

    public Petshop() {}

    public Petshop(int id, String nama, int harga, int stok) {
        this.id = id;
        this.namaProduk = nama;
        this.hargaProduk = harga;
        this.stokProduk = stok;
    }

    public void setId(int id) { this.id = id; }
    public void setNama(String nama) { this.namaProduk = nama; }
    public void setHarga(int harga) { this.hargaProduk = harga; }
    public void setStok(int stok) { this.stokProduk = stok; }

    public int getId() { return id; }
    public String getNama() { return namaProduk; }
    public int getHarga() { return hargaProduk; }
    public int getStok() { return stokProduk; }
}
