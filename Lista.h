#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED
#include <iostream>
#include <windows.h>
#include <mmsystem.h>
using namespace std;
#include "Cancion.h"

class Lista{
    private:
        class Nodo{
            public:
                Cancion song;
                Nodo *next;
                Nodo *prev;
        };
        Nodo *head;
        Nodo *actual;
        int pos;
        int id;
        void actualizarPos();
    public:
        Lista();
        ~Lista();
        void insertarPrimero(Cancion);
        void insertarUltimo(Cancion);
        bool isEmpty();
        void desplegar();
        int travel();
        void siguiente();
        void anterior();
        void eliminar(const int&);
        Cancion buscar(const int&);
        void modificar( int,Cancion);
        void imprimir(int,Cancion);
        void imprimirActual();
        void play();
        void reproducir();
        void llenar();
        void invertir();

};

void gotoxy(int x, int y){
    HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition(hcon, dwPos);
}

Lista::Lista(){
    head=nullptr;
    pos=20;
    id=1;
}

Lista::~Lista(){
    if(head!=nullptr){
        Nodo *temp=head->next;
        Nodo *temp2;
        while(temp!=head){
            temp2=temp;
            temp=temp->next;
            delete temp2;
        }
        delete head;
    }
}

void Lista::insertarPrimero(Cancion cancion){
    Nodo *nuevo=new Nodo();
    nuevo->song= cancion;
    nuevo->song.pos= this->pos;
    pos++;
    if(head == nullptr){
        nuevo->next=nuevo;
        nuevo->prev= nuevo;
        head=nuevo;
    }
    else{
        Nodo *last = head->prev;
        nuevo->next=head;
        nuevo->prev=last;
        head->prev=nuevo;
        last->next=nuevo;
        head=nuevo;

    }
    actual=nuevo;

}

void Lista::insertarUltimo(Cancion cancion) {
    Nodo *nuevo=new Nodo();

    nuevo->song= cancion;
    nuevo->song.pos= this->pos;
    nuevo->song.setID(id++);
    pos++;
    if(head == nullptr) {
        nuevo->next=nuevo;
        nuevo->prev= nuevo;
        head=nuevo;
        }
    else {
        Nodo *last = head->prev;
        nuevo->next=head;
        nuevo->prev=last;
        head->prev=nuevo;
        last->next=nuevo;
        }

    actual=nuevo;
    }

bool Lista::isEmpty(){
    if(head==nullptr){
        return true;
    }
    else{
        return false;
    }
}

void Lista::desplegar(){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    if(!isEmpty()){
        int n(20);
        int id(1);
        Nodo *temp=head;
        SetConsoleTextAttribute(hConsole, 9);
        gotoxy(7, actual->song.pos);
        cout<<"->";
        SetConsoleTextAttribute(hConsole, 15);
        Cancion cancion;
        do{

            cancion =temp->song;
            gotoxy(10, 17);cout<<" -------------------------------------------------------------------------------------------------"<<endl;
            gotoxy(8, 18);
            cout<< "  | ID  |        Nombre       |      Artista      |       Album      |    Genero     |   Direccion  |"<<endl;
            gotoxy(10, 19);cout<<"|-------------------------------------------------------------------------------------------------| "<<endl;
                     if(n == actual->song.pos)
                SetConsoleTextAttribute(hConsole, 9);
            gotoxy(10, n);cout<<"|";
            gotoxy(12, n);cout<<" "<<id;
            gotoxy(16, n);cout<<"|";
            gotoxy(18, n);cout<<cancion.getNombre();
            gotoxy(38, n);cout<<"|";
            gotoxy(40, n);cout<<cancion.getAutor();
            gotoxy(58, n);cout<<"|";
            gotoxy(60, n);cout<<cancion.getAlbum();
            gotoxy(77, n);cout<<"|";
            gotoxy(79, n);cout<<cancion.getGenero();
            gotoxy(93, n);cout<<"|";
            gotoxy(95, n);cout<<cancion.getDireccion();
            gotoxy(108, n);cout<<"|";

            temp=temp->next;
            n++;
            id++;
        SetConsoleTextAttribute(hConsole, 15);

        }while(temp!= head);
    }
    else{
        gotoxy(50,5);
        cout<< "La lista esta vacia"<<endl;
    }
}

