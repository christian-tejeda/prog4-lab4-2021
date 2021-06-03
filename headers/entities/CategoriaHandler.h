#ifndef CATEGORIA_HANDLER_H
#define CATEGORIA_HANDLER_H

#include <string>
#include <map>
#include <set>
#include <utility>

#include "../enums.h"


using namespace std;

class CategoriaHandler{

private:
    set<Categoria> cats;

public:
    set<Categoria> obtenerCategorias() const;
    Categoria obtenerCategoriaPorId(nom : string) const;
    Plataforma obtenerPlataformaPorId(plat : string) const;
    Genero obtenerGeneroPorId(genero : string) const;
    agregarCategoria(categoria : Categoria) const;
    actualizarCategoria(categoria : Categoria) const;
    eliminarCategoria(categoria : Categoria) const;
    ~CategoriaHandler();
};

#endif