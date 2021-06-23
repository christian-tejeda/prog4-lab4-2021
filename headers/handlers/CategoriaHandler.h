#ifndef CATEGORIA_HANDLER_H
#define CATEGORIA_HANDLER_H

#include <string>
#include <map>

#include "../utils/enums.h"
#include "../entities/Categoria.h"

using namespace std;

class CategoriaHandler
{

private:
    static CategoriaHandler *instancia;
    map<string, Categoria *> cats;

    CategoriaHandler();
    ~CategoriaHandler();

public:
    static CategoriaHandler *getInstance();

    map<string, Categoria *> obtenerCategorias();

    Categoria *obtenerCategoriaPorId(string nombre);

    void agregarCategoria(Categoria *categoria);

    void eliminarCategoria(Categoria *categoria);

    void crearNuevaCategoria(string nombre, string descripcion, TipoCategoria tipoCategoria);

    static void releaseInstance();
};

#endif