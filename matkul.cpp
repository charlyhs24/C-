#include "matkul.h"
void createlist_matakuliah(list_matakuliah &L){
    first(L) = NULL;
    last(L) = NULL;
}

address_matakuliah alokasi_matakuliah(infotype_matakuliah y){
    address_matakuliah P;
    P = new ElmMatakuliah;
    info(P) = y;
    next(P) = NULL;
    prev(P) = NULL;
    return P;
}

void dealokasi_matakuliah(address_matakuliah P){
    delete P;
}

address_matakuliah find_matkul(list_matakuliah L,string id){
    address_matakuliah P = first(L);
    while(P!=NULL){
        if(P->info.id_matkul == id){
            return P;
        }
        P=next(P);
    }
    return NULL;
}


// buat fungsi find_matkul berdasarkan nama matakuliah
address_matakuliah find_matkulByname(list_matakuliah L, string nama){
    address_matakuliah P = first(L);
    while(P!=NULL){
        if(P->info.nama_matkul == nama){
            return P;
        }
        P=next(P);
    }
    return NULL;
}
void insertlast_matakuliah(list_matakuliah &L, address_matakuliah P){
    if(first(L)==NULL){
        first(L)= P;
        last(L) = P;
    }else{
        prev(P) = last(L);
        next(last(L)) = P;
        last(L) = P;
    }
}

void deletefirst_matakuliah(list_matakuliah &L, address_matakuliah P){
    P = first(L);
    if(first(L)==NULL){
        cout<<"tidak ada data yang dihapus"<<endl;
    }else if(first(L)==last(L)){
        next(P)=NULL;
        prev(P)=NULL;
        first(L)=NULL;
        last(L)=NULL;
        dealokasi_matakuliah(P);
    }else{
        first(L)= next(first(L));
        next(P) = NULL;
        prev(first(L)) = NULL;
        next(P)= NULL;
        dealokasi_matakuliah(P);
    }
}

void deletelast_matakuliah(list_matakuliah &L, address_matakuliah P){
    P = last(L);
    if(first(L)==NULL){
        cout<<"tidak ada data yang dihapus"<<endl;
    }else if(first(L)==last(L)){
        next(P)=NULL;
        prev(P)=NULL;
        first(L)=NULL;
        last(L)=NULL;
        dealokasi_matakuliah(P);
    }else{
        last(L)=prev(last(L));
        prev(P)=NULL;
        next(last(L))=NULL;
        dealokasi_matakuliah(P);
    }
}
void deleteafter_matakuliah(list_matakuliah &L, address_matakuliah P){
    address_matakuliah prec = prev(P);
    if(first(L)==NULL){
        cout<<"tidak ada data yang dihapus"<<endl;
    }else if(next(P)==NULL){
        last(L) = prec;
        next(P) = NULL;
        next(prec) = NULL;
        prev(P) = NULL;
        dealokasi_matakuliah(P);
    }else if(P == first(L)){
        first(L)= next(P);
        next(P)= NULL;
        prev(first(L)) = NULL;
        dealokasi_matakuliah(P);
    }else{
        address_matakuliah nprec = next(P);
        next(prec) = nprec;
        prev(nprec)= prec;
        next(P) = NULL;
        prev(P) = NULL;
        dealokasi_matakuliah(P);
    }
}
void output_relasi(address_matakuliah MK){
    cout<<"Nama Mata Kuliah : "<<MK->info.nama_matkul<<endl;
    cout<<"Id Mata Kuliah : "<<MK->info.id_matkul<<endl;
    cout<<"Jumlah SKS Mata Kuliah : "<<MK->info.jumlah_sks<<endl;
    cout<<endl;
}
void printinfo_matakuliah(list_matakuliah L){
    if(first(L)==NULL){
        cout<<"list empty"<<endl;
    }else{
        address_matakuliah p = first(L);
        int i=1;
        while(p != NULL){
            cout<<"DATA KE "<<i<<endl;i++;
            cout<<"ID MATA KULIAH    : "<<info(p).id_matkul<<endl;
            cout<<"NAMA MATA KULIAH  : "<<info(p).nama_matkul<<endl;
            cout<<"JUMLAH SKS        : "<<info(p).jumlah_sks<<endl;
            p = next(p);
            cout<<endl;
        }
    }
 }

 void editData_MataKuliah(list_matakuliah &L, address_matakuliah P, string id_matakuliah, string nama_matakuliah, int jml_sks){
        P->info.id_matkul = id_matakuliah;
        P->info.nama_matkul = nama_matakuliah;
        P->info.jumlah_sks = jml_sks;
 }