int Lista::travel(){
    int contador=0;
    if(!isEmpty()){
        Nodo *temp=head;
        do{
            contador++;
            temp=temp->next;
        }while(temp!=head);
    }
    return contador;
}

void Lista::eliminar(const int& posicion){
    if(head!=nullptr){
    if(posicion<=travel()){
        if(posicion==1){
            if(travel()==1){
                delete head;
                head=nullptr;
            }
            else{
                Nodo *tempo = head;
                Nodo *last =head->prev;
                head=head->next;
                last->next=head;
                head->prev=last;
                delete tempo;
            }
        }
        else{
            Nodo *temp=head;
            for(int i=1; i<=posicion-1; i++){
                temp=temp->next;
            }
            Nodo *tempo=temp;
            Nodo *anterior=temp->prev;
            temp=temp->next;
            anterior->next=temp;
            temp->prev=anterior;
            delete tempo;
        }
    }
    pos--;
    id--;
    actualizarPos();}
    else
        cout<<"Lista Vacia..."<<endl;

}

Cancion Lista::buscar(const int& posicion){
    Nodo *temp =head;
    for(int i =1; i<=posicion; i++){
        temp=temp->next;
    }
    return temp->song;
}

void Lista::modificar( int id, Cancion c){

        if(!this->isEmpty()) {
        Nodo* aux(head);
        int pos ;

        do {

            if(aux->song.getID() == id) {
                pos=aux->song.pos;
                aux->song=c;
                aux->song.pos=pos;

                return;
                }
                 cout<<"b"<<endl;
            aux=aux->next;
            }
        while(aux!=head);

        }

}

void Lista::imprimir(int puntero, Cancion cancion){
    Nodo* temp = head;
    if(puntero <= travel() && puntero>=1) {
        if(puntero==1) {
            if(travel()==1) {
                cancion = temp->song;
                gotoxy(10,15);
                cout<<"Nombre: " << cancion.getNombre();
                gotoxy(10,16);
                cout<<"Artista: " << cancion.getAutor();
                gotoxy(10,17);
                cout<<"Album: " << cancion.getAlbum();
                gotoxy(10,18);
                cout<<"Genero: " << cancion.getGenero();
                }
            else {
                cancion = temp->song;
                gotoxy(10,15);
                cout<<"Nombre: " << cancion.getNombre();
                gotoxy(10,16);
                cout<<"Artista: " << cancion.getAutor();
                gotoxy(10,17);
                cout<<"Album: " << cancion.getAlbum();
                gotoxy(10,18);
                cout<<"Genero: " << cancion.getGenero();
                }
            }
        else {
            for(int i=1; i<puntero; i++) {
                temp = temp->next;
                cancion = temp->song;
                }
            gotoxy(10,15);
            cout<<"Nombre: " << cancion.getNombre();
            gotoxy(10,16);
            cout<<"Artista: " << cancion.getAutor();
            gotoxy(10,17);
            cout<<"Album: " << cancion.getAlbum();
            gotoxy(10,18);
            cout<<"Genero: " << cancion.getGenero();
            }
        }

}

