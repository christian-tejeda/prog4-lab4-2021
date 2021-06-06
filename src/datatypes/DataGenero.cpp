
#include <string>
#include <map>
#include <set>
#include <utility>

#include "../../headers/datatypes/DataCategoria.h"
#include "../../headers/datatypes/DataGenero.h"

using namespace std;

DataGenero::DataGenero() {}

DataGenero::DataGenero(string nombre, string descripcion, TipoGenero tipoGenero) : DataCategoria(nombre, descripcion)
{
    this->tipoGenero = tipoGenero;
}

TipoGenero DataGenero::getTipoGenero()
{
    return this->tipoGenero;
}

DataGenero::~DataGenero() {}
