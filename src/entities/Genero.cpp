
#include <string>
#include <map>
#include <set>
#include <utility>

//#include "../../headers/entities/Categoria.h"
#include "../../headers/entities/Genero.h"
//#include "../../headers/utils/enums.h"
//#include "../../headers/datatypes/DataCategoria.h"
//#include "../../headers/utils/Fecha.h"

Genero::Genero()
{
}
Genero::Genero(std::string nombre, std::string descripcion, TipoGenero tipoGenero) : Categoria(nombre, descripcion)
{
    this->tipo = tipoGenero;
}

TipoGenero Genero::getTipoGenero()
{
    return this->tipo;
}

Genero::~Genero()
{
}
