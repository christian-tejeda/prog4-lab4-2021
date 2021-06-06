
#include <string>
#include <map>
#include <set>
#include <utility>

#include "../../headers/utils/enums.h"
#include "../../headers/datatypes/DataEstadistica.h"

DataEstadistica::DataEstadistica() {}

DataEstadistica::DataEstadistica(std::string nombre, std::string descripcion, float valor)
{
    this->nombre = nombre;
    this->descripcion = descripcion;
    this->valor = valor;
}
// DataEstadistica::TipoEstadistica getEstadistica(); <- tipo de retorno?

float DataEstadistica::getResultado()
{
    return 0;
}
DataEstadistica::~DataEstadistica() {}
