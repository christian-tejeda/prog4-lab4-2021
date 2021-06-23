#include "../../headers/datatypes/DataVideojuego.h"

DataVideojuego::DataVideojuego() {}

DataVideojuego::DataVideojuego(const DataVideojuego &data)
{
    nombre = data.nombre;
    descripcion = data.descripcion;
    suscripciones = data.suscripciones;
    categorias = data.categorias;
    rating = data.rating;
}

DataVideojuego::DataVideojuego(string nombre, string descripcion, map<TipoPeriodoValidez, float> suscripciones, set<string> nombreCategorias, pair<float, int> rating)
{
    nombre = nombre;
    descripcion = descripcion;
    suscripciones = suscripciones;
    categorias = nombreCategorias;
    rating = rating;
}

string DataVideojuego::getNombre() const { return nombre; }

string DataVideojuego::getDescripcion() const { return descripcion; }

map<TipoPeriodoValidez, float> DataVideojuego::getSuscripciones() const { return suscripciones; }

set<string> DataVideojuego::getNombreCategorias() const { return categorias; }

string DataVideojuego::getNombreEmpresa() const { return nombreEmpresa; }

float DataVideojuego::getHorasTotales() const { return horastotales; }

pair<float, int> DataVideojuego::getRating() const { return rating; }

void DataVideojuego::setNombreEmpresa(string nombreEmpresa) { nombreEmpresa = nombreEmpresa; }

void DataVideojuego::setHorasTotales(float horas) { horastotales = horas; }

void DataVideojuego::agregarCategoria(string categoria) { categorias.insert(categoria); }

bool operator<(const DataVideojuego &d1, const DataVideojuego &d2)
{
    return &d1 < &d2;
}

bool operator!=(const DataVideojuego &d1, const DataVideojuego &d2)
{
    return d1.getNombre() != d2.getNombre() || d1.getHorasTotales() != d2.getHorasTotales() || d1.getDescripcion() != d2.getDescripcion() || d1.getNombreEmpresa() != d2.getNombreEmpresa() || d1.getRating() != d2.getRating() || d1.getSuscripciones() != d2.getSuscripciones();
}

DataVideojuego::~DataVideojuego() {}