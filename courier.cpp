#include "courier.h"
#include <iostream>
using namespace std;
static void tampilRute(const vector<int>& r,const Graph& g) { for(size_t i=0;i<r.size();i++) { if(i) cout<<" -> "; cout<<g.lokasi[findVertex(g,r[i])].nama; } cout<<'\n'; }
void prosesPengiriman(QueuePengiriman& q,const Graph& g,Courier& c,vector<Riwayat>& riwayat) {
    cout<<"\n=== Proses Pengiriman ===\n"; const Pengiriman* p=frontQueue(q); if(!p) { cout<<"Antrean kosong.\n"; return; }
    cout<<"ID: "<<p->id<<" | Hero: "<<p->hero<<" | Item: "<<p->item<<'\n'; auto r=cariRutePengiriman(g,c.lokasi,p->tujuan);
    if(r.empty()) { cout<<"Rute menuju lokasi tujuan tidak ditemukan. Permintaan tetap berada di antrean.\n"; return; }
    cout<<"Rute courier: "; tampilRute(r,g); if(r.size()==1) cout<<"Courier sudah di tujuan, tanpa perjalanan.\n";
    riwayat.push_back({*p,r}); c.lokasi=p->tujuan; dequeue(q); cout<<"Pengiriman berhasil. Lokasi courier saat ini: "<<g.lokasi[findVertex(g,c.lokasi)].nama<<'\n';
}
void batalkanPengirimanTerdepan(QueuePengiriman& q) { auto p=frontQueue(q); if(!p) { cout<<"Antrean kosong.\n"; return; } cout<<"Pengiriman "<<p->id<<" untuk "<<p->hero<<" dibatalkan.\n"; dequeue(q); }
void tampilRiwayat(const vector<Riwayat>& riwayat,const Graph& g) { cout<<"\n=== Riwayat Pengiriman ===\n"; if(riwayat.empty()) cout<<"Belum ada pengiriman berhasil.\n"; for(const auto& r:riwayat) { cout<<"ID: "<<r.data.id<<" | Hero: "<<r.data.hero<<" | Item: "<<r.data.item<<" | Rute: "; tampilRute(r.rute,g); } }
