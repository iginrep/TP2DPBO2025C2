import java.util.*;

public class Main {
    public static void printTable(List<Baju> listBaju) {
        String[] headers = {"ID", "Nama", "Harga", "Stok", "Jenis", "Bahan", "Warna", "Untuk", "Size", "Merk"};
        int[] colWidths = new int[headers.length];
        
        for (int i = 0; i < headers.length; i++) {
            colWidths[i] = headers[i].length();
        }

        for (Baju b : listBaju) {
            colWidths[0] = Math.max(colWidths[0], String.valueOf(b.getId()).length());
            colWidths[1] = Math.max(colWidths[1], b.getNama().length());
            colWidths[2] = Math.max(colWidths[2], String.valueOf(b.getHarga()).length());
            colWidths[3] = Math.max(colWidths[3], String.valueOf(b.getStok()).length());
            colWidths[4] = Math.max(colWidths[4], b.getJenis().length());
            colWidths[5] = Math.max(colWidths[5], b.getBahan().length());
            colWidths[6] = Math.max(colWidths[6], b.getWarna().length());
            colWidths[7] = Math.max(colWidths[7], b.getUntuk().length());
            colWidths[8] = Math.max(colWidths[8], b.getSize().length());
            colWidths[9] = Math.max(colWidths[9], b.getMerk().length());
        }

        System.out.println("-".repeat(Arrays.stream(colWidths).sum() + headers.length + 1));
        for (int i = 0; i < headers.length; i++) {
            System.out.printf("|%-" + colWidths[i] + "s", headers[i]);
        }
        System.out.println("|");
        System.out.println("-".repeat(Arrays.stream(colWidths).sum() + headers.length + 1));

        for (Baju b : listBaju) {
            System.out.printf("|%-" + colWidths[0] + "d|%-" + colWidths[1] + "s|%-" + colWidths[2] + "d|%-" + colWidths[3] + "d|%-" + colWidths[4] + "s|%-" + colWidths[5] + "s|%-" + colWidths[6] + "s|%-" + colWidths[7] + "s|%-" + colWidths[8] + "s|%-" + colWidths[9] + "s|\n",
                b.getId(), b.getNama(), b.getHarga(), b.getStok(), b.getJenis(), b.getBahan(), b.getWarna(), b.getUntuk(), b.getSize(), b.getMerk());
        }
        System.out.println("-".repeat(Arrays.stream(colWidths).sum() + headers.length + 1));
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        List<Baju> listBaju = new ArrayList<>(Arrays.asList(
            new Baju(1, "Baju", 50000, 10, "Kaos", "Katun", "Putih", "Kucing", "S", "Kucing"),
            new Baju(2, "Gelang", 60000, 10, "Tali", "Woll", "Hitam", "Anjing", "M", "Anjing"),
            new Baju(3, "Kalung", 70000, 10, "Tali", "Woll", "Abu-abu", "Kelinci", "L", "Kelinci"),
            new Baju(4, "Topi", 80000, 10, "Kain", "Katun", "Coklat", "Hamster", "XL", "Hamster"),
            new Baju(5, "Sepatu", 90000, 10, "Kulit", "Kulit", "Merah", "Burung", "XXL", "Burung")
        ));
        printTable(listBaju);

        System.out.print("Masukkan ID: ");
        int id = scanner.nextInt();
        scanner.nextLine();
        System.out.print("Masukkan Nama: ");
        String nama = scanner.nextLine();
        System.out.print("Masukkan Harga: ");
        int harga = scanner.nextInt();
        System.out.print("Masukkan Stok: ");
        int stok = scanner.nextInt();
        scanner.nextLine();
        System.out.print("Masukkan Jenis: ");
        String jenis = scanner.nextLine();
        System.out.print("Masukkan Bahan: ");
        String bahan = scanner.nextLine();
        System.out.print("Masukkan Warna: ");
        String warna = scanner.nextLine();
        System.out.print("Masukkan Untuk: ");
        String untuk = scanner.nextLine();
        System.out.print("Masukkan Size: ");
        String size = scanner.nextLine();
        System.out.print("Masukkan Merk: ");
        String merk = scanner.nextLine();

        listBaju.add(new Baju(id, nama, harga, stok, jenis, bahan, warna, untuk, size, merk));
        printTable(listBaju);
    }
}
