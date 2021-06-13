#ifndef I_AGREGAR_CATEGORIA_H
#define I_AGREGAR_CATEGORIA_H

#include "../datatypes/DataGenero.h"
#include "../datatypes/DataPlataforma.h"

#include <set>

class IAgregarCategoria
{ //interface
public:
    virtual set<DataCategoria *> obtenerCategorias() = 0;
    virtual void agregarPlataforma(DataPlataforma *plataforma) = 0;
    virtual void agregarGenero(DataGenero *genero) = 0;
    virtual void agregarOtraCategoria(DataCategoria *otra) = 0;
    virtual void confirmarAgregarCategoria(bool confirmar) = 0;

    virtual ~IAgregarCategoria(){};
};

#endif