#ifndef CANCION_H_INCLUDED
#define CANCION_H_INCLUDED
#include <iostream>
#include <string>
using namespace std;

class Cancion{

    private:
        int id;
        string nombre;
        string autor;
        string album;
        string genero;
        string direccion;
    public:
        int pos;
        void setID(const int&);
        void setNombre(const string&);
        void setAutor(const string&);
        void setAlbum(const string&);
        void setGenero(const string&);
        void setDireccion(const string&);

        int getID();
        string getNombre();
        string getAutor();
        string getAlbum();
        string getGenero();
        string getDireccion();
        string toString();

};

void Cancion::setID(const int& i){
    id=i;
}

void Cancion::setNombre(const string& name){
    nombre=name;
}

void Cancion::setAutor(const string& author){
    autor=author;
}

void Cancion::setAlbum(const string& al){
    album=al;
}

void Cancion::setGenero(const string& gen){
    genero=gen;
}

void Cancion::setDireccion(const string& direction){
    direccion=direction;
}

int Cancion::getID(){
    return id;
}

string Cancion::getNombre(){
    return nombre;
}

string Cancion::getAutor(){
    return autor;
}

string Cancion::getAlbum(){
    return album;
}

string Cancion::getGenero(){
    return genero;
}

string Cancion::getDireccion(){
    return direccion;
}

string Cancion::toString(){
    string impresion;

    impresion += "\nNombre: ";
    impresion += nombre;
    impresion += "\nAutor: ";
    impresion +=autor;
    impresion += "\nAlbum: ";
    impresion +=album;
    impresion += "\n Genero: ";
    impresion += genero;
    impresion += "\nDireccion: ";
    impresion += direccion;
    return impresion;
}



#endif // CANCION_H_INCLUDED
