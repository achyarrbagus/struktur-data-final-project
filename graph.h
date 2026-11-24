#ifndef GRAPH_H
#define GRAPH_H
#include <string>
#include <vector>
const int MAX_LOKASI = 20;
struct Lokasi { int id; std::string nama; };
struct Graph { Lokasi lokasi[MAX_LOKASI]; bool jalur[MAX_LOKASI][MAX_LOKASI]{}; int jumlahLokasi = 0; };
void createGraph(Graph& g);
bool addVertex(Graph& g, int id, const std::string& nama);
int findVertex(const Graph& g, int id);
bool addEdge(Graph& g, int asal, int tujuan);
bool removeEdge(Graph& g, int asal, int tujuan);
void displayGraph(const Graph& g);
std::vector<int> cariRutePengiriman(const Graph& g, int asal, int tujuan);
#endif
