#include "player.h"
#include <ctime>

int randomInt(int  max_int)
{
    srand(time(NULL));
    return (rand() % max_int) + 1;
}

void printInfo(List L)
{
    /**
    * PR : menampilkan informasi ID, nama, dan lokasi file
    */

    address Q = first(L);
    if(first(L)==NULL)
    {
        cout<<"list kosong"<<endl;
    }
    else
    {
        do
        {
            cout<<"name    : "<<info(Q).name<<endl
                <<"ID      : "<<info(Q).ID<<endl
                <<"location: "<<info(Q).location<<endl;
            Q = next(Q);
        }
        while(Q!=first(L));
        cout<<"==============================================="<<endl;
    }
}


void playMusic(address P)
{
    /**
    * PR : memainkan lagu yang ditunjuk oleh pointer P
    */

    string filename = info(P).location+"/"+info(P).name;
    cout<<"playing "<<filename<<endl;
    PlaySound(TEXT(filename.c_str()), NULL, SND_FILENAME);
    _sleep(500); //delay 0.5 second
}


void shuffleList(List &L)
{
    /**
    * PR : mengacak isi (elemen) dari list L
    * FS : isi (elemen) dari list teracak
    */
    //-------------your code here-------------
    address P=first(L);
    address Q;
    if(first(L)==NULL&&last(L)==NULL){
        cout<<"list kosong"<<endl;
    }else{
        if(next(first(L))==first(L)){
            cout<<"tidak bisa di-shuffle"<<endl;
        }else{
            do{
                P=next(next(Q));
                deleteAfter(L,P,Q);
                insertAfter(L,prev(prev(P)),Q);
            }while(P!=first(L));
        }
    }
    //----------------------------------------
}

void sortListByID(List &L)
{
    /**
    * PR : mengurutkan isi (elemen) dari list L berdasarkan ID
    * FS : isi (elemen) dari list L terurut
    */
    //-------------your code here-------------
    List L2;
    address P,Prec;

    if(first(L)==NULL&&last(L)==NULL)
    {
        cout<<"list kosong"<<endl;
    }
    else
    {
        if(next(first(L))==first(L))
        {
            cout<<"list sudah terurut"<<endl;
        }
        else
        {
            do{
                if(first(L2)==NULL&&last(L2)==NULL){
                    deleteFirst(L,P);
                    insertFirst(L2,P);
                }deleteFirst(L,P);
                if(info(P).ID<info(first(L2)).ID){
                    insertFirst(L2,P);
                }if(info(P).ID>info(last(L2)).ID){
                    insertLast(L2,P);
                }else{
                    address Prec=first(L);
                    while(info(next(Prec)).ID<info(P).ID){
                        Prec=next(Prec);
                    }
                    insertAfter(L,Prec,P);
                }
            }while(first(L)!=NULL);
            L=L2;
        }
    }
//----------------------------------------

}

void playRepeat(List &L, int n)
{
    /**
    * PR : memainkan seluruh lagu di dalam list
    *      dari lagu pertama hingga terakhir sebanyak n kali
    */
    //-------------your code here-------------
    address P=first(L);
    do
    {
        do
        {
            playMusic(P);
            P=next(P);
        }
        while(P!=first(L));
        n--;
    }
    while(n>0);
    //----------------------------------------
}

void deleteMusicByID(List &L, infotype x)
{
    /**
    * IS : list L mungkin kosong
    * PR : menerima input user untuk ID lagu yang ingin dihapus
    *      jika ID lagu ditemukan, hapus (deallocate) lagu dari list
    * FS : elemen dengan ID yang dicari dideallocate
    */
    //-------------your code here-------------
    address P;
    address w=findElmByID(L,x);
    address Q=first(L);

    if(w==NULL)
    {
        cout<<"data tidak ditemukan"<<endl;
    }
    else
    {
        while(info(w).ID!=info(next(Q)).ID)
        {
            Q=next(Q);
        }
        deleteAfter(L,Q,P);
        deallocate(P);
    }
    //----------------------------------------
}
