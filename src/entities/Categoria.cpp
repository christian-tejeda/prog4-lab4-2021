
#include <string>
#include <map>
#include <set>
#include <utility>

#include "../../headers/entities/Categoria.h"
#include "../../headers/entities/Usuario.h"
#include "../../headers/utils/enums.h"
#include "../../headers/datatypes/DataCategoria.h"
#include "../../headers/utils/Fecha.h"

Categoria::Categoria() { }

Categoria::Categoria(std::string nombre, std::string descripcion) {
    this->nombre = nombre;
    this->descripcion = descripcion;
}

std::string Categoria::getNombre() {
    return this->nombre;
}

std::string Categoria::getDescripcion()
{
    return this->descripcion;
}

void Categoria::setNombre(std::string nombre) {
    this->nombre = nombre;
}

void Categoria::setDescipcion(std::string descripcion) {
    this->descripcion = descripcion;
}

DataCategoria Categoria::getData()
{
    return DataCategoria(this->nombre, this->descripcion);
}
