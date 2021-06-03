#ifndef CATEGORIA_HANDLER_H
#define CATEGORIA_HANDLER_H

#include <string>
#include <map>
#include <set>
#include <utility>

#include "../enums.h"
#include "../entities/Categoria.h"


using namespace std;

class CategoriaHandler{

private:
    set<Categoria> cats;

public:
    set<Categoria> obtenerCategorias();
    Categoria obtenerCategoriaPorId(string nom);
    Plataforma obtenerPlataformaPorId(string plat);
    Genero obtenerGeneroPorId(string genero);
    agregarCategoria(Categoria categoria);
    actualizarCategoria(Categoria categoria);
    eliminarCategoria(Categoria categoria);
    ~CategoriaHandler();
};

#endif