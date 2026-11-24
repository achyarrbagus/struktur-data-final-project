#ifndef COURIER_H
#define COURIER_H
#include "queue.h"
#include <vector>
struct Courier { std::string nama; int lokasi; };
struct Riwayat { Pengiriman data; std::vector<int> rute; };
void prosesPengiriman(QueuePengiriman& q, const Graph& g, Courier& c, std::vector<Riwayat>& riwayat);
void batalkanPengirimanTerdepan(QueuePengiriman& q);
void tampilRiwayat(const std::vector<Riwayat>& riwayat, const Graph& g);
#endif
