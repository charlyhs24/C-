#include "student.h"
#include "matkul.h"
void createlist_student(list_student &L){
    L.first = NULL;
    L.last = NULL;
}
address_student alokasi_student(infotype_student x){
    address_student st = new elm_student;
    st->info_student = x;
    st->next = NULL;
    st->prev = NULL;
    st->nextrelasi =NULL;
    return st;
}

address_relasi alokasi_relasi(address_matakuliah info){
    address_relasi relasi = new elm_relasi;
    relasi->next = NULL;
    relasi->info = info;
    return relasi;
}

void input_relasi(address_student P, address_relasi tmp){

    if(P->nextrelasi == NULL){
        P->nextrelasi = tmp;
    }else{
        address_relasi q = P->nextrelasi;
        if(next(q)==NULL){
            next(q)= tmp;
        }else{
            while(next(q) != NULL){
                q = next(q);
            }
            next(q)= tmp;
        }
    }
}

void insert_student(list_student &L, address_student P){
    if(L.first == NULL && L.last == NULL){
        L.first = P;
        L.last = P;
    }else{
        prev(P) = last(L);
        next(last(L))= P;
        last(L) = P;
    }
}
void deletefirst_student(list_student &L, address_student P){
    P = first(L);
    if(first(L)== NULL){
        cout<<"list empty"<<endl;
    }else if(next(P)==NULL){
        next(P)=NULL;
        prev(P)=NULL;
        first(L)=NULL;
        last(L)=NULL;

    }else{
        first(L)=next(P);
        next(P)= NULL;
        prev(P)= NULL;
        prev(first(L))=NULL;
    }
}
void deleteafter_student(list_student &L, address_student P){
    if(first(L)==NULL){
        cout<<"list empty"<<endl;
    }else if(P == first(L)){
        deletefirst_student(L,P);
    }else if(P==last(L)){
        deletelast_student(L,P);
    }else{
        address_student prec = prev(P);
        next(prec) = next(P);
        prev(next(P)) = prec;
        next(P)= NULL;
        prev(P) = NULL;
    }
}
void deletelast_student(list_student &L, address_student P){
    P = last(L);
    address_student prec = prev(P);
    last(L) = prec;
    next(prec)=NULL;

}
address_student find_student(list_student L,string nama){
    address_student p_student = first(L);
    while(p_student != NULL){
        if(p_student->info_student.nama == nama){
            return p_student;
        }else{
            p_student = next(p_student);
        }
    }
    return NULL;
}

void printinfo_relasi(address_student P){
    address_relasi q = P->nextrelasi;
    int i=1;
    while(q != NULL){
        cout<<"DATA KE : "<<i<<endl;
        output_relasi(q->info);
        q = next(q);
        i=i+1;
    }

}
void editData_student(list_student &L,address_student P, string nama, string nim, string jurusan,string kelas,string angkatan){
    P->info_student.nama = nama;
    P->info_student.nim = nim;
    P->info_student.kelas = kelas;
    P->info_student.jurusan = jurusan;
    P->info_student.angkatan = angkatan;
}

void printinfo_student(list_student L){
    address_student P = first(L);
    address_student Q = first(L);
    int i = 1;
    while(P!=NULL){
        cout<<"DATA KE "<<i<<endl;
        cout<<"NIM          : "<<P->info_student.nim<<endl;
        cout<<"NAMA LENGKAP : "<<P->info_student.nama<<endl;
        cout<<"KELAS        : "<<P->info_student.kelas<<endl;
        cout<<"JURUSAN      : "<<P->info_student.jurusan<<endl;
        cout<<"ANGKATAN     : "<<P->info_student.angkatan<<endl;
        cout<<endl;
        i = i+1;
        P = next(P);
    }
}

//void deleteRelasiMatkul(list_student &L, address_student P, address_matakuliah Q){
//    address_relasi R = P->nextrelasi;
//    while(P != NULL){
//            while(next(R) != NULL){
//                if(R==Q){
//
//                }
//            }
//        P = next(P);
//    }
//
//}
