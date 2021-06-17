
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
DataCategoria::DataCategoria(string nombre, string descripcion,TipoCategoria tipo)
{
    this->nombre = nombre;
    this->descripcion = descripcion;
    this->tipo=tipo;
}
std::string DataCategoria::getNombre() const
{
    return this->nombre;
}

std::string DataCategoria::getDescripcion() const
{
    return this->descripcion;
}
TipoCategoria DataCategoria::getTipo() const
{
    return this->tipo;
}

DataCategoria::~DataCategoria() {}
