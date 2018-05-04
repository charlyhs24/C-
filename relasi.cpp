#include "relasi.h"
void createlist_relasi(list_relasi &L){
    first(L) = NULL;
    last(L) = NULL;
}
address_relasi alokasi_relasi(infotype_relasi relasi){
    address_relasi P = new elmrelasi;
    prev(P) = NULL;
    info(P) = relasi;
    next(P) = NULL;
    return P;
}
void insert_last(list_relasi &L, address_relasi P){
    if (first(L) == NULL){
        first(L) = P;
        last(L) = P;
    }
    else{
        next(last(L)) = P;
        prev(P) = last(L);
        last(L) = P;
    }
}
void delete_first(list_relasi &L, address_relasi P){

}
void delete_last(list_relasi &L, address_relasi P){

}
address_relasi findmatakuliah(list_relasi L, address_matakuliah am){

}
address_relasi findstudent(list_relasi,address_student as){

}
void printinfo_relasi(list_relasi L){

}


