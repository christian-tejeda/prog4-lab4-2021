
#include <string>
#include <map>
#include <set>
#include <utility>

#include "../../headers/entities/Videojuego.h"

Videojuego::Videojuego()
{
}
Videojuego::Videojuego(std::string nombre,
                       std::string descripcion,
                       map<TipoPeriodoValidez, float> suscripciones,
                       pair<float, int> rating,
                       set<ContratoSuscripcion *> contratos,
                       set<Categoria *> categorias,
                       ContextoEstadistica *ctx)
{
    this->nombre = nombre;
    this->descripcion = descripcion;
    this->suscripciones = suscripciones;
    this->rating = rating;
    this->contratos = contratos;
    this->categorias = categorias;
    this->ctx = ctx;
}
//Getters
std::string Videojuego::getNombre()
{
    this->nombre;
}
std::string Videojuego::getDescripcion()
{
    this->descripcion;
}
map<TipoPeriodoValidez, float> Videojuego::getSuscripciones()
{
    this->suscripciones;
}
pair<float, int> Videojuego::getRating()
{
    this->rating;
}
// set<ContratoSuscripcion *> getContratos();
set<Categoria *> Videojuego::getCategorias()
{
    this->categorias = categorias;
}
ContextoEstadistica *Videojuego::getContextoEstadistica()
{
    this->ctx;
}
map<TipoPeriodoValidez, float> Videojuego::getPeriodoValidez()
{
    this->suscripciones;
}
//Setters
void Videojuego::setNombre(std::string nombre)
{
    this->nombre = nombre;
}
void Videojuego::setDescripcion(std::string desc)
{
    this->descripcion = desc;
}
void Videojuego::setSuscripciones(TipoPeriodoValidez validez, float precio)
{
}
void Videojuego::setRating(float prom, int cantVotos)
{
}
// void setContrato(ContratoSuscripcion *);
void Videojuego::setCategoria(Categoria *)
{
}
void Videojuego::setContextoEstadistica(ContextoEstadistica *)
{
}
//Ops
void Videojuego::agregarGenero(Genero g) {}
void Videojuego::agregarPlataforma(Plataforma p) {}
void Videojuego::agregarOtraCategoria(Categoria o) {}
set<Jugador *> Videojuego::getSuscriptores()
{
    set<Jugador *> res;
    res.insert(nullptr);
    return res;
}
int Videojuego::getCantidadSuscriptores()
{
    return 0;
}

DataVideojuego Videojuego::getData()
{
    return DataVideojuego(this->nombre, this->descripcion, this->suscripciones, this->categorias, this->rating);
}
Videojuego::~Videojuego() {}