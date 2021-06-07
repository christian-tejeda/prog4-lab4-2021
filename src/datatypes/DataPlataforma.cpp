
#include <string>
#include <map>
#include <set>
#include <utility>

#include "../../headers/datatypes/DataCategoria.h"
#include "../../headers/datatypes/DataPlataforma.h"

using namespace std;

DataPlataforma::DataPlataforma() {}

DataPlataforma::DataPlataforma(string nombre, string descripcion, TipoPlataforma tipoPlatafoma) : DataCategoria(nombre, descripcion)
{
    this->tipoPlataforma = tipoPlatafoma;
}

TipoPlataforma DataPlataforma::getTipoPlataforma()
{
    return this->tipoPlataforma;
}

DataPlataforma::~DataPlataforma() {}
