#ifndef QUEUE_H
#define QUEUE_H
#include <string>
#include "graph.h"
struct Pengiriman { int id; std::string hero, item; int tujuan; };
struct NodePengiriman { Pengiriman data; NodePengiriman* next; };
struct QueuePengiriman { NodePengiriman* front=nullptr; NodePengiriman* rear=nullptr; };
void createQueue(QueuePengiriman& q);
bool isEmptyQueue(const QueuePengiriman& q);
void enqueue(QueuePengiriman& q, const Pengiriman& p);
bool dequeue(QueuePengiriman& q);
const Pengiriman* frontQueue(const QueuePengiriman& q);
bool idDalamQueue(const QueuePengiriman& q, int id);
void displayQueue(const QueuePengiriman& q, const Graph& g);
void clearQueue(QueuePengiriman& q);
#endif
