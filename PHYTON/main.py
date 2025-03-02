from Baju import Baju

def print_table(baju_list):
    headers = ["ID", "Nama", "Harga", "Stok", "Jenis", "Bahan", "Warna", "Untuk", "Size", "Merk"]
    col_widths = [max(len(str(int(getattr(b, attr)))) if attr == "_harga_produk" else len(str(getattr(b, attr))) for b in baju_list) for attr in ["_id", "_nama_produk", "_harga_produk", "_stok_produk", "_jenis_aksesoris", "_bahan_aksesoris", "_warna_aksesoris", "_untuk_hewan", "_size_baju", "_merk_baju"]]
    col_widths = [max(len(h), w) for h, w in zip(headers, col_widths)]
    
    print("-" * (sum(col_widths) + len(headers) + 1))
    print("|" + "|".join(h.ljust(w) for h, w in zip(headers, col_widths)) + "|")
    print("-" * (sum(col_widths) + len(headers) + 1))
    
    for b in baju_list:
        print("|" + "|".join(str(int(getattr(b, attr))) if attr == "_harga_produk" else str(getattr(b, attr)).ljust(w) for attr, w in zip(["_id", "_nama_produk", "_harga_produk", "_stok_produk", "_jenis_aksesoris", "_bahan_aksesoris", "_warna_aksesoris", "_untuk_hewan", "_size_baju", "_merk_baju"], col_widths)) + "|")
    print("-" * (sum(col_widths) + len(headers) + 1))

def main():
    list_baju = [
        Baju(1, "Baju", 50000, 10, "Kaos", "Katun", "Putih", "Kucing", "S", "Kucing"),
        Baju(2, "Gelang", 60000, 10, "Tali", "Woll", "Hitam", "Anjing", "M", "Anjing"),
        Baju(3, "Kalung", 70000, 10, "Tali", "Woll", "Merah", "Hamster", "L", "Hamster"),
        Baju(4, "Topi", 80000, 10, "Kain", "Katun", "Biru", "Kelinci", "XL", "Kelinci"),
        Baju(5, "Sepatu", 90000, 10, "Kulit", "Kulit", "Hijau", "Burung", "XXL", "Burung")
    ]
    print_table(list_baju)
    
    # Tambah data baru
    id = int(input("Masukkan ID: "))
    nama = input("Masukkan Nama: ")
    harga = int(input("Masukkan Harga: "))
    stok = int(input("Masukkan Stok: "))
    jenis = input("Masukkan Jenis: ")
    bahan = input("Masukkan Bahan: ")
    warna = input("Masukkan Warna: ")
    untuk = input("Masukkan Untuk: ")
    size = input("Masukkan Size: ")
    merk = input("Masukkan Merk: ")
    
    baju_baru = Baju(id, nama, harga, stok, jenis, bahan, warna, untuk, size, merk)
    list_baju.append(baju_baru)
    
    print_table(list_baju)

if __name__ == "__main__":
    main()
