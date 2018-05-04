#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED
#define next(P) (P)->next
#define prev(P) (P)->prev
#define First(L) L.first
#define last(L) L.last
#include <iostream>
#include "matkul.h"

using namespace std;

struct Student_s{
    string nim;
    string nama;
    string kelas;
    string jurusan;
    string angkatan;
};
typedef Student_s infotype_student;
typedef struct elm_student *address_student;
typedef struct elm_relasi *address_relasi;
struct elm_relasi{
    address_matakuliah next;
    address_relasi nextrelasi;
};

struct elm_student{
    infotype_student info_student;
    address_student next;
    address_student prev;
    address_relasi nextrelasi;
};


struct list_student{
    address_student first;
    address_student last;
};


void createlist_student(list_student &L);
address_student alokasi_student(infotype_student y);

address_relasi alokasi_relasi(address_matakuliah info);
address_student find_elm_student(list_student &L);

void insert_student(list_student &L, address_student P);
address_student find_student(list_student L,string nama);
void deletefirst_student(list_student &L, address_student P);
void deletelast_student (list_student &L, address_student P);

void deleteafter_student (list_student &L, address_student P);
void printinfo_student(list_student L);
#endif // STUDENT_H_INCLUDED
