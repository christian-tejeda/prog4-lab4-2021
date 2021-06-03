#ifndef DATA_CATEGORIA_H
#define DATA_CATEGORIA_H

#include <string>
#include <map>
#include <set>
#include <utility>

#include "../utils/enums.h"

using namespace std;

class DataCategoria{
private:
    string nombre;
    string descripcion;
public:
    DataCategoria();
    DataCategoria(string nombre, string descripcion);
    string getNombre() const;
    string getDescripcion() const;
    //setNombre(string nombre) const;
    //setDescripcion(string descripcion) const;
    ~DataCategoria();
};

#endif