void Lista:: imprimirActual(){
    if(head!=nullptr){
    system("cls");

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 9);
    cout<<"--ACTUAL--";
    SetConsoleTextAttribute(hConsole, 9);
        if(actual->song.getNombre()=="You Rock My World"){
        SetConsoleTextAttribute(hConsole, 7);
        gotoxy(60, 2);cout<<"           §§§$$§§$§§_"<<endl;
        gotoxy(60, 3);cout<<"         $$$$$§§§$$§§$§_:"<<endl;
        gotoxy(60, 4);cout<<"       ($$$$$$$§§§$$§§$§§_(§§)_"<<endl;
        gotoxy(60, 5);cout<<"       ($$$$$$$$$$$$§§$$__$§§$)~"<<endl;
        gotoxy(60, 6);cout<<"        (§§§$$$$§$$$$§§$$§§$§§$§§~"<<endl;
        gotoxy(60, 7);cout<<"        ((_($$§§$§§$§§§§§§§§§$$§§$"<<endl;
        gotoxy(60, 8);cout<<"        ))_(§$$$$$$§§$$§§$§§$§§§§§~"<<endl;
        gotoxy(60, 9);cout<<"         ((_)_((§$$§$$§§$$§§$§§$§§§§((...."<<endl;
        gotoxy(60, 10);cout<<"           ))_)_§$$))_$$$§§§$$§§$§§$§§§§§"<<endl;
        gotoxy(60, 11);cout<<"           (__(_))_§$§§§§§$$§§$$§§$§§$§§§"<<endl;
        gotoxy(60, 12);cout<<"               (__$_$$§§§§§§$$§§$$§§$§§$§§"<<endl;
        gotoxy(60, 13);cout<<"               )_$_$§$§§§§§§$§§$$§§$§§§§__§"<<endl;
        gotoxy(60, 14);cout<<"                  )$__§§§§§§$§$$_§$$§§___§$§"<<endl;
        gotoxy(60, 15);cout<<"                 (§___$§§§§§$§§$_§$$___§§§§§§"<<endl;
        gotoxy(60, 16);cout<<"                 ($§__$§$§§§$$$§§§_$__$§§§§§$§§"<<endl;
        gotoxy(60, 17);cout<<"                  §§§_§$$$$$§§§§§§§$§§_§$$§$$§§§§"<<endl;
        gotoxy(60, 18);cout<<"                  (§__§§§§§§§§§§$§§$$§§_§§$_§§§§§"<<endl;
        gotoxy(60, 19);cout<<"                   (§_$$§§$§§§§§§§§$$§§$§_$§§§§§§"<<endl;
        gotoxy(60, 20);cout<<"                    §_$§§$§§§§§§§§$$§§_§§$§§§§§§"<<endl;
        gotoxy(60, 21);cout<<"                    §__$$§§§§$§§§§§§$_§§$§§$§§§"<<endl;
        gotoxy(60, 22);cout<<"                     §_$$§§§§$§§§§§__$§§$§§$§§"<<endl;
        gotoxy(60, 23);cout<<"                     §_$$_§§§§§§$§§$$§§$§§§§"<<endl;
        gotoxy(60, 24);cout<<"                     §§§§_§§§§§$§§$$§§$§§§§"<<endl;
        gotoxy(60, 25);cout<<"                     §§§$$::::§§$$$§§$$§§$_§"<<endl;
        gotoxy(60, 26);cout<<"                   §§§§:§§§§§§__§§$§§$§_§§"<<endl;
        gotoxy(60, 27);cout<<"                 §$$:§§§§§$$$§___§$§§$§§§§"<<endl;
        gotoxy(60, 28);cout<<"              §§:§§$§$$§§$$__$§§$§§§§§§"<<endl;
        gotoxy(60, 29);cout<<"            $$§:§§§$§$$$$$§§$$§§$§§$§_§§§"<<endl;
        gotoxy(60, 30);cout<<"          $$§:§§$$$$$$§§$§§§§§§§$$  $§§"<<endl;
        gotoxy(60, 31);cout<<"       $$$§::§$$$$$$§§$§§§§§§§§§      §§"<<endl;
        gotoxy(60, 32);cout<<"     $$$§::§$$$$FL$§§§§§§§$§§$         §"<<endl;
        gotoxy(60, 33);cout<<"   $$$§::§§$$$$§§§§$$$§§§§"<<endl;
        gotoxy(60, 34);cout<<" $$§::§§§$$§§$§§§§§§§§§"<<endl;
        gotoxy(60, 35);cout<<"$§§§$§§§§§$$§§§§§§§"<<endl;
        gotoxy(60, 36);cout<<"§§§§§§§$$§§$§§§§"<<endl;
        gotoxy(60, 37);cout<<" §§§§§§§§$§§_§§$"<<endl;
        gotoxy(60, 38);cout<<" §§§§§§§§§$§§$_§§§"<<endl;
        gotoxy(60, 39);cout<<"  §§§§$§§§$§$§§$_§§"<<endl;
        gotoxy(60, 40);cout<<"   §§§§$§§§$§$§§$_§§"<<endl;
        gotoxy(60, 41);cout<<"     $§§§§§§§§§§§$§_§§"<<endl;
        gotoxy(60, 42);cout<<"      §§§$§§§§§§$§§$§_§"<<endl;
        gotoxy(60, 43);cout<<"       $§§§§§§§$$§$$§§_§§"<<endl;
        gotoxy(60, 44);cout<<"        §§§§$$§§$$§§$$§§_§"<<endl;
        gotoxy(60, 45);cout<<"         §$§$$$§§§§§§$$§§$§§"<<endl;
        gotoxy(60, 46);cout<<"          $$$$§§$ §§$§§$§§§§§§"<<endl;
        gotoxy(60, 47);cout<<"           §$§§$§§ §§§§§§§§§$$§§$§"<<endl;
        gotoxy(60, 48);cout<<"            §$§§$§§ §§§§§§§§ $$§§$"<<endl;
        gotoxy(60, 49);cout<<"             §$§§$§§ $§§§§§  §§$§"<<endl;
        gotoxy(60, 50);cout<<"                 §$§§$      §§§§"<<endl;
        gotoxy(60, 51);cout<<"                  §§§§§ §§  §§§§$"<<endl;
        gotoxy(60, 52);cout<<"                  §§§$§§  $§§§§§§§"<<endl;
        gotoxy(60, 53);cout<<"                   §$§§$§    §$§§§§"<<endl;
        gotoxy(60, 54);cout<<"                     §§§$§§   §§$§§"<<endl;
    }else if(actual->song.getNombre()=="Rayando El Sol"){
        SetConsoleTextAttribute(hConsole, 7);
   	gotoxy(50,2 );cout<<"                 __                                      __  "<<endl;
	gotoxy(50,3 );cout<<"                 |--|                                   |--|"<<endl;
	gotoxy(50,4 );cout<<"      .._       o' o'                     (())))   _    o' o'"<<endl;
	gotoxy(50,5 );cout<<"     //\\\    |  __                      )) _ _))  ,' ; |  __  "<<endl;
	gotoxy(50,6 );cout<<"    ((-.-\)  o' |--|  ,;::::;.          (C    )   / /^ o' |--| "<<endl;
	gotoxy(50,7 );cout<<"   _))'='(\-.  o' o' ,:;;;;;::.         )\   -'(  / /     o' o' "<<endl;
	gotoxy(50,8 );cout<<"  (          \       :' o o `::       ,-)()  /_.')/                 ."<<endl;
	gotoxy(50,9 );cout<<"  | | .)(. |\ \      (  (_    )      /  (  `'  /\_)  .:izf:,_  .  |"<<endl;
	gotoxy(50,10 );cout<<"  | | _   _| \ \     :| ,==. |:     /  ,   _  / /1  .:q568Glip-, \\ |"<<endl;
	gotoxy(50,11 );cout<<"  \ \/ '-' (__\_\____::\`--'/::    /  /   / \/ //|\    \-38'^ ^`8k='  \\L,"<<endl;
	gotoxy(50,12 );cout<<"   \__\\[][]____(_\_|::,`--',::   /  /   /__/ <(  \  \8) o o 18-'_ ( /"<<endl;
	gotoxy(50,13 );cout<<":\o*.-.(     '-,':   _    :`.|  L----' _)/ ))-..__)(  J  498:- /] "<<endl;
	gotoxy(50,14 );cout<<":   [   \\     |     |=|   '  |\_____|,/.' //.   -38, 7~ P88;-'/ / "<<endl;
	gotoxy(50,15 );cout<<":  | \\   \\    |  |  |_|   |  |    ||  :: (( :   :  ,`""'`-._,' /"<<endl;
	gotoxy(50,16 );cout<<":  |  \\   \\   ;  |   |    |  |      \\\_::_)) |  :  ,     ,_    /"<<endl;
	gotoxy(50,17 );cout<<":( |   /  )) /  /|   |    |  |    |    [    |   \_\      _;--==--._ "<<endl;
	gotoxy(50,18 );cout<<":  |  /  /  /  / |   |    |  |    |    Y    |CJR (_\____:_        _:"<<endl;
	gotoxy(50,19 );cout<<":  | /  / _/  /  \   |lf  |  |  CJ|mk  |    | ,--==--.  |_`--==--'_|"<<endl;
	gotoxy(50,20 );cout<<"                                                         `--==--'"<<endl;
    }else if(actual->song.getNombre()=="Labios Rotos"){
        SetConsoleTextAttribute(hConsole, 7);
            gotoxy(50,2 );cout<<"           .. .. "<<endl;
           gotoxy(50,3 ); cout<<"         .'  `  `. "<<endl;
            gotoxy(50,4 );cout<<"       .'_.-...-._`. "<<endl;
            gotoxy(50,5 );cout<<"        `.       .' "<<endl;
            gotoxy(50,6 );cout<<"          `-...-' "<<endl;

            gotoxy(70,7);cout<<"           .. .. "<<endl;
           gotoxy(70,8); cout<<"         .'  `  `. "<<endl;
            gotoxy(70,9);cout<<"       .'_.-...-._`. "<<endl;
            gotoxy(70,10);cout<<"        `.       .' "<<endl;
            gotoxy(70,11);cout<<"          `-...-' "<<endl;

            gotoxy(85,2);cout<<"           .. .. "<<endl;
           gotoxy(85,3); cout<<"         .'  `  `. "<<endl;
            gotoxy(85,4);cout<<"       .'_.-...-._`. "<<endl;
            gotoxy(85,5);cout<<"        `.       .' "<<endl;
            gotoxy(85,6);cout<<"          `-...-' "<<endl;
        }else if(actual->song.getNombre()=="Veneno"){
        SetConsoleTextAttribute(hConsole, 7);
            gotoxy(60, 1);cout<<"                        |"<<endl;
            gotoxy(60, 2);cout<<"                    \\       /"<<endl;
            gotoxy(60, 3);cout<<"                      .---."<<endl;
            gotoxy(60, 4);cout<<"                 --  /     \\  --"<<endl;
            gotoxy(60, 5);cout<<"`~~^~^~^~^~^~^~^~^~^-=======-~^~^~^~~^~^~^~^~^~^~^~`"<<endl;
            gotoxy(60, 6);cout<<"`~^_~^~^~-~^_~^~^_~-=========- -~^~^~^-~^~^_~^~^~^~`"<<endl;
            gotoxy(60, 7);cout<<"`~^~-~~^~^~-^~^_~^~~ -=====- ~^~^~-~^~_~^~^~~^~-~^~`"<<endl;
            gotoxy(60, 8);cout<<"`~^~^~-~^~~^~-~^~~-~^~^~-~^~~^-~^~^~^-~^~^~^~^~~^~-`"<<endl;
        }
        else{
            SetConsoleTextAttribute(hConsole, 7);
            gotoxy(50, 1);cout<<"                           ,"<<endl;
            gotoxy(50, 2);cout<<"                       ,   |"<<endl;
            gotoxy(50, 3);cout<<"    _,,._              |  0' "<<endl;
            gotoxy(50, 4);cout<<"  ,'     `.__,--.     0'     "<<endl;
            gotoxy(50, 5);cout<<" /   .--.        |           ,,, "<<endl;
            gotoxy(50, 6);cout<<" | [=========|==|==|=|==|=|==___]"<<endl;
            gotoxy(50, 7);cout<<" \    '--'  __    |           ''' "<<endl;
            gotoxy(50, 8);cout<<"  `._   _,'  `--'            "<<endl;
            gotoxy(50, 9);cout<<"     ""'     , __,0     ,    "<<endl;
            gotoxy(50, 10);cout<<"             |) |)   / |    "<<endl;
            gotoxy(50, 11);cout<<"   ____     0'  0    | 0'    "<<endl;
            gotoxy(50, 12);cout<<"   |  |             0'       "<<endl;
            gotoxy(50, 13);cout<<"  0' 0'"<<endl;
        }
    gotoxy(0, 2);
    SetConsoleTextAttribute(hConsole, 7);
    cout<<"Nombre: ";
    SetConsoleTextAttribute(hConsole, 9);
    cout<<actual->song.getNombre();
    gotoxy(0, 3);
    SetConsoleTextAttribute(hConsole, 7);
    cout<< "Artista: ";
    SetConsoleTextAttribute(hConsole, 9);
    cout<<actual->song.getAutor();
    gotoxy(0, 4);
    SetConsoleTextAttribute(hConsole, 7);
    cout<< "Album: ";
    SetConsoleTextAttribute(hConsole, 9);
    cout<<actual->song.getAlbum();
    gotoxy(0, 5);
    SetConsoleTextAttribute(hConsole, 7);
    cout<< "Genero: ";
    SetConsoleTextAttribute(hConsole, 9);
    cout<<actual->song.getGenero();
    cout<<endl;
    SetConsoleTextAttribute(hConsole, 7);
    }
    else
        cout<<"Lista vacia..."<<endl;
    system("pause");
}

