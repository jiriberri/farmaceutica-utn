#include "ArchivoVentas.h"
#include <iostream>
using namespace std;

ArchivoVentas::ArchivoVentas(std::string nombreArchivo){

 _nombreArchivo=nombreArchivo;
}


bool ArchivoVentas::guardarVenta(Venta reg)
{
    FILE* p = fopen(_nombreArchivo.c_str(), "ab"); // abrir en modo append
    if (p == NULL)
    {

        cout<<"Error, archivo no encontrado"<<endl;
        return 0;
    }

    fwrite(&reg, sizeof(Venta), 1, p); // escribe el cliente
    fclose(p);

    return true;
}


int ArchivoVentas::cantidadRegistros(){

FILE *p =fopen (_nombreArchivo.c_str(),"rb");

if(p==NULL){

    cout<<"Error,archivo no encontrado"<<endl;
    return 0;

}
fseek(p,0,SEEK_END);

int cantidad= ftell(p)/sizeof(Venta);

fclose(p);

return cantidad;

}

Venta ArchivoVentas::leerVenta(int pos){
FILE *p= fopen (_nombreArchivo.c_str(),"rb");

if(p==nullptr){

    return Venta();
}

Venta ven;

 fseek(p, sizeof(Venta) * pos, SEEK_SET);  // mueve puntero a la posición
    fread(&ven, sizeof(Venta), 1, p);           // lee el cliente
    fclose(p);

 return ven;
}

bool ArchivoVentas::modificarVenta(Venta obj, int pos)
{

    FILE *p =fopen(_nombreArchivo.c_str(),"rb+");

    if(p==nullptr)
    {
        return false;
    }
    fseek(p, pos * sizeof obj, 0);
    bool escribio=fwrite(&obj,sizeof obj,1,p);
    fclose(p);
    return escribio;
}

int ArchivoVentas::buscarPorNumFactura(int numFactura)
{
    int total = cantidadRegistros();

    for (int i = 0; i < total; i++)
    {
        Venta v = leerVenta(i);
        if (v.getNumFacturas() == numFactura)
        {
            return i;
        }
    }

    return -1;
}





bool ArchivoVentas::existe() const {
    FILE* p = fopen(_nombreArchivo.c_str(), "rb");

    if (p == NULL) return false;

    fclose(p);

    return true;
}
