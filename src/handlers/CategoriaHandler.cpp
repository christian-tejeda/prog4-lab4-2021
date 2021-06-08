#include <string>
#include <map>
#include <set>
#include <utility>

#include "../../headers/utils/enums.h"
#include "../../headers/entities/Categoria.h"
#include "../../headers/entities/Genero.h"
#include "../../headers/entities/Plataforma.h"
#include "../../headers/handlers/CategoriaHandler.h"

using namespace std;

CategoriaHandler *CategoriaHandler::instancia = nullptr;

CategoriaHandler::CategoriaHandler() {}

CategoriaHandler *CategoriaHandler::getInstance() {}

map<std::string, Categoria *> CategoriaHandler::obtenerCategorias()
{
    map<std::string, Categoria *> res;
    return res;
}

Categoria *CategoriaHandler::obtenerCategoriaPorId(std::string nom)
{
    return nullptr;
}

Plataforma *CategoriaHandler::obtenerPlataformaPorId(std::string plat)
{
    return nullptr;
}

Genero *CategoriaHandler::obtenerGeneroPorId(std::string genero)
{
    return nullptr;
}

void CategoriaHandler::agregarCategoria(Categoria *categoria)
{
}

void CategoriaHandler::actualizarCategoria(Categoria *categoria)
{
}

void CategoriaHandler::eliminarCategoria(Categoria *categoria) {}

CategoriaHandler::~CategoriaHandler() {}