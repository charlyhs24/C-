#ifndef RELASI_H_INCLUDED
#define RELASI_H_INCLUDED
#define info(P) (P)->info
#define next(P) (P)->next
#define prev(P) (P)->prev
#define First(L) ((L).first)
#define last(L) ((L).last)
#include "matkul.h"
#include "student.h"
#include <iostream>

using namespace std;
struct inforelasi{

};
typedef inforelasi infotype_relasi;
typedef struct elmrelasi *address_relasi;
struct elmrelasi{
    address_relasi next;
    address_relasi prev;
    infotype_relasi info;
};
struct list_relasi{
    address_relasi first;
    address_relasi last;
};
void createlist_relasi(list_relasi &L);
address_relasi alokasi_relasi(infotype_relasi relasi);
void insert_last(list_relasi &L, address_relasi P);
void delete_first(list_relasi &L, address_relasi P);
void delete_last(list_relasi &L, address_relasi P);
address_relasi findmatakuliah(list_relasi L, address_matakuliah am);
address_relasi findstudent(list_relasi,address_student as);
void printinfo_relasi(list_relasi L);
#endif // RELASI_H_INCLUDED
