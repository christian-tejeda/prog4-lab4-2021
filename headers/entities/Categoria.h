#ifndef CATEGORIA_H
#define CATEGORIA_H

#include <string>

#include "../utils/enums.h"
#include "../datatypes/DataCategoria.h"

class Categoria
{
private:
    string nombre;
    string descripcion;
    TipoCategoria tipo;

public:
    Categoria();
    Categoria(string nombre, string descripcion);
    Categoria(string nombre, string descripcion, TipoCategoria tipoCategoria);

    string getNombre();
    string getDescripcion();
    TipoCategoria getTipo();

    void setNombre(string nombre);
    void setDescipcion(string descripcion);

    DataCategoria getData();

    ~Categoria();
};

#endif