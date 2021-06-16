
#include <string>
#include <map>
#include <set>
#include <utility>

#include "../../headers/datatypes/DataUsuario.h"
#include "../../headers/utils/enums.h"
#include "../../headers/datatypes/DataVideojuego.h"
#include "../../headers/utils/Fecha.h"

using namespace std;

DataVideojuego::DataVideojuego()
{
}
DataVideojuego::DataVideojuego(string nombre, string descripcion, map<TipoPeriodoValidez, float> suscripciones, set<string> nombreCategorias, pair<float, int> rating)
{
    this->nombre = nombre;
    this->descripcion = descripcion;
    this->suscripciones = suscripciones;
    this->categorias = nombreCategorias;
    this->rating = rating;
}
//Getters
string DataVideojuego::getNombre() const
{
    return this->nombre;
}
string DataVideojuego::getDescripcion() const
{
    return this->descripcion;
}
map<TipoPeriodoValidez, float> DataVideojuego::getSuscripciones() const
{
    return this->suscripciones;
}
set<string> DataVideojuego::getNombreCategorias()
{
    return this->categorias;
}
//Los métodos addCategoria(cat), addPlataforma(plataforma), addGenero(genero) equivalen a aplicarle el metodo insert al set
string DataVideojuego::getNombreEmpresa()
{
    return this->nombreEmpresa;
}
pair<float, int> DataVideojuego::getRating()
{
    return this->rating;
}

void DataVideojuego::setNombreEmpresa(std::string nombreEmpresa){
    this->nombreEmpresa=nombreEmpresa;
}

DataVideojuego::~DataVideojuego() {}