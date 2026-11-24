# Courier Delivery Simulator

Simulasi console pengiriman item terinspirasi Dota 2 untuk mata kuliah Struktur Data.

**Achyar Bagus Pambudi — 103042500020**

**Annasya Zakira — 103042500072**

Program menggunakan queue linked node buatan sendiri untuk FIFO, graph adjacency matrix dua arah tanpa bobot, dan BFS dengan antrean array untuk rute dengan jumlah jalur paling sedikit. Courier mulai di Base; pengiriman yang tidak memiliki rute tetap berada di depan antrean. Data hanya ada selama program berjalan.

## Menjalankan

Persyaratan: compiler C++17 dan `make`. Untuk pengujian diperlukan Python 3.

```sh
make
./courier
make test
```

Tanpa make: `g++ -std=c++17 -Wall -Wextra -pedantic main.cpp queue.cpp graph.cpp courier.cpp -o courier`. Pada Windows jalankan `courier.exe`.

Menu mencakup peta, tambah/hapus jalur, tambah/lihat/proses/batalkan pengiriman, posisi courier, dan riwayat. ID harus unik di antrean; nama tidak boleh kosong dan tujuan harus tersedia. Pilih 0 untuk keluar. Input akhir berkas juga mengakhiri program. Lokasi awal: Base, Mid Lane, Top Lane, Bottom Lane dan Jungle. Peta dapat memiliki maksimum 20 lokasi; lokasi awal ditentukan di kode.

## Berkas

- `queue.h/cpp`: ADT antrean linked node.
- `graph.h/cpp`: ADT graph dan BFS.
- `courier.h/cpp`: proses dan riwayat pengiriman.
- `main.cpp`: menu dan validasi input.
- `tests/test_cli.py`: pengujian integrasi console.
- `LAPORAN.md`: laporan proyek dan pengujian.
- `COMMIT_LOG.md`: catatan perkembangan aktual.

Lihat riwayat lengkap dengan `git log --oneline`. Ini adalah penyederhanaan mekanik permainan, bukan reproduksi seluruh aturan Dota 2.
