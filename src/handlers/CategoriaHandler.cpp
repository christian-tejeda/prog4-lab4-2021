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

map<std::string, Categoria *> CategoriaHandler::obtenerCategorias() {}

Categoria *CategoriaHandler::obtenerCategoriaPorId(std::string nom) {}

Plataforma *CategoriaHandler::obtenerPlataformaPorId(std::string plat) {}

Genero *CategoriaHandler::obtenerGeneroPorId(std::string genero) {}

void CategoriaHandler::agregarCategoria(Categoria *categoria) {}

void CategoriaHandler::actualizarCategoria(Categoria *categoria) {}

void CategoriaHandler::eliminarCategoria(Categoria *categoria) {}

CategoriaHandler::~CategoriaHandler() {}