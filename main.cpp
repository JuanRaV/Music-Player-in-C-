#include <iostream>
#include <windows.h>
#include <mmsystem.h>
#include "Lista.h"
#include "Cancion.h"
using namespace std;

Cancion cancion;
Lista *lista = new Lista();
void menu();
void imprimirActual();
void gotoxy(int x, int y);

void noValor(){
    cout<< "Ingrese un digito valido"<<endl;
    system("pause");
    system("cls");
}

void menu(){
    CONSOLE_FONT_INFOEX cfi;
    cfi.cbSize = sizeof(cfi);
    cfi.nFont = 0;
    cfi.dwFontSize.X = 0;                   // Width of each character in the font
    cfi.dwFontSize.Y = 20;                  // Height
    cfi.FontFamily = FF_DONTCARE;
    cfi.FontWeight = FW_BOLD;
    std::wcscpy(cfi.FaceName, L"Bahnschrift SemiBold"); // Choose your font
    SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    int id=1;
    int opc, num;
    int puntero=1;
    string aux1,aux;
    char opcion[100], numero[100];
    do{
        system("cls");
         SetConsoleTextAttribute(hConsole, 9);
        cout<< "----------MUSIC PLAYER----------"<<endl;
        cout<<"\t    Juan Ra"<<endl<<endl;
        SetConsoleTextAttribute(hConsole, 7);
        cout<< "[1] Llenar lista"<<endl;
        cout<< "[2] Ingresar cancion"<<endl;
        cout<< "[3] Siguiente"<<endl;
        cout<< "[4] Anterior"<<endl;
        cout<< "[5] Eliminar"<<endl;
        cout<< "[6] Modificar"<<endl;
        cout<< "[7] Play"<<endl;
        cout<< "[8] Stop"<<endl;
        cout<< "[9] Mostrar cancion actual"<<endl;
        cout<< "[10] Invertir"<<endl;
        cout<< "[11] Salir"<<endl;
        lista->desplegar();
        gotoxy(0, 14);
        cout<<"Seleccione una opcion: "; cin>>opcion;
        if(opc=atoi(opcion)){
            switch(opc){
                case 1:
                    lista->llenar();
                    break;
                case 2:

                    SetConsoleTextAttribute(hConsole, 9);
                    gotoxy(60,3);cout<<"--INGRESAR CANCION--"<<endl;
                    SetConsoleTextAttribute(hConsole, 7);
                    gotoxy(60,4);cout<< "Nombre: ";
                    cin.sync();
                    getline(cin, aux1);
                    cancion.setNombre(aux1);
                    gotoxy(60,5);cout<< "Artista: ";
                    getline(cin, aux);
                    cancion.setAutor(aux);
                    gotoxy(60,6);cout<< "Album: ";
                    getline(cin, aux);
                    cancion.setAlbum(aux);
                    gotoxy(60,7);cout<< "Genero: ";
                    getline(cin, aux);
                    cancion.setGenero(aux);
                    gotoxy(60,8);cout<< "Ingrese direccion: ";
                    getline(cin, aux);
                        SetConsoleTextAttribute(hConsole, 9);
                        gotoxy(60,9);cout<<"Cancion repetida"<<endl;
                        SetConsoleTextAttribute(hConsole, 7);
                        gotoxy(60,10);system("pause");

                        cancion.setDireccion(aux);
                        lista->insertarUltimo(cancion);
                        id++;
                        SetConsoleTextAttribute(hConsole, 9);
                        gotoxy(60,9);cout<< "CANCION AGREGADA CORRECTAMENTE"<<endl;
                        SetConsoleTextAttribute(hConsole, 7);
                        gotoxy(60,10);system("pause");
                        system("cls");


                    break;
                case 3:
                    lista->siguiente();
                    break;
                case 4:
                    lista->anterior();
                    break;
                case 5:
                    cout<< "Ingrese el ID que desea eliminar: "; cin>>numero;
                    if(num=atoi(numero)){
                        if(puntero==1){

                        }
                        else{
                            puntero--;
                        }
                        cancion.setID(num);
                        lista->eliminar(num);
                    }
                    else{
                        noValor();
                    }
                    break;
                case 6:
                    SetConsoleTextAttribute(hConsole, 9);
                    gotoxy(60,3);cout<<"--MODIFICAR--"<<endl;
                    SetConsoleTextAttribute(hConsole, 7);
                    gotoxy(60,4);cout<< "Ingrese el ID que desea modificar: "; cin>>numero;
                    if(num=atoi(numero)){
                        gotoxy(60,5);cout<< "Nombre nuevo: ";
                        cin.sync();
                        getline(cin, aux);
                        cancion.setNombre(aux);
                        gotoxy(60,6);cout<< "Artista nuevo: ";
                        getline(cin, aux);
                        cancion.setAutor(aux);
                        gotoxy(60,7);cout<< "Album nuevo: ";
                        getline(cin, aux);
                        cancion.setAlbum(aux);
                        gotoxy(60,8);cout<< "Genero nuevo: ";
                        getline(cin, aux);
                        cancion.setGenero(aux);
                        gotoxy(60,9);cout<< "Direccion nueva: ";
                        getline(cin, aux);
                        cancion.setDireccion(aux);
                        cancion.setID(num);
                        lista->modificar(num, cancion);
                        SetConsoleTextAttribute(hConsole, 9);
                        gotoxy(60,10);cout<< "CANCION ACTUALIZADA CORRECTAMENTE"<<endl;
                        SetConsoleTextAttribute(hConsole, 7);
                        gotoxy(60,11);system("pause");
                    }
                    else{
                        noValor();
                    }
                    break;
                case 7:
                    cout<<"Reproduciendo archivo: ";
                    SetConsoleTextAttribute(hConsole, 9);
                    lista->reproducir();
                    cout<<endl;
                    SetConsoleTextAttribute(hConsole, 7);
                    system("pause");
                    break;
                case 8:
                    PlaySound(NULL,NULL,0);

                    break;
                case 9:
                    lista->imprimirActual();

                    break;
                case 10:
                    lista->invertir();
                    SetConsoleTextAttribute(hConsole, 9);
                    cout<< "Saliendo del programa..."<<endl;
                    cout<< "Hasta luego"<<endl;
                    SetConsoleTextAttribute(hConsole, 7);

                    break;
                case 11:

                    SetConsoleTextAttribute(hConsole, 9);
                    cout<< "Saliendo del programa..."<<endl;
                    cout<< "Hasta luego"<<endl;
                    SetConsoleTextAttribute(hConsole, 7);

                    break;

            }
        }
        else{
            noValor();
        }
    }while(opc!=11);

}


int main(){
    menu();
    return 0;
}
