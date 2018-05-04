#ifndef MATKUL_H_INCLUDED
#define MATKUL_H_INCLUDED
#include <cstdlib>
#include <iostream>

#define info(P) (P)->info
#define next(P) (P)->next
#define prev(P) (P)->prev
#define first(L) ((L).first)
#define last(L) ((L).last)
#define Nil NULL

using namespace std;
struct matakuliah{
    string id_matkul;
    string nama_matkul;
    int jumlah_sks;
};
typedef matakuliah infotype_matakuliah;

typedef struct ElmMatakuliah *address_matakuliah;
struct ElmMatakuliah{
    infotype_matakuliah info;
    address_matakuliah next;
    address_matakuliah prev;
};
struct list_matakuliah{
    address_matakuliah first;
    address_matakuliah last;
};

void createlist_matakuliah(list_matakuliah &L);
address_matakuliah alokasi_matakuliah(infotype_matakuliah y);

address_matakuliah find_matkul(list_matakuliah L,string id);
void insertfirst_matakuliah(list_matakuliah &L, address_matakuliah P);

void insertlast_matakuliah(list_matakuliah &L, address_matakuliah P);
void deletefirst_matakuliah(list_matakuliah &L, address_matakuliah P);

void deletelast_matakuliah (list_matakuliah &L, address_matakuliah P);
void deleteafter_matakuliah (list_matakuliah &L, address_matakuliah P);

void printinfo_matakuliah(list_matakuliah L);


#endif // MATKUL_H_INCLUDED
