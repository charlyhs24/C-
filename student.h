#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED
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
    address_matakuliah info;
    address_relasi next;
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
address_student alokasi_student(infotype_student x);

address_relasi alokasi_relasi(address_matakuliah info);
void input_relasi(address_student P, address_relasi tmp);

void insert_student(list_student &L, address_student P);

void deletefirst_student(list_student &L, address_student P);
void deleteafter_student(list_student &L, address_student P);

void deletelast_student(list_student &L, address_student P);
address_student find_student(list_student L,string nama);

void printinfo_relasi(address_student P);
void editData_student(list_student &L,address_student P,string nama, string nim, string jurusan,string kelas,string angkatan);

void deleteRelasiMatkul(list_student &L, address_student P, address_matakuliah Q);

void printinfo_student(list_student L);
#endif // STUDENT_H_INCLUDED
