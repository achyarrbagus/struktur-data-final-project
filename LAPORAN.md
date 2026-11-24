# Laporan Tugas Besar Struktur Data

## Simulasi Pengiriman Barang Courier Dota 2

**Nama:** Achyar Bagus Pambudi  
**NIM:** 103042500020  
  
**Nama:** Annasya Zakira  
**NIM:** 103042500072  

**Mata kuliah:** Struktur Data 
**Repository:** https://github.com/achyarrbagus/struktur-data-final-project

## 1. Pendahuluan

Courier pada Dota 2 dapat mengantarkan item kepada hero [1]. Mekanik tersebut dipilih karena menggabungkan urutan permintaan dengan keterhubungan lokasi. Simulasi ini menyederhanakan permainan menjadi satu courier dan peta statis yang jalurnya dapat diubah pengguna. FIFO dan tujuan yang tetap merupakan aturan simulasi, bukan klaim aturan permainan asli. Konsep perlu dikonfirmasi pada pendampingan agar tidak terlalu mirip kelompok lain.

Tujuannya adalah menerapkan queue dan graph, mencari rute, serta menunjukkan hasil melalui console. Pembelian, gold, pertempuran, gerak otomatis, banyak courier, dan penyimpanan permanen berada di luar lingkup.

## 2. Rancangan dan Alur

Pengguna memasukkan ID, hero, item, dan ID tujuan. ID harus unik dalam antrean, nama tidak kosong, dan tujuan terdaftar. Permintaan ditempatkan di belakang antrean. Proses mengambil bagian depan tanpa menghapusnya, kemudian mencari rute dari lokasi courier. Jika berhasil, rute dicatat, lokasi diperbarui dan node dihapus. Jika gagal, node tetap di depan; pengguna dapat memperbaiki jalur atau membatalkannya. Tujuan yang sama dianggap berhasil tanpa perjalanan.

Peta awal terdiri dari Base, Mid Lane, Top Lane, Bottom Lane, dan Jungle. Sisi awal: Base–Mid, Base–Top, Base–Bottom, Mid–Jungle, dan Jungle–Top. Semua sisi dua arah tanpa bobot.

## 3. Struktur Data dan Algoritma

**Queue:** `QueuePengiriman` mempunyai pointer `front` dan `rear`, dengan `NodePengiriman` yang menyimpan `Pengiriman` dan pointer `next`. `enqueue` menambah di belakang, `dequeue` menghapus depan, `frontQueue` membaca depan, dan `displayQueue` menelusuri node. Enqueue dan dequeue O(1); pencarian ID dan tampilan O(n). Seluruh node dibebaskan saat keluar melalui menu.

**Graph:** `Graph` menyimpan array `Lokasi`, jumlah lokasi, dan matriks boolean `jalur[MAX_LOKASI][MAX_LOKASI]`, dengan kapasitas 20. `addVertex`, `findVertex`, `addEdge`, `removeEdge`, dan `displayGraph` mengelola peta. Penambahan atau penghapusan sisi mengubah kedua arah.

**BFS:** `cariRutePengiriman` menggunakan antrean array buatan sendiri, penanda kunjungan, dan array pendahulu. Setelah tujuan ditemukan, pendahulu ditelusuri balik lalu urutan dibalik. BFS memberikan jalur dengan jumlah sisi paling sedikit pada graph tanpa bobot [2]; ini bukan jarak fisik atau waktu tercepat. Karena menggunakan matriks, waktu pencarian O(V²) dan ruang matriks O(V²).

**Data lain:** `Courier` menyimpan nama dan ID lokasi saat ini. `Riwayat` menyimpan salinan pengiriman berhasil dan rutenya; `vector` dipakai sebagai penyimpanan riwayat dan hasil rute, bukan sebagai queue atau graph. `prosesPengiriman` menggabungkan queue, BFS, courier, dan riwayat; `batalkanPengirimanTerdepan` menghapus node terdepan. `main.cpp` menangani menu dan validasi.

## 4. Implementasi dan Pengujian

Kompilasi dan pengujian dilakukan dengan `make test` menggunakan C++17 dan Python 3. Pengujian integrasi memberi masukan ke program console dan memeriksa keluarannya.

| Skenario | Hasil yang diperiksa |
|---|---|
| Dua permintaan | Urutan tampil dan proses FIFO; rute dari lokasi courier yang diperbarui |
| Antrean kosong | Pesan kosong, program tetap berjalan |
| Rute tersedia | Rute Base–Mid Lane–Jungle dan pengiriman berhasil |
| Rute terputus | Pesan gagal, permintaan tetap di antrean, dapat dibatalkan |
| Tujuan sama | Berhasil tanpa perjalanan |
| ID duplikat | Ditolak dan diminta ulang |
| Nama kosong dan lokasi tidak tersedia | Ditolak dan diminta ulang |
| Hapus dan tambah jalur | Jalur terputus, kemudian rute berhasil setelah ditambahkan kembali dengan arah terbalik |
| Sesi baru | Antrean dan riwayat kosong |

Hasil terakhir: `make test` lulus seluruh pemeriksaan tersebut. Perbaikan masukan uji dilakukan setelah satu skenario awal gagal karena urutan masukan pengujian keliru. Untuk demonstrasi kelas, jalankan program dan ambil tangkapan layar hasil sendiri sesuai format dosen.

## 5. Kendala dan Solusi

Pengiriman gagal tidak boleh menghilangkan permintaan. Solusinya membaca node depan tanpa menghapus, lalu melakukan dequeue hanya setelah rute ditemukan. Untuk menjaga jalur dua arah, kedua sel matriks diperbarui bersama. Validasi dilakukan melalui pembacaan satu baris agar input nonangka tidak membuat stream macet.

## 6. Kesimpulan dan Saran

Queue mengatur urutan layanan, sedangkan graph dan BFS menentukan keterjangkauan serta rute dengan sisi paling sedikit. Keduanya bertemu pada proses pengiriman. Pengembangan selanjutnya dapat menambahkan bobot jarak, beberapa courier, atau prioritas dengan aturan tersendiri.

## Referensi

1. Liquipedia, [Courier — Dota 2 Wiki](https://liquipedia.net/dota2/Courier), diakses 24 November 2026.
2. OpenStax, [Introduction to Computer Science: Sample Algorithms by Problem](https://openstax.org/books/introduction-computer-science/pages/3-5-sample-algorithms-by-problem), diakses 24 November 2026.

## Catatan penyusunan

Draf ini dibuat dengan bantuan AI berdasarkan PRD dan implementasi. Mahasiswa perlu meninjau, memahami, dan menyesuaikannya dengan format serta ketentuan dosen. PRD meminta laporan asli buatan mahasiswa dan versi hasil suntingan bila AI digunakan untuk penyuntingan; laporan asli mahasiswa belum diberikan, sehingga perbandingan kedua versi belum dapat dibuat.
