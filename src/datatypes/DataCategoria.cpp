
#include <string>
#include <map>
#include <set>
#include <utility>

#include "../../headers/datatypes/DataCategoria.h"

using namespace std;

DataCategoria::DataCategoria()
{
    nombre = "";
    descripcion = "";
}

DataCategoria::DataCategoria(string nombre, string descripcion)
{
    nombre = nombre;
    descripcion = descripcion;
}

DataCategoria::DataCategoria(const DataCategoria &data)
{
    nombre = data.nombre;
    descripcion = data.descripcion;
}

DataCategoria::DataCategoria(string nombre, string descripcion, TipoCategoria tipo)
{
    nombre = nombre;
    descripcion = descripcion;
    tipo = tipo;
}

string DataCategoria::getNombre() const { return nombre; }

string DataCategoria::getDescripcion() const { return descripcion; }

TipoCategoria DataCategoria::getTipo() const { return tipo; }

bool operator<(const DataCategoria &d1, const DataCategoria &d2)
{
    return &d1 < &d2;
}

bool operator!=(const DataCategoria &d1, const DataCategoria &d2)
{
    return d1.getNombre() != d2.getNombre() || d1.getDescripcion() != d2.getDescripcion();
}

DataCategoria::~DataCategoria() {}
