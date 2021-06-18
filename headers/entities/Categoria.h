#ifndef CATEGORIA_H
#define CATEGORIA_H

#include <string>
#include <map>
#include <set>
#include <utility>

#include "../utils/enums.h"
#include "../datatypes/DataCategoria.h"
class Categoria
{
private:
    std::string nombre;
    std::string descripcion;
    TipoCategoria tipo;

public:
    Categoria();
    Categoria(std::string nombre, std::string descripcion);
    Categoria(std::string nombre, std::string descripcion,TipoCategoria cat);
    std::string getNombre();
    std::string getDescripcion();
    TipoCategoria getTipo();
    void setNombre(std::string nombre);
    void setDescipcion(std::string descripcion);
    DataCategoria getData();
    ~Categoria();
};

#endif