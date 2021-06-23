#ifndef I_AGREGAR_CATEGORIA_H
#define I_AGREGAR_CATEGORIA_H

#include "../datatypes/DataCategoria.h"

#include <set>

class IAgregarCategoria
{
public:
    virtual set<DataCategoria> obtenerCategorias() = 0;

    virtual void agregarCategoria(string nombre, string descripcion, TipoCategoria tipoCategoria) = 0;

    virtual void confirmarAgregarCategoria() = 0;

    virtual ~IAgregarCategoria(){};
};

#endif