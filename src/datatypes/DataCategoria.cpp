
#include <string>
#include <map>
#include <set>
#include <utility>

#include "../../headers/datatypes/DataCategoria.h"
#include "../../headers/utils/Fecha.h"

using namespace std;

DataCategoria::DataCategoria() {}

DataCategoria::DataCategoria(string nombre, string descripcion)
{
    this->nombre = nombre;
    this->descripcion = descripcion;
}

std::string DataCategoria::getNombre() const
{
    return this->nombre;
}

std::string DataCategoria::getDescripcion() const
{
    return this->descripcion;
}

DataCategoria::~DataCategoria() {}
