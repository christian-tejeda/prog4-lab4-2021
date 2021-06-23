
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <utility>

#include "../../headers/FactoryStrategyEstadistica.h"
#include "../../headers/entities/Videojuego.h"
#include "../../headers/entities/ContratoSuscripcion.h"

Videojuego::Videojuego() {}

Videojuego::Videojuego(string nombre, string descripcion, map<TipoPeriodoValidez, float> suscripciones, pair<float, int> rating, set<ContratoSuscripcion *> contratos, map<string, Categoria *> categorias, string nombreEmpresa)
{
  this->nombre = nombre;
  this->descripcion = descripcion;
  this->suscripciones = suscripciones;
  this->rating = rating;
  this->contratos = contratos;
  this->categorias = categorias;
  this->nombreEmpresa = nombreEmpresa;
}

string Videojuego::getNombre() { return this->nombre; }

string Videojuego::getDescripcion() { return this->descripcion; }

map<TipoPeriodoValidez, float> Videojuego::getSuscripciones() { return this->suscripciones; }

pair<float, int> Videojuego::getRating() { return this->rating; }

map<string, Categoria *> Videojuego::getCategorias() { return this->categorias; }

void Videojuego::agregarSuscriptor(ContratoSuscripcion *contrato) { this->contratos.insert(contrato); }

set<string> Videojuego::getNombreCategorias()
{
  set<string> res;
  map<string, Categoria *>::iterator it;

  for (it = this->categorias.begin(); it != this->categorias.end(); it++)
  {
    string agregar = it->first;
    res.insert(agregar);
  }

  return res;
}

map<TipoPeriodoValidez, float> Videojuego::getPeriodoValidez() { return this->suscripciones; }

void Videojuego::setNombre(string nombre) { this->nombre = nombre; }

void Videojuego::setDescripcion(string descripcion) { this->descripcion = descripcion; }

void Videojuego::setSuscripciones(TipoPeriodoValidez validez, float precio)
{
  ///TODO: nada??
}

void Videojuego::setRating(float prom, int cantVotos)
{
  ///TODO: nada??
}

void Videojuego::setCategoria(Categoria *categoria)
{
  this->categorias.insert(pair<string, Categoria *>(categoria->getNombre(), categoria));
}

void Videojuego::agregarCategoria(Categoria *o)
{
  ///TODO: nada??
}

string Videojuego::getNombreEmpresa() { return this->nombreEmpresa; }

set<Jugador *> Videojuego::getSuscriptores()
{
  set<Jugador *> res;
  set<ContratoSuscripcion *>::iterator it;

  for (it = this->contratos.begin(); it != this->contratos.end(); it++)
  {
    ContratoSuscripcion *contrato = *it;
    Jugador *jugador = contrato->getJugador();
    res.insert(jugador);
  }

  return res;
}
int Videojuego::getCantidadSuscriptores() { return this->contratos.size(); }

float Videojuego::calcularEstadistica(TipoEstadistica tipoEstadistica)
{
  FactoryStrategyEstadistica *factoryEst =
      FactoryStrategyEstadistica::getInstance();

  IStrategyIEstadistica *strategy = factoryEst->getStrategy(tipoEstadistica);

  return strategy->calcularEstadistica(this);
}

void Videojuego::agregarPuntaje(float puntaje)
{
  this->rating.first += puntaje;
  this->rating.second++;
}

DataVideojuego Videojuego::getData()
{
  DataVideojuego data(this->nombre, this->descripcion, this->suscripciones, this->getNombreCategorias(), this->rating);
  data.setNombreEmpresa(this->nombreEmpresa);

  return data;
}

Videojuego::~Videojuego() {}