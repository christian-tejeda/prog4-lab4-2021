
#include <string>
#include <map>
#include <set>
#include <utility>

#include "../../headers/entities/Categoria.h"
#include "../../headers/entities/Plataforma.h"
#include "../../headers/utils/enums.h"
#include "../../headers/datatypes/DataCategoria.h"
#include "../../headers/utils/Fecha.h"

Plataforma::Plataforma()
{
}
Plataforma::Plataforma(std::string nombre, std::string descripcion, TipoPlataforma tipoPlataforma) : Categoria(nombre, descripcion)
{
    this->tipoPlataforma = tipoPlataforma;
}

TipoPlataforma Plataforma::getTipoPlataforma()
{
    return this->tipoPlataforma;
}

Plataforma::~Plataforma()
{
}
