public class Baju extends Aksesoris {
    private String untukHewan;
    private String sizeBaju;
    private String merkBaju;

    public Baju() {}

    public Baju(int id, String nama, int harga, int stok, String jenis, String bahan, String warna, String untuk, String size, String merk) {
        super(id, nama, harga, stok, jenis, bahan, warna);
        this.untukHewan = untuk;
        this.sizeBaju = size;
        this.merkBaju = merk;
    }

    public void setUntuk(String untuk) { this.untukHewan = untuk; }
    public void setSize(String size) { this.sizeBaju = size; }
    public void setMerk(String merk) { this.merkBaju = merk; }

    public String getUntuk() { return untukHewan; }
    public String getSize() { return sizeBaju; }
    public String getMerk() { return merkBaju; }
}