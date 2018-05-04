#include "student.h"
#include "menu.h"
#include "matkul.h"

int main()
{
    int choose;
    Student_s x;
    matakuliah m;
    list_student S;
    list_matakuliah M;
    createlist_matakuliah(M);
    createlist_student(S);
    matakuliah xx,y,z;

    xx.id_matkul = "CSH123";
    xx.nama_matkul = "Machine Learning";
    xx.jumlah_sks = 3;

    y.id_matkul = "CSH101";
    y.nama_matkul = "STRUKTUR DATA";
    y.jumlah_sks = 4;

    z.id_matkul  = "CSH111";
    z.nama_matkul = "SISTEM INFORMASI";
    z.jumlah_sks = 3;
    insertlast_matakuliah(M,alokasi_matakuliah(xx));
    insertlast_matakuliah(M,alokasi_matakuliah(y));
    insertlast_matakuliah(M,alokasi_matakuliah(z));
do{
    cout<<endl;
    cout<<"pilih menu : "<<endl;
    cout<<"1. input mahasiswa"<<endl;
    cout<<"2. input matakuliah"<<endl;
    cout<<"3. lihat data mahasiswa"<<endl;
    cout<<"4. hapus matakuliah "<<endl;
    cout<<"0. keluar"<<endl;
    cout<<"pilih : ";
    cin>>choose;
    if(choose==1){
        cout<<"Nama Lengkap : ";
        cin>>x.nama;
        cout<<"NIM          : ";
        cin>>x.nim;
        cout<<"KELAS        : ";
        cin>>x.kelas;
        cout<<"JURUSAN      : ";
        cin>>x.jurusan;
        cout<<"ANGKATAN     : ";
        cin>>x.angkatan;
        insert_student(S,alokasi_student(x));
    }else if(choose==2){
        printinfo_matakuliah(M);
        cout<<"Nama Mahasiswa : ";
        cin>>x.nama;
        cout<<"Kode Matakuliah Yang diambil : ";
        cin>>m.id_matkul;
        address_matakuliah mt = find_matkul(M,m.id_matkul);
        address_student st = find_student(S,x.nama);
        address_relasi ar = alokasi_relasi(mt);
        if(st->nextrelasi == NULL){
            st->nextrelasi = ar;
        }else{
// add condition when not empty
            cout<<"full";
        }
    }else if(choose==3){
        printinfo_student(S);
    }
}
while(choose != 0);

}

