#ifndef CATEGORIA_H
#define CATEGORIA_H

#include <string>
#include <map>
#include <set>
#include <utility>

#include "../utils/enums.h"
#include "../datatypes/DataCategoria.h"

using namespace std;

class Categoria{
private:
    string nombre;
    string descripcion;
public:
    Categoria();
    string getNombre();
    string getDescripcion();
    void setNombre(string nombre);
    void setDescipcion(string descripcion);
    DataCategoria getData();
    ~Categoria();
};

#endif