void Lista::play(){
    string temp=actual->song.getDireccion();
    string d;
    for(int i=0; i<temp.length(); i++){
        d+=temp[i];
        if(temp[i]== '\\'){
            d+='\\';
        }
    const char* dir=d.c_str();
    system(dir);
    }
}

void Lista::siguiente(){
    if(head!=nullptr)
        actual=actual->next;
    else{
        cout<<"Lista Vacia..."<<endl;\
        system("pause");}

}

void Lista::anterior(){
    if(head!=nullptr)
        actual=actual->prev;
    else{
    cout<<"Lista Vacia..."<<endl;
    system("pause");
    }

}

void Lista::reproducir(){
    string s=actual->song.getDireccion();
    int n= s.length();
    char char_array[n+1];
    strcpy(char_array, s.c_str());
    for(int i=0; i<n; i++){
        cout<< char_array[i];
    }

    PlaySound(TEXT(char_array), NULL, SND_FILENAME | SND_ASYNC);
}

void Lista:: llenar(){
    Cancion cancion;
    string nombre= "Rayando El Sol";
    string artista= "Mana";
    string album= "Falta De Amor";
    string genero="Alternativo";
    cancion.setNombre(nombre);
    cancion.setAutor(artista);
    cancion.setAlbum(album);
    cancion.setGenero(genero);
    cancion.setDireccion("1-RES");
    this->insertarUltimo(cancion);

    string nombre1 ="Oh My God";
    string artista1= "Adele";
    string album1= "30";
    string genero1= "Pop";
    cancion.setNombre(nombre1);
    cancion.setAutor(artista1);
    cancion.setAlbum(album1);
    cancion.setGenero(genero1);
    cancion.setDireccion("2-OMG");
    this->insertarUltimo(cancion);

    string nombre2= "Labios Rotos";
    string artista2="Zoe";
    string album2="MTV Unplugged";
    string genero2="Alternativo";
    cancion.setNombre(nombre2);
    cancion.setAutor(artista2);
    cancion.setAlbum(album2);
    cancion.setGenero(genero2);
    cancion.setDireccion("3-LR");
    this->insertarUltimo(cancion);

    string nombre3= "Veneno";
    string artista3="Danny Ocean";
    string album3="54+1";
    string genero3="Reggaeton";
    cancion.setNombre(nombre3);
    cancion.setAutor(artista3);
    cancion.setAlbum(album3);
    cancion.setGenero(genero3);
    cancion.setDireccion("4-V");
    this->insertarUltimo(cancion);

    string nombre4= "You Rock My World";
    string artista4="Michael Jackson";
    string album4="Bad";
    string genero4="Pop";
    cancion.setNombre(nombre4);
    cancion.setAutor(artista4);
    cancion.setAlbum(album4);
    cancion.setGenero(genero4);
    cancion.setDireccion("5-YRMW");
    this->insertarUltimo(cancion);

}

void Lista::invertir(){
    if(head != NULL) {
        Nodo* prevNode = head;
        Nodo* tempNode = head;
        Nodo* curNode = head->next;


        prevNode->prev = prevNode;

        while(curNode != head) {

            tempNode = curNode->next;

            curNode->next = prevNode;
            prevNode->prev = curNode;
            head->next = curNode;
            curNode->prev = head;

            prevNode = curNode;
            curNode = tempNode;
            }


        head = prevNode;
        actual= prevNode;
        actualizarPos();
        }else{
            cout<<"Lista Vacia..."<<endl;
            system("pause");
        }

}
void Lista::actualizarPos(){

    Nodo *index(head);
        int i(20),id(1);
    do {
        index->song.pos=i;
        index->song.setID(id);
        index=index->next;
        id++;
        i++;
        }
    while(index!=head);

    actual=head;
    this->desplegar();
}




#endif // LISTA_H_INCLUDED
