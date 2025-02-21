import java.util.Scanner;

public class main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        PetShop petshop = new PetShop();
        int pilihan, id;
        String nama, kategori;
        double harga;

        do {
            System.out.println("\nMENU PETSHOP");
            System.out.println("1. Tambah Produk");
            System.out.println("2. Tampilkan Produk");
            System.out.println("3. Ubah Produk");
            System.out.println("4. Hapus Produk");
            System.out.println("5. Cari Produk");
            System.out.println("0. Keluar");
            System.out.print("Pilih menu: ");
            pilihan = scanner.nextInt();
            scanner.nextLine();

            switch (pilihan) {
                case 1:
                    System.out.println("\nTambah Produk");
                    System.out.print("ID: ");
                    id = scanner.nextInt();
                    scanner.nextLine();
                    System.out.print("Nama Produk: ");
                    nama = scanner.nextLine();
                    System.out.print("Kategori: ");
                    kategori = scanner.nextLine();
                    System.out.print("Harga: Rp ");
                    harga = scanner.nextDouble();
                    petshop.tambahProduk(id, nama, kategori, harga);
                    break;
                case 2:
                    petshop.tampilkanProduk();
                    break;
                case 3:
                    System.out.println("\nUbah Produk");
                    System.out.print("ID Produk yang akan diubah: ");
                    id = scanner.nextInt();
                    scanner.nextLine();
                    System.out.print("Nama Baru: ");
                    nama = scanner.nextLine();
                    System.out.print("Kategori Baru: ");
                    kategori = scanner.nextLine();
                    System.out.print("Harga Baru: Rp ");
                    harga = scanner.nextDouble();
                    petshop.ubahProduk(id, nama, kategori, harga);
                    break;
                case 4:
                    System.out.println("\nHapus Produk");
                    System.out.print("ID Produk yang akan dihapus: ");
                    id = scanner.nextInt();
                    petshop.hapusProduk(id);
                    break;
                case 5:
                    System.out.println("\nCari Produk");
                    System.out.print("Masukkan nama produk: ");
                    scanner.nextLine();
                    nama = scanner.nextLine();
                    petshop.cariProduk(nama);
                    break;
                case 0:
                    System.out.println("Keluar dari program. Terima kasih!");
                    break;
                default:
                    System.out.println("Pilihan tidak valid! Coba lagi.");
                    break;
            }
        } while (pilihan != 0);

        scanner.close();
    }
}
