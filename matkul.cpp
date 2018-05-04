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

address_matakuliah find_matkul(list_matakuliah L,string id){
    address_matakuliah p_matkul = first(L);
    while(p_matkul != NULL){
        if(p_matkul->info.id_matkul == id){
            return p_matkul;
        }else{
            return NULL;
        }
        p_matkul = p_matkul->next;
    }
}

void insertfirst_matakuliah(list_matakuliah &L, address_matakuliah P){
    if(first(L) == NULL){
        first(L) = P;
        last(L) = P;
    } else{
        next(P)=first(L);
        prev(first(L))= P;
        first(L)=P;
    }
}

void insertlast_matakuliah(list_matakuliah &L, address_matakuliah P){
    if(first(L) == NULL){
        first(L) = P;
        last(L) = P;
    } else{
        next(last(L)) = P;
        prev(P)= last(L);
        last(L)=P;
    }
}

void deletefirst_matakuliah(list_matakuliah &L, address_matakuliah P){
    P = first(L);
    if (first(L) == NULL){
        cout<<" DATA KOSONG";
    }

    if(first(L) == last(L)){
        first(L) = NULL;
        last(L) = NULL;
    } else {
        first(L) = next(P);
        prev(last(L)) = NULL;
        next(P) = NULL;
    }
}

void deletelast_matakuliah (list_matakuliah &L, address_matakuliah P){
    P = last(L);
    if (first(L) == NULL){
        cout<<" DATA KOSONG";
    }

    if(first(L) == last(L)){
        first(L) = NULL;
        last(L) = NULL;
    } else {
        last(L) = prev(P);
        next(last(L)) = NULL;
        prev(P) = NULL;
    }
}

void deleteafter_matakuliah (list_matakuliah &L, address_matakuliah P){
    address_matakuliah Q;
    P = next(Q);

    if (first(L) == NULL){
        cout<<" DATA KOSONG";
    }
    if (first(L) == last(L)){
        first(L) = NULL;
        last(L) = NULL;
    } else {
        next(Q) = next(P);
        prev(next(Q))  = prev(Q);

        next(P) = NULL;
        prev(P) = NULL;
    }
}
void printinfo_matakuliah(list_matakuliah L){
    address_matakuliah p = first(L);
    int i=1;
    while(p!=NULL){
        cout<<"DATA KE "<<i<<endl;i++;
        cout<<"ID MATA KULIAH    : "<<info(p).id_matkul<<endl;
        cout<<"NAMA MATA KULIAH  : "<<info(p).nama_matkul<<endl;
        cout<<"JUMLAH SKS        : "<<info(p).jumlah_sks<<endl;
        p = next(p);
        cout<<endl;
    }
 }
