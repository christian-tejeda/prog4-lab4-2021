

#include <map>
#include <set>
#include <utility>

#include "../../headers/entities/Categoria.h"

Categoria::Categoria() {}

Categoria::Categoria(string nombre, string descripcion)
{
    this->nombre = nombre;
    this->descripcion = descripcion;
}
Categoria::Categoria(string nombre, string descripcion, TipoCategoria cat)
{
    this->nombre = nombre;
    this->descripcion = descripcion;
    this->tipo = cat;
}

string Categoria::getNombre() { return this->nombre; }

string Categoria::getDescripcion() { return this->descripcion; }

TipoCategoria Categoria::getTipo() { return this->tipo; }

void Categoria::setNombre(string nombre) { this->nombre = nombre; }

void Categoria::setDescipcion(string descripcion) { this->descripcion = descripcion; }

DataCategoria Categoria::getData() { return DataCategoria(this->nombre, this->descripcion); }

Categoria::~Categoria() {}
