#include "graph.h"
#include <iostream>
#include <algorithm>
using namespace std;
bool addVertex(Graph& g, int id, const string& nama) {
    if (g.jumlahLokasi == MAX_LOKASI || findVertex(g,id) != -1 || nama.empty()) return false;
    g.lokasi[g.jumlahLokasi++] = {id,nama}; return true;
}
int findVertex(const Graph& g, int id) { for(int i=0;i<g.jumlahLokasi;i++) if(g.lokasi[i].id==id) return i; return -1; }
bool addEdge(Graph& g,int asal,int tujuan) { int a=findVertex(g,asal), b=findVertex(g,tujuan); if(a<0||b<0||a==b||g.jalur[a][b]) return false; g.jalur[a][b]=g.jalur[b][a]=true; return true; }
bool removeEdge(Graph& g,int asal,int tujuan) { int a=findVertex(g,asal), b=findVertex(g,tujuan); if(a<0||b<0||a==b||!g.jalur[a][b]) return false; g.jalur[a][b]=g.jalur[b][a]=false; return true; }
void createGraph(Graph& g) { g=Graph{}; addVertex(g,1,"Base"); addVertex(g,2,"Mid Lane"); addVertex(g,3,"Top Lane"); addVertex(g,4,"Bottom Lane"); addVertex(g,5,"Jungle"); addEdge(g,1,2); addEdge(g,1,3); addEdge(g,1,4); addEdge(g,2,5); addEdge(g,5,3); }
void displayGraph(const Graph& g) { cout << "\n=== Peta dan Jalur ===\n"; for(int i=0;i<g.jumlahLokasi;i++){ cout<<g.lokasi[i].id<<". "<<g.lokasi[i].nama<<" -> "; bool ada=false; for(int j=0;j<g.jumlahLokasi;j++) if(g.jalur[i][j]) { if(ada) cout<<", "; cout<<g.lokasi[j].nama; ada=true; } if(!ada) cout<<"(tidak ada jalur)"; cout<<'\n'; } }
vector<int> cariRutePengiriman(const Graph& g,int asal,int tujuan) {
    int a=findVertex(g,asal), b=findVertex(g,tujuan); if(a<0||b<0) return {};
    int antrean[MAX_LOKASI], depan=0, belakang=0, sebelumnya[MAX_LOKASI]; bool dikunjungi[MAX_LOKASI]{};
    fill(sebelumnya,sebelumnya+MAX_LOKASI,-1); antrean[belakang++]=a; dikunjungi[a]=true;
    while(depan<belakang) { int u=antrean[depan++]; if(u==b) break; for(int v=0;v<g.jumlahLokasi;v++) if(g.jalur[u][v]&&!dikunjungi[v]) { dikunjungi[v]=true; sebelumnya[v]=u; antrean[belakang++]=v; } }
    if(!dikunjungi[b]) return {}; vector<int> rute; for(int v=b;v!=-1;v=sebelumnya[v]) rute.push_back(g.lokasi[v].id); reverse(rute.begin(),rute.end()); return rute;
}
