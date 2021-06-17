#ifndef I_AGREGAR_CATEGORIA_H
#define I_AGREGAR_CATEGORIA_H

//#include "../datatypes/DataGenero.h"
//#include "../datatypes/DataPlataforma.h"
#include "../datatypes/DataCategoria.h"

#include <set>

class IAgregarCategoria
{ //interface
public:
    virtual std::set<DataCategoria *> obtenerCategorias() = 0;
    virtual void agregarCategoria(std::string nombre,std::string descripcion, TipoCategoria tipo) = 0;
    //virtual void agregarGenero(DataGenero *genero) = 0;
    //virtual void agregarOtraCategoria(DataCategoria *otra) = 0;
    virtual void confirmarAgregarCategoria(bool confirmar) = 0;

    virtual ~IAgregarCategoria(){};
};

#endif