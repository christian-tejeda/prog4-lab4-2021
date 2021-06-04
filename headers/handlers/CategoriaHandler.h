#ifndef CATEGORIA_HANDLER_H
#define CATEGORIA_HANDLER_H

#include <string>
#include <map>
#include <set>
#include <utility>

#include "../utils/enums.h"
#include "../entities/Categoria.h"
#include "../entities/Genero.h"
#include "../entities/Plataforma.h"



using namespace std;

class CategoriaHandler{

protected:
    static CategoriaHandler* singleCH;
    CategoriaHandler();

private:
    set<Categoria*> cats;

public:
    static CategoriaHandler* GetCategoriaHandler();
    set<Categoria*> obtenerCategorias();
    Categoria* obtenerCategoriaPorId(string nom);
    Plataforma* obtenerPlataformaPorId(string plat);
    Genero* obtenerGeneroPorId(string genero);
    void agregarCategoria(Categoria * categoria);
    void actualizarCategoria(Categoria * categoria);
    void eliminarCategoria(Categoria * categoria);
    ~CategoriaHandler();
};

#endif