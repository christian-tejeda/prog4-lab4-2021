
#include <map>
#include <set>
#include <string>
#include <utility>

#include "../../headers/FactoryStrategyEstadistica.h"
#include "../../headers/entities/Videojuego.h"

Videojuego::Videojuego() {}
Videojuego::Videojuego(std::string nombre, std::string descripcion,
                       map<TipoPeriodoValidez, float> suscripciones,
                       pair<float, int> rating,
                       set<ContratoSuscripcion *> contratos,
                       map<string, Categoria *> categorias,
                       std::string nombreEmpresa) {
  this->nombre = nombre;
  this->descripcion = descripcion;
  this->suscripciones = suscripciones;
  this->rating = rating;
  this->contratos = contratos;
  this->categorias = categorias;
  this->nombreEmpresa = nombreEmpresa;
}

// Getters
std::string Videojuego::getNombre() { return this->nombre; }
std::string Videojuego::getDescripcion() { return this->descripcion; }
map<TipoPeriodoValidez, float> Videojuego::getSuscripciones() {
  return this->suscripciones;
}
pair<float, int> Videojuego::getRating() { return this->rating; }
// set<ContratoSuscripcion *> getContratos();
map<string, Categoria *> Videojuego::getCategorias() {
  return this->categorias;
}
set<string> Videojuego::getNombreCategorias() {
  set<string> res;
  map<string, Categoria *>::iterator it;
  for (it = this->categorias.begin(); it != this->categorias.end(); it++) {
    string agregar = it->first;
    res.insert(agregar);
  }
  return res;
}

map<TipoPeriodoValidez, float> Videojuego::getPeriodoValidez() {
  return this->suscripciones;
}

// Setters
void Videojuego::setNombre(std::string nombre) { this->nombre = nombre; }
void Videojuego::setDescripcion(std::string desc) { this->descripcion = desc; }
void Videojuego::setSuscripciones(TipoPeriodoValidez validez, float precio) {}
void Videojuego::setRating(float prom, int cantVotos) {}
// void setContrato(ContratoSuscripcion *);
void Videojuego::setCategoria(Categoria *) {}

void Videojuego::agregarCategoria(Categoria o) {}
set<Jugador *> Videojuego::getSuscriptores() {
  set<Jugador *> res;
  res.insert(nullptr);
  return res;
}
int Videojuego::getCantidadSuscriptores() { return this->suscripciones.size; }

float Videojuego::calcularEstadistica(TipoEstadistica tipoEstadistica) {
  FactoryStrategyEstadistica *factoryEst =
      FactoryStrategyEstadistica::getInstance();

  IStrategyIEstadistica *strategy = factoryEst->getStrategy(tipoEstadistica);

  return strategy->calcularEstadistica(this);
}

DataVideojuego *Videojuego::getData() {
  DataVideojuego data =
      DataVideojuego(this->nombre, this->descripcion, this->suscripciones,
                     this->getNombreCategorias(), this->rating);
  data.setNombreEmpresa(this->nombreEmpresa);
  DataVideojuego *res;
  *res = data;
  return res;
}
Videojuego::~Videojuego() {}