#include "queue.h"
#include <iostream>
using namespace std;
void createQueue(QueuePengiriman& q) { q.front=q.rear=nullptr; }
bool isEmptyQueue(const QueuePengiriman& q) { return q.front==nullptr; }
void enqueue(QueuePengiriman& q,const Pengiriman& p) { NodePengiriman* n=new NodePengiriman{p,nullptr}; if(q.rear) q.rear->next=n; else q.front=n; q.rear=n; }
bool dequeue(QueuePengiriman& q) { if(isEmptyQueue(q)) return false; NodePengiriman* n=q.front; q.front=n->next; if(!q.front) q.rear=nullptr; delete n; return true; }
const Pengiriman* frontQueue(const QueuePengiriman& q) { return q.front ? &q.front->data : nullptr; }
bool idDalamQueue(const QueuePengiriman& q,int id) { for(auto n=q.front;n;n=n->next) if(n->data.id==id) return true; return false; }
void displayQueue(const QueuePengiriman& q,const Graph& g) { cout<<"\n=== Antrean Pengiriman ===\n"; if(isEmptyQueue(q)) cout<<"Antrean kosong.\n"; int i=1; for(auto n=q.front;n;n=n->next) { int idx=findVertex(g,n->data.tujuan); cout<<i++<<". ID: "<<n->data.id<<" | Hero: "<<n->data.hero<<" | Item: "<<n->data.item<<" | Tujuan: "<<(idx>=0 ? g.lokasi[idx].nama : "Tidak dikenal")<<'\n'; } }
void clearQueue(QueuePengiriman& q) { while(dequeue(q)) {} }
