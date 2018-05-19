#include "student.h"
#include "matkul.h"


int main()
{
    int choose;
    Student_s x,ns,ns2,ns3;
    matakuliah m;
    list_student S;
    list_matakuliah M;
    createlist_matakuliah(M);
    createlist_student(S);
    matakuliah xx,y,yy,z,zz;
    ns.nama = "charly";
    ns.nim = "1301150023";
    ns.kelas = "IF-39-09";
    ns.jurusan = "IF";
    ns.angkatan = "2015";

    ns2.nama = "aziz";
    ns2.nim = "1301150023";
    ns2.kelas = "IF-39-09";
    ns2.jurusan = "IF";
    ns2.angkatan = "2015";

    ns3.nama = "ray";
    ns3.nim = "1301150023";
    ns3.kelas = "IF-39-09";
    ns3.jurusan = "IF";
    ns3.angkatan = "2015";

    xx.id_matkul = "CSH123";
    xx.nama_matkul = "Machine Learning";
    xx.jumlah_sks = 3;

    y.id_matkul = "CSH101";
    y.nama_matkul = "STRUKTUR DATA";
    y.jumlah_sks = 4;

    z.id_matkul  = "CSH111";
    z.nama_matkul = "SISTEM_INFORMASI";
    z.jumlah_sks = 3;

    zz.id_matkul  = "CSH112";
    zz.nama_matkul = "Jaringan Komputer";
    zz.jumlah_sks = 4;

    insertlast_matakuliah(M,alokasi_matakuliah(xx));
    insertlast_matakuliah(M,alokasi_matakuliah(y));
    insertlast_matakuliah(M,alokasi_matakuliah(z));
    insertlast_matakuliah(M,alokasi_matakuliah(zz));
    insert_student(S,alokasi_student(ns));
    insert_student(S,alokasi_student(ns2));
    insert_student(S,alokasi_student(ns3));
    do
    {
        cout<<endl;
        cout<<"pilih menu : "<<endl;
        cout<<"1. insert mahasiswa"<<endl;
        cout<<"2. input matakuliah"<<endl;
        cout<<"3. lihat seluruh data mahasiswa"<<endl;
        cout<<"4. lihat seluruh data matakuliah"<<endl;
        cout<<"5. lihat daftar matakuliah yang di ambil"<<endl;
        cout<<"6. hapus data mahasiswa "<<endl;
        cout<<"7. hapus data matakuliah "<<endl;
        cout<<"8. insert matakuliah baru "<<endl;
        cout<<"9. hapus matakuliah mahasiswa "<<endl;
        cout<<"10.edit data matakuliah "<<endl;
        cout<<"11.edit data mahasiswa "<<endl;
        cout<<"0. keluar"<<endl;
        cout<<"pilih : ";
        cin>>choose;
        if(choose==1)
        {
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
        }
        else if(choose==2)
        {
            printinfo_matakuliah(M);
            cout<<"Nama Mahasiswa : ";
            cin>>x.nama;
            cout<<"Kode Matakuliah Yang diambil : ";
            cin>>m.id_matkul;
            address_matakuliah mt = find_matkul(M, m.id_matkul);
            address_student AS = find_student(S, x.nama);
            input_relasi(AS,alokasi_relasi(mt));
        }
        else if(choose==3)
        {
            printinfo_student(S);
        }
        else if(choose == 4)
        {
            printinfo_matakuliah(M);
        }
        else if(choose == 5)
        {
            cout<<"Masukan Nama Mahasiswa : ";
            cin>>x.nama;
            address_student AS = find_student(S,x.nama);
            printinfo_relasi(AS);
        }
        else if(choose == 6)
        {
            cout<<"Masukan Nama Mahasiswa yang Ingin Dihapus : ";
            cin>>x.nama;
            address_student AS = find_student(S,x.nama);
            if(AS == NULL){
                    cout<<"data mahasiswa tidak ada";
            }else{
                deleteafter_student(S,AS);
                cout<<"berhasil menghapus data mahasiswa";
            }
        }
        else if(choose == 7)
        {
            cout<<"Masukan Nama Mata Kuliah yang Ingin Dihapus : ";
            cin>>m.nama_matkul;
            address_matakuliah AM = find_matkulByname(M,m.nama_matkul);
            cout<<"alamat mt :"<<AM<<endl;
            if(AM==NULL){
                cout<<"data yang ingin dihapus tidak ada"<<endl;
            }else{
                deleteafter_matakuliah(M,AM);
                cout<<"data berhasil dihapus "<<endl;
            }
//            cout<<"Masukan Kode Mata Kuliah yang Ingin Dihapus : ";
//            cin>>m.id_matkul;
//            address_matakuliah mt = find_matkul(M,m.id_matkul);
//            if(mt==NULL){
//                cout<<"data yang ingin dihapus tidak ada"<<endl;
//            }else{
//                deleteafter_matakuliah(M,mt);
//                cout<<"data berhasil dihapus "<<endl;
//            }
        }
        else if(choose == 8)
        {
            cout<<"Masukan Kode Matakuliah : ";
            cin>>yy.id_matkul;
            cout<<"Masukan Nama Matakuliah : ";
            cin>>yy.nama_matkul;
            cout<<"Masukan Jumlah SKS : ";
            cin>>yy.jumlah_sks;
            insertlast_matakuliah(M,alokasi_matakuliah(yy));
        }
        else if(choose == 9){

        }
        else if(choose == 10){
            matakuliah m,n;
            cout<<"Masukan Kode Mata Kuliah: ";
            cin>>m.id_matkul;
            address_matakuliah AM = find_matkul(M, m.id_matkul);
            cout<<"Edit Nama Mata Kuliah: ";
            cin>>n.nama_matkul;
            cout<<"Edit Kode Mata Kuliah: ";
            cin>>n.id_matkul;
            cout<<"Edit Jumlah SKS: ";
            cin>>n.jumlah_sks;

            editData_MataKuliah(M, AM, n.id_matkul, n.nama_matkul, n.jumlah_sks);

        }
        else if(choose == 11) {
            cout<<"Masukan Nama mahasiswa: ";
            cin>>x.nama;
            address_student AS = find_student(S, x.nama);
            Student_s ES;
            cout<<"Edit Nama: ";
            cin>>ES.nama;
            cout<<"Edit Nim: ";
            cin>>ES.nim;
            cout<<"Edit Kelas: ";
            cin>>ES.kelas;
            cout<<"Edit Angkatan: ";
            cin>>ES.angkatan;
            cout<<"Edit Jurusan: ";
            cin>>ES.jurusan;

            editData_student(S, AS, ES.nama, ES.nim, ES.jurusan, ES.kelas, ES.angkatan);
        }
        else if(choose == 12){

        }
    }
    while(choose != 0);
    return 0;
}

