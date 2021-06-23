#include <string>
#include <map>
#include <set>
#include <utility>

#include "../../headers/utils/enums.h"
#include "../../headers/entities/Categoria.h"
#include "../../headers/handlers/CategoriaHandler.h"

using namespace std;

CategoriaHandler *CategoriaHandler::instancia = nullptr;

CategoriaHandler::CategoriaHandler() {}

CategoriaHandler *CategoriaHandler::getInstance()
{
    if (instancia == nullptr)
        instancia = new CategoriaHandler();

    return instancia;
}

map<string, Categoria *> CategoriaHandler::obtenerCategorias() { return this->cats; }

Categoria *CategoriaHandler::obtenerCategoriaPorId(string nombre)
{
    if (this->cats.find(nombre) != this->cats.end())
        return this->cats.find(nombre)->second;
    else
        return nullptr;
}

void CategoriaHandler::agregarCategoria(Categoria *categoria)
{
    this->cats.insert(pair<string, Categoria *>(categoria->getNombre(), categoria));
}

void CategoriaHandler::eliminarCategoria(Categoria *categoria)
{
    ////TODO: vacio??
}

void CategoriaHandler::crearNuevaCategoria(string nombre, string descripcion, TipoCategoria tipo)
{
    Categoria *categoria = new Categoria(nombre, descripcion, tipo);
    this->cats.insert(pair<string, Categoria *>(nombre, categoria));
}

CategoriaHandler::~CategoriaHandler() {}

void CategoriaHandler::releaseInstance()
{
    if (instancia != nullptr)
    {
        delete instancia;
        instancia = nullptr;
    }
}
