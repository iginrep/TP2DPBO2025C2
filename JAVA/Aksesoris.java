public class Aksesoris extends Petshop {
    private String jenisAksesoris;
    private String bahanAksesoris;
    private String warnaAksesoris;

    public Aksesoris() {}

    public Aksesoris(int id, String nama, int harga, int stok, String jenis, String bahan, String warna) {
        super(id, nama, harga, stok);
        this.jenisAksesoris = jenis;
        this.bahanAksesoris = bahan;
        this.warnaAksesoris = warna;
    }

    public void setJenis(String jenis) { this.jenisAksesoris = jenis; }
    public void setBahan(String bahan) { this.bahanAksesoris = bahan; }
    public void setWarna(String warna) { this.warnaAksesoris = warna; }

    public String getJenis() { return jenisAksesoris; }
    public String getBahan() { return bahanAksesoris; }
    public String getWarna() { return warnaAksesoris; }
}
