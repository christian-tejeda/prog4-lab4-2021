#ifndef CATEGORIA_H
#define CATEGORIA_H

#include <string>
#include <map>
#include <set>
#include <utility>

#include "../utils/enums.h"
#include "../datatypes/DataCategoria.h"

using namespace std;

class Categoria
{
private:
    std::string nombre;
    std::string descripcion;

public:
    Categoria();
    std::string getNombre();
    std::string getDescripcion();
    void setNombre(std::string nombre);
    void setDescipcion(std::string descripcion);
    DataCategoria getData();
    ~Categoria();
};

#endif