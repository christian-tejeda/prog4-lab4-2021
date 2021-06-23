#ifndef VIDEOJUEGO_H
#define VIDEOJUEGO_H

#include <map>
#include <set>
#include <string>

#include "../datatypes/DataVideojuego.h"
#include "../utils/enums.h"
#include "Categoria.h"

class ContratoSuscripcion;
class Jugador;

class Videojuego
{
private:
  string nombre;
  string descripcion;
  map<TipoPeriodoValidez, float> suscripciones;
  pair<float, int> rating;
  set<ContratoSuscripcion *> contratos;
  map<string, Categoria *> categorias;
  string nombreEmpresa;

public:
  Videojuego();
  Videojuego(string nombre, string descripcion, map<TipoPeriodoValidez, float> suscripciones, pair<float, int> rating, set<ContratoSuscripcion *> contratos, map<string, Categoria *> categorias, string nombreEmpresa);

  string getNombre();
  string getDescripcion();
  map<TipoPeriodoValidez, float> getSuscripciones();
  pair<float, int> getRating();
  set<ContratoSuscripcion *> getContratos();
  map<string, Categoria *> getCategorias();
  set<string> getNombreCategorias();
  map<TipoPeriodoValidez, float> getPeriodoValidez();
  string getNombreEmpresa();

  void setNombre(string nombre);
  void setDescripcion(string descripcion);
  void setSuscripciones(TipoPeriodoValidez validez, float precio);
  void setRating(float promedio, int cantidadVotos);
  void setContrato(ContratoSuscripcion *contrato);
  void setCategoria(Categoria *categoria);

  void agregarCategoria(Categoria *categoria);
  set<Jugador *> getSuscriptores();
  int getCantidadSuscriptores();
  void agregarPuntaje(float puntaje);
  void agregarSuscriptor(ContratoSuscripcion *contrato);
  float calcularEstadistica(TipoEstadistica tipoEstadistica);

  DataVideojuego getData();

  ~Videojuego();
};

#endif