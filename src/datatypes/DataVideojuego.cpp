
#include <string>
#include <map>
#include <set>
#include <utility>

#include "../../headers/datatypes/DataUsuario.h"
#include "../../headers/utils/enums.h"
#include "../../headers/datatypes/DataVideojuego.h"
#include "../../headers/utils/Fecha.h"

using namespace std;

DataVideojuego::DataVideojuego() {
}

DataVideojuego::DataVideojuego(string nombre, string descripcion, map<TipoPeriodoValidez, float> suscripciones, set<string> nombreCategorias, pair<float, int> rating) {
    this->nombre = nombre;
    this->descripcion = descripcion;
    this->suscripciones = suscripciones;
    this->categorias = nombreCategorias;
    this->rating = rating;
}
//Getters
string DataVideojuego::getNombre(){
    return this->nombre;
}

string DataVideojuego::getDescripcion(){
    return this->descripcion;
}

map<TipoPeriodoValidez, float> DataVideojuego::getSuscripciones(){
    return this->suscripciones;
}

set<string> DataVideojuego::getNombreCategorias() {
    return this->categorias;
}
//Los métodos addCategoria(cat), addPlataforma(plataforma), addGenero(genero) equivalen a aplicarle el metodo insert al set
string DataVideojuego::getNombreEmpresa() {
    return this->nombreEmpresa;
}

float DataVideojuego::getHorasTotales() {
    return this->horastotales;
}

pair<float, int> DataVideojuego::getRating() {
    return this->rating;
}

void DataVideojuego::setNombreEmpresa(std::string nombreEmpresa) {
    this->nombreEmpresa=nombreEmpresa;
}

void DataVideojuego::setHorasTotales(float horas) {
    this->horastotales=horas;
}

void DataVideojuego::agregarCategoria(string categoria) {
    this->categorias.insert(categoria);
}

DataVideojuego::~DataVideojuego() {
}