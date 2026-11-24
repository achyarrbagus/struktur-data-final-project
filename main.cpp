#include "courier.h"
#include <iostream>
#include <sstream>
#include <cctype>
#include <cstdlib>
using namespace std;
static string baca(const string& prompt) { cout<<prompt; string s; if(!getline(cin,s)) { cout<<"\nInput berakhir.\n"; exit(0); } return s; }
static int angka(const string& prompt) { while(true) { string s=baca(prompt); stringstream ss(s); int n; char c; if(ss>>n && !(ss>>c)) return n; cout<<"Masukkan bilangan bulat yang valid.\n"; } }
static string teks(const string& prompt) { while(true) { string s=baca(prompt); if(s.find_first_not_of(" \t\r\n")!=string::npos) return s; cout<<"Input tidak boleh kosong.\n"; } }
int main() {
    Graph g; createGraph(g); QueuePengiriman q; createQueue(q); Courier c{"Courier",1}; vector<Riwayat> riwayat;
    while(true) {
        cout<<"\n=====================================\n      COURIER DELIVERY SIMULATOR\n=====================================\nLokasi courier saat ini: "<<g.lokasi[findVertex(g,c.lokasi)].nama<<"\n\n1. Lihat Peta dan Jalur\n2. Tambah Jalur\n3. Hapus Jalur\n4. Tambah Permintaan Pengiriman\n5. Lihat Antrean Pengiriman\n6. Proses Pengiriman Terdepan\n7. Batalkan Pengiriman Terdepan\n8. Lihat Lokasi Courier\n9. Lihat Riwayat Pengiriman\n0. Keluar\n";
        int pilihan=angka("Pilihan: ");
        if(pilihan==0) { clearQueue(q); cout<<"Program selesai.\n"; return 0; }
        if(pilihan==1) displayGraph(g);
        else if(pilihan==2 || pilihan==3) { displayGraph(g); int a=angka("ID lokasi asal: "), b=angka("ID lokasi tujuan: "); int x=findVertex(g,a),y=findVertex(g,b); if(x<0||y<0) cout<<"Lokasi tidak tersedia.\n"; else if(a==b) cout<<"Lokasi asal dan tujuan tidak boleh sama.\n"; else if(pilihan==2) cout<<(addEdge(g,a,b)?"Jalur berhasil ditambahkan.\n":"Jalur sudah ada.\n"); else cout<<(removeEdge(g,a,b)?"Jalur berhasil dihapus.\n":"Jalur belum ada.\n"); }
        else if(pilihan==4) { Pengiriman p; do { p.id=angka("ID pengiriman: "); if(idDalamQueue(q,p.id)) cout<<"ID sudah digunakan dalam antrean.\n"; } while(idDalamQueue(q,p.id)); p.hero=teks("Nama hero: "); p.item=teks("Nama item: "); displayGraph(g); do { p.tujuan=angka("ID tujuan: "); if(findVertex(g,p.tujuan)<0) cout<<"Lokasi tujuan tidak tersedia.\n"; } while(findVertex(g,p.tujuan)<0); enqueue(q,p); cout<<"Permintaan berhasil ditambahkan ke antrean.\n"; }
        else if(pilihan==5) displayQueue(q,g);
        else if(pilihan==6) prosesPengiriman(q,g,c,riwayat);
        else if(pilihan==7) batalkanPengirimanTerdepan(q);
        else if(pilihan==8) cout<<"Lokasi courier saat ini: "<<g.lokasi[findVertex(g,c.lokasi)].nama<<'\n';
        else if(pilihan==9) tampilRiwayat(riwayat,g);
        else cout<<"Pilihan tidak tersedia.\n";
    }
}
