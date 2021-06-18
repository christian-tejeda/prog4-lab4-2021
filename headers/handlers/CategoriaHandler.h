#ifndef CATEGORIA_HANDLER_H
#define CATEGORIA_HANDLER_H

#include <string>
#include <map>
#include <set>
#include <utility>

#include "../utils/enums.h"
#include "../entities/Categoria.h"
//#include "../entities/Genero.h"
//#include "../entities/Plataforma.h"

using namespace std;

class CategoriaHandler
{ //singleton

private:
    static CategoriaHandler *instancia;
    map<string, Categoria *> cats;
    CategoriaHandler();
    ~CategoriaHandler();

public:
    static CategoriaHandler *getInstance();

    map<string, Categoria *> obtenerCategorias();

    Categoria *obtenerCategoriaPorId(string nombre);

    // Plataforma *obtenerPlataformaPorId(string nombre);

    // Genero *obtenerGeneroPorId(string nombre);

    void agregarCategoria(Categoria *categoria);

    void eliminarCategoria(Categoria *categoria);

    void crearNuevaCategoria(std::string nombre,std::string descripcion, TipoCategoria tipo);

    static void releaseInstance();
};

#endif