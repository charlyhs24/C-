#include "student.h"

void createlist_student(list_student &L){
    L.first = NULL;
    L.last = NULL;
}
address_student alokasi_student(infotype_student x){
    address_student st = new elm_student;
    st->info_student = x;
    st->next = NULL;
    st->prev = NULL;
    st->nextrelasi = NULL;
    return st;
}

address_relasi alokasi_relasi(address_matakuliah info){
    address_relasi relasi = new elm_relasi;
    relasi->nextrelasi = NULL;
    relasi->next = info;
    return relasi;
}

void insert_student(list_student &L, address_student P){
    if(L.first == NULL && L.last == NULL){
        L.first = P;
        L.last = P;
    }else{
        next(last(L))= P;
        prev(P) = last(L);
        last(L)=P;
    }
}
address_student find_student(list_student L,string nama){
    address_student p_student = first(L);
    while(p_student != NULL){
        if(p_student->info_student.nama == nama){
            return p_student;
        }else{
            return NULL;
        }
        p_student = next(p_student);
    }
}

void deletefirst_student(list_student &L, address_student P){
    if(First(L)==NULL && last(L)==NULL){
        cout<<"List Student Sudah Kosong"<<endl;
    }else if (next(First(L))==last(L)){
        P = First(L);
        First(L)==NULL;
        last(L)==NULL;
    }else{
        P = First(L);
        First(L) = next(P);
        prev(next(P))==NULL;
        next(P)==NULL;
        prev(P)==NULL;
    }
}
address_student find_elm_student(list_student &L){
    address_student P = First(L);
    while(P!=NULL){

    }
}
void deletelast_student (list_student &L, address_student P){

}
void deleteafter_student (list_student &L, address_student P){

}

void printinfo_student(list_student L){
    address_student P = First(L);
    while(P!=NULL){
        cout<<"NIM          : "<<P->info_student.nim<<endl;
        cout<<"NAMA LENGKAP : "<<P->info_student.nama<<endl;
        cout<<"KELAS        : "<<P->info_student.kelas<<endl;
        cout<<"JURUSAN      : "<<P->info_student.jurusan<<endl;
        cout<<"ANGKATAN     : "<<P->info_student.angkatan<<endl;
        P = next(P);
    }
}
