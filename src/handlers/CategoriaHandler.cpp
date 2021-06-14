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

CategoriaHandler *CategoriaHandler::getInstance()
{
    if (instancia == nullptr)
        instancia = new CategoriaHandler();

    return instancia;
}

map<std::string, Categoria *> CategoriaHandler::obtenerCategorias() { return this->cats; }

Categoria *CategoriaHandler::obtenerCategoriaPorId(std::string nombre) { return this->cats[nombre]; }

// Plataforma *CategoriaHandler::obtenerPlataformaPorId(std::string nombre) { return this->cats[nombre]; }

// Genero *CategoriaHandler::obtenerGeneroPorId(std::string nombre) { return this->cats[nombre]; }

void CategoriaHandler::agregarCategoria(Categoria *categoria)
{
    this->cats.insert(std::pair<std::string, Categoria *>(categoria->getNombre(), categoria));
}

void CategoriaHandler::eliminarCategoria(Categoria *categoria) {}

CategoriaHandler::~CategoriaHandler() {}