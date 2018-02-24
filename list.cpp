#include "list.h"

void createList(List &L) {
    /**
    * FS : first(L) dan last(L) diset Nil
    */
    //-------------your code here-------------
    first(L)=NULL;
    last(L)=NULL;

    //----------------------------------------
}

address allocate(infotype x) {
    /**
    * FS : mengembalikan elemen list baru dengan info = x,
    *      next dan prev elemen = Nil
    */

    address P = NULL;
    //-------------your code here-------------
    P=new elmlist;
    info(P)=x;
    next(P)=NULL;
    prev(P)=NULL;

    //----------------------------------------
    return P;
}

void deallocate(address &P) {
    /**
    * FS : menghapus elemen yang ditunjuk oleh P (delete)
    */
    //-------------your code here-------------
    delete P;
    //----------------------------------------
}

void insertFirst(List &L, address P) {
    /**
    * IS : List L mungkin kosong
    * FS : elemen yang ditunjuk P menjadi elemen pertama pada List L
    */
    //-------------your code here-------------
    if(first(L)==NULL&&last(L)==NULL){
        first(L)=P;
        last(L)=P;
        next(P)=P;
        prev(P)=P;
    }else{
        next(P)=first(L);
        prev(first(L))=P;
        first(L)=P;
        next(last(L))=first(L);
        prev(first(L))=last(L);
    }
    //----------------------------------------
}

void insertLast(List &L, address P) {
    /**
    * IS : List L mungkin kosong
    * FS : elemen yang ditunjuk P menjadi elemen terakhir pada List L
    */
    //-------------your code here-------------
    if(first(L)==NULL&&last(L)==NULL){
        first(L)=P;
        last(L)=P;
        next(P)=P;
        prev(P)=P;
    }else{
        prev(P)=last(L);
        next(last(L))=P;
        last(L)=P;
        next(last(L))=first(L);
        prev(first(L))=last(L);
    }
    //----------------------------------------
}

address findElmByID(List L, infotype x) {
    /**
    * IS : List L mungkin kosong
    * FS : mengembalikan elemen dengan info.ID = x.ID,
           mengembalikan Nil jika tidak ditemukan
    */

    address P = NULL;
    //-------------your code here-------------
    if(first(L)==NULL&&last(L)==NULL){
        cout<<"List kosong"<<endl;
    }else{
        P=first(L);
        while(P!=NULL){
            if(x.ID==info(P).ID){
                return P;
            }
            P=next(P);
        }
        return NULL;
    }
    //----------------------------------------
    return P;
}

address findElmByName(List L, infotype x) {
    /**
    * IS : List L mungkin kosong
    * FS : mengembalikan elemen dengan info.name = x.name,
           mengembalikan Nil jika tidak ditemukan
    */

    address P = NULL;
    //-------------your code here-------------
     if(first(L)==NULL&&last(L)==NULL){
        cout<<"List kosong"<<endl;
     }else{
        P=first(L);
        while(P!=NULL){
            if(x.name==info(P).name){
                return P;
            }
            P=next(P);
        }
        return NULL;
     }
    //----------------------------------------
    return P;
}

void deleteFirst(List &L, address &P) {
    /**
    * IS : List L mungkin kosong
    * FS : elemen pertama di dalam List L dilepas dan disimpan/ditunjuk oleh P
    */
    //-------------your code here-------------
    if(first(L)==NULL&&last(L)==NULL){
        cout<<"List kosong"<<endl;
    }else{
        P=first(L);
        if(next(first(L))==first(L)){
            first(L)=NULL;
            last(L)=NULL;
        }else{
            next(last(L))=next(P);
            prev(next(P))=last(L);
            first(L)=next(P);
        }
        next(P)=NULL;
        prev(P)=NULL;
    }
    //----------------------------------------
}

void deleteLast(List &L, address &P) {
    /**
    * IS : List L mungkin kosong
    * FS : elemen tarakhir di dalam List L dilepas dan disimpan/ditunjuk oleh P
    */
    //-------------your code here-------------
    if(first(L)==NULL&&last(L)==NULL){
        cout<<"list kosong"<<endl;
    }else{
        P=last(L);
        if(prev(last(L))==last(L)){
            last(L)=NULL;
            first(L)=NULL;
        }else{
            last(L)=prev(P);
            prev(first(L))=last(L);
            next(last(L))=first(L);
        }
        next(P)=NULL;
        prev(P)=NULL;
    }
    //----------------------------------------
}

void insertAfter(List &L, address &Prec, address P) {
    /**
    * IS : Prec dan P tidak NULL
    * FS : elemen yang ditunjuk P menjadi elemen di belakang elemen yang
    *      ditunjuk pointer Prec
    */
    //-------------your code here-------------
    if(first(L)==NULL&&last(L)==NULL)
    {
        insertFirst(L,P);
    }
    else
    {
            next(P)=next(Prec);
            prev(P)=Prec;
            prev(next(P))=P;
            next(Prec)=P;
    }
    //----------------------------------------
}
void deleteAfter(List &L, address &Prec, address &P) {
    /**
    * IS : Prec tidak NULL
    * FS : elemen yang berada di belakang elemen Prec dilepas
    *      dan disimpan/ditunjuk oleh P
    */
    //-------------your code here-------------
    if(first(L)==NULL&&last(L)==NULL){
        cout<<"list kosong"<<endl;
    }else{
        if(next(Prec)==first(L)){
            deleteFirst(L,P);
        }else if(next(Prec)==last(L)){
            deleteLast(L,P);
        }else{
            P=next(Prec);
            next(Prec)=next(P);
            prev(next(P))=Prec;
            next(P)=NULL;
            prev(P)=NULL;
        }
    }
    //----------------------------------------
}

